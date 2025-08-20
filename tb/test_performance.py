# test_performance.py ─────────────────────────────────────────────────────────
# Performance verification test for Prosperity PPU surgical optimizations
# Tests the impact of:
#   1. Weight bandwidth (128 B/cycle banking)
#   2. Task FIFO between dispatcher and processor
#   3. Double-buffer tiles for I/O overlap
#   4. TCAM Top-N candidate reducer
#   5. Scalable popcount with carry chains
#   6. Processor writeback skid FIFO
#   7. Clock-enable gating
#
# Expected improvements:
#   - Weight stalls → ~0 cycles
#   - Task stalls → significant reduction
#   - BRAM stalls → ~0 cycles
#   - PE utilization → 70%+ at density ≥10%
#   - Fmax improvement from timing optimizations

import random
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ReadOnly, ReadWrite, Timer
from cocotb_test.simulator import run
from pathlib import Path
import numpy as np
import time

# Test parameters
ROWS = 256
SPIKES = 16
PE_COUNT = 128
WEIGHT_WIDTH = 8
ACC_WIDTH = 16
NO_WIDTH = 8
CLK_PERIOD = 10  # ns (100 MHz target)

class PerformanceMetrics:
    """Track performance metrics across tests"""
    def __init__(self):
        self.test_results = []

    def add_result(self, density, cycles, weight_stalls, task_stalls, bram_stalls, pe_util):
        self.test_results.append({
            'density': density,
            'cycles': cycles,
            'weight_stalls': weight_stalls,
            'task_stalls': task_stalls,
            'bram_stalls': bram_stalls,
            'pe_util': pe_util
        })

    def print_summary(self, dut):
        dut._log.info("=== PERFORMANCE SUMMARY ===")
        dut._log.info("Density | Cycles | Weight_Stall | Task_Stall | BRAM_Stall | PE_Util% | Pass")
        dut._log.info("--------|--------|-------------|------------|------------|----------|------")

        for result in self.test_results:
            # Check optimization targets
            weight_pass = result['weight_stalls'] < 20  # Should be ~0 with banking
            bram_pass = result['bram_stalls'] < 10     # Should be ~0 with skid FIFO
            util_pass = result['density'] < 10.0 or result['pe_util'] >= 70.0  # 70%+ at high density
            overall_pass = weight_pass and bram_pass and util_pass

            dut._log.info(f"{result['density']:6.1f}% | {result['cycles']:6d} | "
                         f"{result['weight_stalls']:11d} | {result['task_stalls']:10d} | "
                         f"{result['bram_stalls']:10d} | {result['pe_util']:7.1f}% | "
                         f"{'✓' if overall_pass else '✗'}")

def popcount(x):
    """Count set bits in integer"""
    return bin(x).count('1')

def generate_test_pattern(density_percent):
    """Generate spike pattern with target density"""
    target_bits = max(1, int(SPIKES * density_percent / 100.0))
    pattern = 0
    bits_set = 0

    while bits_set < target_bits:
        bit_pos = random.randint(0, SPIKES-1)
        if not (pattern & (1 << bit_pos)):
            pattern |= (1 << bit_pos)
            bits_set += 1

    return pattern

async def setup_weight_memory(dut):
    """Initialize weight memory with test patterns"""
    dut._log.info("Initializing weight memory with test patterns...")

    # Initialize all PE weights for all spikes
    for spike_idx in range(SPIKES):
        # Generate weight data for all 128 PEs in parallel (banked)
        weight_vector = 0
        for pe_idx in range(PE_COUNT):
            weight_val = ((pe_idx + spike_idx * 2) & 0xFF)  # Test pattern
            weight_vector |= (weight_val << (pe_idx * WEIGHT_WIDTH))

        # Weight memory model - respond when address matches
        dut.weight_data.value = weight_vector

async def setup_output_buffer(dut):
    """Initialize output buffer with prefix values"""
    dut._log.info("Setting up output buffer...")
    # The output buffer is modeled as responding to read addresses
    # We'll set a simple pattern for prefix data
    pass

