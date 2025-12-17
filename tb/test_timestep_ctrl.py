"""
test_timestep_ctrl.py - Cocotb tests for timestep controller
"""

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge, Timer
from cocotb_test.simulator import run
from pathlib import Path

CLK_PERIOD = 10  # ns


@cocotb.test()
async def test_basic_timesteps(dut):
    """Test basic timestep counting"""
    
    clock = Clock(dut.clk, CLK_PERIOD, units="ns")
    cocotb.start_soon(clock.start())
    
    # Reset
    dut.rst_n.value = 0
    dut.start.value = 0
    dut.tile_done.value = 0
    dut.num_timesteps.value = 5
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)
    
    dut._log.info("=== Testing Basic Timesteps (5 timesteps) ===")
    
    # Start simulation
    dut.start.value = 1
    await RisingEdge(dut.clk)
    dut.start.value = 0
    
    timesteps_completed = 0
    max_cycles = 1000
    cycles = 0
    
    while cycles < max_cycles and not dut.sim_done.value:
        # Check for tile_start pulse
        if dut.tile_start.value:
            dut._log.info(f"Timestep {int(dut.timestep_idx.value)}: tile_start received")
        
        # Simulate tile processing (takes a few cycles)
        if dut.tile_start.value:
            await RisingEdge(dut.clk)
            await RisingEdge(dut.clk)
            await RisingEdge(dut.clk)
            dut.tile_done.value = 1
            await RisingEdge(dut.clk)
            dut.tile_done.value = 0
            cycles += 4
        
        # Check for timestep_end pulse
        if dut.timestep_end.value:
            timesteps_completed += 1
            dut._log.info(f"Timestep {int(dut.timestep_idx.value)}: timestep_end received (total: {timesteps_completed})")
        
        await RisingEdge(dut.clk)
        cycles += 1
    
    # Verify
    assert dut.sim_done.value, "Simulation should be done"
    assert timesteps_completed == 5, f"Expected 5 timesteps, got {timesteps_completed}"
    
    dut._log.info(f"✅ Basic timesteps test PASSED ({timesteps_completed} timesteps in {cycles} cycles)")


@cocotb.test()
async def test_single_timestep(dut):
    """Test single timestep case"""
    
    clock = Clock(dut.clk, CLK_PERIOD, units="ns")
    cocotb.start_soon(clock.start())
    
    # Reset
    dut.rst_n.value = 0
    dut.start.value = 0
    dut.tile_done.value = 0
    dut.num_timesteps.value = 1
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)
    
    dut._log.info("=== Testing Single Timestep ===")
    
    # Start
    dut.start.value = 1
    await RisingEdge(dut.clk)
    dut.start.value = 0
    
    # Wait for tile_start
    while not dut.tile_start.value:
        await RisingEdge(dut.clk)
    
    assert int(dut.timestep_idx.value) == 0, "Should be at timestep 0"
    
    # Simulate tile completion
    await RisingEdge(dut.clk)
    dut.tile_done.value = 1
    await RisingEdge(dut.clk)
    dut.tile_done.value = 0
    
    # Wait for sim_done
    for _ in range(10):
        if dut.sim_done.value:
            break
        await RisingEdge(dut.clk)
    
    assert dut.sim_done.value, "Simulation should complete after 1 timestep"
    dut._log.info("✅ Single timestep test PASSED")


@cocotb.test()
async def test_zero_timesteps(dut):
    """Test zero timesteps (should not start)"""
    
    clock = Clock(dut.clk, CLK_PERIOD, units="ns")
    cocotb.start_soon(clock.start())
    
    # Reset
    dut.rst_n.value = 0
    dut.start.value = 0
    dut.tile_done.value = 0
    dut.num_timesteps.value = 0  # Zero timesteps
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)
    
    dut._log.info("=== Testing Zero Timesteps ===")
    
    # Try to start
    dut.start.value = 1
    await RisingEdge(dut.clk)
    dut.start.value = 0
    
    # Wait a few cycles
    for _ in range(5):
        await RisingEdge(dut.clk)
    
    # Should not have started
    assert not dut.sim_active.value, "Should not be active with 0 timesteps"
    assert not dut.tile_start.value, "Should not start tile processing"
    
    dut._log.info("✅ Zero timesteps test PASSED")


@cocotb.test()
async def test_sim_active_signal(dut):
    """Test sim_active signal behavior"""
    
    clock = Clock(dut.clk, CLK_PERIOD, units="ns")
    cocotb.start_soon(clock.start())
    
    # Reset
    dut.rst_n.value = 0
    dut.start.value = 0
    dut.tile_done.value = 0
    dut.num_timesteps.value = 2
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)
    
    dut._log.info("=== Testing sim_active Signal ===")
    
    # Before start
    assert not dut.sim_active.value, "Should not be active before start"
    
    # Start
    dut.start.value = 1
    await RisingEdge(dut.clk)
    dut.start.value = 0
    await RisingEdge(dut.clk)
    
    # During simulation
    assert dut.sim_active.value, "Should be active during simulation"
    
    # Complete timesteps
    for _ in range(2):
        while not dut.tile_start.value:
            await RisingEdge(dut.clk)
        await RisingEdge(dut.clk)
        dut.tile_done.value = 1
        await RisingEdge(dut.clk)
        dut.tile_done.value = 0
        for _ in range(3):
            await RisingEdge(dut.clk)
    
    # Wait for completion
    for _ in range(10):
        if dut.sim_done.value:
            break
        await RisingEdge(dut.clk)
    
    # After completion
    assert dut.sim_done.value, "Should be done"
    assert not dut.sim_active.value, "Should not be active after completion"
    
    dut._log.info("✅ sim_active signal test PASSED")


# ── Pytest wrapper ─────────────────────────────────────────────────────────
def test_timestep_ctrl():
    repo = Path(__file__).resolve().parents[1]
    verilog_sources = [
        repo / "ppu" / "timestep_ctrl.v",
    ]

    run(
        verilog_sources=[str(v) for v in verilog_sources],
        toplevel="timestep_ctrl",
        module="test_timestep_ctrl",
        parameters={
            "TIMESTEP_WIDTH": "16",
        },
        sim_build="sim_build",
        timescale="1ns/1ps",
    )


if __name__ == "__main__":
    test_timestep_ctrl()
