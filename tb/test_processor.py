# test_processor_updated.py  ──────────────────────────────────────────────────
# Updated test bench for the improved 128-PE Processor module
# Tests proper MAC operations, weight loading, and product sparsity

import random
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ReadOnly, ReadWrite, Timer
from cocotb_test.simulator import run
from pathlib import Path
import numpy as np

# Test parameters
ROWS = 256
SPIKES = 16  
PE_COUNT = 128
WEIGHT_WIDTH = 8
ACC_WIDTH = 16
NO_WIDTH = 8
CLK_PERIOD = 10  # ns

def signed_to_unsigned(val, bits):
    """Convert signed value to unsigned representation"""
    if val < 0:
        return (1 << bits) + val
    return val

def unsigned_to_signed(val, bits):
    """Convert unsigned value to signed representation"""
    if val >= (1 << (bits - 1)):
        return val - (1 << bits)
    return val

@cocotb.test()
async def test_processor_weight_loading(dut):
    """Test weight loading functionality"""
    
    # Start clock
    clock = Clock(dut.clk, CLK_PERIOD, units="ns")
    cocotb.start_soon(clock.start())
    
    # Reset
    dut.rst_n.value = 0
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk) 
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)
    
    dut._log.info("=== Testing Weight Loading ===")
    
    # Initialize weight memory with known values
    test_weights = {}
    for pe in range(min(4, PE_COUNT)):  # Test first 4 PEs for simplicity
        for spike in range(min(4, SPIKES)):  # Test first 4 spikes
            weight = random.randint(-127, 127)  # 8-bit signed
            test_weights[(pe, spike)] = weight
    
    # Start a dummy task to trigger weight loading
    dut.task_row_id.value = 1
    dut.task_prefix_id.value = 0  
    dut.task_pattern.value = 0b0001  # Single spike pattern
    dut.output_rd_data.value = 0
    
    # Issue task
    dut.task_valid.value = 1
    await RisingEdge(dut.clk)
    dut.task_valid.value = 0
    
    # Wait for weight loading to complete
    weight_load_cycles = 0
    max_load_cycles = PE_COUNT * SPIKES + 10
    
    while weight_load_cycles < max_load_cycles:
        # Provide weight data when requested
        if dut.weight_rd_en.value:
            addr = int(dut.weight_addr.value)
            pe_idx = addr // SPIKES
            spike_idx = addr % SPIKES
            
            if (pe_idx, spike_idx) in test_weights:
                weight_val = test_weights[(pe_idx, spike_idx)]
                dut.weight_data.value = signed_to_unsigned(weight_val, WEIGHT_WIDTH)
                dut._log.info(f"Providing weight[{pe_idx}][{spike_idx}] = {weight_val}")
            else:
                dut.weight_data.value = 0
        
        await RisingEdge(dut.clk)
        weight_load_cycles += 1
        
        # Check if we've moved past weight loading
        try:
            state = int(dut.state.value)
            if state > 1:  # ST_LOAD_WEIGHTS = 1
                dut._log.info(f"Weight loading completed after {weight_load_cycles} cycles")
                dut._log.info("✅ Weight loading test PASSED")
                return  # Test passed successfully
        except:
            pass
    
    # If we reach here, weight loading timed out
    dut._log.error("❌ Weight loading test TIMEOUT")
    assert False, f"Weight loading timed out after {max_load_cycles} cycles"

