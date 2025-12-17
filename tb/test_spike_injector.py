"""
test_spike_injector.py - Cocotb tests for spike injector
"""

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge
from cocotb_test.simulator import run
from pathlib import Path
import random

CLK_PERIOD = 10  # ns
ROWS = 256
SPIKES = 16
MAX_TIMESTEPS = 256


@cocotb.test()
async def test_single_timestep_inject(dut):
    """Test injecting spikes for a single timestep"""
    
    clock = Clock(dut.clk, CLK_PERIOD, units="ns")
    cocotb.start_soon(clock.start())
    
    # Reset
    dut.rst_n.value = 0
    dut.tile_start.value = 0
    dut.timestep_idx.value = 0
    dut.host_wr_en.value = 0
    dut.host_wr_addr.value = 0
    dut.host_wr_data.value = 0
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)
    
    dut._log.info("=== Testing Single Timestep Injection ===")
    
    # Load test patterns into buffer for timestep 0
    test_patterns = {}
    for row in range(min(10, ROWS)):  # Just test first 10 rows
        pattern = random.randint(0, (1 << SPIKES) - 1)
        test_patterns[row] = pattern
        
        # Write to buffer: address = timestep * ROWS + row
        addr = 0 * ROWS + row
        dut.host_wr_en.value = 1
        dut.host_wr_addr.value = addr
        dut.host_wr_data.value = pattern
        await RisingEdge(dut.clk)
    
    dut.host_wr_en.value = 0
    await RisingEdge(dut.clk)
    
    dut._log.info(f"Loaded {len(test_patterns)} patterns into buffer")
    
    # Trigger injection
    dut.tile_start.value = 1
    dut.timestep_idx.value = 0
    await RisingEdge(dut.clk)
    dut.tile_start.value = 0
    
    # Monitor TCAM writes
    tcam_writes = {}
    max_cycles = ROWS + 10
    cycles = 0
    
    while cycles < max_cycles and not dut.inject_done.value:
        if dut.tcam_set_en.value:
            addr = int(dut.tcam_set_addr.value)
            key = int(dut.tcam_set_key.value)
            tcam_writes[addr] = key
            dut._log.info(f"TCAM write: addr={addr}, key=0x{key:04x}")
        
        await RisingEdge(dut.clk)
        cycles += 1
    
    # Verify
    assert dut.inject_done.value, "Should signal inject_done"
    assert len(tcam_writes) == ROWS, f"Should write all {ROWS} rows, got {len(tcam_writes)}"
    
    # Check that loaded patterns match
    for row, expected in test_patterns.items():
        assert row in tcam_writes, f"Row {row} not written to TCAM"
        assert tcam_writes[row] == expected, \
            f"Row {row}: expected 0x{expected:04x}, got 0x{tcam_writes[row]:04x}"
    
    dut._log.info(f"✅ Single timestep injection PASSED ({cycles} cycles)")


@cocotb.test()
async def test_multiple_timesteps(dut):
    """Test injecting spikes for multiple timesteps"""
    
    clock = Clock(dut.clk, CLK_PERIOD, units="ns")
    cocotb.start_soon(clock.start())
    
    # Reset
    dut.rst_n.value = 0
    dut.tile_start.value = 0
    dut.timestep_idx.value = 0
    dut.host_wr_en.value = 0
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)
    
    dut._log.info("=== Testing Multiple Timesteps ===")
    
    num_timesteps = 3
    patterns_per_timestep = 5
    
    # Load patterns for multiple timesteps
    test_data = {}  # test_data[timestep][row] = pattern
    
    for t in range(num_timesteps):
        test_data[t] = {}
        for row in range(patterns_per_timestep):
            pattern = (t << 8) | row  # Unique pattern per timestep/row
            test_data[t][row] = pattern
            
            addr = t * ROWS + row
            dut.host_wr_en.value = 1
            dut.host_wr_addr.value = addr
            dut.host_wr_data.value = pattern
            await RisingEdge(dut.clk)
    
    dut.host_wr_en.value = 0
    await RisingEdge(dut.clk)
    
    dut._log.info(f"Loaded patterns for {num_timesteps} timesteps")
    
    # Inject each timestep
    for t in range(num_timesteps):
        dut._log.info(f"Injecting timestep {t}")
        
        # Trigger injection
        dut.tile_start.value = 1
        dut.timestep_idx.value = t
        await RisingEdge(dut.clk)
        dut.tile_start.value = 0
        
        # Wait for completion
        max_cycles = ROWS + 10
        cycles = 0
        tcam_writes = {}
        
        while cycles < max_cycles and not dut.inject_done.value:
            if dut.tcam_set_en.value:
                addr = int(dut.tcam_set_addr.value)
                key = int(dut.tcam_set_key.value)
                tcam_writes[addr] = key
            
            await RisingEdge(dut.clk)
            cycles += 1
        
        assert dut.inject_done.value, f"Timestep {t} should complete"
        
        # Verify loaded patterns
        for row, expected in test_data[t].items():
            assert tcam_writes[row] == expected, \
                f"Timestep {t}, Row {row}: expected 0x{expected:04x}, got 0x{tcam_writes[row]:04x}"
        
        # Wait before next timestep
        await RisingEdge(dut.clk)
        await RisingEdge(dut.clk)
    
    dut._log.info(f"✅ Multiple timesteps PASSED ({num_timesteps} timesteps)")


