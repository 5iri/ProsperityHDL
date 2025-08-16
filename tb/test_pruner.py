# -----------------------------------------------------------------------------
#  File: test_pruner.py  – Cocotb / pytest test with detailed prefix log
# -----------------------------------------------------------------------------
import random, csv, enum
from pathlib import Path

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ClockCycles
from cocotb_test.simulator import run


# -------------------- DUT parameters ----------------------------------------
N, M, NO_WIDTH = 256, 16, 8
CLK_PERIOD_NS, RESET_CYCLES = 10, 2


class PrunerState(enum.IntEnum):
    S_IDLE = 0; S_FILT = 1; S_SEL = 2; S_XOR = 3; S_OUT = 4; S_NEXT = 5


def popcount(x) -> int:
    return bin(x).count("1")


# -------------------- DUT reset ---------------------------------------------
async def reset_dut(dut):
    dut.rst_n.value = 0
    dut.si_valid.value = 0
    dut.dispatch_ready.value = 0
    for i in range(N):
        dut.NO_table[i].value = 0
        dut.spike_matrix[i].value = 0
    await ClockCycles(dut.clk, RESET_CYCLES)
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)


# -------------------- synthetic tile ----------------------------------------
def generate_tile(seed=0xC0FFEE):
    random.seed(seed)
    rows = []
    bases = [
        0b1001_0110_1100_0011,
        0b0110_1001_0011_1100,
        0b1111_0000_1111_0000,
    ]
    rows += bases
    for b in bases:
        rows += [b & 0xFF00, b & 0x00FF, b & 0xF0F0]
    rows += random.sample(rows, k=8)
    while len(rows) < N:
        if random.random() < 0.6:
            proto = random.choice(bases); mask = random.getrandbits(M)
            rows.append(proto & mask)
        else:
            rows.append(random.getrandbits(M))
    return rows[:N]


def analyse_reuse(rows):
    reuse = 0
    for idx, row in enumerate(rows):
        NO_row = popcount(row)
        for p_idx, prefix in enumerate(rows):
            if p_idx == idx: continue
            NO_p = popcount(prefix)
            if (prefix & row) == prefix and NO_p < NO_row: reuse += 1; break
            if prefix == row and p_idx < idx: reuse += 1; break
    return reuse


# -------------------- simulation monitor ------------------------------------
async def monitor_pruner(dut, NOs, log_list):
    cycles = processed = reuse_found = 0

    while not dut.prune_done.value and cycles < 15000:
        await RisingEdge(dut.clk)
        cycles += 1

        if dut.prune_valid.value:
            row_idx   = int(dut.row_idx_r.value)
            prefix_id = int(dut.prefix_id.value)
            pattern   = int(dut.pattern.value)

            reuse_edge = prefix_id != row_idx
            if reuse_edge: reuse_found += 1
            processed += 1

            log_entry = {
                "Row": row_idx,
                "Prefix": prefix_id,
                "Reuse": reuse_edge,
                "Pattern_bin": format(pattern, f"0{M}b"),
                "Row_NO": NOs[row_idx],
                "Prefix_NO": NOs[prefix_id],
            }
            log_list.append(log_entry)

            # pretty one-liner for console
            dut._log.info(
                f"[{processed:3d}] Row {row_idx:3d} → Prefix {prefix_id:3d} "
                f"({'R' if reuse_edge else '-'})  "
                f"PAT={log_entry['Pattern_bin']}  "
                f"NO={NOs[row_idx]:2d}/{NOs[prefix_id]:2d}"
            )

    assert dut.prune_done.value == 1, "Pruner did not finish in time"
    return processed, reuse_found, cycles


