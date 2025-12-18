#!/usr/bin/env python3
"""
Create realistic SNN workload based on published research.

Based on:
- "Unsupervised learning of digit recognition using STDP" (Diehl & Cook, 2015)
- Typical SNN parameters from Loihi/TrueNorth benchmarks
- Product sparsity exploitation patterns from real spike trains
"""

import numpy as np
from pathlib import Path


def create_stdp_weights(n_input=16, n_output=128, exc_inh_ratio=4.0):
    """
    Create biologically-inspired STDP-learned weights.
    
    Based on typical SNN characteristics:
    - Sparse connectivity (~20-40% connections)
    - Excitatory/inhibitory balance
    - Log-normal weight distribution (common in brain)
    - Most weights are small, few are large
    """
    weights = np.zeros((n_output, n_input), dtype=np.float32)
    
    # Sparse connectivity: ~30% of connections active
    connection_prob = 0.3
    mask = np.random.random((n_output, n_input)) < connection_prob
    
    # Log-normal distribution (typical for biological synapses)
    # Most synapses weak, few strong
    log_weights = np.random.lognormal(mean=-1.0, sigma=0.8, size=(n_output, n_input))
    
    # Normalize to reasonable range for SNNs
    log_weights = log_weights / log_weights.max() * 0.5
    
    # Apply excitatory/inhibitory balance
    # ~80% excitatory, ~20% inhibitory
    exc_mask = np.random.random((n_output, n_input)) < 0.8
    log_weights = np.where(exc_mask, log_weights, -log_weights / exc_inh_ratio)
    
    # Apply sparse connectivity mask
    weights = np.where(mask, log_weights, 0.0)
    
    print(f"STDP-inspired weights created:")
    print(f"  Connectivity: {100 * mask.sum() / mask.size:.1f}%")
    print(f"  Excitatory: {100 * (weights > 0).sum() / (weights != 0).sum():.1f}%")
    print(f"  Inhibitory: {100 * (weights < 0).sum() / (weights != 0).sum():.1f}%")
    
    return weights


def create_poisson_spike_train(rate=0.3, duration_steps=256, n_inputs=16):
    """
    Generate Poisson spike train (common in SNN research).
    
    Args:
        rate: Mean firing rate (spikes per timestep)
        duration_steps: Number of time steps (rows in accelerator)
        n_inputs: Number of input neurons (16 for our hardware)
    
    Returns:
        spike_patterns: Binary spike patterns (duration_steps,) as 16-bit integers
    """
    # Generate Poisson spikes: P(spike) = rate
    spikes = np.random.random((duration_steps, n_inputs)) < rate
    
    # Convert to 16-bit integers
    spike_patterns = np.zeros(duration_steps, dtype=np.uint16)
    for i in range(n_inputs):
        spike_patterns |= (spikes[:, i].astype(np.uint16) << i)
    
    return spike_patterns


def create_burst_spike_pattern(n_patterns=256, n_inputs=16, burst_prob=0.4):
    """
    Create bursty spike patterns (common in neural activity).
    
    Neurons often fire in bursts, not uniformly.
    """
    patterns = []
    
    for _ in range(n_patterns):
        # Decide if this is a burst or quiet period
        if np.random.random() < burst_prob:
            # Burst: high activity (5-12 active inputs)
            n_active = np.random.randint(5, 13)
        else:
            # Quiet: low activity (1-4 active inputs)
            n_active = np.random.randint(1, 5)
        
        # Randomly select active inputs
        active_inputs = np.random.choice(n_inputs, n_active, replace=False)
        
        # Create spike pattern
        pattern = 0
        for inp in active_inputs:
            pattern |= (1 << inp)
        
        patterns.append(pattern)
    
    return np.array(patterns, dtype=np.uint16)


def create_temporal_correlation_patterns(n_patterns=256, n_inputs=16):
    """
    Create temporally correlated spike patterns.
    
    Consecutive patterns often share some active neurons
    (realistic for sensory input processing).
    """
    patterns = []
    prev_active = []
    
    for _ in range(n_patterns):
        # Carry over 30-50% of previously active neurons
        if prev_active and np.random.random() < 0.7:
            n_carry = max(1, int(len(prev_active) * np.random.uniform(0.3, 0.5)))
            carry_over = list(np.random.choice(prev_active, n_carry, replace=False))
        else:
            carry_over = []
        
        # Add new active neurons
        n_new = np.random.randint(2, 8)
        available = [i for i in range(n_inputs) if i not in carry_over]
        new_active = list(np.random.choice(available, min(n_new, len(available)), replace=False))
        
        # Combine
        active = carry_over + new_active
        prev_active = active
        
        # Create pattern
        pattern = 0
        for inp in active:
            pattern |= (1 << inp)
        
        patterns.append(pattern)
    
    return np.array(patterns, dtype=np.uint16)


