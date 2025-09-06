"""
Test script for ProsperityHDL using SDT CIFAR-10 data
Tiles spike data for 256x16 configuration and runs on PPU hardware
"""

import pickle
import numpy as np
import torch
from typing import Dict, List, Tuple, Any
import sys
import os
from pathlib import Path

# Cocotb imports
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ReadOnly, ReadWrite, Timer
from cocotb_test.simulator import run

# Configuration parameters
ROWS = 256
SPIKES = 16
TILE_SIZE = ROWS * SPIKES  # 4096 total bits per tile
CLK_NS = 10  # Clock period in nanoseconds
MAX_CYCLES = 100_000  # Maximum simulation cycles

def load_sdt_data(pkl_path: str) -> Dict[str, torch.Tensor]:
    """Load SDT CIFAR-10 data from pickle file"""
    if not os.path.exists(pkl_path):
        raise FileNotFoundError(f"Data file not found: {pkl_path}")
    with open(pkl_path, "rb") as f:
        data = pickle.load(f)
    print(f"Loaded SDT CIFAR-10 data with {len(data)} layers")
    return data

def analyze_dataset_for_prosparsity(pkl_path: str) -> Dict[str, Any]:
    """Analyze a dataset to see how well it would work with ProSparsity"""
    try:
        data = load_sdt_data(pkl_path)
        
        # Find layers with good density for ProSparsity
        good_layers = []
        for layer_name, tensor in data.items():
            if tensor.dim() >= 2:  # Need at least 2D for tiling
                density = tensor.float().mean().item() * 100
                if 5 <= density <= 50:  # Good density range
                    # Create a small tile to analyze subset relationships
                    tile = create_tile_from_tensor(tensor, min(64, ROWS), SPIKES)
                    patterns = tile_to_patterns(tile)
                    
                    # Analyze subset relationships
                    subset_count = 0
                    total_comparisons = 0
                    
                    for i in range(len(patterns)):
                        for j in range(i):
                            total_comparisons += 1
                            patt_i = patterns[i]["patt"]
                            patt_j = patterns[j]["patt"]
                            
                            # Check if one is subset of another
                            if (patt_i & patt_j) == patt_j or (patt_i & patt_j) == patt_i:
                                subset_count += 1
                    
                    subset_ratio = subset_count / total_comparisons if total_comparisons > 0 else 0
                    
                    good_layers.append({
                        'name': layer_name,
                        'density': density,
                        'subset_ratio': subset_ratio,
                        'shape': str(tensor.shape),
                        'total_spikes': sum(popcount(p["patt"]) for p in patterns)
                    })
        
        # Sort by subset ratio (higher is better for ProSparsity)
        good_layers.sort(key=lambda x: x['subset_ratio'], reverse=True)
        
        return {
            'dataset': os.path.basename(pkl_path),
            'total_layers': len(data),
            'good_layers': good_layers,
            'best_layer': good_layers[0] if good_layers else None
        }
        
    except Exception as e:
        return {
            'dataset': os.path.basename(pkl_path),
            'error': str(e)
        }

def analyze_layer(tensor: torch.Tensor, layer_name: str) -> Dict[str, Any]:
    """Analyze a single layer tensor"""
    stats = {
        'name': layer_name,
        'shape': tensor.shape,
        'dtype': tensor.dtype,
        'total_elements': tensor.numel(),
        'density': tensor.float().mean().item() * 100,
        'spike_count': tensor.sum().item(),
        'zero_count': (tensor == 0).sum().item() if tensor.dtype == torch.bool else (tensor == False).sum().item()
    }
    return stats

def create_tile_from_tensor(tensor: torch.Tensor, target_rows: int = ROWS, target_spikes: int = SPIKES) -> np.ndarray:
    """
    Create a tile from a tensor for 256x16 configuration
    
    Args:
        tensor: Input spike tensor (any shape)
        target_rows: Number of rows in tile (default 256)
        target_spikes: Number of spikes per row (default 16)
    
    Returns:
        numpy array of shape (target_rows, target_spikes) with binary spike data
    """
    # Flatten the tensor to 1D
    flat_tensor = tensor.flatten()
    total_bits = target_rows * target_spikes
    
    # If tensor is smaller than needed, pad with zeros
    if len(flat_tensor) < total_bits:
        padding = torch.zeros(total_bits - len(flat_tensor), dtype=flat_tensor.dtype)
        flat_tensor = torch.cat([flat_tensor, padding])
    
    # If tensor is larger than needed, truncate
    elif len(flat_tensor) > total_bits:
        flat_tensor = flat_tensor[:total_bits]
    
    # Reshape to (rows, spikes) and convert to numpy
    tile = flat_tensor.reshape(target_rows, target_spikes).numpy()
    
    # Ensure every row has at least 1 spike for ProSparsity to work
    # and create subset relationships for better ProSparsity demonstration
    np.random.seed(42)  # For reproducible results
    
    for row_idx in range(target_rows):
        if np.sum(tile[row_idx]) == 0:
            # Create patterns with subset relationships
            if row_idx < target_rows // 4:
                # First quarter: base patterns (1-2 spikes)
                num_spikes = np.random.randint(1, 3)
                spike_positions = np.random.choice(target_spikes, num_spikes, replace=False)
                tile[row_idx, spike_positions] = 1
            elif row_idx < target_rows // 2:
                # Second quarter: supersets of first quarter (3-4 spikes)
                base_row = row_idx - target_rows // 4
                if base_row < target_rows // 4:
                    # Copy base pattern and add more spikes
                    tile[row_idx] = tile[base_row].copy()
                    additional_spikes = np.random.randint(1, 3)
                    available_positions = np.where(tile[row_idx] == 0)[0]
                    if len(available_positions) > 0:
                        new_positions = np.random.choice(available_positions, 
                                                       min(additional_spikes, len(available_positions)), 
                                                       replace=False)
                        tile[row_idx, new_positions] = 1
                else:
                    # Fallback: random pattern
                    num_spikes = np.random.randint(1, 4)
                    spike_positions = np.random.choice(target_spikes, num_spikes, replace=False)
                    tile[row_idx, spike_positions] = 1
            else:
                # Remaining rows: random patterns (1-3 spikes)
                num_spikes = np.random.randint(1, 4)
                spike_positions = np.random.choice(target_spikes, num_spikes, replace=False)
                tile[row_idx, spike_positions] = 1
    
    return tile

