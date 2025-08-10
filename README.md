# Prosperity PPU: Product Sparsity Accelerator for SNNs

This repository implements the **Prosperity PPU**—a hardware accelerator for spiking neural networks (SNNs) that exploits **product sparsity** to dramatically reduce computation by reusing shared spike patterns across matrix rows.

## Architecture Overview

- **Pipeline:** Detector → Pruner → Dispatcher → Processor
- **Key Features:**
  - **Product Sparsity:** Identifies and reuses identical or subset spike patterns (prefixes) to avoid redundant MACs.
  - **TCAM-based Detector:** Fast, parallel detection of prefix relationships.
  - **Pruner:** Selects the best prefix for each row and computes the suffix mask.
  - **Dispatcher:** Sorts and issues rows in dependency-safe order (prefix before suffix).
  - **Single-port RAM Interface:** For loading spike tiles from the host.

## File Structure

- `ppu/top.v`         — Top-level PPU module (pipeline controller)
- `ppu/detector.v`    — TCAM-based prefix detector
- `ppu/pruner.v`      — Prefix selection and suffix mask computation
- `ppu/dispatcher.v`  — Sorting and dispatch logic
- `ppu/tcam/hdl/`     — TCAM hardware modules
- `tb/`               — Python cocotb testbenches

## How It Works

1. **Tile Load:** Host loads a tile of spike patterns into the PPU's RAM.
2. **Detection:** For each row, the detector finds all possible prefixes (subsets).
3. **Pruning:** The pruner selects the best prefix (max overlap, lowest index) and computes the suffix mask (bits to compute).
4. **Dispatch:** The dispatcher sorts all rows by popcount and row index, ensuring all prefixes are processed before their suffixes.
5. **Processing:** Only the suffix bits are computed, reusing results from prefixes for maximum efficiency.

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

## Customization
- Change `ROWS`, `SPIKES`, and `NO_WIDTH` parameters in the testbenches or top module for different tile sizes.
- Edit the testbenches in `tb/` to create custom spike patterns or test new scenarios.

## References
- [Prosperity: Accelerating SNNs via Product Sparsity (arXiv:2503.03379)](https://arxiv.org/abs/2503.03379)

## License
(c) 2025. See individual source files for license details.
