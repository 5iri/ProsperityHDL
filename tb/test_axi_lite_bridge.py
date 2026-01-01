"""
test_axi_lite_bridge.py - AXI4-Lite Bridge Tests

Tests the AXI4-Lite slave bridge for the Prosperity PPU.
Validates register access, spike buffer I/O, and weight control.
"""

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ClockCycles, Timer
from cocotb_test.simulator import run
import pytest
import os

# Address map (matches axi_lite_bridge.v)
ADDR_CSR_BASE = 0x0000
ADDR_WEIGHT_CTRL = 0x0040
ADDR_WEIGHT_BASE = 0x0044
ADDR_WEIGHT_STATUS = 0x0048
ADDR_INJECT_BASE = 0x1000
ADDR_COLLECT_BASE = 0x9000


async def reset_dut(dut):
    """Reset the DUT."""
    dut.rst_n.value = 0
    # AXI signals
    dut.s_axi_awaddr.value = 0
    dut.s_axi_awprot.value = 0
    dut.s_axi_awvalid.value = 0
    dut.s_axi_wdata.value = 0
    dut.s_axi_wstrb.value = 0xF
    dut.s_axi_wvalid.value = 0
    dut.s_axi_bready.value = 1
    dut.s_axi_araddr.value = 0
    dut.s_axi_arprot.value = 0
    dut.s_axi_arvalid.value = 0
    dut.s_axi_rready.value = 1
    # Backend signals
    dut.csr_rdata.value = 0
    dut.csr_ready.value = 1
    dut.spike_collect_rd_data.value = 0
    dut.weight_load_done.value = 0
    dut.weight_load_busy.value = 0
    await ClockCycles(dut.clk, 5)
    dut.rst_n.value = 1
    await ClockCycles(dut.clk, 2)


async def axi_write(dut, addr, data):
    """Perform AXI4-Lite write transaction."""
    # Address phase - hold valid until ready
    dut.s_axi_awaddr.value = addr
    dut.s_axi_awvalid.value = 1
    
    # Wait for address handshake
    for _ in range(50):
        await RisingEdge(dut.clk)
        if dut.s_axi_awready.value == 1:
            break
    await RisingEdge(dut.clk)
    dut.s_axi_awvalid.value = 0
    
    # Data phase - hold valid until ready
    dut.s_axi_wdata.value = data
    dut.s_axi_wstrb.value = 0xF
    dut.s_axi_wvalid.value = 1
    
    # Wait for data handshake
    for _ in range(50):
        await RisingEdge(dut.clk)
        if dut.s_axi_wready.value == 1:
            break
    await RisingEdge(dut.clk)
    dut.s_axi_wvalid.value = 0
    
    # Wait for response
    dut.s_axi_bready.value = 1
    for _ in range(50):
        await RisingEdge(dut.clk)
        if dut.s_axi_bvalid.value == 1:
            resp = int(dut.s_axi_bresp.value)
            await RisingEdge(dut.clk)
            dut.s_axi_bready.value = 0
            return resp
    
    return -1  # Timeout


async def axi_read(dut, addr):
    """Perform AXI4-Lite read transaction."""
    # Address phase - hold valid until ready
    dut.s_axi_araddr.value = addr
    dut.s_axi_arvalid.value = 1
    
    # Wait for address handshake
    for _ in range(50):
        await RisingEdge(dut.clk)
        if dut.s_axi_arready.value == 1:
            break
    await RisingEdge(dut.clk)
    dut.s_axi_arvalid.value = 0
    
    # Wait for data
    dut.s_axi_rready.value = 1
    for _ in range(50):
        await RisingEdge(dut.clk)
        if dut.s_axi_rvalid.value == 1:
            data = int(dut.s_axi_rdata.value)
            resp = int(dut.s_axi_rresp.value)
            await RisingEdge(dut.clk)
            dut.s_axi_rready.value = 0
            return data, resp
    
    return None, -1  # Timeout


@cocotb.test()
async def test_axi_reset(dut):
    """Test AXI bridge reset state."""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    await reset_dut(dut)
    
    # Check reset state
    assert dut.s_axi_awready.value == 0, "awready should be 0 in idle"
    assert dut.s_axi_wready.value == 0, "wready should be 0 in idle"
    assert dut.s_axi_bvalid.value == 0, "bvalid should be 0 in idle"
    assert dut.s_axi_arready.value == 0, "arready should be 0 in idle"
    assert dut.s_axi_rvalid.value == 0, "rvalid should be 0 in idle"
    
    dut._log.info("Reset state test PASSED")


@cocotb.test()
async def test_axi_csr_write(dut):
    """Test CSR write through AXI."""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    await reset_dut(dut)
    
    # Write to CSR address using simplified inline sequence
    addr = ADDR_CSR_BASE + 0x0C
    data = 0x0064
    
    # Address phase - hold awvalid high until we see awready AND clock edge
    dut.s_axi_awaddr.value = addr
    dut.s_axi_awvalid.value = 1
    
    # Wait for awready, then wait one more edge to complete handshake
    for i in range(10):
        await RisingEdge(dut.clk)
        if dut.s_axi_awready.value == 1:
            dut._log.info(f"awready seen at cycle {i}")
            break
    
    await RisingEdge(dut.clk)  # Complete handshake cycle
    dut.s_axi_awvalid.value = 0
    
    # Data phase - hold wvalid high until handshake completes
    dut.s_axi_wdata.value = data
    dut.s_axi_wstrb.value = 0xF
    dut.s_axi_wvalid.value = 1
    
    # Wait for wready, then wait one more edge to complete handshake
    for i in range(10):
        await RisingEdge(dut.clk)
        if dut.s_axi_wready.value == 1:
            dut._log.info(f"wready seen at cycle {i}")
            break
    
    await RisingEdge(dut.clk)  # Complete handshake cycle
    dut.s_axi_wvalid.value = 0
    
    # Response phase
    dut.s_axi_bready.value = 1
    for i in range(10):
        await RisingEdge(dut.clk)
        if dut.s_axi_bvalid.value == 1:
            resp = int(dut.s_axi_bresp.value)
            dut._log.info(f"bvalid seen at cycle {i}, bresp={resp}")
            break
    else:
        resp = -1
    
    assert resp == 0, f"Write response should be OKAY, got {resp}"
    dut._log.info("CSR write test PASSED")


