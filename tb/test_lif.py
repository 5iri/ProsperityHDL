"""
test_lif.py - Cocotb testbench for single LIF neuron module (IEEE FP16)

All values are in IEEE 754 half-precision floating point (FP16) format.

FP16 Format: [15]=sign, [14:10]=exponent (bias=15), [9:0]=mantissa
Common values:
    0x0000 = 0.0
    0x3C00 = 1.0
    0x4000 = 2.0
    0x4200 = 3.0
    0x4400 = 4.0
    0x4500 = 5.0
    0x4900 = 10.0
    0x5640 = 100.0
    0x57F0 = 127.0
    0xBC00 = -1.0

Tests:
  1. Reset behavior
  2. Basic integration (input accumulates in membrane potential)
  3. Leak decay
  4. Threshold firing and reset
  5. Refractory period
  6. Negative clamping
"""

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ClockCycles
import struct
import random

# Default parameters (must match DUT)
INPUT_WIDTH = 16
VMEM_WIDTH = 16


def float_to_fp16(f):
    """Convert Python float to IEEE FP16 (16-bit unsigned integer)."""
    # Pack as FP32, then truncate to FP16 manually, or use numpy/struct
    # Using struct to pack as half-precision
    packed = struct.pack('e', f)
    return struct.unpack('H', packed)[0]


def fp16_to_float(fp16):
    """Convert IEEE FP16 (16-bit unsigned integer) to Python float."""
    packed = struct.pack('H', fp16 & 0xFFFF)
    return struct.unpack('e', packed)[0]


# Pre-computed FP16 constants
FP16_ZERO = 0x0000   # 0.0
FP16_ONE = 0x3C00    # 1.0
FP16_TWO = 0x4000    # 2.0
FP16_TEN = 0x4900    # 10.0
FP16_FIFTY = 0x5240  # 50.0
FP16_HUNDRED = 0x5640  # 100.0
FP16_TWO_HUNDRED = 0x5A40  # 200.0


async def reset_dut(dut):
    """Reset the DUT."""
    dut.rst_n.value = 0
    dut.update_en.value = 0
    dut.input_valid.value = 0
    dut.synaptic_input.value = FP16_ZERO
    dut.cfg_threshold.value = FP16_TWO_HUNDRED  # 200.0 in FP16
    dut.cfg_leak.value = FP16_ONE              # 1.0 in FP16
    dut.cfg_reset_potential.value = FP16_ZERO  # 0.0 in FP16
    dut.cfg_refractory.value = 2               # 2 cycles (integer)
    await ClockCycles(dut.clk, 5)
    dut.rst_n.value = 1
    await ClockCycles(dut.clk, 2)


async def update_neuron(dut, synaptic_input_fp16=None):
    """Run one neuron update cycle with FP16 input."""
    if synaptic_input_fp16 is not None:
        dut.synaptic_input.value = synaptic_input_fp16
        dut.input_valid.value = 1
    else:
        dut.input_valid.value = 0

    dut.update_en.value = 1
    await RisingEdge(dut.clk)
    dut.update_en.value = 0
    dut.input_valid.value = 0
    await RisingEdge(dut.clk)

    return int(dut.spike_out.value)


def get_vmem(dut):
    """Read membrane potential as FP16."""
    return int(dut.vmem_out.value)


def get_vmem_float(dut):
    """Read membrane potential as Python float."""
    fp16 = get_vmem(dut)
    return fp16_to_float(fp16)


@cocotb.test()
async def test_reset_state(dut):
    """Test that neuron starts at 0 after reset."""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    await reset_dut(dut)

    vmem = get_vmem(dut)
    assert vmem == FP16_ZERO, f"Vmem should be 0x0000 (0.0) after reset, got 0x{vmem:04x}"
    assert dut.spike_out.value == 0, "No spike after reset"
    assert dut.in_refractory.value == 0, "Not in refractory after reset"

    dut._log.info("PASS: Reset state correct")