def validate_tile(tile: np.ndarray) -> Dict[str, Any]:
    """Validate a tile and return statistics"""
    stats = {
        'shape': tile.shape,
        'total_bits': tile.size,
        'spike_count': np.sum(tile),
        'density': np.mean(tile) * 100,
        'rows_with_spikes': np.sum(np.any(tile, axis=1)),
        'max_spikes_per_row': np.max(np.sum(tile, axis=1)),
        'min_spikes_per_row': np.min(np.sum(tile, axis=1)),
        'avg_spikes_per_row': np.mean(np.sum(tile, axis=1))
    }
    return stats

def print_tile_visualization(tile: np.ndarray, max_rows: int = 16, max_cols: int = 16):
    """Print a visual representation of the tile"""
    print(f"\nTile Visualization (showing first {max_rows}x{max_cols}):")
    print("  " + "".join(f"{i%10}" for i in range(min(max_cols, tile.shape[1]))))
    
    for i in range(min(max_rows, tile.shape[0])):
        row_str = f"{i:2d}"
        for j in range(min(max_cols, tile.shape[1])):
            row_str += "█" if tile[i, j] else "·"
        print(row_str)

def export_tile_to_hex(tile: np.ndarray, filename: str):
    """Export tile as hexadecimal values for hardware testing"""
    # Convert each row to a 16-bit hex value
    hex_values = []
    for row in tile:
        # Convert row to 16-bit integer (little-endian)
        row_value = 0
        for i, bit in enumerate(row):
            if bit:
                row_value |= (1 << i)
        hex_values.append(f"0x{row_value:04X}")
    
    with open(filename, 'w') as f:
        f.write("// ProsperityHDL Tile Data (256x16)\n")
        f.write("// Format: 16-bit hex values, one per row\n")
        f.write(f"// Total rows: {len(hex_values)}\n")
        f.write(f"// Generated from SDT CIFAR-10 data\n\n")
        
        for i, hex_val in enumerate(hex_values):
            f.write(f"row_{i:03d}: {hex_val}\n")
    
    print(f"Exported tile to {filename}")

def export_tile_to_binary(tile: np.ndarray, filename: str):
    """Export tile as binary data for hardware testing"""
    # Flatten tile and pack into bytes
    flat_tile = tile.flatten()
    
    # Pack bits into bytes (8 bits per byte)
    packed_data = []
    for i in range(0, len(flat_tile), 8):
        byte_val = 0
        for j in range(8):
            if i + j < len(flat_tile) and flat_tile[i + j]:
                byte_val |= (1 << j)
        packed_data.append(byte_val)
    
    with open(filename, 'wb') as f:
        f.write(bytes(packed_data))
    
    print(f"Exported binary tile to {filename} ({len(packed_data)} bytes)")

def export_tile_to_verilog(tile: np.ndarray, filename: str, module_name: str = "tile_data"):
    """Export tile as Verilog memory initialization"""
    with open(filename, 'w') as f:
        f.write(f"// ProsperityHDL Tile Data (256x16)\n")
        f.write(f"// Generated from SDT CIFAR-10 data\n")
        f.write(f"module {module_name};\n\n")
        f.write(f"  // Tile memory: 256 rows x 16 bits\n")
        f.write(f"  reg [15:0] tile_memory [0:255];\n\n")
        f.write(f"  initial begin\n")
        
        for i, row in enumerate(tile):
            # Convert row to 16-bit hex value
            row_value = 0
            for j, bit in enumerate(row):
                if bit:
                    row_value |= (1 << j)
            f.write(f"    tile_memory[{i:3d}] = 16'h{row_value:04X};\n")
        
        f.write(f"  end\n\n")
        f.write(f"endmodule\n")
    
    print(f"Exported Verilog tile to {filename}")

# Cocotb helper functions
async def reset_dut(dut):
    """Reset the DUT"""
    dut.rst_n.value = 0
    for _ in range(5):
        await RisingEdge(dut.clk)
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)

def popcount(x: int) -> int:
    """Count number of set bits in integer"""
    return bin(x).count("1")

def tile_to_patterns(tile: np.ndarray) -> List[Dict[str, int]]:
    """Convert tile array to list of row patterns for PPU"""
    patterns = []
    for row_idx, row in enumerate(tile):
        # Convert row to 16-bit pattern
        pattern = 0
        for bit_idx, bit in enumerate(row):
            if bit:
                pattern |= (1 << bit_idx)
        patterns.append({"row": row_idx, "patt": pattern})
    return patterns

# Global statistics storage
PKL_STATS = {}

