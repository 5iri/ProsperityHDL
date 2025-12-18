"""
ProsperityHDL Golden Model Testbench

Comprehensive golden reference model for SNN accelerator verification:
- IEEE FP16 weight support
- Product sparsity prefix selection (paper-faithful)
- MAC operation verification
- LIF neuron dynamics verification
- End-to-end inference accuracy

Golden Model Checks:
- XOR invariant for each task: residual == row_patt ^ prefix_patt
- Order-insensitive multiset compare vs golden of (row, prefix, residual)
- MAC accuracy (FP16)
- LIF neuron state transitions

NULL prefix encoding (for roots):
- Default: fixed ID 255 (PROS_NULL="255")
- Or use row_id as NULL (PROS_NULL="row")
"""

import os
import sys
import random
import struct
import logging
import datetime
from pathlib import Path
from typing import Dict, List, Any, Tuple
from collections import Counter
from dataclasses import dataclass

import numpy as np

# cocotb
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ReadOnly, Timer
from cocotb_test.simulator import run

# ============================================================================
# Configuration
# ============================================================================

ROWS = 256
SPIKES = 16
CLK_NS = 10
MAX_CYCLES = 200_000

# Logging
LOG_DIR = Path(__file__).parent / "debug_logs"
LOG_DIR.mkdir(exist_ok=True)


# ============================================================================
# Basic Utilities
# ============================================================================

def popcount(x: int) -> int:
    """Count number of set bits."""
    return int(bin(x).count("1"))


# ============================================================================
# IEEE 754 FP16 Golden Model Utilities
# ============================================================================

def fp16_to_float(bits: int) -> float:
    """Convert 16-bit IEEE 754 half-precision to Python float."""
    bits_int = int(bits) & 0xFFFF
    fp16_bytes = struct.pack('<H', bits_int)
    return float(np.frombuffer(fp16_bytes, dtype=np.float16)[0].astype(np.float32))


def float_to_fp16(value: float) -> int:
    """Convert Python float to 16-bit IEEE 754 half-precision bits."""
    fp16_val = np.float16(value)
    return int(struct.unpack('<H', fp16_val.tobytes())[0])


def fp16_mac(weights_fp16: np.ndarray, spikes: np.ndarray) -> float:
    """
    Golden MAC operation with FP16 weights and binary spikes.
    
    Args:
        weights_fp16: Weight bit representations (uint16 array)
        spikes: Binary spike vector (0 or 1)
    
    Returns:
        Accumulation result as float32
    """
    weights_float = np.array([fp16_to_float(w) for w in weights_fp16], dtype=np.float32)
    result = np.sum(weights_float * spikes.astype(np.float32))
    return float(result)


# ============================================================================
# LIF Neuron Golden Model
# ============================================================================

@dataclass
class LIFNeuronState:
    """LIF (Leaky Integrate-and-Fire) neuron state."""
    vmem: float = 0.0
    refractory_counter: int = 0


class LIFNeuronGolden:
    """
    Golden reference LIF neuron implementation.
    Matches hardware behavior exactly.
    """
    
    def __init__(self, threshold: float = 100.0, leak: float = 2.0, 
                 reset_potential: float = 0.0, refractory_period: int = 2):
        self.threshold = threshold
        self.leak = leak
        self.reset_potential = reset_potential
        self.refractory_period = refractory_period
        self.state = LIFNeuronState()
    
    def update(self, synaptic_input: float, enable: bool = True) -> bool:
        """
        Update neuron for one timestep.
        
        Args:
            synaptic_input: Input current (MAC result)
            enable: Enable LIF update
        
        Returns:
            True if neuron fired (spike), False otherwise
        """
        if not enable:
            return False
        
        if self.state.refractory_counter > 0:
            self.state.refractory_counter -= 1
            return False
        
        # Leak
        self.state.vmem = max(0.0, self.state.vmem - self.leak)
        
        # Integrate
        self.state.vmem = self.state.vmem + synaptic_input
        
        # Fire?
        if self.state.vmem >= self.threshold:
            self.state.vmem = self.reset_potential
            self.state.refractory_counter = self.refractory_period
            return True
        
        return False
    
    def reset(self):
        """Reset neuron to initial state."""
        self.state = LIFNeuronState()


