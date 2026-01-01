"""
test_csr.py - CSR Register File Tests

Tests the Control/Status Register file for the Prosperity PPU.
Validates register read/write, control pulse generation, and status reporting.
"""

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ClockCycles, Timer
from cocotb_test.simulator import run
import pytest
import os

# Register addresses
REG_CTRL         = 0x00
REG_STATUS       = 0x04
REG_CONFIG       = 0x08
REG_TIMESTEPS    = 0x0C
REG_LIF_THRESH   = 0x10
REG_LIF_LEAK     = 0x14
REG_LIF_RESET    = 0x18
REG_LIF_REFRAC   = 0x1C
REG_TIMESTEP_IDX = 0x20
REG_SPIKE_COUNT  = 0x24
REG_CYCLE_COUNT  = 0x28
REG_CYCLE_COUNT_H= 0x2C
REG_TILE_COUNT   = 0x30
REG_IRQ_STATUS   = 0x34
REG_IRQ_ENABLE   = 0x38
REG_VERSION      = 0x3C


async def reset_dut(dut):
    """Reset the DUT."""
    dut.rst_n.value = 0
    dut.reg_addr.value = 0
    dut.reg_wdata.value = 0
    dut.reg_wr_en.value = 0
    dut.reg_rd_en.value = 0
    dut.ppu_ready.value = 1
    dut.ppu_busy.value = 0
    dut.sim_done.value = 0
    dut.sim_active.value = 0
    dut.timestep_idx.value = 0
    dut.spike_count.value = 0
    dut.tile_done.value = 0
    await ClockCycles(dut.clk, 5)
    dut.rst_n.value = 1
    await ClockCycles(dut.clk, 2)


async def write_reg(dut, addr, data):
    """Write a register."""
    dut.reg_addr.value = addr
    dut.reg_wdata.value = data
    dut.reg_wr_en.value = 1
    await RisingEdge(dut.clk)
    dut.reg_wr_en.value = 0
    await RisingEdge(dut.clk)


async def read_reg(dut, addr):
    """Read a register."""
    dut.reg_addr.value = addr
    dut.reg_rd_en.value = 1
    await RisingEdge(dut.clk)
    dut.reg_rd_en.value = 0
    await RisingEdge(dut.clk)
    return dut.reg_rdata.value.integer


@cocotb.test()
async def test_csr_reset_values(dut):
    """Test that registers have correct reset values."""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    await reset_dut(dut)
    
    # Read version register
    version = await read_reg(dut, REG_VERSION)
    assert version == 0x00020000, f"Version mismatch: {version:#x}"
    
    # Check default LIF parameters
    thresh = await read_reg(dut, REG_LIF_THRESH)
    assert thresh == 0x3C00, f"Default threshold should be 1.0 (FP16): {thresh:#x}"
    
    leak = await read_reg(dut, REG_LIF_LEAK)
    assert leak == 0x2E66, f"Default leak should be 0.1 (FP16): {leak:#x}"
    
    reset_pot = await read_reg(dut, REG_LIF_RESET)
    assert reset_pot == 0x0000, f"Default reset should be 0.0: {reset_pot:#x}"
    
    refrac = await read_reg(dut, REG_LIF_REFRAC)
    assert refrac == 2, f"Default refractory should be 2: {refrac}"
    
    dut._log.info("Reset values test PASSED")


@cocotb.test()
async def test_csr_read_write(dut):
    """Test basic register read/write operations."""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    await reset_dut(dut)
    
    # Write and read back timesteps
    await write_reg(dut, REG_TIMESTEPS, 100)
    timesteps = await read_reg(dut, REG_TIMESTEPS)
    assert timesteps == 100, f"Timesteps mismatch: {timesteps}"
    
    # Write and read back LIF threshold
    await write_reg(dut, REG_LIF_THRESH, 0x4000)  # FP16 2.0
    thresh = await read_reg(dut, REG_LIF_THRESH)
    assert thresh == 0x4000, f"Threshold mismatch: {thresh:#x}"
    
    # Write and read back LIF leak
    await write_reg(dut, REG_LIF_LEAK, 0x3555)  # ~0.333
    leak = await read_reg(dut, REG_LIF_LEAK)
    assert leak == 0x3555, f"Leak mismatch: {leak:#x}"
    
    # Write and read back config
    await write_reg(dut, REG_CONFIG, 0x03)  # lif_enable=1, auto_repeat=1
    config = await read_reg(dut, REG_CONFIG)
    assert config == 0x03, f"Config mismatch: {config:#x}"
    
    dut._log.info("Read/write test PASSED")


@cocotb.test()
async def test_csr_control_pulses(dut):
    """Test that control register generates proper pulses."""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    await reset_dut(dut)
    
    # Write start bit
    await write_reg(dut, REG_CTRL, 0x01)
    
    # Check that ctrl_start pulsed
    await RisingEdge(dut.clk)
    assert dut.ctrl_start.value == 0, "ctrl_start should be cleared after pulse"
    
    # Write stop bit
    await write_reg(dut, REG_CTRL, 0x02)
    await RisingEdge(dut.clk)
    assert dut.ctrl_stop.value == 0, "ctrl_stop should be cleared after pulse"
    
    # Write sw_reset bit
    await write_reg(dut, REG_CTRL, 0x04)
    await RisingEdge(dut.clk)
    assert dut.ctrl_sw_reset.value == 0, "ctrl_sw_reset should be cleared after pulse"
    
    dut._log.info("Control pulses test PASSED")


