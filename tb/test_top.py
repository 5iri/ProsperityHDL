# tests/test_top.py  ───────────────────────────────────────────────────────
# End-to-end bench for ppu_top.v  – 256-row coverage & row-set check

import random
from pathlib import Path
from collections import Counter, defaultdict

import cocotb
from cocotb.clock   import Clock
from cocotb.triggers import RisingEdge, ReadOnly, ReadWrite
from cocotb_test.simulator import run

# ----------------------------------------------------------------------
# Parameters mirrored in RTL generics
# ----------------------------------------------------------------------
CLK_NS, ROWS, SPIKES, NO_WIDTH = 10, 256, 16, 8
MAX_CYCLES, SEED = 80_000, 2026


# ── Helpers ─────────────────────────────────────────────────────────────
def popcount(x: int) -> int:
    return bin(x).count("1")


def random_pattern(lo: int = 1, hi: int = SPIKES) -> int:
    bits, patt = random.sample(range(SPIKES), random.randint(lo, hi)), 0
    for b in bits:
        patt |= 1 << b
    return patt


def pattern_stats(patterns, spikes=16) -> str:
    if not patterns:
        return "No patterns processed"
    pcs = [popcount(p) for p in patterns]
    hist = Counter(pcs)
    lines = [
        "\n=== PATTERN STATS ===",
        f"Total patterns   : {len(patterns)}",
        f"Unique patterns  : {len(set(patterns))}",
        f"Popcount range   : {min(pcs)}–{max(pcs)}",
        f"Popcount hist    : {dict(hist)}",
    ]
    return "\n".join(lines)


async def reset(dut):
    dut.rst_n.value = 0
    for _ in range(5):
        await RisingEdge(dut.clk)
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)


# ── Main test ───────────────────────────────────────────────────────────
@cocotb.test()
async def ppu_pipeline_random(dut):
    """Run a full 256-row tile and check the complete row-set returned."""
    random.seed(SEED)
    cocotb.start_soon(Clock(dut.clk, CLK_NS, units="ns").start())
    await reset(dut)

    # ------------------------------------------------------------
    # 1. Build a random 256-row tile
    # ------------------------------------------------------------
    tile = [
        {"row": r, "patt": random_pattern(1, SPIKES - 1)}
        for r in range(ROWS)
    ]

    # ------------------------------------------------------------
    # 2. Pre-load SPIKE RAM via public port
    # ------------------------------------------------------------
    dut.tile_mem_wr_en.value = 0
    for entry in tile:
        dut.tile_mem_addr.value    = entry["row"]
        dut.tile_mem_data_in.value = entry["patt"]
        dut.tile_mem_wr_en.value   = 1
        await RisingEdge(dut.clk)
    dut.tile_mem_wr_en.value = 0
    dut.tile_mem_addr.value  = 0
    cocotb.log.info("• Tile RAM pre-load complete")

    # ------------------------------------------------------------
    # 3. Kick off pipeline
    # ------------------------------------------------------------

    dut.tile_start.value = 1
    await RisingEdge(dut.clk)
    dut.tile_start.value = 0
    dut.core_ready.value = 1          # Always ready – no back-pressure

    # ------------------------------------------------------------
    # 4. Collect dispatched tasks
    # ------------------------------------------------------------
    issued_rows = []
    pc_prev, row_prev = -1, -1
    patt_seen = defaultdict(int)
    cycles = 0

    # Keep `core_ready` high

    # ── Latency bookkeeping ─────────────────────────────────────
    state_names = {0: 'IDLE', 1: 'LOAD', 2: 'INIT', 3: 'PROC', 4: 'DONE'}
    state_cycles = {s: 0 for s in state_names}
    tile_done_seen = False

    # Keep `core_ready` high and simply latch new tasks when `task_valid` rises.
