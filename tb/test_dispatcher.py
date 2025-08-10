# test_dispatcher.py ──────────────────────────────────────────────────────
# Enhanced‐logging + extra assertions edition  (03-Jul-2025)
#
# • Drives dispatcher.v with legal ProSparsity rows
# • Verifies global ascending (pop-count, row-idx) order
# • Verifies EM / PM prefix-before-suffix rules
# • Provides a tiny deterministic test for waveform debug
# • Rich DEBUG-level logs at every handshake

import random
from pathlib import Path

import cocotb
from cocotb.clock   import Clock
from cocotb.triggers import RisingEdge

# ----------------------------------------------------------------------
# Simulation parameters (mirror RTL generics)
# ----------------------------------------------------------------------
CLK_NS     = 10
ROWS       = 256
SPIKES     = 16
NO_WIDTH   = 8
MAX_CYCLES = 50_000
SEED       = 2025


# ── Utility helpers ──────────────────────────────────────────────────────
def popcount(x: int) -> int:
    return bin(x).count("1")


def is_subset(a: int, b: int) -> bool:
    """True if bit-pattern a ⊆ b."""
    return (a & b) == a


def random_pattern(lo: int = 1, hi: int = SPIKES) -> int:
    bits, patt = random.sample(range(SPIKES), random.randint(lo, hi)), 0
    for b in bits:
        patt |= 1 << b
    return patt


async def reset(dut):
    cocotb.log.debug("→ asserting reset")
    dut.rst_n.value          = 0
    dut.row_info_valid.value = 0
    dut.row_last.value       = 0
    for _ in range(3):
        await RisingEdge(dut.clk)
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)
    cocotb.log.debug("← de-assert reset")


# ─────────────────────────────────────────────────────────────────────────
# Full-size randomised regression
# ─────────────────────────────────────────────────────────────────────────
@cocotb.test()
async def test_dispatcher_prosparsity(dut):
    """Large randomised PM/EM legality + global order check."""
    random.seed(SEED)
    cocotb.start_soon(Clock(dut.clk, CLK_NS, units="ns").start())
    await reset(dut)

    # Static inputs
    dut.prev_compute_busy.value = 0
    dut.proc_ready.value        = 1
    dut.pruner_done.value       = 0      # not used in minimal RTL

    # ---------- Generate a legal ProSparsity tile ----------
    tile_rows, prefix_bank = [], []
    for row in range(ROWS):
        if row == 0 or random.random() < 0.25:            # new prefix
            patt = random_pattern(1, SPIKES - 1)
            pc   = popcount(patt)
            prefix_bank.append({'row': row, 'pattern': patt, 'pc': pc})
            tile_rows.append({'row': row, 'prefix': row,
                              'pattern': patt, 'pc': pc})
        else:                                             # suffix
            pref = random.choice(prefix_bank)
            if random.random() < 0.4:                     # Exact-Match
                patt, pc = pref['pattern'], pref['pc']
            else:                                         # Partial-Match
                base = pref['pattern']                    # FIX: define first
                free = [b for b in range(SPIKES) if not (base >> b & 1)]
                extra = (random.sample(
                    free, random.randint(1, min(3, len(free))))
                         if free else [])
                patt = base
                for b in extra:
                    patt |= 1 << b
                pc = popcount(patt)
            tile_rows.append({'row': row, 'prefix': pref['row'],
                              'pattern': patt, 'pc': pc})

    cocotb.log.info(f"Generated {ROWS} legal rows "
                    f"({len(prefix_bank)} prefixes)")

    # ---------- Drive spatial channel ----------
    sent = 0
    while sent < ROWS:
        if dut.row_info_ready.value:
            rec = tile_rows[sent]
            dut.row_info_valid.value = 1
            dut.row_idx.value        = rec['row']
            dut.row_prefix_id.value  = rec['prefix']
            dut.row_pattern.value    = rec['pattern']
            dut.row_popcnt.value     = rec['pc']
            dut.row_last.value       = int(sent == ROWS - 1)

            cocotb.log.debug(f"TX row={rec['row']:03d}  "
                             f"prefix={rec['prefix']:03d}  "
                             f"pc={rec['pc']:02d}  patt={rec['pattern']:0{SPIKES}b}")
            await RisingEdge(dut.clk)

            # ready/valid discipline
            assert (not dut.row_info_valid.value) or dut.row_info_ready.value, \
                "row_info_valid held high without ready!"

            sent += 1
        else:
            dut.row_info_valid.value = 0
            dut.row_last.value       = 0
            await RisingEdge(dut.clk)

    dut.row_info_valid.value = 0
    dut.row_last.value       = 0
    cocotb.log.info("• Finished pumping spatial tuples")

    # ---------- Collect dispatched tasks & verify ----------
    got, pc_prev, row_prev = [], -1, -1
    patt_seen, pc_seen     = {}, {}
    cycles = 0

    while len(got) < ROWS and cycles < MAX_CYCLES:
        if dut.task_valid.value and dut.proc_ready.value:
            r   = dut.task_row_id.value.integer
            prf = dut.task_prefix_id.value.integer
            patt = dut.task_pattern.value.integer
            pc   = popcount(patt)

            cocotb.log.debug(f"RX row={r:03d}  pref={prf:03d}  "
                             f"pc={pc:02d}  patt={patt:0{SPIKES}b}")

            # Global ascending order
            assert pc > pc_prev or (pc == pc_prev and r > row_prev), \
                "Global order violation"
            pc_prev, row_prev = pc, r

            # EM / PM legality
            if prf != r:                                 # suffix
                assert prf in patt_seen, \
                    "Suffix dispatched before its prefix!"
                pref_patt, pref_pc = patt_seen[prf], pc_seen[prf]
                if pc == pref_pc:                        # EM
                    assert patt == pref_patt, "EM pattern mismatch"
                    assert r > prf,       "EM row index must follow prefix"
                else:                                    # PM
                    assert pref_pc < pc,  "PM pop-count ordering"
                    assert is_subset(pref_patt, patt), \
                        "PM subset rule violated"

            patt_seen[r], pc_seen[r] = patt, pc
            got.append(r)

        if dut.tile_done.value and len(got) < ROWS:
            cocotb.log.warning("tile_done asserted early!")

        await RisingEdge(dut.clk)
        cycles += 1

    assert len(got) == ROWS, \
        f"Dispatcher produced {len(got)}/{ROWS} tasks (cycles={cycles})"
    cocotb.log.info("✓ Full-size dispatcher test passed "
                    f"({len(got)} tasks, {cycles} cycles)")