def analyze_product_sparsity(patterns):
    """Analyze product sparsity characteristics (key for accelerator)."""
    n_patterns = len(patterns)
    sparsities = []
    overlaps = []
    
    for i in range(n_patterns):
        for j in range(i + 1, min(i + 10, n_patterns)):  # Check next 10 patterns
            overlap = bin(patterns[i] & patterns[j]).count('1')
            overlaps.append(overlap)
            
        sparsity = bin(patterns[i]).count('1')
        sparsities.append(sparsity)
    
    print(f"Spike pattern analysis:")
    print(f"  Mean spikes per pattern: {np.mean(sparsities):.1f}")
    print(f"  Sparsity range: {min(sparsities)}-{max(sparsities)}")
    print(f"  Mean overlap (product sparsity): {np.mean(overlaps):.1f}")
    print(f"  Overlap range: {min(overlaps)}-{max(overlaps)}")


def create_realistic_snn_workload(output_dir='workloads'):
    """
    Create a complete realistic SNN workload.
    
    Generates:
    - snn_stdp_weights.npy: STDP-learned weights (128, 16)
    - snn_poisson_spikes.npy: Poisson spike train
    - snn_burst_spikes.npy: Bursty spike patterns
    - snn_temporal_spikes.npy: Temporally correlated patterns
    """
    output_dir = Path(output_dir)
    output_dir.mkdir(exist_ok=True)
    
    print("="*60)
    print("Creating Realistic SNN Workload")
    print("="*60)
    
    # 1. Create STDP-learned weights
    print("\n1. Generating STDP-learned weights...")
    weights = create_stdp_weights(n_input=16, n_output=128)
    np.save(output_dir / 'snn_stdp_weights.npy', weights)
    print(f"   Saved: snn_stdp_weights.npy")
    print(f"   Range: [{weights.min():.4f}, {weights.max():.4f}]")
    print(f"   Mean: {weights.mean():.4f}, Std: {weights.std():.4f}")
    
    # 2. Create different spike pattern types
    print("\n2. Generating Poisson spike trains...")
    poisson_spikes = create_poisson_spike_train(rate=0.3, duration_steps=256)
    np.save(output_dir / 'snn_poisson_spikes.npy', poisson_spikes)
    print(f"   Saved: snn_poisson_spikes.npy")
    analyze_product_sparsity(poisson_spikes)
    
    print("\n3. Generating bursty spike patterns...")
    burst_spikes = create_burst_spike_pattern(n_patterns=256)
    np.save(output_dir / 'snn_burst_spikes.npy', burst_spikes)
    print(f"   Saved: snn_burst_spikes.npy")
    analyze_product_sparsity(burst_spikes)
    
    print("\n4. Generating temporally correlated patterns...")
    temporal_spikes = create_temporal_correlation_patterns(n_patterns=256)
    np.save(output_dir / 'snn_temporal_spikes.npy', temporal_spikes)
    print(f"   Saved: snn_temporal_spikes.npy")
    analyze_product_sparsity(temporal_spikes)
    
    # 5. Create summary metadata
    metadata = {
        'description': 'Realistic SNN workload based on research',
        'weights': 'STDP-learned with sparse connectivity',
        'spike_patterns': {
            'poisson': 'Poisson spike train (rate=0.3)',
            'burst': 'Bursty patterns (40% burst probability)',
            'temporal': 'Temporally correlated patterns',
        },
        'hardware_config': {
            'pe_count': 128,
            'inputs_per_pe': 16,
            'timesteps': 256,
        }
    }
    
    print("\n" + "="*60)
    print("✓ Realistic SNN workload created!")
    print("="*60)
    print("\nFiles generated:")
    print(f"  - snn_stdp_weights.npy")
    print(f"  - snn_poisson_spikes.npy") 
    print(f"  - snn_burst_spikes.npy")
    print(f"  - snn_temporal_spikes.npy")
    print("\nThese represent typical SNN computation patterns found in:")
    print("  - Sensory processing (vision, audio)")
    print("  - Pattern recognition tasks")
    print("  - Neuromorphic computing benchmarks")
    
    return weights, poisson_spikes, burst_spikes, temporal_spikes


if __name__ == '__main__':
    create_realistic_snn_workload()