@cocotb.test()
async def test_realistic_sparse_workload(dut):
    """Test with realistic sparse spike patterns (1-3 spikes per row)"""
    
    clock = Clock(dut.clk, CLK_PERIOD, units="ns")
    cocotb.start_soon(clock.start())
    
    # Reset
    dut.rst_n.value = 0
    dut.tile_start.value = 0
    dut.timestep_idx.value = 0
    dut.host_wr_en.value = 0
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)
    
    dut._log.info("=== Testing Realistic Sparse Workload ===")
    
    # Generate sparse patterns (1-3 spikes per row, typical for SNNs)
    test_patterns = {}
    total_spikes = 0
    
    for row in range(ROWS):
        num_spikes = random.randint(1, 3)  # Realistic sparsity
        pattern = 0
        
        # Set random spike positions
        spike_positions = random.sample(range(SPIKES), num_spikes)
        for pos in spike_positions:
            pattern |= (1 << pos)
        
        test_patterns[row] = pattern
        total_spikes += num_spikes
        
        # Write to buffer
        addr = 0 * ROWS + row
        dut.host_wr_en.value = 1
        dut.host_wr_addr.value = addr
        dut.host_wr_data.value = pattern
        await RisingEdge(dut.clk)
    
    dut.host_wr_en.value = 0
    await RisingEdge(dut.clk)
    
    avg_spikes = total_spikes / ROWS
    dut._log.info(f"Generated sparse patterns: avg {avg_spikes:.2f} spikes/row")
    
    # Trigger injection
    dut.tile_start.value = 1
    dut.timestep_idx.value = 0
    await RisingEdge(dut.clk)
    dut.tile_start.value = 0
    
    # Monitor and verify
    tcam_writes = {}
    for _ in range(ROWS + 10):
        if dut.tcam_set_en.value:
            addr = int(dut.tcam_set_addr.value)
            key = int(dut.tcam_set_key.value)
            tcam_writes[addr] = key
        
        if dut.inject_done.value:
            break
        await RisingEdge(dut.clk)
    
    assert dut.inject_done.value, "Should complete injection"
    assert len(tcam_writes) == ROWS, f"Should write all rows"
    
    # Verify patterns
    mismatches = 0
    for row, expected in test_patterns.items():
        if tcam_writes[row] != expected:
            mismatches += 1
    
    assert mismatches == 0, f"Found {mismatches} pattern mismatches"
    dut._log.info(f"✅ Realistic sparse workload PASSED (avg {avg_spikes:.2f} spikes/row)")