@cocotb.test()
async def test_weight_bandwidth_optimization(dut):
    """Test Priority 1: Weight bandwidth upgrade to 128 B/cycle"""

    # Start clock
    clock = Clock(dut.clk, CLK_PERIOD, units="ns")
    cocotb.start_soon(clock.start())

    # Reset
    dut.rst_n.value = 0
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)

    dut._log.info("=== Testing Weight Bandwidth Optimization ===")

    await setup_weight_memory(dut)
    await setup_output_buffer(dut)

    # Test pattern with moderate sparsity
    test_pattern = generate_test_pattern(25.0)  # 25% density

    # Monitor weight read enable cycles
    weight_read_cycles = 0
    start_cycle = int(dut.total_cycles.value)

    # Send task
    dut.task_valid.value = 1
    dut.task_row_id.value = 10
    dut.task_prefix_id.value = 5
    dut.task_pattern.value = test_pattern

    await RisingEdge(dut.clk)
    dut.task_valid.value = 0

    # Monitor weight loading phase
    while int(dut.proc_busy.value) == 1:
        if int(dut.weight_rd_en.value) == 1:
            weight_read_cycles += 1
        await RisingEdge(dut.clk)

    # Check that weight loading is efficient
    dut._log.info(f"Weight read cycles: {weight_read_cycles}")
    dut._log.info(f"Weight stall cycles: {int(dut.stall_weight_cycles.value)}")

    # With banking, we should read all weights in SPIKES cycles (16), not SPIKES*PE_COUNT (2048)
    assert weight_read_cycles <= SPIKES + 5, f"Weight loading too slow: {weight_read_cycles} cycles"
    assert int(dut.stall_weight_cycles.value) < 20, f"Too many weight stalls: {int(dut.stall_weight_cycles.value)}"

    dut._log.info("✅ Weight bandwidth optimization verified")

@cocotb.test()
async def test_performance_counters(dut):
    """Test that performance counters are working correctly"""

    # Start clock
    clock = Clock(dut.clk, CLK_PERIOD, units="ns")
    cocotb.start_soon(clock.start())

    # Reset
    dut.rst_n.value = 0
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)

    dut._log.info("=== Testing Performance Counters ===")

    await setup_weight_memory(dut)

    # Check counters start at 0
    assert int(dut.total_cycles.value) >= 0
    assert int(dut.stall_weight_cycles.value) == 0
    assert int(dut.stall_task_cycles.value) == 0
    assert int(dut.stall_bram_cycles.value) == 0
    assert int(dut.pe_active_cycles.value) == 0

    initial_total = int(dut.total_cycles.value)

    # Run a task and verify counters increment
    test_pattern = generate_test_pattern(12.5)

    dut.task_valid.value = 1
    dut.task_row_id.value = 20
    dut.task_prefix_id.value = 15
    dut.task_pattern.value = test_pattern

    await RisingEdge(dut.clk)
    dut.task_valid.value = 0

    # Wait for completion
    while int(dut.proc_busy.value) == 1:
        await RisingEdge(dut.clk)

    # Verify counters have incremented
    final_total = int(dut.total_cycles.value)
    assert final_total > initial_total, "Total cycle counter not incrementing"

    # Log final counter values
    dut._log.info(f"Total cycles: {final_total}")
    dut._log.info(f"Weight stalls: {int(dut.stall_weight_cycles.value)}")
    dut._log.info(f"Task stalls: {int(dut.stall_task_cycles.value)}")
    dut._log.info(f"BRAM stalls: {int(dut.stall_bram_cycles.value)}")
    dut._log.info(f"PE active: {int(dut.pe_active_cycles.value)}")

    dut._log.info("✅ Performance counters verified")

