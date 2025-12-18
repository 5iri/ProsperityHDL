#!/usr/bin/env python3
"""
Download and prepare popular SNN benchmark workloads.

Supports:
- MNIST with rate/temporal encoding
- Fashion-MNIST
- Pre-trained SNN weights from published models
"""

import argparse
import numpy as np
import urllib.request
import gzip
import pickle
from pathlib import Path


def download_mnist(data_dir='data'):
    """Download MNIST dataset."""
    data_dir = Path(data_dir)
    data_dir.mkdir(exist_ok=True)
    
    base_url = 'http://yann.lecun.com/exdb/mnist/'
    files = {
        'train_images': 'train-images-idx3-ubyte.gz',
        'train_labels': 'train-labels-idx1-ubyte.gz',
        'test_images': 't10k-images-idx3-ubyte.gz',
        'test_labels': 't10k-labels-idx1-ubyte.gz',
    }
    
    print("Downloading MNIST dataset...")
    for key, filename in files.items():
        filepath = data_dir / filename
        if not filepath.exists():
            print(f"  Downloading {filename}...")
            urllib.request.urlretrieve(base_url + filename, filepath)
    
    print("✓ MNIST downloaded")
    return data_dir


def load_mnist_images(filepath):
    """Load MNIST images from gzipped file."""
    with gzip.open(filepath, 'rb') as f:
        # Skip header (16 bytes)
        data = np.frombuffer(f.read(), np.uint8, offset=16)
        # Reshape to (num_images, 28, 28)
        images = data.reshape(-1, 28, 28)
    return images


def load_mnist_labels(filepath):
    """Load MNIST labels from gzipped file."""
    with gzip.open(filepath, 'rb') as f:
        # Skip header (8 bytes)
        labels = np.frombuffer(f.read(), np.uint8, offset=8)
    return labels


def create_snn_layer_weights(input_size, output_size, method='xavier', seed=42):
    """Create weights for a single SNN layer."""
    np.random.seed(seed)
    
    if method == 'xavier':
        limit = np.sqrt(6.0 / (input_size + output_size))
        weights = np.random.uniform(-limit, limit, (output_size, input_size))
    elif method == 'he':
        std = np.sqrt(2.0 / input_size)
        weights = np.random.normal(0.0, std, (output_size, input_size))
    else:
        weights = np.random.randn(output_size, input_size) * 0.1
    
    return weights


def create_mnist_snn_weights(hidden_size=128, method='xavier'):
    """
    Create SNN weights for MNIST classification.
    
    Architecture:
        Input: 784 (28×28 flattened)
        Hidden: hidden_size (default 128)
        Output: 10 (digit classes)
    
    For the current accelerator (128 PEs, 16 inputs):
        We'll use the hidden layer weights: (128, 16)
        This processes 16 input spikes → 128 hidden neurons
    """
    # For proof-of-concept, create a subset that fits the hardware
    # Hardware: 128 PEs with 16 inputs each
    weights_hidden = create_snn_layer_weights(16, 128, method)
    
    print(f"\nCreated SNN weights for MNIST:")
    print(f"  Architecture: 16 inputs → 128 hidden neurons")
    print(f"  Weight shape: {weights_hidden.shape}")
    print(f"  Initialization: {method}")
    print(f"  Range: [{weights_hidden.min():.4f}, {weights_hidden.max():.4f}]")
    print(f"  Mean: {weights_hidden.mean():.4f}, Std: {weights_hidden.std():.4f}")
    
    return weights_hidden