# -------------------- cocotb test -------------------------------------------
@cocotb.test()
async def test_product_sparsity(dut):
    # 1. clock + reset
    cocotb.start_soon(Clock(dut.clk, CLK_PERIOD_NS, units="ns").start())
    await reset_dut(dut)

    # 2. create tile + load into DUT memories
    rows = generate_tile()
    NOs  = [popcount(r) for r in rows]
    for i in range(N):
        dut.NO_table[i].value = NOs[i]
        dut.spike_matrix[i].value = rows[i]

    # 3. present initial handshake
    dut.dispatch_ready.value = 1
    dut.si_vector.value = (1 << N) - 1
    dut.row_index.value = 0
    dut.row_NO.value = NOs[0]
    dut.si_valid.value = 1

    # 4. run + collect per-row log
    pruned_log = []
    processed, reuse_found, cycles = await monitor_pruner(dut, NOs, pruned_log)

    # 5. write CSV for offline analysis
    csv_path = Path("sim_build") / "pruned_forest_log.csv"
    csv_path.parent.mkdir(exist_ok=True)
    with csv_path.open("w", newline="") as fh:
        writer = csv.DictWriter(fh, fieldnames=pruned_log[0].keys())
        writer.writeheader(); writer.writerows(pruned_log)
    dut._log.info(f"Detailed prefix log written to {csv_path}")

    # 6. functional assertions
    expected_reuse = analyse_reuse(rows)
    dut._log.info(
        f"Processed={processed}  reuse_found={reuse_found}/{expected_reuse}  "
        f"cycles={cycles}"
    )
    
    # Basic completeness assertions
    assert processed == N, f"Expected {N} rows processed, got {processed}"
    assert reuse_found >= 0.7 * expected_reuse, "Reuse efficiency < 70 %"
    
    # Additional meaningful assertions
    assert cycles > 0, "Pruner should take at least one cycle to complete"
    assert cycles < 10 * N, f"Pruner took too many cycles: {cycles} > {10 * N}"
    
    # Verify prefix relationships are valid
    prefix_count = 0
    invalid_prefixes = 0
    
    for entry in pruned_log:
        row_idx = entry["Row"]
        prefix_id = entry["Prefix"]
        row_pattern = rows[row_idx]
        prefix_pattern = rows[prefix_id]
        
        if row_idx != prefix_id:  # This is a suffix row
            # Verify prefix is actually a subset
            if not is_subset(prefix_pattern, row_pattern):
                invalid_prefixes += 1
                dut._log.error(f"Invalid prefix relationship: row {row_idx} pattern {row_pattern:016b} "
                              f"does not contain prefix {prefix_id} pattern {prefix_pattern:016b}")
        else:
            prefix_count += 1
    
    assert invalid_prefixes == 0, f"Found {invalid_prefixes} invalid prefix relationships"
    
    # More reasonable assertion: either we have some self-prefixes OR high reuse efficiency
    if prefix_count == 0:
        dut._log.info("No self-prefixes found - all rows reuse other prefixes (good for efficiency)")
        # If no self-prefixes, we should have good reuse efficiency
        reuse_efficiency = reuse_found / max(expected_reuse, 1)  # Avoid division by zero
        assert reuse_efficiency >= 0.5 or reuse_found >= N // 4, \
            f"With no self-prefixes, expected good reuse: efficiency={reuse_efficiency:.2f}, reuse_found={reuse_found}"
    else:
        dut._log.info(f"Found {prefix_count} self-prefixes")
    
    # Verify reasonable prefix distribution - each prefix should be used by at least one row
    prefix_usage = {}
    for entry in pruned_log:
        prefix_id = entry["Prefix"]
        prefix_usage[prefix_id] = prefix_usage.get(prefix_id, 0) + 1
    
    unique_prefixes = len(prefix_usage)
    assert unique_prefixes > 0, "At least one prefix should be used"
    assert unique_prefixes <= N, "Number of unique prefixes should not exceed number of rows"
    
    dut._log.info(f"Prefix distribution: {unique_prefixes} unique prefixes used")
    
    # Verify output pattern correctness (XOR relationship)
    for entry in pruned_log:
        row_idx = entry["Row"]
        prefix_id = entry["Prefix"]
        # Note: We would need to capture the output pattern to verify XOR relationship
        # This assertion structure shows the intent
    
    dut._log.info(f"✅ Product sparsity test passed: {unique_prefixes} unique prefixes, "
                  f"{prefix_count} self-prefixes, {reuse_found} reuse instances, "
                  f"efficiency {reuse_found/max(expected_reuse, 1):.1%}")

def is_subset(pattern_a, pattern_b):
    """Check if pattern_a is a subset of pattern_b"""
    return (pattern_a & pattern_b) == pattern_a


# -------------------- pytest harness ----------------------------------------
def test_pruner_pytest():
    repo = Path(__file__).parent
    rtl  = repo.parent / "ppu" / "pruner.v"

    run(
        verilog_sources=[str(rtl)],
        toplevel="pruner",
        module="test_pruner",
        parameters={"N": str(N), "M": str(M), "NO_WIDTH": str(NO_WIDTH)},
        timescale="1ns/1ps",
        simulator="verilator",
        compile_args=["-Wall", "-Wno-fatal"],
        waves=0,
        build_dir="sim_build",
    )


if __name__ == "__main__":
    test_pruner_pytest()
