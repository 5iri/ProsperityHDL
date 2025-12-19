# Prosperity PPU: Product Sparsity Accelerator for SNNs

> **⚠️ Prototype / Research Implementation**  
> This is an experimental prototype for exploring product sparsity in SNN accelerators. It is intended for research, simulation, and FPGA prototyping—not production deployment.

This repository implements the **Prosperity PPU**—a hardware accelerator for spiking neural networks (SNNs) that exploits **product sparsity** to dramatically reduce computation by reusing shared spike patterns across matrix rows.

## Architecture Overview

- **Pipeline:** Detector → Pruner → Dispatcher → Processor
- **Key Features:**
  - **Product Sparsity:** Identifies and reuses identical or subset spike patterns (prefixes) to avoid redundant MACs.
  - **TCAM-based Detector:** Fast, parallel detection of prefix relationships.
  - **Pruner:** Selects the best prefix for each row and computes the suffix mask.
  - **Dispatcher:** Sorts and issues rows in dependency-safe order (prefix before suffix).
  - **128-PE Processor:** Parallel computation array using IEEE‑754 FP16 weights and FP16 accumulators (full FP16 datapath).
  - **Single-port RAM Interface:** For loading spike tiles from the host.

## File Structure

- `ppu/top.v`         — Top-level PPU module (pipeline controller)
- `ppu/detector.v`    — TCAM-based prefix detector
- `ppu/pruner.v`      — Prefix selection and suffix mask computation
- `ppu/dispatcher.v`  — Sorting and dispatch logic
- `ppu/processor.v`   — 128-PE array for matrix computation
- `ppu/tcam/hdl/`     — TCAM hardware modules
- `tb/`               — Python cocotb testbenches

## How It Works

1. **Tile Load:** Host loads a tile of spike patterns into the PPU's RAM.
2. **Detection:** For each row, the detector finds all possible prefixes (subsets).
3. **Pruning:** The pruner selects the best prefix (max overlap, lowest index) and computes the suffix mask (bits to compute).
4. **Dispatch:** The dispatcher sorts all rows by popcount and row index, ensuring all prefixes are processed before their suffixes.
5. **Processing:** The 128-PE processor array performs matrix computation, reusing prefix results and computing only the suffix bits for maximum efficiency. Each PE uses 8-bit weights with 16-bit accumulators.

## Running Tests

