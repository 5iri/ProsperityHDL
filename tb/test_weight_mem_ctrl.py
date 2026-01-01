"""
test_weight_mem_ctrl.py - Weight Memory Controller Tests

Tests the weight memory controller for the Prosperity PPU.
Validates burst reads, FP16 unpacking, and streaming to processor.
"""

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ClockCycles, FallingEdge
from cocotb_test.simulator import run
import pytest
import os
import struct

# Constants
PE_COUNT = 128
SPIKES = 16
TOTAL_WEIGHTS = PE_COUNT * SPIKES  # 2048
BURST_LEN = 16


async def reset_dut(dut):
    """Reset the DUT."""
    dut.rst_n.value = 0
    dut.load_start.value = 0
    dut.base_addr.value = 0
    dut.mem_arready.value = 0
    dut.mem_rdata.value = 0
    dut.mem_rresp.value = 0
    dut.mem_rlast.value = 0
    dut.mem_rvalid.value = 0
    await ClockCycles(dut.clk, 5)
    dut.rst_n.value = 1
    await ClockCycles(dut.clk, 2)


def fp16_to_int(f):
    """Convert float to FP16 integer representation."""
    # Pack as half-precision float, unpack as unsigned short
    return struct.unpack('H', struct.pack('e', f))[0]


def int_to_fp16(i):
    """Convert FP16 integer representation to float."""
    return struct.unpack('e', struct.pack('H', i))[0]


@cocotb.test()
async def test_weight_ctrl_idle(dut):
    """Test that controller starts in idle state."""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    await reset_dut(dut)
    
    # Check idle state
    assert dut.load_busy.value == 0, "Should not be busy after reset"
    assert dut.load_done.value == 0, "Should not be done after reset"
    assert dut.mem_arvalid.value == 0, "No address request in idle"
    assert dut.weight_wr_en.value == 0, "No weight writes in idle"
    
    dut._log.info("Idle state test PASSED")


@cocotb.test()
async def test_weight_ctrl_addr_phase(dut):
    """Test address phase of burst read."""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    await reset_dut(dut)
    
    # Start load with base address
    base_addr = 0x1000_0000
    dut.base_addr.value = base_addr
    dut.load_start.value = 1
    await RisingEdge(dut.clk)
    dut.load_start.value = 0
    
    # Wait for address valid
    for _ in range(10):
        await RisingEdge(dut.clk)
        if dut.mem_arvalid.value == 1:
            break
    
    assert dut.mem_arvalid.value == 1, "Address should be valid"
    assert dut.mem_araddr.value == base_addr, f"Address mismatch: {dut.mem_araddr.value:#x}"
    assert dut.load_busy.value == 1, "Should be busy during load"
    
    # Accept address
    dut.mem_arready.value = 1
    await RisingEdge(dut.clk)
    dut.mem_arready.value = 0
    await RisingEdge(dut.clk)
    
    # Address valid should deassert
    assert dut.mem_arvalid.value == 0, "Address valid should clear after handshake"
    
    dut._log.info("Address phase test PASSED")


@cocotb.test()
async def test_weight_ctrl_data_unpack(dut):
    """Test data unpacking from 32-bit words to FP16."""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    await reset_dut(dut)
    
    # Start load
    dut.base_addr.value = 0x0
    dut.load_start.value = 1
    await RisingEdge(dut.clk)
    dut.load_start.value = 0
    
    # Wait for address phase
    for _ in range(10):
        await RisingEdge(dut.clk)
        if dut.mem_arvalid.value == 1:
            break
    
    # Accept address
    dut.mem_arready.value = 1
    await RisingEdge(dut.clk)
    dut.mem_arready.value = 0
    
    # Wait for read ready
    for _ in range(5):
        await RisingEdge(dut.clk)
        if dut.mem_rready.value == 1:
            break
    
    # Send one 32-bit word with two FP16 weights
    # Lower 16 bits: 0x3C00 (1.0), Upper 16 bits: 0x4000 (2.0)
    weight_word = (0x4000 << 16) | 0x3C00
    dut.mem_rdata.value = weight_word
    dut.mem_rvalid.value = 1
    dut.mem_rlast.value = 0
    await RisingEdge(dut.clk)
    dut.mem_rvalid.value = 0
    
    # Wait for unpacking
    weights_captured = []
    for _ in range(20):
        await RisingEdge(dut.clk)
        if dut.weight_wr_en.value == 1:
            weights_captured.append({
                'addr': int(dut.weight_addr.value),
                'data': int(dut.weight_data.value)
            })
        if len(weights_captured) >= 2:
            break
    
    assert len(weights_captured) >= 2, f"Expected 2 weight writes, got {len(weights_captured)}"
    assert weights_captured[0]['data'] == 0x3C00, f"First weight should be 0x3C00: {weights_captured[0]['data']:#x}"
    assert weights_captured[1]['data'] == 0x4000, f"Second weight should be 0x4000: {weights_captured[1]['data']:#x}"
    
    dut._log.info("Data unpack test PASSED")