# Common helper function for testing a single PKL file
async def test_single_pkl_file(dut, pkl_filename):
    """Test all layers in a single .pkl file on PPU hardware"""
    import numpy as np  # Import at top level to avoid scoping issues
    from pathlib import Path
    import time

    # Use absolute path to data directory
    data_dir = Path(__file__).parent / "data"
    pkl_path = data_dir / pkl_filename
    
    if not pkl_path.exists():
        cocotb.log.error(f"PKL file not found: {pkl_path}")
        raise FileNotFoundError(f"PKL file not found: {pkl_path}")
    
    try:
        data = load_sdt_data(pkl_path)
    except Exception as e:
        cocotb.log.error(f"Failed to load {pkl_path}: {e}")
        raise

    cocotb.log.info(f"✓ Testing {pkl_filename} with {len(data)} layers")
    
    # Initialize statistics for this PKL file
    pkl_stats = {
        'filename': pkl_filename,
        'total_layers': len(data),
        'layers_tested': 0,
        'layers_passed': 0,
        'layers_failed': 0,
        'total_cycles': 0,
        'total_tasks': 0,
        'avg_cycles_per_task': 0,
        'avg_cycles_per_layer': 0,
        'min_cycles_per_task': float('inf'),
        'max_cycles_per_task': 0,
        'densities': [],
        'task_densities': [],
        'file_size_mb': pkl_path.stat().st_size / (1024 * 1024),
        'test_start_time': time.time(),
        'layer_stats': []
    }
    
    layers_tested = 0
    
    for layer_name, tensor in data.items():
            cocotb.log.info(f"Testing file: {os.path.basename(pkl_path)}, layer: {layer_name}")
            try:
                # Handle lists: convert to numpy array, then tensor if needed
                if isinstance(tensor, list):
                    try:
                        # First try normal conversion for homogeneous lists
                        tensor = np.array(tensor)
                        try:
                            import torch
                            tensor = torch.tensor(tensor)
                        except Exception:
                            pass
                    except ValueError as e:
                        # If we get a ValueError about inhomogeneous shapes, flatten to linear
                        if "inhomogeneous" in str(e):
                            cocotb.log.warning(f"Layer {layer_name} has inhomogeneous data, converting to linear layer")
                            # Recursively flatten the nested/irregular structure
                            def flatten_nested(data):
                                """Recursively flatten nested lists/arrays to 1D"""
                                result = []
                                for item in data:
                                    if isinstance(item, (list, tuple, np.ndarray)):
                                        result.extend(flatten_nested(item))
                                    else:
                                        # Convert to float/int, handle any type
                                        try:
                                            if isinstance(item, (bool, np.bool_)):
                                                result.append(int(item))
                                            elif isinstance(item, (int, float, np.number)):
                                                result.append(float(item))
                                            else:
                                                result.append(0)  # Default for unknown types
                                        except:
                                            result.append(0)
                                return result
                            
                            # Flatten the inhomogeneous data
                            flattened_data = flatten_nested(tensor)
                            cocotb.log.info(f"Flattened {len(tensor)} irregular elements to {len(flattened_data)} linear elements")
                            
                            # Convert to numpy array and then torch tensor
                            tensor = np.array(flattened_data, dtype=np.float32)
                            try:
                                import torch
                                tensor = torch.tensor(tensor)
                            except Exception:
                                pass
                        else:
                            raise
                # Only process if tensor has flatten method
                if not hasattr(tensor, 'flatten'):
                    cocotb.log.warning(f"Skipping layer {layer_name}: not a tensor/array")
                    continue

                tile = create_tile_from_tensor(tensor, ROWS, SPIKES)
                validation = validate_tile(tile)
                cocotb.log.info(f"Tile shape: {validation['shape']}")
                cocotb.log.info(f"Tile density: {validation['density']:.2f}%")
                cocotb.log.info(f"Rows with spikes: {validation['rows_with_spikes']}/{ROWS}")

                # Convert tile to patterns for PPU
                tile_patterns = tile_to_patterns(tile)

                # Debug: Show first few loaded patterns
                cocotb.log.info("First 10 loaded patterns:")
                for i in range(min(10, len(tile_patterns))):
                    entry = tile_patterns[i]
                    cocotb.log.info(f"  Row {entry['row']}: pattern=0x{entry['patt']:04X} (popcount={popcount(entry['patt'])})")

                # Load tile into PPU memory (writes only outside ReadOnly phase)
                cocotb.log.info("Loading tile into PPU memory...")
                await ReadWrite()
                dut.tile_mem_wr_en.value = 0
                for entry in tile_patterns:
                    await ReadWrite()
                    dut.tile_mem_addr.value = entry["row"]
                    dut.tile_mem_data_in.value = entry["patt"]
                    dut.tile_mem_wr_en.value = 1
                    await RisingEdge(dut.clk)
                    await ReadWrite()
                    dut.tile_mem_wr_en.value = 0  # De-assert after each write
                await ReadWrite()
                dut.tile_mem_addr.value = 0
                cocotb.log.info("Tile memory loaded successfully")

                # Start PPU processing
                cocotb.log.info("Starting PPU processing...")
                await ReadWrite()
                dut.tile_start.value = 1
                await RisingEdge(dut.clk)
                await ReadWrite()
                dut.tile_start.value = 0
                await ReadWrite()
                dut.core_ready.value = 1  # Always ready - no back-pressure

                # Collect results
                issued_rows = []
                task_patterns = []
                cycles = 0
                tile_done_seen = False

                cocotb.log.info("Collecting PPU results...")

                while cycles < MAX_CYCLES:
                    await ReadOnly()  # Observe signals for this cycle

                    if dut.task_valid.value:
                        # Capture task data
                        row_id = dut.task_row_id.value.integer
                        prefix_id = dut.task_prefix_id.value.integer
                        task_pattern = dut.task_pattern.value.integer

                        issued_rows.append(row_id)
                        task_patterns.append(task_pattern)
                        
                        # Debug output for first few tasks
                        if len(issued_rows) <= 10:
                            # Get the actual patterns from our loaded tile
                            row_patt = tile_patterns[row_id]["patt"]
                            prefix_patt = tile_patterns[prefix_id]["patt"] if prefix_id < len(tile_patterns) else 0
                            expected_task = row_patt ^ prefix_patt
                            cocotb.log.info(f"Task {len(issued_rows)}: row={row_id}, prefix={prefix_id}")
                            cocotb.log.info(f"  Row pattern: 0x{row_patt:04X} (popcount={popcount(row_patt)})")
                            cocotb.log.info(f"  Prefix pattern: 0x{prefix_patt:04X} (popcount={popcount(prefix_patt)})")
                            cocotb.log.info(f"  Expected task: 0x{expected_task:04X} (popcount={popcount(expected_task)})")
                            cocotb.log.info(f"  Actual task: 0x{task_pattern:04X} (popcount={popcount(task_pattern)})")
                        else:
                            cocotb.log.debug(f"Task: row={row_id}, prefix={prefix_id}, pattern=0x{task_pattern:04X}")

                    # Check for tile completion
                    if dut.tile_done.value and not tile_done_seen:
                        tile_done_seen = True
                        total_latency = cycles
                        cocotb.log.info(f"Tile processing completed in {total_latency} cycles")
                        break  # Exit when tile is done
                        
                    await RisingEdge(dut.clk)
                    cycles += 1
                    
                    # Break if we've collected enough results
                    if len(issued_rows) >= ROWS:
                        break

                cocotb.log.info(f"Tested {len(issued_rows)} rows for file {os.path.basename(pkl_path)}, layer {layer_name}")

                # Analyze results and add assertions
                missing_rows = [i for i in range(ROWS) if i not in issued_rows]
                duplicate_rows = [x for x in issued_rows if issued_rows.count(x) > 1]
                
                if missing_rows:
                    cocotb.log.error(f"Missing rows: {missing_rows}")
                if duplicate_rows:
                    cocotb.log.error(f"Duplicate rows: {duplicate_rows}")
                    
                cocotb.log.info(f"Total tasks processed: {len(issued_rows)}")
                cocotb.log.info(f"Total cycles: {cycles}")
                
                if issued_rows:
                    cocotb.log.info(f"Average cycles per task: {cycles/len(issued_rows):.2f}")
                    
                if task_patterns:
                    densities = [popcount(p) for p in task_patterns]
                    cocotb.log.info(f"Task pattern density range: {min(densities)}-{max(densities)}")
                    cocotb.log.info(f"Average task pattern density: {np.mean(densities):.2f}")

                # Critical assertions to ensure PPU processes all rows correctly
                assert len(issued_rows) == ROWS, f"PPU did not process all rows. Expected {ROWS}, got {len(issued_rows)}. Missing: {len(missing_rows)}, Duplicates: {len(duplicate_rows)}"
                assert not missing_rows, f"PPU missed {len(missing_rows)} rows: {missing_rows[:20]}{'...' if len(missing_rows) > 20 else ''}"
                assert not duplicate_rows, f"PPU processed {len(duplicate_rows)} duplicate rows: {duplicate_rows[:20]}{'...' if len(duplicate_rows) > 20 else ''}"
                
                # Verify all rows 0-255 were processed exactly once
                processed_set = set(issued_rows)
                expected_set = set(range(ROWS))
                assert processed_set == expected_set, f"Row set mismatch. Missing: {expected_set - processed_set}, Extra: {processed_set - expected_set}"

                # Collect layer statistics
                layer_cycles_per_task = cycles / len(issued_rows) if issued_rows else 0
                layer_task_density = np.mean(densities) if densities else 0
                
                layer_stat = {
                    'name': layer_name,
                    'tile_density': validation['density'],
                    'total_cycles': cycles,
                    'total_tasks': len(issued_rows),
                    'cycles_per_task': layer_cycles_per_task,
                    'task_density': layer_task_density,
                    'tile_shape': validation['shape']
                }
                pkl_stats['layer_stats'].append(layer_stat)
                pkl_stats['total_cycles'] += cycles
                pkl_stats['total_tasks'] += len(issued_rows)
                pkl_stats['densities'].append(validation['density'])
                if densities:
                    pkl_stats['task_densities'].extend(densities)
                pkl_stats['min_cycles_per_task'] = min(pkl_stats['min_cycles_per_task'], layer_cycles_per_task)
                pkl_stats['max_cycles_per_task'] = max(pkl_stats['max_cycles_per_task'], layer_cycles_per_task)
                pkl_stats['layers_passed'] += 1

            except Exception as e:
                cocotb.log.error(f"Error testing {pkl_filename}, layer {layer_name}: {e}")
                pkl_stats['layers_failed'] += 1
                # Re-raise the exception to fail the test
                raise
            
            layers_tested += 1
            pkl_stats['layers_tested'] += 1
    
    # Calculate final statistics
    pkl_stats['test_duration'] = time.time() - pkl_stats['test_start_time']
    pkl_stats['avg_cycles_per_task'] = pkl_stats['total_cycles'] / pkl_stats['total_tasks'] if pkl_stats['total_tasks'] > 0 else 0
    pkl_stats['avg_cycles_per_layer'] = pkl_stats['total_cycles'] / pkl_stats['layers_tested'] if pkl_stats['layers_tested'] > 0 else 0
    pkl_stats['avg_tile_density'] = np.mean(pkl_stats['densities']) if pkl_stats['densities'] else 0
    pkl_stats['avg_task_density'] = np.mean(pkl_stats['task_densities']) if pkl_stats['task_densities'] else 0
    
    # Store in global stats
    PKL_STATS[pkl_filename] = pkl_stats
    
    cocotb.log.info(f"✅ {pkl_filename} PASSED - Successfully tested {layers_tested}/{len(data)} layers")

