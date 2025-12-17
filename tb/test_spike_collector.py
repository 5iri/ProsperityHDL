"""
test_spike_collector.py - Cocotb tests for spike collector
"""

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge
from cocotb_test.simulator import run
from pathlib import Path
import random

CLK_PERIOD = 10  # ns
ROWS = 256
PE_COUNT = 128
MAX_TIMESTEPS = 256


@cocotb.test()
async def test_basic_collection(dut):
    """Test basic spike collection"""
    
    clock = Clock(dut.clk, CLK_PERIOD, units="ns")
    cocotb.start_soon(clock.start())
    
    # Reset
    dut.rst_n.value = 0
    dut.spike_in.value = 0
    dut.spike_valid.value = 0
    dut.spike_row_id.value = 0
    dut.timestep_idx.value = 0
    dut.collect_enable.value = 0
    dut.clear_buffer.value = 0
    dut.host_rd_en.value = 0
    dut.host_rd_addr.value = 0
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)
    
    dut._log.info("=== Testing Basic Spike Collection ===")
    
    # Enable collection
    dut.collect_enable.value = 1
    dut.timestep_idx.value = 0
    
    # Inject test spikes
    test_spikes = {
        0: 0b1010,  # Row 0: PE 1, 3
        1: 0b0101,  # Row 1: PE 0, 2
        5: 0b1111,  # Row 5: PE 0,1,2,3
    }
    
    for row, spike_pattern in test_spikes.items():
        dut.spike_row_id.value = row
        dut.spike_in.value = spike_pattern
        dut.spike_valid.value = 1
        await RisingEdge(dut.clk)
        dut.spike_valid.value = 0
        await RisingEdge(dut.clk)
    
    dut._log.info(f"Collected {len(test_spikes)} spike vectors")
    
    # Read back and verify (need extra cycle for registered read)
    for row, expected in test_spikes.items():
        addr = 0 * ROWS + row  # timestep 0
        dut.host_rd_en.value = 1
        dut.host_rd_addr.value = addr
        await RisingEdge(dut.clk)
        await RisingEdge(dut.clk)  # Extra cycle for registered output
        
        result = int(dut.host_rd_data.value)
        dut._log.info(f"Row {row}: expected=0x{expected:032x}, got=0x{result:032x}")
        assert result == expected, f"Row {row} mismatch"
    
    dut.host_rd_en.value = 0
    
    spike_count = int(dut.spike_count.value)
    assert spike_count == len(test_spikes), f"Expected {len(test_spikes)} spikes, got {spike_count}"
    
    dut._log.info(f"✅ Basic collection PASSED ({spike_count} spikes)")


@cocotb.test()
async def test_multiple_timesteps(dut):
    """Test collecting spikes across multiple timesteps"""
    
    clock = Clock(dut.clk, CLK_PERIOD, units="ns")
    cocotb.start_soon(clock.start())
    
    # Reset
    dut.rst_n.value = 0
    dut.spike_in.value = 0
    dut.spike_valid.value = 0
    dut.collect_enable.value = 0
    dut.clear_buffer.value = 0
    dut.host_rd_en.value = 0
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)
    
    dut._log.info("=== Testing Multiple Timesteps ===")
    
    dut.collect_enable.value = 1
    
    # Generate test data: test_data[timestep][row] = spike_pattern
    num_timesteps = 3
    spikes_per_timestep = 5
    test_data = {}
    
    for t in range(num_timesteps):
        test_data[t] = {}
        dut.timestep_idx.value = t
        
        for row in range(spikes_per_timestep):
            # Create unique pattern per timestep/row
            pattern = (1 << (t * 4)) | (1 << row)  # Unique bits
            test_data[t][row] = pattern
            
            # Inject spike
            dut.spike_row_id.value = row
            dut.spike_in.value = pattern
            dut.spike_valid.value = 1
            await RisingEdge(dut.clk)
            dut.spike_valid.value = 0
            await RisingEdge(dut.clk)
        
        dut._log.info(f"Timestep {t}: collected {spikes_per_timestep} spikes")
    
    # Verify all timesteps
    total_verified = 0
    for t in range(num_timesteps):
        for row, expected in test_data[t].items():
            addr = t * ROWS + row
            dut.host_rd_en.value = 1
            dut.host_rd_addr.value = addr
            await RisingEdge(dut.clk)
            await RisingEdge(dut.clk)  # Extra cycle for registered read
            
            result = int(dut.host_rd_data.value)
            assert result == expected, \
                f"t={t}, row={row}: expected 0x{expected:x}, got 0x{result:x}"
            total_verified += 1
    
    dut.host_rd_en.value = 0
    
    dut._log.info(f"✅ Multiple timesteps PASSED ({total_verified} spikes verified)")