@cocotb.test()
async def test_basic_integration(dut):
    """Test that synaptic input integrates into membrane potential (FP16)."""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    await reset_dut(dut)

    # Set high threshold so no firing (1000.0 in FP16 = 0x63D0)
    dut.cfg_threshold.value = float_to_fp16(1000.0)
    dut.cfg_leak.value = FP16_ZERO  # No leak for this test

    # Apply input: 100.0 in FP16
    fp16_100 = float_to_fp16(100.0)
    await update_neuron(dut, synaptic_input_fp16=fp16_100)

    vmem_float = get_vmem_float(dut)
    dut._log.info(f"After input 100.0: vmem = {vmem_float}")
    assert abs(vmem_float - 100.0) < 1.0, f"Expected vmem≈100, got {vmem_float}"

    # Apply another input: 50.0
    fp16_50 = float_to_fp16(50.0)
    await update_neuron(dut, synaptic_input_fp16=fp16_50)

    vmem_float = get_vmem_float(dut)
    dut._log.info(f"After input 50.0: vmem = {vmem_float}")
    assert abs(vmem_float - 150.0) < 1.0, f"Expected vmem≈150, got {vmem_float}"

    dut._log.info("PASS: Basic integration works")


@cocotb.test()
async def test_leak_decay(dut):
    """Test that leak subtracts from membrane potential each update (FP16)."""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    await reset_dut(dut)

    dut.cfg_threshold.value = float_to_fp16(1000.0)  # High threshold
    dut.cfg_leak.value = float_to_fp16(10.0)         # Leak = 10.0 in FP16

    # Inject initial charge: 100.0
    await update_neuron(dut, synaptic_input_fp16=float_to_fp16(100.0))

    vmem_float = get_vmem_float(dut)
    # Leak applied first (0-10 clamped to 0), then +100 = 100
    dut._log.info(f"After input 100.0: vmem = {vmem_float}")
    assert abs(vmem_float - 100.0) < 1.0, f"Expected vmem≈100, got {vmem_float}"

    # Run update with no input - should decay by leak
    await update_neuron(dut, synaptic_input_fp16=FP16_ZERO)

    vmem_float = get_vmem_float(dut)
    # 100 - 10 (leak) + 0 (input) = 90
    dut._log.info(f"After leak: vmem = {vmem_float}")
    assert abs(vmem_float - 90.0) < 1.0, f"Expected vmem≈90 after leak, got {vmem_float}"

    # Another update
    await update_neuron(dut, synaptic_input_fp16=FP16_ZERO)
    vmem_float = get_vmem_float(dut)
    dut._log.info(f"After second leak: vmem = {vmem_float}")
    assert abs(vmem_float - 80.0) < 1.0, f"Expected vmem≈80 after second leak, got {vmem_float}"

    dut._log.info("PASS: Leak decay works")


@cocotb.test()
async def test_threshold_firing(dut):
    """Test that neuron fires when membrane potential exceeds threshold (FP16)."""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    await reset_dut(dut)

    dut.cfg_threshold.value = float_to_fp16(200.0)
    dut.cfg_leak.value = FP16_ZERO
    dut.cfg_reset_potential.value = FP16_ZERO
    dut.cfg_refractory.value = 0  # No refractory for this test

    # Build up to just below threshold
    spike = await update_neuron(dut, synaptic_input_fp16=float_to_fp16(150.0))
    vmem_float = get_vmem_float(dut)
    dut._log.info(f"After input 150.0: vmem = {vmem_float}, spike = {spike}")
    assert spike == 0, f"Should not spike yet (150 < 200), spike={spike}"

    # Push over threshold
    spike = await update_neuron(dut, synaptic_input_fp16=float_to_fp16(60.0))  # 150 + 60 = 210 > 200
    dut._log.info(f"After input 60.0: spike = {spike}")
    assert spike == 1, f"Neuron should have spiked, spike={spike}"

    # Check reset
    vmem = get_vmem(dut)
    assert vmem == FP16_ZERO, f"Vmem should reset to 0x0000 after spike, got 0x{vmem:04x}"

    dut._log.info("PASS: Threshold firing works")