@cocotb.test()
async def test_csr_status_readback(dut):
    """Test status register reflects PPU state."""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    await reset_dut(dut)
    
    # Set PPU ready
    dut.ppu_ready.value = 1
    dut.ppu_busy.value = 0
    dut.sim_done.value = 0
    await ClockCycles(dut.clk, 2)
    
    status = await read_reg(dut, REG_STATUS)
    assert status & 0x01, "Ready bit should be set"
    assert not (status & 0x02), "Busy bit should be clear"
    
    # Set PPU busy
    dut.ppu_ready.value = 0
    dut.ppu_busy.value = 1
    await ClockCycles(dut.clk, 2)
    
    status = await read_reg(dut, REG_STATUS)
    assert not (status & 0x01), "Ready bit should be clear"
    assert status & 0x02, "Busy bit should be set"
    
    # Set sim_done
    dut.ppu_busy.value = 0
    dut.sim_done.value = 1
    await ClockCycles(dut.clk, 2)
    
    status = await read_reg(dut, REG_STATUS)
    assert status & 0x04, "Done bit should be set"
    
    dut._log.info("Status readback test PASSED")


@cocotb.test()
async def test_csr_cycle_counter(dut):
    """Test cycle counter increments during simulation."""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    await reset_dut(dut)
    
    # Read initial cycle count
    count_before = await read_reg(dut, REG_CYCLE_COUNT)
    assert count_before == 0, "Cycle count should start at 0"
    
    # Enable simulation
    dut.sim_active.value = 1
    await ClockCycles(dut.clk, 100)
    dut.sim_active.value = 0
    await ClockCycles(dut.clk, 2)
    
    # Read cycle count
    count_after = await read_reg(dut, REG_CYCLE_COUNT)
    assert count_after >= 100, f"Cycle count should be >= 100, got {count_after}"
    
    dut._log.info(f"Cycle counter test PASSED (count={count_after})")


@cocotb.test()
async def test_csr_tile_counter(dut):
    """Test tile counter increments on tile_done."""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    await reset_dut(dut)
    
    # Read initial tile count
    count_before = await read_reg(dut, REG_TILE_COUNT)
    assert count_before == 0, "Tile count should start at 0"
    
    # Pulse tile_done 5 times
    for _ in range(5):
        dut.tile_done.value = 1
        await RisingEdge(dut.clk)
        dut.tile_done.value = 0
        await ClockCycles(dut.clk, 2)
    
    # Read tile count
    count_after = await read_reg(dut, REG_TILE_COUNT)
    assert count_after == 5, f"Tile count should be 5, got {count_after}"
    
    dut._log.info("Tile counter test PASSED")


@cocotb.test()
async def test_csr_interrupt(dut):
    """Test interrupt generation on sim_done."""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    await reset_dut(dut)
    
    # Enable sim_done interrupt
    await write_reg(dut, REG_IRQ_ENABLE, 0x01)
    
    # Check IRQ is initially low
    assert dut.irq.value == 0, "IRQ should be low initially"
    
    # Trigger sim_done
    dut.sim_done.value = 1
    await ClockCycles(dut.clk, 2)
    
    # Check IRQ is asserted
    assert dut.irq.value == 1, "IRQ should be asserted on sim_done"
    
    # Read IRQ status
    irq_status = await read_reg(dut, REG_IRQ_STATUS)
    assert irq_status & 0x01, "sim_done IRQ status bit should be set"
    
    # Clear IRQ by writing 1
    await write_reg(dut, REG_IRQ_STATUS, 0x01)
    dut.sim_done.value = 0
    await ClockCycles(dut.clk, 2)
    
    # Check IRQ is cleared
    irq_status = await read_reg(dut, REG_IRQ_STATUS)
    assert not (irq_status & 0x01), "IRQ status should be cleared"
    assert dut.irq.value == 0, "IRQ should be deasserted"
    
    dut._log.info("Interrupt test PASSED")


@cocotb.test()
async def test_csr_config_outputs(dut):
    """Test that configuration writes propagate to outputs."""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    await reset_dut(dut)
    
    # Configure LIF parameters
    await write_reg(dut, REG_LIF_THRESH, 0x4200)  # FP16 3.0
    await write_reg(dut, REG_LIF_LEAK, 0x3000)    # FP16 0.5
    await write_reg(dut, REG_LIF_RESET, 0x0000)   # FP16 0.0
    await write_reg(dut, REG_LIF_REFRAC, 5)
    await write_reg(dut, REG_CONFIG, 0x01)        # Enable LIF
    await write_reg(dut, REG_TIMESTEPS, 50)
    
    await ClockCycles(dut.clk, 2)
    
    # Verify outputs
    assert dut.cfg_lif_threshold.value == 0x4200, "Threshold output mismatch"
    assert dut.cfg_lif_leak.value == 0x3000, "Leak output mismatch"
    assert dut.cfg_lif_reset.value == 0x0000, "Reset potential output mismatch"
    assert dut.cfg_lif_refractory.value == 5, "Refractory output mismatch"
    assert dut.cfg_lif_enable.value == 1, "LIF enable output mismatch"
    assert dut.cfg_num_timesteps.value == 50, "Timesteps output mismatch"
    
    dut._log.info("Config outputs test PASSED")


# pytest entry point
def runCocotbTests():
    """Run cocotb tests."""
    proj_path = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    
    run(
        verilog_sources=[os.path.join(proj_path, "ppu", "csr.v")],
        toplevel="csr",
        module="test_csr",
        simulator="verilator",
        sim_build=os.path.join(os.path.dirname(__file__), "sim_build", "test_csr"),
    )


if __name__ == "__main__":
    runCocotbTests()