# ─────────────────────────────────────────────────────────────────────────
# Tiny deterministic test (8 rows) for quick debug
# ─────────────────────────────────────────────────────────────────────────
@cocotb.test()
async def test_dispatcher_small(dut):
    """Eight-row deterministic test for quick waveform debug."""
    random.seed(SEED + 1)
    cocotb.start_soon(Clock(dut.clk, CLK_NS, units="ns").start())
    await reset(dut)

    dut.prev_compute_busy.value = 0
    dut.proc_ready.value        = 1
    dut.pruner_done.value       = 0

    rows = [
        (0, 0, 0b0011), (1, 1, 0b1100),
        (2, 0, 0b0011), (3, 0, 0b0111),
        *[(n, n, random_pattern(1, 4)) for n in range(4, 8)],
    ]

    for i, (row, pref, patt) in enumerate(rows):
        while not dut.row_info_ready.value:
            await RisingEdge(dut.clk)
        dut.row_info_valid.value = 1
        dut.row_idx.value, dut.row_prefix_id.value = row, pref
        dut.row_pattern.value, dut.row_popcnt.value = patt, popcount(patt)
        dut.row_last.value = int(i == len(rows) - 1)
        cocotb.log.debug(f"TX small row={row}, pref={pref}, patt={patt:04b}")
        await RisingEdge(dut.clk)
    dut.row_info_valid.value = 0
    dut.row_last.value       = 0

    seen, cycles = 0, 0
    while seen < len(rows) and cycles < 1_000:
        if dut.task_valid.value:
            seen += 1
        await RisingEdge(dut.clk)
        cycles += 1

    assert seen == len(rows), "Small-test task count mismatch"
    cocotb.log.info("✓ Small dispatcher test passed")


# ─────────────────────────────────────────────────────────────────────────
# Pytest wrapper for cocotb-test / Verilator
# ─────────────────────────────────────────────────────────────────────────
def test_dispatcher():
    from cocotb_test.simulator import run
    repo = Path(__file__).resolve().parents[1]
    verilog_sources = [repo / "ppu" / "dispatcher.v"]

    run(
        verilog_sources=[str(v) for v in verilog_sources],
        toplevel="dispatcher",
        module="test_dispatcher",
        parameters={
            "ROWS":     str(ROWS),
            "SPIKES":   str(SPIKES),
            "NO_WIDTH": str(NO_WIDTH),
        },
        timescale="1ns/1ps",
        simulator="verilator",
        compile_args=[
            "-Wall", "-Wno-fatal",
            "-Wno-UNOPTFLAT", "-Wno-UNSIGNED",
            "-DSIMULATION",
        ],
        waves=True,
    )


if __name__ == "__main__":
    # One-shot convenience run (python test_dispatcher.py)
    test_dispatcher()