@cocotb.test()
async def test_refractory_period(dut):
    """Test that neuron ignores input during refractory period (FP16)."""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    await reset_dut(dut)

    dut.cfg_threshold.value = float_to_fp16(100.0)
    dut.cfg_leak.value = FP16_ZERO
    dut.cfg_reset_potential.value = FP16_ZERO
    dut.cfg_refractory.value = 3  # 3 updates refractory

    # Trigger a spike
    spike = await update_neuron(dut, synaptic_input_fp16=float_to_fp16(150.0))
    dut._log.info(f"Triggered spike with 150.0, spike = {spike}")
    assert spike == 1, "Should spike"
    assert dut.in_refractory.value == 1, "Should be in refractory"

    # During refractory, input should be ignored
    for t in range(3):
        spike = await update_neuron(dut, synaptic_input_fp16=float_to_fp16(200.0))
        assert spike == 0, f"Should NOT spike during refractory (t={t})"
        vmem = get_vmem(dut)
        assert vmem == FP16_ZERO, f"Vmem should stay at reset during refractory, got 0x{vmem:04x}"

    # After refractory, should integrate again
    assert dut.in_refractory.value == 0, "Should exit refractory"
    spike = await update_neuron(dut, synaptic_input_fp16=float_to_fp16(50.0))
    vmem_float = get_vmem_float(dut)
    dut._log.info(f"After refractory, input 50.0: vmem = {vmem_float}")
    assert abs(vmem_float - 50.0) < 1.0, f"Should integrate after refractory, got vmem={vmem_float}"

    dut._log.info("PASS: Refractory period works")


@cocotb.test()
async def test_negative_clamping(dut):
    """Test that membrane potential clamps to 0 (doesn't go negative) (FP16)."""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    await reset_dut(dut)

    dut.cfg_threshold.value = float_to_fp16(1000.0)
    dut.cfg_leak.value = float_to_fp16(50.0)  # Large leak

    # Start at 0, apply leak (should clamp to 0, not go negative)
    await update_neuron(dut, synaptic_input_fp16=FP16_ZERO)

    vmem = get_vmem(dut)
    assert vmem == FP16_ZERO, f"Vmem should clamp to 0x0000, got 0x{vmem:04x}"

    # Add small input, then leak should bring back toward 0
    await update_neuron(dut, synaptic_input_fp16=float_to_fp16(30.0))

    vmem_float = get_vmem_float(dut)
    # 0 - 50 (clamped to 0) + 30 = 30
    dut._log.info(f"After input 30.0: vmem = {vmem_float}")
    assert abs(vmem_float - 30.0) < 1.0, f"Expected ≈30, got {vmem_float}"

    # Another update with no input
    await update_neuron(dut, synaptic_input_fp16=FP16_ZERO)
    vmem = get_vmem(dut)
    # 30 - 50 = -20 -> clamped to 0
    dut._log.info(f"After leak with no input: vmem = 0x{vmem:04x}")
    assert vmem == FP16_ZERO, f"Should clamp negative to 0x0000, got 0x{vmem:04x}"

    dut._log.info("PASS: Negative clamping works")


# ---------------- PyTest harness ------------------------------------
def runCocotbTests():
    from cocotb_test.simulator import run
    from pathlib import Path
    import os

    repo = Path(__file__).resolve().parents[1]
    tb_dir = Path(__file__).resolve().parent
    verilog_sources = [
        repo / "ppu" / "lif.v",
    ]

    # Set PYTHONPATH so cocotb can find test_lif module
    os.environ["PYTHONPATH"] = str(tb_dir) + ":" + os.environ.get("PYTHONPATH", "")

    run(
        verilog_sources=[str(v) for v in verilog_sources],
        toplevel="lif",
        module="test_lif",
        simulator="verilator",
        compile_args=["-Wall", "-Wno-fatal"],
        sim_build=str(tb_dir / "sim_build"),
    )


if __name__ == "__main__":
    runCocotbTests()