# Detect the rising edge of `task_valid` to avoid double-counting tasks held
# valid for multiple cycles.

    while cycles < MAX_CYCLES and len(issued_rows) < ROWS:
        await ReadOnly()  # observe signals for this cycle (read-only phase)
        # Count cycle for current FSM state
        try:
            cur_state = int(dut.dbg_state.value)
            if cur_state in state_cycles:
                state_cycles[cur_state] += 1
        except AttributeError:
            pass  # state signal not visible

        if dut.task_valid.value:
            # Task is present this cycle – capture it
            row = dut.task_row_id.value.integer
            prefix_id = dut.task_prefix_id.value.integer
            task_patt = dut.task_pattern.value.integer
            row_patt  = tile[row]["patt"]
            prefix_patt = tile[prefix_id]["patt"]
            pc  = popcount(task_patt)
            row_pc = popcount(row_patt)
            prefix_pc = popcount(prefix_patt)

            # 1. Global dispatch order must be non-decreasing popcount, tie-break by row id
            assert pc > pc_prev or (pc == pc_prev and row > row_prev), (
                "Ordering error: prev(row=%d,pc=%d) → row=%d,pc=%d" % (row_prev, pc_prev, row, pc))
            pc_prev, row_prev = pc, row

            # 2. Prefix must be subset (or identical) of row pattern
            assert (prefix_patt & ~row_patt) == 0, (
                f"Prefix not subset: row {row:#x}, prefix {prefix_id:#x}")

            # 3. Task pattern must equal row ⊕ prefix
            assert task_patt == (row_patt ^ prefix_patt), (
                f"Task pattern mismatch: expected {(row_patt ^ prefix_patt):#x}, got {task_patt:#x}")

            # 4. Popcount relationship as per paper
            assert pc == row_pc - prefix_pc, (
                f"Popcount mismatch: expected {row_pc - prefix_pc}, got {pc}")

            # 5. Prefix selection rule: smaller popcount or (equal popcount & lower index)
            assert prefix_pc < row_pc or (prefix_pc == row_pc and prefix_id <= row), (
                "Prefix selection rule violated")

            issued_rows.append(row)
            patt_seen[row] += 1

        # Check for tile completion
        if dut.tile_done.value and not tile_done_seen:
            tile_done_seen = True
            total_latency = cycles
        
        await RisingEdge(dut.clk)
        cycles += 1

    # ------------------------------------------------------------
    # 5. Row-set verification
    # ------------------------------------------------------------
    missing = sorted(set(range(ROWS)) - set(issued_rows))
    dupes   = [r for r, cnt in patt_seen.items() if cnt > 1]

    assert not missing, f"Missing rows: {missing}"
    assert not dupes,   f"Duplicate rows: {dupes}"
    assert len(issued_rows) == ROWS, \
        f"Expected {ROWS} tasks, got {len(issued_rows)}"

    cocotb.log.info(pattern_stats(list(patt_seen.keys()), SPIKES))
    cocotb.log.info("✓ PPU pipeline emitted every row exactly once")

    # ── Latency report ─────────────────────────────────────────
    if tile_done_seen:
        cocotb.log.info(f"Tile latency   : {total_latency} cycles ({total_latency*CLK_NS} ns)")
    else:
        cocotb.log.warning("Tile_done never asserted within timeout")

    for s, n in state_cycles.items():
        cocotb.log.info(f"Latency[{state_names[s]}] : {n} cycles")

# ── Pytest wrapper (cocotb-test) ─────────────────────────────────────────
def test_ppu():
    repo = Path(__file__).resolve().parents[1]
    verilog_sources = [
        repo / "ppu" / "top.v",
        repo / "ppu" / "detector.v",
        repo / "ppu" / "pruner.v",
        repo / "ppu" / "dispatcher.v",
        repo / "ppu" / "tcam" / "hdl" / "tcam_line_array.v",
        repo / "ppu" / "tcam" / "hdl" / "tcam_line_encoder.v",
        repo / "ppu" / "tcam" / "hdl" / "tcam_sdpram.v",
    ]

    run(
        verilog_sources=[str(v) for v in verilog_sources],
        toplevel="top",
        module="test_top",
        parameters={
            "ROWS":     str(ROWS),
            "SPIKES":   str(SPIKES),
            "NO_WIDTH": str(NO_WIDTH),
        },
        timescale="1ns/1ps",
        simulator="verilator",
        compile_args=["-Wall", "-Wno-fatal"],
        waves=True,
    )


if __name__ == "__main__":
    test_ppu()