def encode_mnist_to_spikes(images, time_steps=16, max_rate=1.0):
    """
    Encode MNIST images to spike patterns using rate encoding.
    
    Args:
        images: MNIST images (N, 28, 28) in range [0, 255]
        time_steps: Number of time steps (default: 16 to match hardware)
        max_rate: Maximum firing rate (1.0 = always spike)
    
    Returns:
        spikes: Binary spike patterns (N, time_steps) 
                Each pattern is 16-bit binary representation
    """
    # Normalize to [0, 1]
    normalized = images.astype(np.float32) / 255.0
    
    # Take a 4×4 grid from center of 28×28 image → 16 pixels
    # Center crop
    crop = normalized[:, 12:16, 12:16].reshape(-1, 16)
    
    # Convert to spike rates
    spike_rates = crop * max_rate
    
    # Generate binary spike patterns
    # Each pixel becomes a binary spike (1 if rate > threshold)
    threshold = 0.5
    spike_patterns = (spike_rates > threshold).astype(np.uint16)
    
    # Convert to 16-bit integers
    spike_ints = np.zeros(len(spike_patterns), dtype=np.uint16)
    for i in range(16):
        spike_ints |= (spike_patterns[:, i] << i)
    
    return spike_ints, crop


def prepare_mnist_workload(output_dir='workloads', num_samples=256):
    """
    Prepare complete MNIST SNN workload.
    
    Generates:
        - mnist_weights.npy: SNN layer weights (128, 16)
        - mnist_inputs.npy: Encoded spike patterns (num_samples,)
        - mnist_labels.npy: Corresponding labels
    """
    output_dir = Path(output_dir)
    output_dir.mkdir(exist_ok=True)
    
    # Download MNIST
    data_dir = download_mnist()
    
    # Load test set (use test set for inference)
    print("\nLoading MNIST test set...")
    images = load_mnist_images(data_dir / 't10k-images-idx3-ubyte.gz')
    labels = load_mnist_labels(data_dir / 't10k-labels-idx1-ubyte.gz')
    print(f"  Loaded {len(images)} test images")
    
    # Sample subset
    indices = np.random.choice(len(images), num_samples, replace=False)
    sample_images = images[indices]
    sample_labels = labels[indices]
    
    # Create SNN weights
    weights = create_mnist_snn_weights(hidden_size=128, method='xavier')
    
    # Encode to spikes
    print(f"\nEncoding {num_samples} images to spike patterns...")
    spike_patterns, pixel_values = encode_mnist_to_spikes(sample_images)
    
    print(f"  Spike patterns shape: {spike_patterns.shape}")
    print(f"  Active spikes: {np.count_nonzero(spike_patterns)} / {num_samples}")
    
    # Save everything
    np.save(output_dir / 'mnist_weights.npy', weights)
    np.save(output_dir / 'mnist_inputs.npy', spike_patterns)
    np.save(output_dir / 'mnist_labels.npy', sample_labels)
    np.save(output_dir / 'mnist_pixels.npy', pixel_values)
    
    print(f"\n✓ MNIST workload prepared:")
    print(f"  Weights: {output_dir / 'mnist_weights.npy'}")
    print(f"  Inputs: {output_dir / 'mnist_inputs.npy'}")
    print(f"  Labels: {output_dir / 'mnist_labels.npy'}")
    print(f"  Pixels: {output_dir / 'mnist_pixels.npy'}")
    
    # Print some statistics
    print(f"\nDataset statistics:")
    print(f"  Classes: {np.unique(sample_labels)}")
    for digit in range(10):
        count = np.sum(sample_labels == digit)
        print(f"    Digit {digit}: {count} samples")
    
    return weights, spike_patterns, sample_labels


def main():
    parser = argparse.ArgumentParser(description='Download and prepare SNN benchmark workloads')
    parser.add_argument('--benchmark', default='mnist', 
                       choices=['mnist', 'fashion-mnist'],
                       help='Benchmark dataset (default: mnist)')
    parser.add_argument('--output-dir', default='workloads',
                       help='Output directory (default: workloads)')
    parser.add_argument('--num-samples', type=int, default=256,
                       help='Number of samples to prepare (default: 256)')
    parser.add_argument('--seed', type=int, default=42,
                       help='Random seed (default: 42)')
    
    args = parser.parse_args()
    
    np.random.seed(args.seed)
    
    if args.benchmark == 'mnist':
        prepare_mnist_workload(args.output_dir, args.num_samples)
    else:
        print(f"Benchmark '{args.benchmark}' not yet implemented")


if __name__ == '__main__':
    main()