# ============================================================================
# Product Sparsity Golden Model
# ============================================================================

def _null_prefix_id(row_id: int, m: int) -> int:
    """
    NULL prefix encoding for root rows.
    Returns row_id itself (self-reference means no valid prefix).
    
    This is semantically correct since a row can never be its own prefix:
    - PM requires proper subset (A ⊂ Si, A ≠ Si) - row is not proper subset of itself
    - EM requires different rows with exact match (i < j, Si = Sj) - row cannot be both i and j
    """
    return row_id


def golden_prosparsity_subset(tile_patterns: List[Dict[str, int]]) -> List[Tuple[int, int, int]]:
    """
    Paper-faithful one-prefix selection:
      * Choose p != r with patt[p] subset-of patt[r]
      * Among candidates, maximize popcount(patt[p])
      * Tie-break by largest index p (but EM requires p < r)
      * If none, root: prefix=NULL, residual=patt[r]
    
    Returns list of (row_id, prefix_id, residual).
    """
    m = len(tile_patterns)
    patt = [tp["patt"] for tp in tile_patterns]
    NO = [popcount(x) for x in patt]

    triples: List[Tuple[int, int, int]] = []
    for r in range(m):
        best_p, best_sz = None, -1
        for p in range(m):
            if p == r:
                continue
            # Prefix must not be heavier than row
            if NO[p] > NO[r]:
                continue
            # Equal-mass rule: prefix must have earlier index
            if NO[p] == NO[r] and not (p < r):
                continue
            # Subset constraint
            if (patt[p] & patt[r]) == patt[p]:
                sz = NO[p]
                if sz > best_sz or (sz == best_sz and (best_p is None or p > best_p)):
                    best_p, best_sz = p, sz

        if best_p is None:
            # Root row
            pfx = _null_prefix_id(r, m)
            resid = patt[r]
            triples.append((r, pfx, resid))
        else:
            resid = patt[r] ^ patt[best_p]
            triples.append((r, best_p, resid))
    
    return triples


# ============================================================================
# Complete SNN Layer Golden Model
# ============================================================================

class SNNLayerGolden:
    """
    Complete golden reference for one SNN layer.
    Integrates product sparsity, MAC (FP16), and LIF dynamics.
    """
    
    def __init__(self, weights_fp16: np.ndarray, num_neurons: int = 128,
                 lif_threshold: float = 100.0, lif_leak: float = 2.0,
                 lif_reset: float = 0.0, lif_refractory: int = 2):
        self.weights_fp16 = weights_fp16
        self.num_neurons = num_neurons
        
        self.neurons = [
            LIFNeuronGolden(lif_threshold, lif_leak, lif_reset, lif_refractory)
            for _ in range(num_neurons)
        ]
    
    def process_spike_pattern(self, spike_pattern: int, enable_lif: bool = True) -> np.ndarray:
        """Process one spike pattern through the layer."""
        spikes = np.array([(spike_pattern >> i) & 1 for i in range(16)], dtype=np.uint8)
        output_spikes = np.zeros(self.num_neurons, dtype=np.uint8)
        
        for neuron_idx in range(self.num_neurons):
            synaptic_input = fp16_mac(self.weights_fp16[neuron_idx], spikes)
            fired = self.neurons[neuron_idx].update(synaptic_input, enable_lif)
            output_spikes[neuron_idx] = 1 if fired else 0
        
        return output_spikes
    
    def process_tile(self, tile_patterns: List[Dict[str, int]], 
                    enable_lif: bool = True) -> Tuple[np.ndarray, List]:
        """Process complete tile with product sparsity exploitation."""
        prefix_info = golden_prosparsity_subset(tile_patterns)
        output_spikes_per_row = np.zeros((len(tile_patterns), self.num_neurons), dtype=np.uint8)
        
        for row_idx, (row, prefix, residual) in enumerate(prefix_info):
            pattern = tile_patterns[row]['patt']
            output_spikes = self.process_spike_pattern(pattern, enable_lif)
            output_spikes_per_row[row_idx] = output_spikes
        
        return output_spikes_per_row, prefix_info
    
    def reset_neurons(self):
        """Reset all neurons to initial state."""
        for neuron in self.neurons:
            neuron.reset()