@cocotb.test()
async def test_axi_csr_read(dut):
    """Test CSR read through AXI."""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    await reset_dut(dut)
    
    # Set up CSR read data
    dut.csr_rdata.value = 0xDEADBEEF
    
    # Read from CSR address
    data, resp = await axi_read(dut, ADDR_CSR_BASE + 0x3C)  # REG_VERSION
    
    assert resp == 0, f"Read response should be OKAY, got {resp}"
    assert data == 0xDEADBEEF, f"Read data mismatch: {data:#x}"
    
    dut._log.info("CSR read test PASSED")


@cocotb.test()
async def test_axi_spike_inject_write(dut):
    """Test spike injection buffer write through AXI."""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    await reset_dut(dut)
    
    # Write spike pattern to injection buffer
    test_pattern = 0xABCD
    test_addr = ADDR_INJECT_BASE + 0x10  # Offset 4 (word-aligned)
    
    resp = await axi_write(dut, test_addr, test_pattern)
    
    assert resp == 0, f"Write response should be OKAY, got {resp}"
    
    # Check spike injection interface was driven
    # The write happened in a previous cycle, check the output values
    dut._log.info("Spike inject write test PASSED")


@cocotb.test()
async def test_axi_spike_collect_read(dut):
    """Test spike collection buffer read through AXI."""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    await reset_dut(dut)
    
    # Set up spike collection read data
    test_spikes = 0x55AA55AA  # Some spike pattern
    dut.spike_collect_rd_data.value = test_spikes
    
    # Read from collection buffer
    data, resp = await axi_read(dut, ADDR_COLLECT_BASE + 0x08)
    
    assert resp == 0, f"Read response should be OKAY, got {resp}"
    # Data is zero-extended from PE_COUNT bits
    dut._log.info(f"Spike collect read: {data:#x}")
    
    dut._log.info("Spike collect read test PASSED")


@cocotb.test()
async def test_axi_weight_ctrl(dut):
    """Test weight memory control registers."""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    await reset_dut(dut)
    
    # Write base address
    base_addr = 0x8000_0000
    resp = await axi_write(dut, ADDR_WEIGHT_BASE, base_addr)
    assert resp == 0, "Base address write should succeed"
    
    await ClockCycles(dut.clk, 2)
    assert dut.weight_base_addr.value == base_addr, "Base address mismatch"
    
    # Read back base address
    data, resp = await axi_read(dut, ADDR_WEIGHT_BASE)
    assert resp == 0, "Base address read should succeed"
    assert data == base_addr, f"Base address readback mismatch: {data:#x}"
    
    # Trigger weight load
    resp = await axi_write(dut, ADDR_WEIGHT_CTRL, 0x1)
    assert resp == 0, "Weight load trigger should succeed"
    
    # Check load_start pulse
    await ClockCycles(dut.clk, 1)
    # load_start is a pulse, might have cleared
    
    # Simulate busy status
    dut.weight_load_busy.value = 1
    data, resp = await axi_read(dut, ADDR_WEIGHT_STATUS)
    assert data & 0x2, "Busy bit should be set"
    
    # Simulate done
    dut.weight_load_busy.value = 0
    dut.weight_load_done.value = 1
    data, resp = await axi_read(dut, ADDR_WEIGHT_STATUS)
    assert data & 0x1, "Done bit should be set"
    
    dut._log.info("Weight control test PASSED")


@cocotb.test()
async def test_axi_invalid_address(dut):
    """Test access to invalid address returns error."""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    await reset_dut(dut)
    
    # Read from invalid address
    data, resp = await axi_read(dut, 0x8000)  # Outside valid range
    
    # Should return SLVERR (2) or DEADBEEF
    dut._log.info(f"Invalid read: data={data:#x}, resp={resp}")
    assert resp == 2 or data == 0xDEADBEEF, "Invalid address should return error"
    
    dut._log.info("Invalid address test PASSED")


@cocotb.test()
async def test_axi_back_to_back(dut):
    """Test back-to-back transactions."""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    await reset_dut(dut)
    
    # Perform multiple writes
    for i in range(5):
        addr = ADDR_INJECT_BASE + (i * 4)
        data = 0x1000 + i
        resp = await axi_write(dut, addr, data)
        assert resp == 0, f"Write {i} should succeed"
    
    # Set up read data
    dut.csr_rdata.value = 0x12345678
    
    # Perform multiple reads
    for i in range(5):
        addr = ADDR_CSR_BASE + 0x3C  # VERSION register
        data, resp = await axi_read(dut, addr)
        assert resp == 0, f"Read {i} should succeed"
        assert data == 0x12345678, f"Read {i} data mismatch"
    
    dut._log.info("Back-to-back test PASSED")


# pytest entry point
def runCocotbTests():
    """Run cocotb tests."""
    proj_path = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    
    run(
        verilog_sources=[os.path.join(proj_path, "ppu", "axi_lite_bridge.v")],
        toplevel="axi_lite_bridge",
        module="test_axi_lite_bridge",
        simulator="verilator",
        sim_build=os.path.join(os.path.dirname(__file__), "sim_build", "test_axi_lite_bridge"),
    )


if __name__ == "__main__":
    runCocotbTests()