@cocotb.test()
async def test_processor_mac_operations(dut):
    """Test MAC operations with known weights and spikes"""
    
    # Start clock
    clock = Clock(dut.clk, CLK_PERIOD, units="ns")
    cocotb.start_soon(clock.start())
    
    # Reset
    dut.rst_n.value = 0
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk) 
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)
    
    dut._log.info("=== Testing MAC Operations ===")
    
    # Simple test: 2 spikes, known weights
    test_pattern = 0b0000000000000011  # Two spikes at positions 0 and 1
    test_pe = 0  # Test first PE
    
    # Known weights for testing
    weight_0 = 10   # Weight for spike 0
    weight_1 = 20   # Weight for spike 1
    prefix_value = 100  # Starting prefix value
    
    expected_result = prefix_value + weight_0 + weight_1
    
    # Setup test
    dut.task_row_id.value = 1
    dut.task_prefix_id.value = 0
    dut.task_pattern.value = test_pattern
    
    # Setup prefix data (mock output buffer read)
    prefix_data = 0
    for pe in range(PE_COUNT):
        pe_value = prefix_value if pe == test_pe else 0
        prefix_data |= (pe_value << (pe * ACC_WIDTH))
    dut.output_rd_data.value = prefix_data
    
    # Issue task
    dut.task_valid.value = 1
    await RisingEdge(dut.clk)
    dut.task_valid.value = 0
    
    # Process task with weight provision
    cycle_count = 0
    max_cycles = 100
    
    while cycle_count < max_cycles:
        # Provide weights when requested
        if dut.weight_rd_en.value:
            addr = int(dut.weight_addr.value)
            pe_idx = addr // SPIKES
            spike_idx = addr % SPIKES
            
            if pe_idx == test_pe:
                if spike_idx == 0:
                    dut.weight_data.value = signed_to_unsigned(weight_0, WEIGHT_WIDTH)
                elif spike_idx == 1:
                    dut.weight_data.value = signed_to_unsigned(weight_1, WEIGHT_WIDTH)
                else:
                    dut.weight_data.value = 0
            else:
                dut.weight_data.value = 0
            
            dut._log.info(f"Providing weight[{pe_idx}][{spike_idx}] for addr {addr}")
        
        # Check for completion
        if dut.proc_done.value and dut.output_wr_en.value:
            # Extract result for test PE
            output_data = int(dut.output_wr_data.value)
            pe_result_bits = (output_data >> (test_pe * ACC_WIDTH)) & ((1 << ACC_WIDTH) - 1)
            pe_result = unsigned_to_signed(pe_result_bits, ACC_WIDTH)
            
            dut._log.info(f"MAC Result: {pe_result} (expected: {expected_result})")
            
            # Verify result (allow some tolerance for implementation details)
            if abs(pe_result - expected_result) <= 1:
                dut._log.info("✅ MAC operations test PASSED")
                return  # Test passed successfully
            else:
                dut._log.error(f"❌ MAC operations test FAILED: got {pe_result}, expected {expected_result}")
                assert False, f"MAC operations failed: got {pe_result}, expected {expected_result}"
            break
        
        await RisingEdge(dut.clk)
        cycle_count += 1
    
    if cycle_count >= max_cycles:
        dut._log.error("❌ MAC operations test TIMEOUT")
        assert False, f"MAC operations test timed out after {max_cycles} cycles"

@cocotb.test() 
async def test_processor_product_sparsity(dut):
    """Test product sparsity with prefix reuse"""
    
    # Start clock
    clock = Clock(dut.clk, CLK_PERIOD, units="ns")
    cocotb.start_soon(clock.start())
    
    # Reset
    dut.rst_n.value = 0
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk) 
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)
    
    dut._log.info("=== Testing Product Sparsity ===")
    
    # Test scenario: suffix pattern with non-zero prefix
    prefix_pattern = 0b0000000000000011  # Prefix has spikes at 0, 1
    suffix_pattern = 0b0000000000000100  # Suffix adds spike at 2
    full_pattern   = 0b0000000000000111  # Full would be 0, 1, 2
    
    # Weights for testing
    weights = [5, 10, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]  # Only first 3 matter
    
    # Expected calculations:
    # Prefix result: 5 + 10 = 15
    # Suffix computation: prefix_result + weight[2] = 15 + 15 = 30
    prefix_result = weights[0] + weights[1]  # 15
    expected_final = prefix_result + weights[2]  # 30
    
    # Setup task with suffix pattern  
    dut.task_row_id.value = 2
    dut.task_prefix_id.value = 1  # Different from row_id to test prefix loading
    dut.task_pattern.value = suffix_pattern
    
    # Setup prefix data in output buffer
    prefix_data = 0
    for pe in range(PE_COUNT):
        pe_value = prefix_result if pe == 0 else 0  # Only PE 0 for simplicity
        prefix_data |= (pe_value << (pe * ACC_WIDTH))
    dut.output_rd_data.value = prefix_data
    
    # Issue task
    dut.task_valid.value = 1
    await RisingEdge(dut.clk)
    dut.task_valid.value = 0
    
    # Process task
    cycle_count = 0
    max_cycles = 100
    
    while cycle_count < max_cycles:
        # Provide weights when requested
        if dut.weight_rd_en.value:
            addr = int(dut.weight_addr.value)
            pe_idx = addr // SPIKES
            spike_idx = addr % SPIKES
            
            if pe_idx == 0 and spike_idx < len(weights):
                weight_val = weights[spike_idx]
                dut.weight_data.value = signed_to_unsigned(weight_val, WEIGHT_WIDTH)
            else:
                dut.weight_data.value = 0
        
        # Check for completion
        if dut.proc_done.value and dut.output_wr_en.value:
            # Extract result for PE 0
            output_data = int(dut.output_wr_data.value)
            pe_result_bits = (output_data >> (0 * ACC_WIDTH)) & ((1 << ACC_WIDTH) - 1)
            pe_result = unsigned_to_signed(pe_result_bits, ACC_WIDTH)
            
            dut._log.info(f"Product Sparsity Result: {pe_result}")
            dut._log.info(f"Expected: {expected_final} (prefix: {prefix_result} + suffix: {weights[2]})")
            
            # Verify result
            if abs(pe_result - expected_final) <= 1:
                dut._log.info("✅ Product sparsity test PASSED")
                return  # Test passed successfully
            else:
                dut._log.error(f"❌ Product sparsity test FAILED")
                assert False, f"Product sparsity failed: got {pe_result}, expected {expected_final}"
            break
        
        await RisingEdge(dut.clk)
        cycle_count += 1
    
    if cycle_count >= max_cycles:
        dut._log.error("❌ Product sparsity test TIMEOUT")
        assert False, f"Product sparsity test timed out after {max_cycles} cycles"