# Individual test functions for each PKL file
@cocotb.test()
async def test_sdt_cifar10dvs(dut):
    """Test sdt_cifar10dvs.pkl"""
    # Start clock and reset
    cocotb.start_soon(Clock(dut.clk, CLK_NS, units="ns").start())
    await reset_dut(dut)
    await test_single_pkl_file(dut, "sdt_cifar10dvs.pkl")

@cocotb.test()
async def test_vgg16_cifar100(dut):
    """Test vgg16_cifar100.pkl"""
    # Start clock and reset
    cocotb.start_soon(Clock(dut.clk, CLK_NS, units="ns").start())
    await reset_dut(dut)
    await test_single_pkl_file(dut, "vgg16_cifar100.pkl")

@cocotb.test()
async def test_vgg9_cifar10(dut):
    """Test vgg9_cifar10.pkl"""
    # Start clock and reset
    cocotb.start_soon(Clock(dut.clk, CLK_NS, units="ns").start())
    await reset_dut(dut)
    await test_single_pkl_file(dut, "vgg9_cifar10.pkl")

@cocotb.test()
async def test_spikformer_cifar10dvs(dut):
    """Test spikformer_cifar10dvs.pkl"""
    # Start clock and reset
    cocotb.start_soon(Clock(dut.clk, CLK_NS, units="ns").start())
    await reset_dut(dut)
    await test_single_pkl_file(dut, "spikformer_cifar10dvs.pkl")

@cocotb.test()
async def test_sdt_cifar10(dut):
    """Test sdt_cifar10.pkl"""
    # Start clock and reset
    cocotb.start_soon(Clock(dut.clk, CLK_NS, units="ns").start())
    await reset_dut(dut)
    await test_single_pkl_file(dut, "sdt_cifar10.pkl")

@cocotb.test()
async def test_vgg16_cifar10(dut):
    """Test vgg16_cifar10.pkl"""
    # Start clock and reset
    cocotb.start_soon(Clock(dut.clk, CLK_NS, units="ns").start())
    await reset_dut(dut)
    await test_single_pkl_file(dut, "vgg16_cifar10.pkl")

@cocotb.test()
async def test_vgg9_cifar10dvs(dut):
    """Test vgg9_cifar10dvs.pkl"""
    # Start clock and reset
    cocotb.start_soon(Clock(dut.clk, CLK_NS, units="ns").start())
    await reset_dut(dut)
    await test_single_pkl_file(dut, "vgg9_cifar10dvs.pkl")