@cocotb.test()
async def test_full_patterns(dut):
    """Test with all-ones patterns (0xFFFF - maximum density)"""
    
    clock = Clock(dut.clk, CLK_PERIOD, units="ns")
    cocotb.start_soon(clock.start())
    
    # Reset
    dut.rst_n.value = 0
    dut.tile_start.value = 0
    dut.timestep_idx.value = 0
    dut.host_wr_en.value = 0
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)
    
    dut._log.info("=== Testing Full Patterns (0xFFFF) ===")
    
    # Load all-ones patterns
    full_pattern = (1 << SPIKES) - 1  # 0xFFFF for SPIKES=16
    
    for row in range(ROWS):
        addr = 0 * ROWS + row
        dut.host_wr_en.value = 1
        dut.host_wr_addr.value = addr
        dut.host_wr_data.value = full_pattern
        await RisingEdge(dut.clk)
    
    dut.host_wr_en.value = 0
    await RisingEdge(dut.clk)
    
    dut._log.info(f"Loaded full patterns (0x{full_pattern:04x}) for all rows")
    
    # Trigger injection
    dut.tile_start.value = 1
    dut.timestep_idx.value = 0
    await RisingEdge(dut.clk)
    dut.tile_start.value = 0
    
    # Verify all patterns are 0xFFFF
    tcam_writes = {}
    for _ in range(ROWS + 10):
        if dut.tcam_set_en.value:
            addr = int(dut.tcam_set_addr.value)
            key = int(dut.tcam_set_key.value)
            tcam_writes[addr] = key
            assert key == full_pattern, f"Row {addr}: expected 0x{full_pattern:04x}, got 0x{key:04x}"
        
        if dut.inject_done.value:
            break
        await RisingEdge(dut.clk)
    
    assert dut.inject_done.value, "Should complete injection"
    assert len(tcam_writes) == ROWS, "Should write all rows"
    dut._log.info(f"✅ Full patterns test PASSED (all {SPIKES} spikes active)")


@cocotb.test()
async def test_dense_workload(dut):
    """Test with dense spike patterns (8-12 spikes per row)"""
    
    clock = Clock(dut.clk, CLK_PERIOD, units="ns")
    cocotb.start_soon(clock.start())
    
    # Reset
    dut.rst_n.value = 0
    dut.tile_start.value = 0
    dut.timestep_idx.value = 0
    dut.host_wr_en.value = 0
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)
    
    dut._log.info("=== Testing Dense Workload ===")
    
    # Generate dense patterns (8-12 spikes per row - stress test)
    test_patterns = {}
    total_spikes = 0
    
    for row in range(ROWS):
        num_spikes = random.randint(8, 12)  # Dense activity
        pattern = 0
        
        # Set random spike positions
        spike_positions = random.sample(range(SPIKES), num_spikes)
        for pos in spike_positions:
            pattern |= (1 << pos)
        
        test_patterns[row] = pattern
        total_spikes += num_spikes
        
        # Write to buffer
        addr = 0 * ROWS + row
        dut.host_wr_en.value = 1
        dut.host_wr_addr.value = addr
        dut.host_wr_data.value = pattern
        await RisingEdge(dut.clk)
    
    dut.host_wr_en.value = 0
    await RisingEdge(dut.clk)
    
    avg_spikes = total_spikes / ROWS
    dut._log.info(f"Generated dense patterns: avg {avg_spikes:.2f} spikes/row")
    
    # Trigger injection
    dut.tile_start.value = 1
    dut.timestep_idx.value = 0
    await RisingEdge(dut.clk)
    dut.tile_start.value = 0
    
    # Monitor and verify
    tcam_writes = {}
    for _ in range(ROWS + 10):
        if dut.tcam_set_en.value:
            addr = int(dut.tcam_set_addr.value)
            key = int(dut.tcam_set_key.value)
            tcam_writes[addr] = key
        
        if dut.inject_done.value:
            break
        await RisingEdge(dut.clk)
    
    assert dut.inject_done.value, "Should complete injection"
    assert len(tcam_writes) == ROWS, f"Should write all rows"
    
    # Verify patterns
    mismatches = 0
    for row, expected in test_patterns.items():
        if tcam_writes[row] != expected:
            mismatches += 1
    
    assert mismatches == 0, f"Found {mismatches} pattern mismatches"
    dut._log.info(f"✅ Dense workload test PASSED (avg {avg_spikes:.2f} spikes/row)")


# ── Pytest wrapper ─────────────────────────────────────────────────────────
def test_spike_injector():
    repo = Path(__file__).resolve().parents[1]
    verilog_sources = [
        repo / "ppu" / "spike_injector.v",
    ]

    run(
        verilog_sources=[str(v) for v in verilog_sources],
        toplevel="spike_injector",
        module="test_spike_injector",
        parameters={
            "ROWS": str(ROWS),
            "SPIKES": str(SPIKES),
            "TIMESTEP_WIDTH": "16",
            "MAX_TIMESTEPS": str(MAX_TIMESTEPS),
        },
        sim_build="sim_build",
        timescale="1ns/1ps",
    )


if __name__ == "__main__":
    test_spike_injector()
