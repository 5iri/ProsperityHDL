"""
test_top_axi.py - AXI-based integration test for Prosperity PPU

Tests the full PPU via AXI4-Lite interface only (Phase 2 integration).
All configuration, spike injection, and readback is done through AXI.
"""

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ClockCycles, Timer
from cocotb_test.simulator import run
from pathlib import Path
import numpy as np
import struct

# Test parameters
CLK_NS = 10
ROWS = 256
SPIKES = 16
PE_COUNT = 128
MAX_TIMESTEPS = 256

# AXI Address Map (from axi_lite_bridge.v)
ADDR_CTRL     = 0x0000  # Control register (start/stop)
ADDR_STATUS   = 0x0004  # Status register
ADDR_CONFIG   = 0x0008  # Configuration register
ADDR_TIMESTEPS = 0x000C # Number of timesteps
ADDR_LIF_THRESH = 0x0010  # LIF threshold
ADDR_LIF_LEAK   = 0x0014  # LIF leak
ADDR_LIF_RESET  = 0x0018  # LIF reset potential
ADDR_LIF_REFRAC = 0x001C  # LIF refractory
ADDR_WEIGHT_CTRL = 0x0040  # Weight control
ADDR_WEIGHT_BASE = 0x0044  # Weight base address
ADDR_WEIGHT_STATUS = 0x0048  # Weight status
ADDR_INJECT_BASE = 0x1000   # Spike injection base
ADDR_COLLECT_BASE = 0x9000  # Spike collection base


async def reset_dut(dut):
    """Reset the DUT and initialize AXI signals."""
    dut.rst_n.value = 0
    # Initialize AXI slave signals
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
    # Initialize AXI master signals (weight memory)
    dut.m_axi_arready.value = 1
    dut.m_axi_rdata.value = 0
    dut.m_axi_rresp.value = 0
    dut.m_axi_rlast.value = 0
    dut.m_axi_rvalid.value = 0
    await ClockCycles(dut.clk, 10)
    dut.rst_n.value = 1
    await ClockCycles(dut.clk, 5)


async def axi_write(dut, addr, data):
    """Perform AXI4-Lite write transaction."""
    # Set up write address and data
    dut.s_axi_awaddr.value = addr
    dut.s_axi_awvalid.value = 1
    dut.s_axi_wdata.value = data
    dut.s_axi_wstrb.value = 0xF
    dut.s_axi_wvalid.value = 1
    dut.s_axi_bready.value = 1
    
    aw_done = False
    w_done = False
    
    for _ in range(200):
        await RisingEdge(dut.clk)
        if dut.s_axi_awready.value == 1 and dut.s_axi_awvalid.value == 1:
            aw_done = True
            dut.s_axi_awvalid.value = 0
        if dut.s_axi_wready.value == 1 and dut.s_axi_wvalid.value == 1:
            w_done = True
            dut.s_axi_wvalid.value = 0
        if aw_done and w_done:
            break
    
    # Wait for write response
    for _ in range(200):
        await RisingEdge(dut.clk)
        if dut.s_axi_bvalid.value == 1:
            resp = int(dut.s_axi_bresp.value)
            await RisingEdge(dut.clk)
            return resp
    return -1


async def axi_read(dut, addr):
    """Perform AXI4-Lite read transaction."""
    dut.s_axi_araddr.value = addr
    dut.s_axi_arvalid.value = 1
    dut.s_axi_rready.value = 1
    
    for _ in range(200):
        await RisingEdge(dut.clk)
        if dut.s_axi_arready.value == 1 and dut.s_axi_arvalid.value == 1:
            dut.s_axi_arvalid.value = 0
            break
    
    for _ in range(200):
        await RisingEdge(dut.clk)
        if dut.s_axi_rvalid.value == 1:
            data = int(dut.s_axi_rdata.value)
            await RisingEdge(dut.clk)
            return data
    return -1


async def weight_dma_responder(dut):
    """Respond to weight DMA requests with test data."""
    weight_data = [i & 0xFFFF for i in range(SPIKES * PE_COUNT)]  # Simple test pattern
    
    while True:
        await RisingEdge(dut.clk)
        if dut.m_axi_arvalid.value == 1 and dut.m_axi_arready.value == 1:
            base_addr = int(dut.m_axi_araddr.value)
            burst_len = int(dut.m_axi_arlen.value) + 1
            
            # Respond with burst data
            for i in range(burst_len):
                await RisingEdge(dut.clk)
                word_idx = (base_addr // 4 + i) % len(weight_data)
                # Pack two 16-bit weights into 32-bit word
                w0 = weight_data[word_idx * 2 % len(weight_data)]
                w1 = weight_data[(word_idx * 2 + 1) % len(weight_data)]
                dut.m_axi_rdata.value = (w1 << 16) | w0
                dut.m_axi_rvalid.value = 1
                dut.m_axi_rlast.value = 1 if i == burst_len - 1 else 0
                dut.m_axi_rresp.value = 0
                
                # Wait for ready
                for _ in range(10):
                    await RisingEdge(dut.clk)
                    if dut.m_axi_rready.value == 1:
                        break
            
            await RisingEdge(dut.clk)
            dut.m_axi_rvalid.value = 0
            dut.m_axi_rlast.value = 0


@cocotb.test()
async def test_axi_csr_access(dut):
    """Test CSR register access via AXI."""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, units="ns").start())
    await reset_dut(dut)
    
    # Write timesteps config
    resp = await axi_write(dut, ADDR_TIMESTEPS, 4)
    assert resp == 0, f"Write failed with response {resp}"
    
    # Read back
    data = await axi_read(dut, ADDR_TIMESTEPS)
    assert data == 4, f"Read mismatch: expected 4, got {data}"
    
    # Write LIF threshold (FP16: 1.0 = 0x3C00)
    resp = await axi_write(dut, ADDR_LIF_THRESH, 0x3C00)
    assert resp == 0
    
    cocotb.log.info("✓ CSR access test passed")