@cocotb.test()
async def test_sparse_spikes(dut):
    """Test with realistic sparse spike patterns"""
    
    clock = Clock(dut.clk, CLK_PERIOD, units="ns")
    cocotb.start_soon(clock.start())
    
    # Reset
    dut.rst_n.value = 0
    dut.collect_enable.value = 0
    dut.clear_buffer.value = 0
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)
    
    dut._log.info("=== Testing Sparse Spikes ===")
    
    dut.collect_enable.value = 1
    dut.timestep_idx.value = 0
    
    # Generate sparse spike patterns (1-3 active PEs per row)
    test_spikes = {}
    total_active_pes = 0
    
    for row in range(20):  # Test subset of rows
        num_spikes = random.randint(1, 3)
        pattern = 0
        
        # Set random PE positions
        for _ in range(num_spikes):
            pe = random.randint(0, PE_COUNT - 1)
            pattern |= (1 << pe)
        
        test_spikes[row] = pattern
        total_active_pes += bin(pattern).count('1')
        
        # Inject
        dut.spike_row_id.value = row
        dut.spike_in.value = pattern
        dut.spike_valid.value = 1
        await RisingEdge(dut.clk)
        dut.spike_valid.value = 0
        await RisingEdge(dut.clk)
    
    avg_spikes = total_active_pes / len(test_spikes)
    dut._log.info(f"Generated {len(test_spikes)} sparse patterns (avg {avg_spikes:.2f} active PEs/row)")
    
    # Verify
    mismatches = 0
    for row, expected in test_spikes.items():
        addr = 0 * ROWS + row
        dut.host_rd_en.value = 1
        dut.host_rd_addr.value = addr
        await RisingEdge(dut.clk)
        await RisingEdge(dut.clk)  # Extra cycle for registered read
        
        result = int(dut.host_rd_data.value)
        if result != expected:
            mismatches += 1
            dut._log.error(f"Row {row}: expected 0x{expected:032x}, got 0x{result:032x}")
    
    dut.host_rd_en.value = 0
    
    assert mismatches == 0, f"Found {mismatches} mismatches"
    dut._log.info(f"✅ Sparse spikes PASSED")


@cocotb.test()
async def test_clear_buffer(dut):
    """Test buffer clearing functionality"""
    
    clock = Clock(dut.clk, CLK_PERIOD, units="ns")
    cocotb.start_soon(clock.start())
    
    # Reset
    dut.rst_n.value = 0
    dut.collect_enable.value = 0
    dut.clear_buffer.value = 0
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)
    
    dut._log.info("=== Testing Buffer Clear ===")
    
    # Collect some spikes
    dut.collect_enable.value = 1
    dut.timestep_idx.value = 0
    
    for row in range(5):
        dut.spike_row_id.value = row
        dut.spike_in.value = 0xAAAA  # Pattern
        dut.spike_valid.value = 1
        await RisingEdge(dut.clk)
        dut.spike_valid.value = 0
        await RisingEdge(dut.clk)
    
    dut._log.info("Collected 5 spike vectors")
    
    # Clear buffer
    dut.clear_buffer.value = 1
    await RisingEdge(dut.clk)
    dut.clear_buffer.value = 0
    await RisingEdge(dut.clk)
    
    # Verify all cleared
    for row in range(5):
        addr = 0 * ROWS + row
        dut.host_rd_en.value = 1
        dut.host_rd_addr.value = addr
        await RisingEdge(dut.clk)
        
        result = int(dut.host_rd_data.value)
        assert result == 0, f"Row {row} should be cleared, got 0x{result:x}"
    
    dut.host_rd_en.value = 0
    
    # Check spike count reset
    spike_count = int(dut.spike_count.value)
    assert spike_count == 0, f"Spike count should be 0, got {spike_count}"
    
    dut._log.info("✅ Buffer clear PASSED")


# ── Pytest wrapper ─────────────────────────────────────────────────────────
def test_spike_collector():
    repo = Path(__file__).resolve().parents[1]
    verilog_sources = [
        repo / "ppu" / "spike_collector.v",
    ]

    run(
        verilog_sources=[str(v) for v in verilog_sources],
        toplevel="spike_collector",
        module="test_spike_collector",
        parameters={
            "ROWS": str(ROWS),
            "PE_COUNT": str(PE_COUNT),
            "TIMESTEP_WIDTH": "16",
            "MAX_TIMESTEPS": str(MAX_TIMESTEPS),
        },
        sim_build="sim_build",
        timescale="1ns/1ps",
    )


if __name__ == "__main__":
    test_spike_collector()