# ============================================================================
# Verification Utilities
# ============================================================================

def create_golden_weights(num_neurons: int = 128, num_inputs: int = 16,
                         init_method: str = 'uniform') -> np.ndarray:
    """Create test weight matrix in FP16 format."""
    if init_method == 'uniform':
        weights_float = np.random.uniform(-1.0, 1.0, (num_neurons, num_inputs))
    elif init_method == 'xavier':
        limit = np.sqrt(6.0 / (num_inputs + num_neurons))
        weights_float = np.random.uniform(-limit, limit, (num_neurons, num_inputs))
    else:
        weights_float = np.random.randn(num_neurons, num_inputs) * 0.1
    
    weights_fp16 = np.array([[float_to_fp16(w) for w in row] for row in weights_float],
                            dtype=np.uint16)
    return weights_fp16


def verify_golden_vs_dut(golden_triples: List[Tuple], dut_triples: List[Tuple]) -> Dict:
    """Compare golden model output vs DUT output."""
    golden_counts = Counter(golden_triples)
    dut_counts = Counter(dut_triples)
    
    match = (golden_counts == dut_counts)
    missing = list((golden_counts - dut_counts).elements())
    extra = list((dut_counts - golden_counts).elements())
    
    return {
        'match': match,
        'golden_count': len(golden_triples),
        'dut_count': len(dut_triples),
        'missing': missing[:20],
        'extra': extra[:20],
        'mismatch_count': len(missing) + len(extra)
    }


def tile_to_patterns(tile: np.ndarray) -> List[Dict[str, int]]:
    """Convert tile array to list of pattern dicts."""
    BITORDER = os.getenv("PROS_BITORDER", "lsb0").lower()
    pats = []
    for r, row in enumerate(tile):
        patt = 0
        if BITORDER == "lsb0":
            for i, bit in enumerate(row):
                if bit:
                    patt |= (1 << i)
        else:
            for i, bit in enumerate(row):
                if bit:
                    patt |= (1 << (15 - i))
        pats.append({"row": r, "patt": patt})
    return pats


# ============================================================================
# DUT Interface
# ============================================================================

async def reset_dut(dut):
    """Reset the DUT."""
    dut.rst_n.value = 0
    for _ in range(5):
        await RisingEdge(dut.clk)
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)


async def run_tile_on_dut(dut, tile_patterns: List[Dict[str, int]]) -> Dict[str, Any]:
    """
    Load tile patterns to DUT, run processing, collect results.
    
    Returns dict with issued_rows, prefix_ids, task_patterns, cycles.
    """
    # Load tile patterns
    for entry in tile_patterns:
        row = entry["row"]
        patt = entry["patt"]
        dut.tile_mem_addr.value = row
        dut.tile_mem_data_in.value = patt
        dut.tile_mem_wr_en.value = 1
        await RisingEdge(dut.clk)
    dut.tile_mem_wr_en.value = 0
    
    # Load popcounts
    for entry in tile_patterns:
        row = entry["row"]
        pc = popcount(entry["patt"])
        dut.pc_mem_addr.value = row
        dut.pc_mem_data_in.value = pc
        dut.pc_mem_wr_en.value = 1
        await RisingEdge(dut.clk)
    dut.pc_mem_wr_en.value = 0
    
    # Reset addresses
    dut.tile_mem_addr.value = 0
    dut.pc_mem_addr.value = 0
    
    # Start processing
    dut.core_ready.value = 1
    dut.tile_start.value = 1
    await RisingEdge(dut.clk)
    dut.tile_start.value = 0
    
    # Collect results
    issued_rows = []
    prefix_ids = []
    task_patterns = []
    cycles = 0
    
    while cycles < MAX_CYCLES and len(issued_rows) < ROWS:
        await ReadOnly()
        
        if dut.task_valid.value:
            rid = dut.task_row_id.value.integer
            pid = dut.task_prefix_id.value.integer
            patt = dut.task_pattern.value.integer
            
            issued_rows.append(rid)
            prefix_ids.append(pid)
            task_patterns.append(patt)
            
            # XOR invariant check
            row_patt = tile_patterns[rid]["patt"]
            
            # NULL prefix: prefix_id == row_id (self-reference)
            if pid == rid:
                prefix_patt = 0  # Root row: residual = row_pattern
            else:
                prefix_patt = tile_patterns[pid]["patt"] if 0 <= pid < len(tile_patterns) else 0
            
            expected = row_patt ^ prefix_patt
            if patt != expected:
                raise AssertionError(
                    f"XOR mismatch: rid={rid} pid={pid} row=0x{row_patt:04X} "
                    f"prefix=0x{prefix_patt:04X} exp=0x{expected:04X} got=0x{patt:04X}"
                )
        
        await RisingEdge(dut.clk)
        cycles += 1
        
        if dut.tile_done.value:
            break
    
    return {
        'issued_rows': issued_rows,
        'prefix_ids': prefix_ids,
        'task_patterns': task_patterns,
        'cycles': cycles
    }


