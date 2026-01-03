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

> **Targets:**
> 1. **Real FPGA Deployment** — Working prototype on FPGA dev board with host software stack
> 2. **ASIC Tapeout Results** — Synthesis reports from standard cell libraries (e.g., TSMC 28nm, SkyWater 130nm) for area/power/timing characterization

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

### Phase 1 Deliverables (✅ Completed 2025-12-18)

All core neuron/timestep I/O plumbing is merged and exercised by cocotb:

- **LIF neuron engine** — `ppu/lif.v` integrates FP16 LIF dynamics inside `ppu/processor.v`, verified by `tb/test_lif.py` and the LIF suites in `tb/test_processor.py`.
- **Global timestep controller** — `ppu/timestep_ctrl.v` drives multi-timestep sequencing, with coverage in `tb/test_timestep_ctrl.py` and tight integration inside `top.v`.
- **Spike encoder / injector** — Research workloads from `tb/workloads/create_snn_workload.py` feed the hardware injector `ppu/spike_injector.v`, covered by `tb/test_spike_injector.py` and the full pipeline test `tb/test_top.py`.
- **Output spike collector** — `ppu/spike_collector.v` captures per-timestep spikes for host readback; validation lives in `tb/test_spike_collector.py` and `tb/test_top.py`.
- **End-to-end verification** — `tb/test_top.py` observes detector → pruner → dispatcher → processor → LIF → collector while the timestep controller and leak pulses govern multi-timestep execution.

### Phase 2 Deliverables (✅ Completed 2026-01-01)

All memory and host interface components are merged and tested:

- **CSR Register File** — `ppu/csr.v` provides memory-mapped registers for PPU control, LIF configuration, timestep settings, status readback, interrupt handling, and performance counters. Verified by `tb/test_csr.py`.
- **Weight Memory Controller** — `ppu/weight_mem_ctrl.v` implements burst-read interface to external memory with FP16 unpacking (2 weights per 32-bit word). Verified by `tb/test_weight_mem_ctrl.py`.
- **AXI4-Lite Bridge** — `ppu/axi_lite_bridge.v` provides standard AXI4-Lite slave interface for host communication, including CSR access, spike buffer I/O, and weight control. Verified by `tb/test_axi_lite_bridge.py`.

### Upcoming Components (Prioritized)

#### Phase 3 — Scalability & Multi-Tile

| # | Component | Description | Effort |
|---|-----------|-------------|--------|
| 8 | **Multi-Tile Router / NoC stub** | Simple packet-based inter-tile routing for larger networks | High |
| 9 | **Tile Mapper (software)** | Python tool: layer → tile assignment, weight layout generation | Medium |

#### Phase 4 — Verification, Tooling & Deployment

| # | Component | Description | Effort |
|---|-----------|-------------|--------|
| 10 | **End-to-end testbench** | Load an SNN, run N timesteps, compare to golden spikes | Medium |
| 11 | **Performance counters** | Cycle, spike, and stall counters for profiling | Low |
| 12 | **FPGA constraints / build** | Pin mapping, clock constraints for target board (Xilinx/Intel) | Medium |
| 13 | **ASIC synthesis scripts** | Synopsys DC / OpenROAD scripts for area/power/timing reports | Medium |

---

### Suggested Prototype Roadmap

```
Week 1–2: Phase 1 (Neuron + Timestep + I/O)  ← ✅ Completed 2025-12-18
    └── LIF module + timestep FSM (ppu/lif.v, ppu/timestep_ctrl.v)
    └── Spike injector + collector (ppu/spike_{injector,collector}.v)
    └── End-to-end cocotb coverage (`tb/test_top.py`, `tb/test_processor.py`)
    └── Workloads + encoders (`tb/workloads/create_snn_workload.py`)

Week 3:   Phase 2 (Memory + Host)  ← ✅ Completed 2026-01-01
    └── CSR regfile (ppu/csr.v) + AXI-Lite wrapper (ppu/axi_lite_bridge.v)
    └── Weight memory controller (ppu/weight_mem_ctrl.v)
    └── cocotb tests for all Phase 2 modules

Week 4:   Phase 3 (Scaling & Multi-Tile)
    └── Multi-tile loopback test
    └── Simple NoC stub for inter-tile routing
    └── Python tile mapper skeleton

Week 5–6: Phase 4 (Verification & Deployment)
    └── End-to-end SNN testbench (LeNet-5 on MNIST)
    └── Performance counters integration
    └── FPGA build (Xilinx Vivado / Intel Quartus)
    └── ASIC synthesis scripts (Synopsys DC / OpenROAD)
```

---

### Prototype Milestones

| Milestone | Description | Target |
|-----------|-------------|--------|
| **M1: Simulation MVP** | Single-tile LeNet-5 layer runs in Verilator, matches golden output | Week 2 ✅ |
| **M2: Multi-Tile Sim** | Two-tile network with NoC routing passes cocotb tests | Week 4 |
| **M3: FPGA Bringup** | Design runs on FPGA dev board with AXI host control | Week 5 |
| **M4: ASIC Synthesis** | Area/power/timing reports from standard cell library (SkyWater 130nm or TSMC 28nm) | Week 6 |
| **M5: Full Benchmark** | Complete LeNet-5 MNIST inference, publish sparsity speedup vs. dense baseline | Week 6 |

---

### Next Concrete Actions

1. **Create `ppu/weight_mem_ctrl.v`** — burst-friendly SRAM/AXI weight fetcher with FP16 packing and outstanding read scheduling.
2. **Add `ppu/axi_lite_bridge.v` + CSR file** — expose all config knobs (sim start, LIF params, spike buffers) plus status (core_ready, sim_done, counters) to software.
3. **Extend `top.v` host pathway** — integrate the new controller/CSR block so tiles, weights, and spikes load/run without direct RAM pokes.
4. **Add `tb/test_weight_path.py`** — cocotb test that drives CSR writes, DMA weight streaming, and multi-timestep replay against the new interfaces.
5. **Add `tools/mapper.py`** — convert `.npz` / numpy exports into memory images consumable by the DMA/CSR workflow and automated regression tests.

---

## References
- [Prosperity: Accelerating SNNs via Product Sparsity (arXiv:2503.03379)](https://arxiv.org/abs/2503.03379)

## License
(c) 2025. See individual source files for license details.