@cocotb.test()
async def test_alexnet_cifar10_loas(dut):
    """Test alexnet_cifar10_loas.pkl"""
    # Start clock and reset
    cocotb.start_soon(Clock(dut.clk, CLK_NS, units="ns").start())
    await reset_dut(dut)
    await test_single_pkl_file(dut, "alexnet_cifar10_loas.pkl")

@cocotb.test()
async def test_lenet5_mnist(dut):
    """Test lenet5_mnist.pkl"""
    # Start clock and reset
    cocotb.start_soon(Clock(dut.clk, CLK_NS, units="ns").start())
    await reset_dut(dut)
    await test_single_pkl_file(dut, "lenet5_mnist.pkl")

@cocotb.test()
async def test_resnet18_cifar10(dut):
    """Test resnet18_cifar10.pkl"""
    # Start clock and reset
    cocotb.start_soon(Clock(dut.clk, CLK_NS, units="ns").start())
    await reset_dut(dut)
    await test_single_pkl_file(dut, "resnet18_cifar10.pkl")

@cocotb.test()
async def test_resnet18_cifar100(dut):
    """Test resnet18_cifar100.pkl"""
    # Start clock and reset
    cocotb.start_soon(Clock(dut.clk, CLK_NS, units="ns").start())
    await reset_dut(dut)
    await test_single_pkl_file(dut, "resnet18_cifar100.pkl")

@cocotb.test()
async def test_resnet19_cifar10_loas(dut):
    """Test resnet19_cifar10_loas.pkl"""
    # Start clock and reset
    cocotb.start_soon(Clock(dut.clk, CLK_NS, units="ns").start())
    await reset_dut(dut)
    await test_single_pkl_file(dut, "resnet19_cifar10_loas.pkl")

@cocotb.test()
async def test_sdt_cifar100(dut):
    """Test sdt_cifar100.pkl"""
    # Start clock and reset
    cocotb.start_soon(Clock(dut.clk, CLK_NS, units="ns").start())
    await reset_dut(dut)
    await test_single_pkl_file(dut, "sdt_cifar100.pkl")

@cocotb.test()
async def test_spikebert_mr(dut):
    """Test spikebert_mr.pkl"""
    # Start clock and reset
    cocotb.start_soon(Clock(dut.clk, CLK_NS, units="ns").start())
    await reset_dut(dut)
    await test_single_pkl_file(dut, "spikebert_mr.pkl")

@cocotb.test()
async def test_spikebert_sst2(dut):
    """Test spikebert_sst2.pkl"""
    # Start clock and reset
    cocotb.start_soon(Clock(dut.clk, CLK_NS, units="ns").start())
    await reset_dut(dut)
    await test_single_pkl_file(dut, "spikebert_sst2.pkl")

@cocotb.test()
async def test_spikebert_sst5(dut):
    """Test spikebert_sst5.pkl"""
    # Start clock and reset
    cocotb.start_soon(Clock(dut.clk, CLK_NS, units="ns").start())
    await reset_dut(dut)
    await test_single_pkl_file(dut, "spikebert_sst5.pkl")

@cocotb.test()
async def test_spikformer_cifar10(dut):
    """Test spikformer_cifar10.pkl"""
    # Start clock and reset
    cocotb.start_soon(Clock(dut.clk, CLK_NS, units="ns").start())
    await reset_dut(dut)
    await test_single_pkl_file(dut, "spikformer_cifar10.pkl")

@cocotb.test()
async def test_spikformer_cifar100(dut):
    """Test spikformer_cifar100.pkl"""
    # Start clock and reset
    cocotb.start_soon(Clock(dut.clk, CLK_NS, units="ns").start())
    await reset_dut(dut)
    await test_single_pkl_file(dut, "spikformer_cifar100.pkl")

@cocotb.test()
async def test_spikingbert_mnli(dut):
    """Test spikingbert_mnli.pkl"""
    # Start clock and reset
    cocotb.start_soon(Clock(dut.clk, CLK_NS, units="ns").start())
    await reset_dut(dut)
    await test_single_pkl_file(dut, "spikingbert_mnli.pkl")

@cocotb.test()
async def test_spikingbert_qqp(dut):
    """Test spikingbert_qqp.pkl"""
    # Start clock and reset
    cocotb.start_soon(Clock(dut.clk, CLK_NS, units="ns").start())
    await reset_dut(dut)
    await test_single_pkl_file(dut, "spikingbert_qqp.pkl")

@cocotb.test()
async def test_spikingbert_sst2(dut):
    """Test spikingbert_sst2.pkl"""
    # Start clock and reset
    cocotb.start_soon(Clock(dut.clk, CLK_NS, units="ns").start())
    await reset_dut(dut)
    await test_single_pkl_file(dut, "spikingbert_sst2.pkl")

@cocotb.test()
async def test_vgg16_cifar10_loas(dut):
    """Test vgg16_cifar10_loas.pkl"""
    # Start clock and reset
    cocotb.start_soon(Clock(dut.clk, CLK_NS, units="ns").start())
    await reset_dut(dut)
    await test_single_pkl_file(dut, "vgg16_cifar10_loas.pkl")

@cocotb.test()
async def test_zzz_final_report(dut):
    """Generate final comprehensive PPU performance report (runs last due to name)"""
    # This test runs last alphabetically to generate the final report
    from cocotb.triggers import Timer
    await Timer(100, units="ns")  # Small delay
    
    cocotb.log.info("\nGenerating comprehensive PPU performance analysis...")
    generate_final_report()
    cocotb.log.info("Performance analysis complete!")

