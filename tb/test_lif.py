"""
test_lif.py - Cocotb testbench for single LIF neuron module
Tests:
  1. Reset behavior
  2. Basic integration (input accumulates in membrane potential)
  3. Leak decay
  4. Threshold firing and reset
  5. Refractory period
"""

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ClockCycles
import random

# Default parameters (must match DUT)
INPUT_WIDTH = 16
VMEM_WIDTH = 16


async def reset_dut(dut):
    """Reset the DUT."""
    dut.rst_n.value = 0
    dut.update_en.value = 0
    dut.input_valid.value = 0
    dut.synaptic_input.value = 0
    dut.cfg_threshold.value = 256
    dut.cfg_leak.value = 1
    dut.cfg_reset_potential.value = 0
    dut.cfg_refractory.value = 2
    await ClockCycles(dut.clk, 5)
    dut.rst_n.value = 1
    await ClockCycles(dut.clk, 2)


async def update_neuron(dut, synaptic_input=None):
    """Run one neuron update cycle."""
    if synaptic_input is not None:
        # Handle signed values
        if synaptic_input < 0:
            synaptic_input = (1 << INPUT_WIDTH) + synaptic_input
        dut.synaptic_input.value = synaptic_input
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
    """Read membrane potential (interpret as signed)."""
    raw = int(dut.vmem_out.value)
    if raw >= (1 << (VMEM_WIDTH - 1)):
        raw -= (1 << VMEM_WIDTH)
    return raw


@cocotb.test()
async def test_reset_state(dut):
    """Test that neuron starts at 0 after reset."""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    await reset_dut(dut)

    vmem = get_vmem(dut)
    assert vmem == 0, f"Vmem should be 0 after reset, got {vmem}"
    assert dut.spike_out.value == 0, "No spike after reset"
    assert dut.in_refractory.value == 0, "Not in refractory after reset"

    dut._log.info("PASS: Reset state correct")


@cocotb.test()
async def test_basic_integration(dut):
    """Test that synaptic input integrates into membrane potential."""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    await reset_dut(dut)

    # Set high threshold so no firing
    dut.cfg_threshold.value = 10000
    dut.cfg_leak.value = 0  # No leak for this test

    # Apply input
    await update_neuron(dut, synaptic_input=100)

    vmem = get_vmem(dut)
    assert vmem == 100, f"Expected vmem=100 after input, got {vmem}"

    # Apply another input
    await update_neuron(dut, synaptic_input=50)

    vmem = get_vmem(dut)
    assert vmem == 150, f"Expected vmem=150 after second input, got {vmem}"

    dut._log.info("PASS: Basic integration works")


@cocotb.test()
async def test_leak_decay(dut):
    """Test that leak subtracts from membrane potential each update."""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    await reset_dut(dut)

    dut.cfg_threshold.value = 10000  # High threshold
    dut.cfg_leak.value = 10

    # Inject initial charge
    await update_neuron(dut, synaptic_input=100)

    vmem = get_vmem(dut)
    # Leak applied first (0-10 clamped to 0), then +100 = 100
    assert vmem == 100, f"Expected vmem=100, got {vmem}"

    # Run update with no input - should decay by leak
    await update_neuron(dut, synaptic_input=0)

    vmem = get_vmem(dut)
    # 100 - 10 (leak) + 0 (input) = 90
    assert vmem == 90, f"Expected vmem=90 after leak, got {vmem}"

    # Another update
    await update_neuron(dut, synaptic_input=0)
    vmem = get_vmem(dut)
    assert vmem == 80, f"Expected vmem=80 after second leak, got {vmem}"

    dut._log.info("PASS: Leak decay works")


@cocotb.test()
async def test_threshold_firing(dut):
    """Test that neuron fires when membrane potential exceeds threshold."""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    await reset_dut(dut)

    dut.cfg_threshold.value = 200
    dut.cfg_leak.value = 0
    dut.cfg_reset_potential.value = 0
    dut.cfg_refractory.value = 0  # No refractory for this test

    # Build up to just below threshold
    spike = await update_neuron(dut, synaptic_input=150)
    assert spike == 0, "Should not spike yet (150 < 200)"

    # Push over threshold
    spike = await update_neuron(dut, synaptic_input=60)  # 150 + 60 = 210 > 200
    assert spike == 1, f"Neuron should have spiked, spike={spike}"

    # Check reset
    vmem = get_vmem(dut)
    assert vmem == 0, f"Vmem should reset to 0 after spike, got {vmem}"

    dut._log.info("PASS: Threshold firing works")


@cocotb.test()
async def test_refractory_period(dut):
    """Test that neuron ignores input during refractory period."""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    await reset_dut(dut)

    dut.cfg_threshold.value = 100
    dut.cfg_leak.value = 0
    dut.cfg_reset_potential.value = 0
    dut.cfg_refractory.value = 3  # 3 updates refractory

    # Trigger a spike
    spike = await update_neuron(dut, synaptic_input=150)
    assert spike == 1, "Should spike"
    assert dut.in_refractory.value == 1, "Should be in refractory"

    # During refractory, input should be ignored
    for t in range(3):
        spike = await update_neuron(dut, synaptic_input=200)  # Would normally cause spike
        assert spike == 0, f"Should NOT spike during refractory (t={t})"
        vmem = get_vmem(dut)
        assert vmem == 0, f"Vmem should stay at reset during refractory, got {vmem}"

    # After refractory, should integrate again
    assert dut.in_refractory.value == 0, "Should exit refractory"
    spike = await update_neuron(dut, synaptic_input=50)
    vmem = get_vmem(dut)
    assert vmem == 50, f"Should integrate after refractory, got vmem={vmem}"

    dut._log.info("PASS: Refractory period works")


@cocotb.test()
async def test_negative_clamping(dut):
    """Test that membrane potential clamps to 0 (doesn't go negative)."""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    await reset_dut(dut)

    dut.cfg_threshold.value = 1000
    dut.cfg_leak.value = 50  # Large leak

    # Start at 0, apply leak (should clamp to 0, not go negative)
    await update_neuron(dut, synaptic_input=0)

    vmem = get_vmem(dut)
    assert vmem == 0, f"Vmem should clamp to 0, got {vmem}"

    # Add small input, then leak should bring back toward 0
    await update_neuron(dut, synaptic_input=30)

    vmem = get_vmem(dut)
    # 0 - 50 (clamped to 0) + 30 = 30
    assert vmem == 30, f"Expected 30, got {vmem}"

    # Another update with no input
    await update_neuron(dut, synaptic_input=0)
    vmem = get_vmem(dut)
    # 30 - 50 = -20 -> clamped to 0
    assert vmem == 0, f"Should clamp negative to 0, got {vmem}"

    dut._log.info("PASS: Negative clamping works")


# ---------------- PyTest harness ------------------------------------
def test_lif():
    from cocotb_test.simulator import run
    from pathlib import Path

    repo = Path(__file__).resolve().parents[1]
    verilog_sources = [
        repo / "ppu" / "lif.v",
    ]

    run(
        verilog_sources=[str(v) for v in verilog_sources],
        toplevel="lif",
        module="test_lif",
        simulator="verilator",
        compile_args=["-Wall", "-Wno-fatal"],
    )


if __name__ == "__main__":
    test_lif()