@cocotb.test()
async def test_axi_spike_injection(dut):
    """Test spike injection via AXI."""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, units="ns").start())
    await reset_dut(dut)
    
    # Inject some spike patterns for timestep 0
    for row in range(10):
        addr = ADDR_INJECT_BASE + row * 4
        pattern = (1 << row) | (1 << (row + 1))  # Two spikes per row
        resp = await axi_write(dut, addr, pattern)
        assert resp == 0, f"Spike inject write failed at row {row}"
    
    cocotb.log.info("✓ Spike injection test passed")


@cocotb.test()
async def test_axi_weight_load(dut):
    """Test weight loading via AXI-triggered DMA."""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, units="ns").start())
    cocotb.start_soon(weight_dma_responder(dut))
    await reset_dut(dut)
    
    # Set weight base address
    resp = await axi_write(dut, ADDR_WEIGHT_BASE, 0x80000000)
    assert resp == 0
    
    # Trigger weight load
    resp = await axi_write(dut, ADDR_WEIGHT_CTRL, 1)
    assert resp == 0
    
    # Wait for load to complete
    for _ in range(10000):
        await ClockCycles(dut.clk, 10)
        status = await axi_read(dut, ADDR_WEIGHT_STATUS)
        if status & 0x2:  # load_done bit
            break
    
    assert status & 0x2, "Weight load did not complete"
    cocotb.log.info("✓ Weight load test passed")


@cocotb.test()
async def test_axi_simulation_flow(dut):
    """Test full simulation flow via AXI."""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, units="ns").start())
    cocotb.start_soon(weight_dma_responder(dut))
    await reset_dut(dut)
    
    # Configure simulation
    await axi_write(dut, ADDR_TIMESTEPS, 2)
    await axi_write(dut, ADDR_LIF_THRESH, 0x3C00)  # 1.0
    await axi_write(dut, ADDR_LIF_LEAK, 0x3800)    # 0.5
    await axi_write(dut, ADDR_LIF_RESET, 0x0000)   # 0.0
    await axi_write(dut, ADDR_LIF_REFRAC, 2)
    await axi_write(dut, ADDR_CONFIG, 0x01)  # Enable LIF
    
    # Load weights
    await axi_write(dut, ADDR_WEIGHT_BASE, 0x80000000)
    await axi_write(dut, ADDR_WEIGHT_CTRL, 1)
    
    for _ in range(10000):
        await ClockCycles(dut.clk, 10)
        status = await axi_read(dut, ADDR_WEIGHT_STATUS)
        if status & 0x2:
            break
    
    # Inject spikes for timestep 0
    for row in range(ROWS):
        addr = ADDR_INJECT_BASE + row * 4
        pattern = row & 0xFFFF
        await axi_write(dut, addr, pattern)
    
    # Start simulation
    await axi_write(dut, ADDR_CTRL, 0x01)
    
    # Wait for completion
    for _ in range(100000):
        await ClockCycles(dut.clk, 100)
        if dut.sim_done.value == 1:
            break
    
    assert dut.sim_done.value == 1, "Simulation did not complete"
    cocotb.log.info("✓ Full simulation flow test passed")


def runCocotbTests():
    repo = Path(__file__).resolve().parents[1]
    verilog_sources = [
        repo / "ppu" / "top.v",
        repo / "ppu" / "detector.v",
        repo / "ppu" / "pruner.v",
        repo / "ppu" / "dispatcher.v",
        repo / "ppu" / "processor.v",
        repo / "ppu" / "lif.v",
        repo / "ppu" / "timestep_ctrl.v",
        repo / "ppu" / "spike_injector.v",
        repo / "ppu" / "spike_collector.v",
        repo / "ppu" / "axi_lite_bridge.v",
        repo / "ppu" / "csr.v",
        repo / "ppu" / "weight_mem_ctrl.v",
        repo / "ppu" / "tcam" / "hdl" / "tcam_line_array.v",
        repo / "ppu" / "tcam" / "hdl" / "tcam_line_encoder.v",
        repo / "ppu" / "tcam" / "hdl" / "tcam_sdpram.v",
    ]

    run(
        verilog_sources=[str(v) for v in verilog_sources],
        toplevel="top",
        module="test_top",
        parameters={
            "ROWS": str(ROWS),
            "SPIKES": str(SPIKES),
            "PE_COUNT": str(PE_COUNT),
            "MAX_TIMESTEPS": str(MAX_TIMESTEPS),
        },
        timescale="1ns/1ps",
        simulator="verilator",
        compile_args=["-Wall", "-Wno-fatal"],
        waves=False,
    )


if __name__ == "__main__":
    runCocotbTests()
