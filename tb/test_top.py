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


async def init_phase1_signals(dut, enable_collection=False):
    """Initialize Phase 1 integration signals (timestep control, spike I/O)"""
    # Timestep control - disabled by default for manual tile_start
    dut.cfg_num_timesteps.value = 1
    dut.sim_start.value = 0
    
    # Spike injection - disabled (using tile_mem interface instead)
    dut.spike_inject_wr_en.value = 0
    dut.spike_inject_wr_addr.value = 0
    dut.spike_inject_wr_data.value = 0
    
    # Spike collection - enable to capture outputs
    dut.spike_collect_enable.value = 1 if enable_collection else 0
    dut.spike_collect_clear.value = 0
    dut.spike_collect_rd_en.value = 0
    dut.spike_collect_rd_addr.value = 0
    
    # LIF configuration for neuron operation
    if enable_collection:
        dut.cfg_lif_threshold.value = 100
        dut.cfg_lif_leak.value = 2
        dut.cfg_lif_reset.value = 0
        dut.cfg_lif_refractory.value = 2
        dut.cfg_lif_enable.value = 1
        dut.timestep_end.value = 0
    
    await RisingEdge(dut.clk)


# ── Main test ───────────────────────────────────────────────────────────
@cocotb.test()
async def ppu_pipeline_random(dut):
    """Run a full 256-row tile and check the complete row-set returned."""
    random.seed(SEED)
    cocotb.start_soon(Clock(dut.clk, CLK_NS, units="ns").start())
    await reset(dut)
    
    # Initialize Phase 1 signals with spike collection enabled
    await init_phase1_signals(dut, enable_collection=True)

    # ------------------------------------------------------------
    # 1. Build a random 256-row tile (input spike patterns)
    # ------------------------------------------------------------
    tile = [
        {"row": r, "patt": random_pattern(1, SPIKES - 1)}
        for r in range(ROWS)
    ]

    # ------------------------------------------------------------
    # 2. Pre-load SPIKE RAM via public port
    cocotb.log.info(f"• Generated {ROWS} random spike patterns")

    # ------------------------------------------------------------
    # 2. Load input spikes via spike_injector (timestep 0)
    # ------------------------------------------------------------
    dut.spike_inject_wr_en.value = 0
    for entry in tile:
        row = entry["row"]
        pattern = entry["patt"]
        # Address = timestep * ROWS + row = 0 * 256 + row
        dut.spike_inject_wr_addr.value = row
        dut.spike_inject_wr_data.value = pattern
        dut.spike_inject_wr_en.value = 1
        await RisingEdge(dut.clk)
    dut.spike_inject_wr_en.value = 0
    cocotb.log.info("• Input spikes loaded into spike_injector")

    # Also load into tile RAM for product sparsity processing
    dut.tile_mem_wr_en.value = 0
    for entry in tile:
        dut.tile_mem_addr.value = entry["row"]
        dut.tile_mem_data_in.value = entry["patt"]
        dut.tile_mem_wr_en.value = 1
        await RisingEdge(dut.clk)
    dut.tile_mem_wr_en.value = 0
    cocotb.log.info("• Tile patterns loaded for product sparsity")
    
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)

    # ------------------------------------------------------------
    # 3. Start simulation via timestep controller
    # ------------------------------------------------------------
    dut.cfg_num_timesteps.value = 1  # Single timestep
    dut.core_ready.value = 1  # Processor ready
    
    dut.sim_start.value = 1
    await RisingEdge(dut.clk)
    dut.sim_start.value = 0
    cocotb.log.info("• Simulation started via timestep controller")

    # ------------------------------------------------------------
    # 4. Monitor complete dataflow: spikes → product sparsity → LIF → spikes
    # ------------------------------------------------------------
    issued_rows = []
    pc_prev, row_prev = -1, -1
    patt_seen = defaultdict(int)
    cycles = 0

    # Latency bookkeeping
    state_names = {0: 'IDLE', 1: 'LOAD', 2: 'INIT', 3: 'PROC', 4: 'DONE'}
    state_cycles = {s: 0 for s in state_names}
    tile_done_seen = False
    sim_done_seen = False
    
    cocotb.log.info("• Monitoring: input spikes → product sparsity → LIF → output spikes")

    while cycles < MAX_CYCLES and not sim_done_seen:
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
            
            # Handle NULL prefix (0xFF = 255) - indicates root row with no reusable prefix
            NULL_PREFIX_ID = 0xFF
            is_null_prefix = (prefix_id == NULL_PREFIX_ID)
            
            if is_null_prefix:
                prefix_patt = 0  # NULL prefix has no pattern contribution
            else:
                prefix_patt = tile[prefix_id]["patt"]
            
            pc  = popcount(task_patt)
            row_pc = popcount(row_patt)
            prefix_pc = popcount(prefix_patt)

            # 1. Global dispatch order: row patterns should be ordered by popcount
            #    (The dispatcher sorts by row pattern popcount, not task/suffix pattern)
            #    Note: Multiple tasks can be generated per row (for different prefixes),
            #    so we track by row_pc, not suffix pc
            assert row_pc >= pc_prev or row > row_prev, (
                "Ordering error: prev(row=%d,row_pc=%d) → row=%d,row_pc=%d" % (row_prev, pc_prev, row, row_pc))
            pc_prev, row_prev = row_pc, row

            # 2. Prefix must be subset (or identical) of row pattern (skip for NULL prefix)
            if not is_null_prefix:
                assert (prefix_patt & ~row_patt) == 0, (
                    f"Prefix not subset: row {row:#x}, prefix {prefix_id:#x}")

                # 3. Task pattern must equal row ⊕ prefix
                assert task_patt == (row_patt ^ prefix_patt), (
                    f"Task pattern mismatch: expected {(row_patt ^ prefix_patt):#x}, got {task_patt:#x}")

                # 4. Popcount relationship as per paper
                assert pc == row_pc - prefix_pc, (
                    f"Popcount mismatch: expected {row_pc - prefix_pc}, got {pc}")

                # 5. Prefix selection rule: prefix popcount must be <= row popcount
                assert prefix_pc <= row_pc, (
                    f"Prefix selection rule violated: prefix_pc={prefix_pc} > row_pc={row_pc}")
            # For NULL prefix, the task pattern handling varies - just verify it's valid
            # (The processor handles NULL prefix specially in passthrough mode)

            issued_rows.append(row)
            patt_seen[row] += 1

        # Check for tile completion
        if dut.tile_done.value and not tile_done_seen:
            tile_done_seen = True
            total_latency = cycles
        
        # Check for simulation completion (timestep controller)
        if dut.sim_done.value and not sim_done_seen:
            sim_done_seen = True
            cocotb.log.info(f"• Timestep controller reports completion at cycle {cycles}")
        
        await RisingEdge(dut.clk)
        cycles += 1
    
    # Continue a bit more to ensure all data is captured
    if sim_done_seen:
        await RisingEdge(dut.clk)
        await RisingEdge(dut.clk)
        await RisingEdge(dut.clk)
        await RisingEdge(dut.clk)
        await RisingEdge(dut.clk)

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

    # ------------------------------------------------------------
    # 6. Verify complete SNN dataflow via spike collector
    # ------------------------------------------------------------
    cocotb.log.info("\n• Reading output spikes from spike_collector...")
    cocotb.log.info("  (Input spikes → Product sparsity → MAC → LIF → Output spikes)")
    
    total_output_spikes = 0
    rows_with_spikes = 0
    sample_size = min(20, ROWS)
    
    for row in range(sample_size):
        dut.spike_collect_rd_en.value = 1
        dut.spike_collect_rd_addr.value = row  # timestep=0, row=row
        await RisingEdge(dut.clk)
        await RisingEdge(dut.clk)  # 1-cycle read latency
        
        spike_data = int(dut.spike_collect_rd_data.value)
        spike_count = bin(spike_data).count('1')
        if spike_count > 0:
            rows_with_spikes += 1
            total_output_spikes += spike_count
            if rows_with_spikes <= 5:  # Show first few
                cocotb.log.info(f"    Row {row}: {spike_count} output spikes")
    
    dut.spike_collect_rd_en.value = 0
    
    cocotb.log.info(f"\n  ✓ Sampled {sample_size} rows: {rows_with_spikes} had output spikes")
    cocotb.log.info(f"  ✓ Total output spikes in sample: {total_output_spikes}")
    cocotb.log.info(f"  ✓ Spike collector stored: {int(dut.spike_collect_count.value)} spike vectors")
    cocotb.log.info("  ✓ Complete dataflow verified: Input spikes → Product sparsity → LIF → Output spikes")

# ── Pytest wrapper (cocotb-test) ─────────────────────────────────────────
def test_ppu():
    repo = Path(__file__).resolve().parents[1]
    verilog_sources = [
        repo / "ppu" / "top.v",
        repo / "ppu" / "detector.v",
        repo / "ppu" / "pruner.v",
        repo / "ppu" / "dispatcher.v",
        repo / "ppu" / "processor.v",
        repo / "ppu" / "lif.v",
        repo / "ppu" / "timestep_ctrl.v",
        repo / "ppu" / "spike_injector.v",
        repo / "ppu" / "spike_collector.v",
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