### Prerequisites
- Python 3.8+
- [cocotb](https://cocotb.org/)
- [cocotb-test](https://github.com/themperek/cocotb-test)
- [Verilator](https://www.veripool.org/verilator/)


### Full Pipeline Test

To run a full random pipeline test:

```sh
pytest tb/test_top.py
```

### Testing Suite

Use the provided testing scripts:

```sh
# Run tests with pytest (cocotb)

# Run full test suite
pytest -q

# Run all cocotb tests (tb folder)
pytest tb/ -v

# Run a single test module
pytest tb/test_top.py -v

# Run a single test function
pytest tb/test_processor.py::runCocotbTests -v
```

Notes:
- This repository no longer includes helper shell scripts; use pytest directly to run cocotb tests.
- Recommended: run inside a Python virtual environment and install requirements from requirements.txt.
- To view simulator/cocotb output, run pytest with -s to disable capture (e.g., pytest -s tb/test_top.py).

## Customization
- Change `ROWS`, `SPIKES`, and `NO_WIDTH` parameters in the testbenches or top module for different tile sizes.
- Adjust `PE_COUNT`, `WEIGHT_WIDTH`, and `ACC_WIDTH` parameters for different processor configurations.
- Edit the testbenches in `tb/` to create custom spike patterns or test new scenarios.

## Roadmap: Prototype → Full SNN Accelerator

> **Goal:** Build a working FPGA prototype that can run small SNN benchmarks (e.g., MNIST on LeNet-5 SNN) end-to-end, demonstrating product sparsity benefits.

### Current State (Prototype Core)

| Module | Status |
|--------|--------|
| **Detector** (TCAM subset lookup) | ✅ Implemented |
| **Pruner** (prefix/redundancy elimination) | ✅ Implemented |
| **Dispatcher** (task distribution) | ✅ Implemented |
| **Processor** (128-PE MAC array, FP16 datapath) | ✅ Implemented |
| **Top integration** (FSM, tile RAM, spike injection & timestep control) | ✅ Implemented |

---

### Recent updates (2025-12-18)

This repository was updated and validated on 2025-12-18 (see tests). Key fixes and improvements include:

- Migrated the processor and LIF datapath to full IEEE‑754 FP16 (weights, accumulators, and leak values).
- Fixed multiple timing and pipeline bugs in weight loading so that all weight words (including first and final) are stored correctly.
- Corrected MAC / LIF handshakes (spike_valid timing, mac_accumulate gating) to avoid stale reads and double accumulation.
- Properly handle FP16 subnormals in add/sub helpers (both inputs and results preserved instead of being implicitly normalized or flushed to zero).
- Exposed 16-bit FP16 leak configuration at top-level (cfg_lif_leak) so software can program true FP16 leak values.
- Implemented and validated spike injector mirroring to top-level tile RAM/popcount so multi‑timestep simulation works correctly.
- Fixed timestep controller and injector race conditions by latching timestep indices and coordinating tile_done/inject_done so timesteps advance reliably.

All cocotb tests pass locally after these fixes (10/10).

---


---

### Missing Components (Prioritized)

#### Phase 1 — Core SNN Functionality

| # | Component | Description | Effort |
|---|-----------|-------------|--------|
| 1 | **LIF Neuron Engine** | Per-timestep membrane potential update, threshold, reset, refractory | Medium |
| 2 | **Timestep Controller** | Global timebase; advances simulation across all neurons; sync barrier | Low |
| 3 | **Spike Encoder (Input)** | Rate/Poisson encoding for input data (images, etc.) | Low |
| 4 | **Output Spike Collector** | Collect output spikes per timestep into host-readable buffer | Low |

#### Phase 2 — Memory & Host Interface

| # | Component | Description | Effort |
|---|-----------|-------------|--------|
| 5 | **Weight Memory Controller** | Burst-read interface to on-chip SRAM or external DRAM | Medium |
| 6 | **DMA / AXI-Lite Bridge** | Host ↔ PPU data transfer for tiles, weights, spikes | Medium |
| 7 | **CSR Register File** | Control/status registers for configuration, start/done, debug | Low |

#### Phase 3 — Scalability

| # | Component | Description | Effort |
|---|-----------|-------------|--------|
| 8 | **Multi-Tile Router / NoC stub** | Simple packet-based inter-tile routing for larger networks | High |
| 9 | **Tile Mapper (software)** | Python tool: layer → tile assignment, weight layout generation | Medium |

#### Phase 4 — Learning (Optional / Research)

| # | Component | Description | Effort |
|---|-----------|-------------|--------|
| 10 | **STDP / Weight Update Path** | Spike-timing-dependent plasticity or host-driven weight update | High |

#### Phase 5 — Verification & Tooling

| # | Component | Description | Effort |
|---|-----------|-------------|--------|
| 11 | **End-to-end testbench** | Load an SNN, run N timesteps, compare to golden spikes | Medium |
| 12 | **Performance counters** | Cycle, spike, and stall counters for profiling | Low |
| 13 | **FPGA constraints / build** | Pin mapping, clock constraints for target board | Low |

---

### Suggested Prototype Roadmap

```
Week 1–2: Phase 1 (Neuron + Timestep + I/O)  ← Minimum Viable Prototype
    └── LIF module + timestep FSM
    └── Spike encoder + collector stubs
    └── Basic end-to-end test (single tile, single layer)
    └── Run LeNet-5 MNIST inference in simulation

Week 3:   Phase 2 (Memory + Host)
    └── CSR regfile + AXI-Lite wrapper
    └── Weight memory controller
    └── FPGA bring-up on dev board

Week 4:   Phase 3 (Scaling)
    └── Multi-tile loopback test
    └── Simple NoC stub
    └── Python mapper skeleton

Week 5+:  Phase 4–5 (Learning + Polish)
    └── STDP hooks (optional)
    └── Perf counters, FPGA build, docs
```

---

### Prototype Milestones

| Milestone | Description | Target |
|-----------|-------------|--------|
| **M1: Simulation MVP** | Single-tile LeNet-5 layer runs in Verilator, matches golden output | Week 2 |
| **M2: FPGA Bringup** | Design runs on FPGA dev board with UART/JTAG control | Week 3 |
| **M3: Full Network** | Complete LeNet-5 MNIST inference on FPGA, measure latency/energy | Week 4 |
| **M4: Benchmarking** | Compare vs. dense baseline, publish sparsity speedup numbers | Week 5 |

---

### Next Concrete Actions

1. **Create `ppu/lif.v`** — leaky-integrate-and-fire neuron with threshold & reset.
2. **Create `ppu/timestep_ctrl.v`** — global timestep counter, start/done handshake.
3. **Extend `top.v`** — integrate LIF outputs after Processor writeback; feed spikes back into next timestep.
4. **Add `tb/test_lif.py`** — unit test for neuron dynamics.
5. **Add `tools/mapper.py`** — stub Python script to convert `.npz` tile exports to memory images.

---

## References
- [Prosperity: Accelerating SNNs via Product Sparsity (arXiv:2503.03379)](https://arxiv.org/abs/2503.03379)

## License
(c) 2025. See individual source files for license details.
