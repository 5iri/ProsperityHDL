#!/usr/bin/env python3
"""
test_spike_compressor.py - Focused test for spike compression functionality

Tests the core LoAS spike compression: packing spikes over T timesteps into contiguous bitstreams.

Test Pattern:
- Neuron 0: spikes at t=0,2,4,15 → temporal pattern=0b1000000000010101 (4 spikes)
- Neuron 1: spikes at t=1,3,5    → temporal pattern=0b0000000000101010 (3 spikes)
Each bit position = one timestep, LSB = t0
"""

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer, ClockCycles
from cocotb.result import TestFailure
from cocotb_test.simulator import run
from pathlib import Path
import logging

# Configure logging
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

@cocotb.test()
async def test_temporal_spike_compression(dut):
    """Test temporal spike compression - one neuron across multiple timesteps"""
    
    # Initialize
    logger = logging.getLogger("cocotb.test")
    logger.setLevel(logging.INFO)
    
    # Reset
    dut.rst_n.value = 0
    dut.enable.value = 0
    dut.window_size.value = 15  # Max 4-bit value for 16 timesteps
    dut.spike_valid.value = 0
    dut.window_complete.value = 0
    dut.compressed_ready.value = 1
    
    # Clock setup
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    
    await ClockCycles(dut.clk, 2)
    
    # Enable module
    dut.rst_n.value = 1
    dut.enable.value = 1
    
    await ClockCycles(dut.clk, 2)
    
    logger.info("=== Testing Temporal Spike Compression ===\n")
    
    # Test data: (neuron_id, timestamp, spike_bit) - individual spike events
    test_data = [
        # Neuron 0: spikes at t=0, t=2, t=4, t=6 → pattern = 0b0101010100000001 (LSB=t0)
        (0, 0, 1),   # Neuron 0 spikes at t=0
        (0, 2, 1),   # Neuron 0 spikes at t=2  
        (0, 4, 1),   # Neuron 0 spikes at t=4
        (0, 15, 1),  # Neuron 0 spikes at t=15
        
        # Neuron 1: spikes at t=1, t=3, t=5 → pattern = 0b0000000000101010
        (1, 1, 1),   # Neuron 1 spikes at t=1
        (1, 3, 1),   # Neuron 1 spikes at t=3
        (1, 5, 1),   # Neuron 1 spikes at t=5
    ]
    
    # Expected compressed results (temporal patterns per neuron)
    expected = {
        0: {"pattern": 0b1000000000010101, "count": 4},  # Neuron 0: t=0,2,4,15 active
        1: {"pattern": 0b0000000000101010, "count": 3},  # Neuron 1: t=1,3,5 active
    }
    
    # Drive spike inputs (individual spike events)
    for neuron_id, timestamp, spike_bit in test_data:
        logger.info(f"  Input: Neuron {neuron_id}, t={timestamp}, spike={spike_bit}")
        
        dut.spike_valid.value = 1
        dut.spike_timestamp.value = timestamp
        dut.spike_neuron_id.value = neuron_id  
        dut.spike_bit.value = spike_bit
        
        # Wait for ready
        while not dut.spike_ready.value:
            await RisingEdge(dut.clk)
            
        await RisingEdge(dut.clk)
        
    # Signal end of input and complete window
    dut.spike_valid.value = 0
    await ClockCycles(dut.clk, 2)
    dut.window_complete.value = 1
    await ClockCycles(dut.clk, 1)
    dut.window_complete.value = 0
        
    logger.info("All spikes sent. Waiting for compression...")
    
    # Collect compressed outputs
    compressed_results = {}
    output_count = 0
    timeout = 100
    
    while output_count < 2 and timeout > 0:
        await RisingEdge(dut.clk)
        
        if dut.compressed_valid.value:
            neuron_id = int(dut.compressed_neuron_id.value)
            pattern = int(dut.compressed_pattern.value) & 0xFFFF
            spike_count = int(dut.spike_count.value)
            
            compressed_results[neuron_id] = {
                "pattern": pattern,
                "count": spike_count
            }
            
            logger.info(f"  Compressed Neuron {neuron_id}: pattern=0b{pattern:016b}, "
                       f"count={spike_count}")
            
            output_count += 1
            
        timeout -= 1
        
    if timeout <= 0:
        raise TestFailure("Timeout waiting for compressed output")
    
    # Validate results
    logger.info("=== Validating Compression Results ===")
    
    for neuron_id, expected_data in expected.items():
        if neuron_id not in compressed_results:
            raise TestFailure(f"Missing compressed data for neuron {neuron_id}")
            
        result = compressed_results[neuron_id]
        
        # Check compressed pattern
        if result["pattern"] != expected_data["pattern"]:
            raise TestFailure(
                f"Neuron {neuron_id} pattern mismatch: "
                f"expected 0b{expected_data['pattern']:016b}, "
                f"got 0b{result['pattern']:016b}"
            )
            
        # Check spike count
        if result["count"] != expected_data["count"]:
            raise TestFailure(
                f"Neuron {neuron_id} count mismatch: "
                f"expected {expected_data['count']}, "
                f"got {result['count']}"
            )
            
        logger.info(f"✓ Neuron {neuron_id} validated: 0b{result['pattern']:016b} with {result['count']} spikes")
    
    logger.info("=== Temporal Spike Compression Test PASSED ===")
    
    # Test compression explanation
    logger.info("\nTemporal Compression Logic Validation:")
    logger.info("Neuron 0: spikes at t=0,2,4,15 → 0b1000000000010101")
    logger.info("Neuron 1: spikes at t=1,3,5   → 0b0000000000101010")
    logger.info("Each bit position = one timestep, LSB = t0")
    logger.info("\n✓ Core Task 1: Temporal spike compression → COMPLETE")


# Removed test_single_timestep_compression - incompatible with temporal module interface


def test_spike_compressor():
    """Run spike compressor tests using cocotb_test"""
    
    proj_root = Path(__file__).resolve().parent.parent
    
    run(
        verilog_sources=[
            proj_root / "ppu" / "spike_compressor.v",
        ],
        toplevel="spike_compressor", 
        module="test_spike_compressor",
        parameters={
            "T_WINDOW": 16,
            "MAX_NEURONS": 256,
            "NEURON_ID_W": 8,
            "TIMESTAMP_W": 4,
        },
        simulator="verilator",
        compile_args=[
            "-Wall",
            "-Wno-UNOPTFLAT", "-Wno-UNSIGNED", 
            "-DSIMULATION",
        ],
        waves=True,
    )

if __name__ == "__main__":
    test_spike_compressor()
    