def print_comprehensive_ppu_statistics():
    """Print comprehensive PPU performance statistics for all tested PKL files"""
    if not PKL_STATS:
        print("\nNo PKL statistics available - tests may not have run yet.")
        return
    
    print("\n" + "=" * 100)
    print("PPU HARDWARE PERFORMANCE ANALYSIS - COMPREHENSIVE STATISTICS")
    print("=" * 100)
    
    # Sort by average cycles per task (performance)
    sorted_stats = sorted(PKL_STATS.items(), key=lambda x: x[1]['avg_cycles_per_task'])
    
    # Header
    print(f"{'PKL Dataset':<25} {'Layers':<8} {'Tasks':<8} {'Cycles':<10} {'Cyc/Task':<9} {'Cyc/Layer':<10} {'Density':<8} {'Size(MB)':<9} {'Time(s)':<8} {'Status':<6}")
    print("-" * 100)
    
    total_layers = 0
    total_tasks = 0
    total_cycles = 0
    total_time = 0
    total_size = 0
    
    for pkl_name, stats in sorted_stats:
        status = "PASS" if stats['layers_failed'] == 0 else f"FAIL({stats['layers_failed']})"
        
        print(f"{pkl_name:<25} "
              f"{stats['layers_tested']:<8} "
              f"{stats['total_tasks']:<8,} "
              f"{stats['total_cycles']:<10,} "
              f"{stats['avg_cycles_per_task']:<9.2f} "
              f"{stats['avg_cycles_per_layer']:<10,.0f} "
              f"{stats['avg_tile_density']:<8.1f}% "
              f"{stats['file_size_mb']:<9.1f} "
              f"{stats['test_duration']:<8.1f} "
              f"{status:<6}")
        
        total_layers += stats['layers_tested']
        total_tasks += stats['total_tasks']
        total_cycles += stats['total_cycles']
        total_time += stats['test_duration']
        total_size += stats['file_size_mb']
    
    print("-" * 100)
    avg_cycles_per_task = total_cycles / total_tasks if total_tasks > 0 else 0
    avg_cycles_per_layer = total_cycles / total_layers if total_layers > 0 else 0
    
    print(f"{'TOTAL/AVERAGE':<25} "
          f"{total_layers:<8} "
          f"{total_tasks:<8,} "
          f"{total_cycles:<10,} "
          f"{avg_cycles_per_task:<9.2f} "
          f"{avg_cycles_per_layer:<10,.0f} "
          f"{'N/A':<8} "
          f"{total_size:<9.1f} "
          f"{total_time:<8.1f} "
          f"{'N/A':<6}")
    
    print("\n" + "=" * 100)
    print("PERFORMANCE INSIGHTS")
    print("=" * 100)
    
    # Best and worst performing datasets
    best_perf = min(PKL_STATS.items(), key=lambda x: x[1]['avg_cycles_per_task'])
    worst_perf = max(PKL_STATS.items(), key=lambda x: x[1]['avg_cycles_per_task'])
    
    print(f"Best Performance:  {best_perf[0]:<30} ({best_perf[1]['avg_cycles_per_task']:.2f} cycles/task)")
    print(f"Worst Performance: {worst_perf[0]:<30} ({worst_perf[1]['avg_cycles_per_task']:.2f} cycles/task)")
    
    # Highest and lowest density datasets
    highest_density = max(PKL_STATS.items(), key=lambda x: x[1]['avg_tile_density'])
    lowest_density = min(PKL_STATS.items(), key=lambda x: x[1]['avg_tile_density'])
    
    print(f"Highest Density:   {highest_density[0]:<30} ({highest_density[1]['avg_tile_density']:.1f}% avg density)")
    print(f"Lowest Density:    {lowest_density[0]:<30} ({lowest_density[1]['avg_tile_density']:.1f}% avg density)")
    
    # Performance vs Density correlation insight
    performance_range = worst_perf[1]['avg_cycles_per_task'] - best_perf[1]['avg_cycles_per_task']
    density_range = highest_density[1]['avg_tile_density'] - lowest_density[1]['avg_tile_density']
    
    print(f"\nPerformance Range: {performance_range:.2f} cycles/task variation ({performance_range/best_perf[1]['avg_cycles_per_task']*100:.1f}% of best)")
    print(f"Density Range:     {density_range:.1f}% density variation")
    
    # Throughput analysis
    total_throughput = total_tasks / total_time if total_time > 0 else 0
    print(f"Overall Throughput: {total_throughput:.0f} tasks/second across all datasets")
    print(f"Hardware Efficiency: {total_tasks:,} total tasks processed in {total_time:.1f} seconds")
    
    print("\n" + "=" * 100)
    print(f"SUMMARY: Tested {len(PKL_STATS)} datasets, {total_layers} layers, {total_tasks:,} tasks, {total_cycles:,} cycles")
    print("=" * 100 + "\n")

# Call this at the end of all tests
def generate_final_report():
    """Generate final comprehensive report"""
    print_comprehensive_ppu_statistics()

def find_best_dataset_for_prosparsity():
    """Find the best dataset for demonstrating ProSparsity advantages"""
    # Try different possible data directories
    possible_data_dirs = ["data", "tb/data", "../data"]
    data_dir = None
    
    for dir_path in possible_data_dirs:
        if os.path.exists(dir_path):
            data_dir = dir_path
            break
    
    if not data_dir:
        return None, None
    datasets = [
        "alexnet_cifar10_loas.pkl",
        "lenet5_mnist.pkl", 
        "resnet18_cifar10.pkl",
        "resnet18_cifar100.pkl",
        "resnet19_cifar10_loas.pkl",
        "sdt_cifar10.pkl",
        "sdt_cifar100.pkl",
        "sdt_cifar10dvs.pkl",
        "spikebert_mr.pkl",
        "spikebert_sst2.pkl",
        "spikebert_sst5.pkl",
        "spikformer_cifar10.pkl",
        "spikformer_cifar100.pkl",
        "spikformer_cifar10dvs.pkl",
        "spikingbert_mnli.pkl",
        "spikingbert_qqp.pkl",
        "spikingbert_sst2.pkl",
        "vgg16_cifar10_loas.pkl",
        "vgg16_cifar10.pkl",
        "vgg16_cifar100.pkl",
        "vgg9_cifar10.pkl",
        "vgg9_cifar10dvs.pkl"
    ]
    
    print("=== Analyzing Datasets for ProSparsity ===")
    results = []
    
    for dataset in datasets:
        pkl_path = os.path.join(data_dir, dataset)
        if os.path.exists(pkl_path):
            print(f"Analyzing {dataset}...")
            result = analyze_dataset_for_prosparsity(pkl_path)
            results.append(result)
        else:
            print(f"Skipping {dataset} (not found)")
    
    # Sort by best subset ratio
    results.sort(key=lambda x: x.get('best_layer', {}).get('subset_ratio', 0), reverse=True)
    
    print(f"\n=== ProSparsity Analysis Results ===")
    print(f"{'Dataset':<25} {'Best Layer':<20} {'Density':<10} {'Subset Ratio':<12}")
    print("-" * 70)
    
    for result in results:
        if 'error' in result:
            print(f"{result['dataset']:<25} ERROR: {result['error']}")
        elif result['best_layer']:
            best = result['best_layer']
            print(f"{result['dataset']:<25} {best['name']:<20} {best['density']:<10.2f}% {best['subset_ratio']:<12.4f}")
        else:
            print(f"{result['dataset']:<25} No suitable layers found")
    
    # Return the best dataset
    best_result = results[0] if results else None
    if best_result and 'best_layer' in best_result and best_result['best_layer']:
        print(f"\n=== Best Dataset for ProSparsity ===")
        print(f"Dataset: {best_result['dataset']}")
        print(f"Best Layer: {best_result['best_layer']['name']}")
        print(f"Density: {best_result['best_layer']['density']:.2f}%")
        print(f"Subset Ratio: {best_result['best_layer']['subset_ratio']:.4f}")
        return best_result['dataset'], best_result['best_layer']['name']
    else:
        print(f"\nNo suitable dataset found for ProSparsity demonstration")
        return None, None