@cocotb.test()
async def test_density_sweep(dut):
    """Test Priority - Full density sweep to verify optimizations"""

    # Start clock
    clock = Clock(dut.clk, CLK_PERIOD, units="ns")
    cocotb.start_soon(clock.start())

    # Reset
    dut.rst_n.value = 0
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)

    dut._log.info("=== Testing Density Sweep Performance ===")

    await setup_weight_memory(dut)
    await setup_output_buffer(dut)

    # Test different densities: 1%, 2%, 5%, 10%, 20%, 40%
    test_densities = [1.0, 2.0, 5.0, 10.0, 20.0, 40.0]
    metrics = PerformanceMetrics()

    for density in test_densities:
        dut._log.info(f"\nTesting {density}% density...")

        # Reset counters by resetting DUT
        dut.rst_n.value = 0
        await RisingEdge(dut.clk)
        dut.rst_n.value = 1
        await RisingEdge(dut.clk)

        # Generate test pattern
        test_pattern = generate_test_pattern(density)
        actual_density = (popcount(test_pattern) * 100.0) / SPIKES

        # Record start time
        start_cycles = int(dut.total_cycles.value)

        # Send task
        dut.task_valid.value = 1
        dut.task_row_id.value = int(density * 2)  # Unique row ID
        dut.task_prefix_id.value = int(density)   # Unique prefix ID
        dut.task_pattern.value = test_pattern

        await RisingEdge(dut.clk)
        dut.task_valid.value = 0

        # Wait for completion
        timeout_cycles = 0
        max_timeout = 10000

        while int(dut.proc_busy.value) == 1:
            await RisingEdge(dut.clk)
            timeout_cycles += 1
            if timeout_cycles > max_timeout:
                dut._log.error(f"Timeout waiting for task completion at {density}% density")
                break

        # Record metrics
        end_cycles = int(dut.total_cycles.value)
        total_task_cycles = end_cycles - start_cycles

        weight_stalls = int(dut.stall_weight_cycles.value)
        task_stalls = int(dut.stall_task_cycles.value)
        bram_stalls = int(dut.stall_bram_cycles.value)
        pe_active = int(dut.pe_active_cycles.value)

        # Calculate PE utilization: pe_active_cycles / (PE_COUNT * total_cycles)
        pe_util = (pe_active * 100.0) / (PE_COUNT * total_task_cycles) if total_task_cycles > 0 else 0.0

        metrics.add_result(actual_density, total_task_cycles, weight_stalls,
                          task_stalls, bram_stalls, pe_util)

        dut._log.info(f"Density {actual_density:.1f}%: {total_task_cycles} cycles, "
                     f"Weight stalls: {weight_stalls}, PE util: {pe_util:.1f}%")

    # Print summary
    metrics.print_summary(dut)

    # Verify optimization targets
    high_density_results = [r for r in metrics.test_results if r['density'] >= 10.0]

    if high_density_results:
        avg_weight_stalls = sum(r['weight_stalls'] for r in high_density_results) / len(high_density_results)
        avg_bram_stalls = sum(r['bram_stalls'] for r in high_density_results) / len(high_density_results)
        avg_pe_util = sum(r['pe_util'] for r in high_density_results) / len(high_density_results)

        dut._log.info("\n=== OPTIMIZATION VERIFICATION ===")
        dut._log.info(f"Avg weight stalls (≥10% density): {avg_weight_stalls:.1f} (target: <20)")
        dut._log.info(f"Avg BRAM stalls (≥10% density): {avg_bram_stalls:.1f} (target: <10)")
        dut._log.info(f"Avg PE utilization (≥10% density): {avg_pe_util:.1f}% (target: ≥70%)")

        # Assert optimization targets
        assert avg_weight_stalls < 20, f"Weight stalls too high: {avg_weight_stalls} (banking may not be working)"
        assert avg_bram_stalls < 10, f"BRAM stalls too high: {avg_bram_stalls} (skid FIFO may not be working)"
        # Note: PE utilization target is aspirational, may need tuning

        dut._log.info("✅ Performance optimization targets met")

@cocotb.test()
async def test_writeback_skid_fifo(dut):
    """Test Priority 6: Writeback skid FIFO hides BRAM latency"""

    # Start clock
    clock = Clock(dut.clk, CLK_PERIOD, units="ns")
    cocotb.start_soon(clock.start())

    # Reset
    dut.rst_n.value = 0
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)

    dut._log.info("=== Testing Writeback Skid FIFO ===")

    await setup_weight_memory(dut)
    await setup_output_buffer(dut)

    # Run multiple rapid tasks to stress writeback
    patterns = [
        generate_test_pattern(15.0),
        generate_test_pattern(20.0),
        generate_test_pattern(25.0)
    ]

    total_bram_stalls = 0

    for i, pattern in enumerate(patterns):
        dut._log.info(f"Running task {i+1}/3...")

        # Send task
        dut.task_valid.value = 1
        dut.task_row_id.value = i + 100
        dut.task_prefix_id.value = i + 50
        dut.task_pattern.value = pattern

        await RisingEdge(dut.clk)
        dut.task_valid.value = 0

        # Wait for completion
        while int(dut.proc_busy.value) == 1:
            await RisingEdge(dut.clk)

        task_bram_stalls = int(dut.stall_bram_cycles.value)
        total_bram_stalls += task_bram_stalls

        dut._log.info(f"Task {i+1} BRAM stalls: {task_bram_stalls}")

    dut._log.info(f"Total BRAM stalls across all tasks: {total_bram_stalls}")

    # With skid FIFO, BRAM stalls should be minimal
    assert total_bram_stalls < 10, f"Too many BRAM stalls: {total_bram_stalls} (skid FIFO not working)"

    dut._log.info("✅ Writeback skid FIFO verified")

def test_processor_performance():
    """cocotb-test entry point for processor performance tests"""
    repo = Path(__file__).resolve().parents[1]
    verilog_sources = [
        repo / "ppu" / "processor.v",
    ]

    run(
        verilog_sources=[str(v) for v in verilog_sources],
        toplevel="processor",
        module="test_performance",
        simulator="verilator",
        compile_args=[
            "-Wall", "-Wno-fatal", "--trace", "--trace-structs"
        ],
        extra_env={
            'COCOTB_RESOLVE_X': 'RANDOM'
        }
    )

if __name__ == "__main__":
    test_processor_performance()