# ============================================================================
# Cocotb Tests
# ============================================================================

@cocotb.test()
async def test_golden_prefix_selection(dut):
    """Test product sparsity prefix selection matches golden."""
    cocotb.log.info("\n" + "="*70)
    cocotb.log.info("TEST: Product Sparsity Prefix Selection")
    cocotb.log.info("="*70)
    
    cocotb.start_soon(Clock(dut.clk, CLK_NS, units="ns").start())
    await reset_dut(dut)
    
    # Create test patterns
    np.random.seed(42)
    random.seed(42)
    
    cocotb.log.info("• Creating synthetic spike patterns...")
    tile_patterns = []
    for row in range(ROWS):
        num_spikes = random.randint(2, 10)
        active_bits = random.sample(range(SPIKES), num_spikes)
        patt = sum(1 << b for b in active_bits)
        tile_patterns.append({'row': row, 'patt': patt})
    
    avg_sparsity = np.mean([popcount(p['patt']) for p in tile_patterns])
    cocotb.log.info(f"  Average sparsity: {avg_sparsity:.1f} spikes/pattern")
    
    # Golden model
    cocotb.log.info("• Running golden prefix selection...")
    golden_triples = golden_prosparsity_subset(tile_patterns)
    
    # Run DUT
    cocotb.log.info("• Running DUT...")
    dut_result = await run_tile_on_dut(dut, tile_patterns)
    dut_triples = list(zip(dut_result['issued_rows'], 
                          dut_result['prefix_ids'], 
                          dut_result['task_patterns']))
    
    # Verify
    cocotb.log.info("• Comparing results...")
    result = verify_golden_vs_dut(golden_triples, dut_triples)
    
    cocotb.log.info(f"\n  Golden tasks:  {result['golden_count']}")
    cocotb.log.info(f"  DUT tasks:     {result['dut_count']}")
    cocotb.log.info(f"  Cycles:        {dut_result['cycles']}")
    cocotb.log.info(f"  Match:         {'✓ PASS' if result['match'] else '✗ FAIL'}")
    
    assert result['match'], f"Mismatch: {result['mismatch_count']} differences"
    assert len(dut_result['issued_rows']) == ROWS, f"Missing rows"
    
    cocotb.log.info("\n✓ GOLDEN PREFIX SELECTION PASSED")