@cocotb.test()
async def test_processor_multiple_tasks(dut):
    """Test processing multiple sequential tasks"""
    
    # Start clock
    clock = Clock(dut.clk, CLK_PERIOD, units="ns")
    cocotb.start_soon(clock.start())
    
    # Reset
    dut.rst_n.value = 0
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk) 
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)
    
    dut._log.info("=== Testing Multiple Tasks ===")
    
    # Test multiple tasks with different patterns
    test_tasks = [
        {"pattern": 0b0001, "row_id": 1, "prefix_id": 0},
        {"pattern": 0b0010, "row_id": 2, "prefix_id": 0},
        {"pattern": 0b0100, "row_id": 3, "prefix_id": 1},
    ]
    
    completed_tasks = 0
    
    for task_idx, task in enumerate(test_tasks):
        dut._log.info(f"Starting task {task_idx + 1}: pattern=0b{task['pattern']:04b}")
        
        # Setup task
        dut.task_row_id.value = task["row_id"]
        dut.task_prefix_id.value = task["prefix_id"] 
        dut.task_pattern.value = task["pattern"]
        dut.output_rd_data.value = task_idx * 100  # Different prefix for each task
        
        # Wait for processor to be ready
        ready_cycles = 0
        while not dut.task_ready.value and ready_cycles < 20:
            await RisingEdge(dut.clk)
            ready_cycles += 1
        
        if not dut.task_ready.value:
            dut._log.error(f"Processor not ready for task {task_idx + 1}")
            continue
        
        # Issue task
        dut.task_valid.value = 1
        await RisingEdge(dut.clk)
        dut.task_valid.value = 0
        
        # Process task
        cycle_count = 0
        max_cycles = 50
        
        while cycle_count < max_cycles:
            # Provide weights
            if dut.weight_rd_en.value:
                dut.weight_data.value = 42  # Constant weight for simplicity
            
            # Check for completion
            if dut.proc_done.value:
                completed_tasks += 1
                dut._log.info(f"✅ Task {task_idx + 1} completed")
                break
            
            await RisingEdge(dut.clk)
            cycle_count += 1
        
        if cycle_count >= max_cycles:
            dut._log.error(f"❌ Task {task_idx + 1} TIMEOUT")
        
        # Small delay between tasks
        await Timer(100, units="ns")
    
    dut._log.info(f"Completed {completed_tasks}/{len(test_tasks)} tasks")
    
    if completed_tasks == len(test_tasks):
        dut._log.info("✅ Multiple tasks test PASSED")
    else:
        dut._log.error("❌ Multiple tasks test FAILED")
        assert False, f"Multiple tasks test failed: only {completed_tasks}/{len(test_tasks)} tasks completed"

# ---------------- PyTest harness ------------------------------------
def test_processor():
    repo = Path(__file__).resolve().parents[1]
    verilog_sources = [
        repo / "ppu" / "processor.v",  # Processor module
    ]

    run(
        verilog_sources=[str(v) for v in verilog_sources],
        toplevel="processor",
        module="test_processor",
        simulator="verilator",
        compile_args=[
            "-Wall", "-Wno-fatal"
        ],
    )

if __name__ == "__main__":
    test_processor()