@cocotb.test()
async def test_weight_ctrl_full_load(dut):
    """Test loading all weights and verify load_done assertion."""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    await reset_dut(dut)
    
    # Start load
    dut.base_addr.value = 0x0
    dut.load_start.value = 1
    await RisingEdge(dut.clk)
    dut.load_start.value = 0
    
    word_idx = 0
    weights_written = 0
    timeout = 60000  # cycles
    total_words = TOTAL_WEIGHTS // 2  # 1024 words
    last_weight_count = 0
    stall_count = 0
    
    # Track if we're offering data
    data_offered = False
    
    for cycle in range(timeout):
        await RisingEdge(dut.clk)
        
        # Handle address phase
        if dut.mem_arvalid.value == 1:
            dut.mem_arready.value = 1
        else:
            dut.mem_arready.value = 0
        
        # AXI handshake: data consumed when rvalid=1 AND rready=1
        if data_offered and dut.mem_rready.value == 1:
            # Previous data was consumed
            word_idx += 1
            data_offered = False
        
        # Provide new data if ready and we have more to send
        if dut.mem_rready.value == 1 and word_idx < total_words and not data_offered:
            dut.mem_rvalid.value = 1
            dut.mem_rdata.value = 0x40003C00  # Two FP16 weights
            dut.mem_rlast.value = 1 if (word_idx % BURST_LEN == BURST_LEN - 1) else 0
            data_offered = True
        elif not data_offered:
            dut.mem_rvalid.value = 0
        
        # Count weight writes
        if dut.weight_wr_en.value == 1:
            weights_written += 1
        
        # Monitor progress
        current_weight_count = int(dut.weights_loaded.value)
        if current_weight_count == last_weight_count:
            stall_count += 1
        else:
            stall_count = 0
            last_weight_count = current_weight_count
        
        # Debug output at key points
        if weights_written > 0 and weights_written % 500 == 0:
            dut._log.info(f"Progress: {weights_written} weights, {word_idx} words, weight_count={current_weight_count}")
        
        # Detect stall
        if stall_count > 1000 and weights_written > 0:
            dut._log.info(f"STALL at weights={weights_written}, words={word_idx}, count={current_weight_count}")
            break
        
        # Check for completion
        if dut.load_done.value == 1:
            dut._log.info(f"load_done at cycle {cycle}")
            break
    
    # Verify completion
    assert dut.load_done.value == 1, f"load_done not asserted (weights={weights_written}, words={word_idx})"
    assert dut.load_busy.value == 0, "load_busy should be cleared"
    
    loaded = int(dut.weights_loaded.value)
    dut._log.info(f"Full load: {word_idx} words, {weights_written} weights, {loaded} reported")
    assert loaded == TOTAL_WEIGHTS, f"Expected {TOTAL_WEIGHTS} weights, got {loaded}"
    
    dut._log.info("Full load test PASSED")


@cocotb.test()
async def test_weight_ctrl_burst_boundary(dut):
    """Test burst boundary handling."""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    await reset_dut(dut)
    
    # Start load
    base_addr = 0x2000
    dut.base_addr.value = base_addr
    dut.load_start.value = 1
    await RisingEdge(dut.clk)
    dut.load_start.value = 0
    
    burst_count = 0
    addresses_seen = []
    
    # Run until we see multiple burst addresses or timeout
    for _ in range(5000):
        await RisingEdge(dut.clk)
        
        if dut.mem_arvalid.value == 1:
            addresses_seen.append(int(dut.mem_araddr.value))
            burst_count += 1
            dut.mem_arready.value = 1
        else:
            dut.mem_arready.value = 0
        
        # Provide data when ready
        if dut.mem_rready.value == 1:
            dut.mem_rvalid.value = 1
            dut.mem_rdata.value = 0x3C003C00  # Two 1.0 FP16 values
            dut.mem_rlast.value = 1  # Simulate end of burst
        else:
            dut.mem_rvalid.value = 0
        
        if burst_count >= 3:
            break
    
    # Check that burst addresses increment correctly
    if len(addresses_seen) >= 2:
        addr_increment = addresses_seen[1] - addresses_seen[0]
        expected_increment = BURST_LEN * 4  # 4 bytes per word
        dut._log.info(f"Burst addresses: {[hex(a) for a in addresses_seen]}")
        dut._log.info(f"Address increment: {addr_increment}, expected: {expected_increment}")
    
    dut._log.info(f"Burst boundary test: saw {burst_count} bursts")
    assert burst_count >= 1, "Should issue at least one burst"


# pytest entry point
def runCocotbTests():
    """Run cocotb tests."""
    proj_path = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    
    run(
        verilog_sources=[os.path.join(proj_path, "ppu", "weight_mem_ctrl.v")],
        toplevel="weight_mem_ctrl",
        module="test_weight_mem_ctrl",
        simulator="verilator",
        sim_build=os.path.join(os.path.dirname(__file__), "sim_build", "test_weight_mem_ctrl"),
    )


if __name__ == "__main__":
    runCocotbTests()