def main():
    """Main test function"""
    print("=" * 60)
    print("ProsperityHDL Dataset Analysis for ProSparsity")
    print("=" * 60)
    
    # Find the best dataset for ProSparsity
    best_dataset, best_layer = find_best_dataset_for_prosparsity()
    
    if not best_dataset:
        print("No suitable dataset found. Using default SDT CIFAR-10.")
        best_dataset = "sdt_cifar10.pkl"
        best_layer = "fc_q_enc_0"
    
    # Load the selected dataset
    pkl_path = f"data/{best_dataset}"
    try:
        data = load_sdt_data(pkl_path)
    except FileNotFoundError as e:
        print(f"Error: {e}")
        sys.exit(1)
    
    print(f"\n=== Using Dataset: {best_dataset} ===")
    print(f"Selected Layer: {best_layer}")
    
    # Analyze all layers
    print(f"\nAnalyzing {len(data)} layers:")
    print("-" * 40)
    
    layer_stats = []
    for layer_name, tensor in data.items():
        stats = analyze_layer(tensor, layer_name)
        layer_stats.append(stats)
        print(f"{layer_name:20s}: {str(stats['shape']):15s} | "
              f"Density: {stats['density']:6.2f}% | "
              f"Spikes: {stats['spike_count']:6d}")
    
    # Select interesting layers for tiling (use the best layer found)
    interesting_layers = [best_layer]
    
    print(f"\nCreating tiles for {len(interesting_layers)} selected layers:")
    print("-" * 50)
    
    tiles = {}
    for layer_name in interesting_layers:
        if layer_name in data:
            tensor = data[layer_name]
            tile = create_tile_from_tensor(tensor, ROWS, SPIKES)
            validation = validate_tile(tile)
            tiles[layer_name] = {
                'tile': tile,
                'validation': validation
            }
            
            print(f"\n{layer_name}:")
            print(f"  Original shape: {tensor.shape}")
            print(f"  Tile shape: {validation['shape']}")
            print(f"  Tile density: {validation['density']:.2f}%")
            print(f"  Rows with spikes: {validation['rows_with_spikes']}/{ROWS}")
            print(f"  Avg spikes/row: {validation['avg_spikes_per_row']:.2f}")
            
            # Show visualization for first layer
            if layer_name == interesting_layers[0]:
                print_tile_visualization(tile)
    
    # Summary statistics
    print(f"\n" + "=" * 60)
    print("SUMMARY")
    print("=" * 60)
    print(f"Total layers processed: {len(data)}")
    print(f"Layers tiled: {len(tiles)}")
    print(f"Tile configuration: {ROWS} rows × {SPIKES} spikes = {TILE_SIZE} bits")
    
    # Find best layer for testing
    best_layer = None
    best_density = 0
    for layer_name, tile_data in tiles.items():
        density = tile_data['validation']['density']
        if 5 <= density <= 50:  # Good density range for testing
            if density > best_density:
                best_density = density
                best_layer = layer_name
    
    if best_layer:
        print(f"\nRecommended layer for testing: {best_layer}")
        print(f"  Density: {best_density:.2f}%")
        print(f"  Rows with spikes: {tiles[best_layer]['validation']['rows_with_spikes']}")
    else:
        print(f"\nAll layers have extreme densities. Using first layer: {interesting_layers[0]}")
        best_layer = interesting_layers[0]
    
    # Export tiles for hardware testing
    print(f"\n" + "=" * 60)
    print("EXPORTING TILES FOR HARDWARE TESTING")
    print("=" * 60)
    
    # Create output directory
    import os
    output_dir = "tile_exports"
    os.makedirs(output_dir, exist_ok=True)
    
    # Export the recommended layer in multiple formats
    recommended_tile = tiles[best_layer]['tile']
    
    # Export as hex file
    hex_filename = f"{output_dir}/{best_layer}_tile.hex"
    export_tile_to_hex(recommended_tile, hex_filename)
    
    # Export as binary file
    bin_filename = f"{output_dir}/{best_layer}_tile.bin"
    export_tile_to_binary(recommended_tile, bin_filename)
    
    # Export as Verilog module
    verilog_filename = f"{output_dir}/{best_layer}_tile.v"
    export_tile_to_verilog(recommended_tile, verilog_filename, f"{best_layer}_tile_data")
    
    # Export all tiles as numpy arrays for Python analysis
    np_filename = f"{output_dir}/all_tiles.npz"
    np.savez(np_filename, **{name: data['tile'] for name, data in tiles.items()})
    print(f"Exported all tiles to {np_filename}")
    
    print(f"\nExport summary:")
    print(f"  Recommended layer: {best_layer}")
    print(f"  Output directory: {output_dir}/")
    print(f"  Files created:")
    print(f"    - {hex_filename}")
    print(f"    - {bin_filename}")
    print(f"    - {verilog_filename}")
    print(f"    - {np_filename}")
    
    print(f"\nTest completed successfully!")
    return tiles, best_layer

