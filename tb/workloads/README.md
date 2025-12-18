# SNN Workload Weights

This directory contains weight files for testing the Prosperity SNN accelerator with actual workloads.

## Weight Format

Weights are stored in **IEEE 754 FP16 (half-precision)** format:
- 16-bit floating-point
- 1 sign bit, 5 exponent bits, 10 mantissa bits
- Range: ±65504 (practical range for SNNs: typically [-2.0, 2.0])

## File Format

Weights should be saved in NumPy format:
- `.npy`: Standard NumPy array format
- `.npz`: Compressed NumPy archive (use key `'weights'`)

Expected shape:
- `(128, 16)`: 128 PEs × 16 inputs per neuron
- `(2048,)`: Flattened array (PE-major order)

## Generating Weight Files

Use the provided script:

```bash
# Generate Xavier-initialized weights
python generate_workload.py --output workloads/xavier_init.npy --init xavier --seed 42

# Generate sparse weights (80% zeros)
python generate_workload.py --output workloads/sparse_weights.npy --init sparse

# Generate normal distribution weights
python generate_workload.py --output workloads/normal_weights.npy --init normal
```

Available initialization methods:
- `uniform`: Uniform random in [-1, 1]
- `normal`: Normal distribution N(0, 0.5)
- `xavier`: Xavier/Glorot initialization
- `he`: He initialization  
- `sparse`: Sparse weights (80% zeros)

## Using Workload Weights in Tests

Edit `test_top.py`:

```python
# Set to your workload file
WORKLOAD_FILE = "workloads/my_network_weights.npy"
```

Or use `None` for random weights:

```python
WORKLOAD_FILE = None  # Random weights
```

## Example Workload Files

- `sample_xavier.npy`: Xavier-initialized weights (provided for testing)

## Creating Custom Workloads

From Python:

```python
import numpy as np

# Create your weights (128 PEs × 16 inputs)
weights = np.random.randn(128, 16) * 0.1  # Small random weights

# Save
np.save('workloads/my_weights.npy', weights)
```

From PyTorch model:

```python
import torch
import numpy as np

# Extract layer weights from PyTorch model
layer = model.fc1  # Your layer
weights = layer.weight.detach().cpu().numpy()

# Reshape/slice to fit (128, 16) if needed
weights = weights[:128, :16]

np.save('workloads/pytorch_layer.npy', weights)
```