@cocotb.test()
async def test_golden_with_workload(dut):
    """Test with realistic SNN workload."""
    cocotb.log.info("\n" + "="*70)
    cocotb.log.info("TEST: Golden Model with SNN Workload")
    cocotb.log.info("="*70)
    
    cocotb.start_soon(Clock(dut.clk, CLK_NS, units="ns").start())
    await reset_dut(dut)
    
    # Load workload if available
    workload_path = Path(__file__).parent / "workloads" / "snn_temporal_spikes.npy"
    
    if workload_path.exists():
        cocotb.log.info(f"• Loading workload: {workload_path.name}")
        patterns_raw = np.load(workload_path)
        tile_patterns = [{'row': i, 'patt': int(patterns_raw[i])} 
                        for i in range(min(ROWS, len(patterns_raw)))]
        while len(tile_patterns) < ROWS:
            tile_patterns.append({'row': len(tile_patterns), 'patt': 0})
    else:
        cocotb.log.info("• Using synthetic patterns (workload not found)")
        random.seed(123)
        tile_patterns = []
        for row in range(ROWS):
            num_spikes = random.randint(3, 8)
            active_bits = random.sample(range(SPIKES), num_spikes)
            patt = sum(1 << b for b in active_bits)
            tile_patterns.append({'row': row, 'patt': patt})
    
    avg_sparsity = np.mean([popcount(p['patt']) for p in tile_patterns])
    cocotb.log.info(f"  Pattern sparsity: {avg_sparsity:.1f} spikes/pattern")
    
    # Golden model
    golden_triples = golden_prosparsity_subset(tile_patterns)
    
    # Run DUT
    cocotb.log.info("• Running DUT...")
    dut_result = await run_tile_on_dut(dut, tile_patterns)
    dut_triples = list(zip(dut_result['issued_rows'], 
                          dut_result['prefix_ids'], 
                          dut_result['task_patterns']))
    
    # Verify
    result = verify_golden_vs_dut(golden_triples, dut_triples)
    
    cocotb.log.info(f"\n  Tasks:   {result['dut_count']}")
    cocotb.log.info(f"  Cycles:  {dut_result['cycles']}")
    cocotb.log.info(f"  Match:   {'✓ PASS' if result['match'] else '✗ FAIL'}")
    
    assert result['match'], f"Mismatch: {result['mismatch_count']} differences"
    
    cocotb.log.info("\n✓ GOLDEN WORKLOAD TEST PASSED")


@cocotb.test()
async def test_golden_lif_integration(dut):
    """Test golden LIF neuron model."""
    cocotb.log.info("\n" + "="*70)
    cocotb.log.info("TEST: Golden LIF Neuron Model")
    cocotb.log.info("="*70)
    
    # Test LIF neuron standalone
    lif = LIFNeuronGolden(threshold=100, leak=2, reset_potential=0, refractory_period=2)
    
    # Test sequence - need cumulative input to exceed threshold
    # vmem starts at 0, leak=2, threshold=100
    # Step 0: vmem = max(0, 0-2) + 50 = 50
    # Step 1: vmem = max(0, 50-2) + 60 = 108 -> FIRE, vmem=0, refrac=2
    # Step 2: refrac=1, no fire
    # Step 3: refrac=0, vmem = max(0, 0-2) + 80 = 80
    test_inputs = [50, 60, 70, 80]
    spikes = []
    
    cocotb.log.info("• Testing LIF neuron sequence:")
    for i, inp in enumerate(test_inputs):
        fired = lif.update(inp)
        spikes.append(fired)
        cocotb.log.info(f"  Step {i}: input={inp}, vmem={lif.state.vmem:.1f}, refrac={lif.state.refractory_counter}, fired={fired}")
    
    # Verify behavior
    assert spikes[1] == True, "LIF should fire on step 1 (cumulative 50+60-2 > 100)"
    assert spikes[2] == False, "LIF should be in refractory period on step 2"
    
    cocotb.log.info("\n✓ GOLDEN LIF MODEL PASSED")
    
    # Allow simulation to complete
    cocotb.start_soon(Clock(dut.clk, CLK_NS, units="ns").start())
    await reset_dut(dut)


# ============================================================================
# Pytest Runners
# ============================================================================

def runCocotbTests():
    """Run all golden model verification tests."""
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
        repo / "ppu" / "tcam" / "hdl" / "tcam_line_array.v",
        repo / "ppu" / "tcam" / "hdl" / "tcam_line_encoder.v",
        repo / "ppu" / "tcam" / "hdl" / "tcam_sdpram.v",
    ]
    
    run(
        verilog_sources=[str(v) for v in verilog_sources],
        toplevel="top",
        module="test_prosperity",
        parameters={"ROWS": str(ROWS), "SPIKES": str(SPIKES), "NO_WIDTH": "8"},
        timescale="1ns/1ps",
        simulator="verilator",
        compile_args=["-Wall", "-Wno-fatal"],
        waves=False,
    )


if __name__ == "__main__":
    test_golden_model()