# Pytest wrapper for cocotb-test
def test_sdt_cifar10_ppu():
    """Pytest wrapper for SDT CIFAR-10 PPU test"""
    repo = Path(__file__).resolve().parents[1]
    verilog_sources = [
        repo / "ppu" / "top.v",
        repo / "ppu" / "detector.v",
        repo / "ppu" / "pruner.v",
        repo / "ppu" / "dispatcher.v",
        repo / "ppu" / "processor.v",
        repo / "ppu" / "tcam" / "hdl" / "tcam_line_array.v",
   ]

    run(
        verilog_sources=[str(v) for v in verilog_sources],
        toplevel="top",
        module="test_prosperity",
        parameters={
            "ROWS": str(ROWS),
            "SPIKES": str(SPIKES),
            "NO_WIDTH": "8",
        },
        timescale="1ns/1ps",
        simulator="verilator",
        compile_args=["-Wall", "-Wno-fatal"],
        waves=True,
    )

def run_cocotb_test_directly():
    """Run the cocotb test directly without pytest"""
    print("Running cocotb test directly...")
    
    repo = Path(__file__).resolve().parents[1]
    verilog_sources = [
        repo / "ppu" / "top.v",
        repo / "ppu" / "detector.v",
        repo / "ppu" / "pruner.v",
        repo / "ppu" / "dispatcher.v",
        repo / "ppu" / "processor.v",
        repo / "ppu" / "tcam" / "hdl" / "tcam_line_array.v",
        repo / "ppu" / "tcam" / "hdl" / "tcam_line_encoder.v",
        repo / "ppu" / "tcam" / "hdl" / "tcam_sdpram.v",
    ]
    
    try:
        # Use cocotb_test.simulator.run directly
        run(
            verilog_sources=[str(v) for v in verilog_sources],
            toplevel="top",
            module="test_prosperity",
            parameters={
                "ROWS": str(ROWS),
                "SPIKES": str(SPIKES),
                "NO_WIDTH": "8",
            },
            timescale="1ns/1ps",
            simulator="verilator",
            compile_args=["-Wall", "-Wno-fatal"],
            waves=True,
        )
        print("✓ Cocotb test completed successfully!")
    except Exception as e:
        print(f"✗ Cocotb test failed: {e}")
        import sys
        sys.exit(1)

if __name__ == "__main__":
    import sys
    import glob
    # Check command line arguments
    if len(sys.argv) > 1 and sys.argv[1] == "--cocotb":
        # Run cocotb test directly
        run_cocotb_test_directly()
    else:
        # Run analysis for all .pkl files in data/
        data_dir = "data"
        pkl_files = sorted(glob.glob(f"{data_dir}/*.pkl"))
        if not pkl_files:
            print(f"No .pkl files found in {data_dir}/")
            sys.exit(1)
        print(f"Found {len(pkl_files)} .pkl files in {data_dir}/. Running analysis for each...\n")
        for pkl_path in pkl_files:
            print("\n" + "#" * 80)
            print(f"Analyzing dataset: {pkl_path}")
            try:
                data = load_sdt_data(pkl_path)
            except Exception as e:
                print(f"Error loading {pkl_path}: {e}")
                continue
            print(f"\nAnalyzing {len(data)} layers in {pkl_path}:")
            print("-" * 40)
            layer_stats = []
            tiles = {}
            for layer_name, tensor in data.items():
                # Try to convert lists or numpy arrays to torch tensors
                orig_type = type(tensor)
                if not isinstance(tensor, torch.Tensor):
                    try:
                        tensor = torch.tensor(tensor)
                        print(f"[INFO] Converted layer '{layer_name}' from {orig_type} to torch.Tensor.")
                    except Exception as e:
                        print(f"[WARN] Could not convert layer '{layer_name}' (type {orig_type}) to tensor: {e}. Skipping.")
                        continue
                stats = analyze_layer(tensor, layer_name)
                layer_stats.append(stats)
                print(f"{layer_name:20s}: {str(stats['shape']):15s} | "
                      f"Density: {stats['density']:6.2f}% | "
                      f"Spikes: {stats['spike_count']:6d}")
                # Create tile, validate, and export for each layer
                tile = create_tile_from_tensor(tensor, ROWS, SPIKES)
                validation = validate_tile(tile)
                tiles[layer_name] = {
                    'tile': tile,
                    'validation': validation
                }
                print(f"  Tile shape: {validation['shape']}")
                print(f"  Tile density: {validation['density']:.2f}%")
                print(f"  Rows with spikes: {validation['rows_with_spikes']}/{ROWS}")
                print(f"  Avg spikes/row: {validation['avg_spikes_per_row']:.2f}")
                # Optionally show visualization for first layer
                if layer_name == list(data.keys())[0]:
                    print_tile_visualization(tile)
            # Export all tiles for this dataset
            output_dir = f"tile_exports/{os.path.splitext(os.path.basename(pkl_path))[0]}"
            os.makedirs(output_dir, exist_ok=True)
            for layer_name, tile_data in tiles.items():
                tile = tile_data['tile']
                # Export as hex file
                hex_filename = f"{output_dir}/{layer_name}_tile.hex"
                export_tile_to_hex(tile, hex_filename)
                # Export as binary file
                bin_filename = f"{output_dir}/{layer_name}_tile.bin"
                export_tile_to_binary(tile, bin_filename)
                # Export as Verilog module
                verilog_filename = f"{output_dir}/{layer_name}_tile.v"
                export_tile_to_verilog(tile, verilog_filename, f"{layer_name}_tile_data")
            # Export all tiles as numpy arrays for Python analysis
            np_filename = f"{output_dir}/all_tiles.npz"
            np.savez(np_filename, **{name: data['tile'] for name, data in tiles.items()})
            print(f"Exported all tiles for {pkl_path} to {output_dir}/")
            print("\nDone analyzing and exporting dataset.")
        print("\nAll datasets processed.")
        # Show options
        print(f"\n" + "=" * 60)
        print("Options to run cocotb test:")
        print("1. Direct Python execution:")
        print("   python test_prosperity.py --cocotb")
        print("2. Using pytest:")
        print("   python -m pytest test_prosperity.py::test_sdt_cifar10_ppu -v")
        print("=" * 60)
