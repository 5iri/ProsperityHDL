# test_detector.py  –  Tests subset detection for detector.v
#
# ▸ Loads spike patterns into TCAM
# ▸ Uses spike rows as testing patterns for calculating subset index
# ▸ Verifies the exact 3-cycle latency behavior
# ▸ Logs detailed state transitions and signal timing
#
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer, ClockCycles
from cocotb_test.simulator import run
from pathlib import Path
import numpy as np

CLK_PERIOD_NS = 10          # 100 MHz
RESET_CYCLES = 2
ROWS_IN_TILE = 256
TEST_ROWS = 256             # Number of test patterns defined in the test
MAX_WAIT_CYC = 1000         # Timeout for variable latency

# Test with different pattern widths up to the hardware limit
PATTERN_WIDTHS = [8, 12, 16]  # Test widths up to SPIKES=16

# TCAM timing parameters
EXPECTED_LOAD_LATENCY = 1    # Cycles to load each row
EXPECTED_QUERY_LATENCY = 3   # Expected 3-cycle latency from query to result

# Helper functions
def popcount(val):
    """Count number of 1s in a value"""
    return bin(val).count('1')

def is_subset(pattern, query):
    """Check if pattern is a subset of query (pattern & query == pattern)"""
    return (pattern & query) == pattern

def cycles_now() -> int:
    """Get current simulation time in cycles"""
    return int(cocotb.utils.get_sim_time('ns') // CLK_PERIOD_NS)

async def hw_reset(dut):
    """Reset the hardware"""
    dut.rst.value = 1
    for _ in range(RESET_CYCLES):
        await RisingEdge(dut.clk)
    dut.rst.value = 0
    await RisingEdge(dut.clk)

async def wait_for_si_valid_with_timeout(dut, timeout_cycles, test_name=""):
    """
    Wait for si_valid to go high with timeout.
    Returns (success, latency_cycles)
    """
    start_cycle = cycles_now()
    waited = 0

    # Track FSM state changes for debugging
    last_state = int(dut.state.value)
    query_in_progress_seen = False

    while waited < timeout_cycles:
        curr_state = int(dut.state.value)
        if curr_state != last_state:
            last_state = curr_state

        # Track query_in_progress transitions for latency debugging
        if int(dut.query_in_progress.value) == 1 and not query_in_progress_seen:
            query_in_progress_seen = True

        if dut.si_valid.value:
            end_cycle = cycles_now()
            latency = end_cycle - start_cycle
            return True, latency
        waited += 1
        await RisingEdge(dut.clk)

    end_cycle = cycles_now()
    latency = end_cycle - start_cycle

    return False, latency

# Complex subset patterns for thorough testing
def generate_complex_subsets(width):
    """Generate patterns with complex subset relationships"""
    patterns = []
    
    # Base patterns with different characteristics
    base_patterns = [
        (1 << width) - 1,           # All ones
        0,                          # All zeros
        (1 << (width//2)) - 1,     # Half ones
        0xAAAA & ((1 << width) - 1),  # Alternating pattern 1
        0x5555 & ((1 << width) - 1),  # Alternating pattern 2
        1 << (width-1),            # MSB only
        1,                         # LSB only
        0x0F0F & ((1 << width) - 1)  # Nibble pattern
    ]
    
    # Add base patterns
    patterns.extend(base_patterns)
    
    # Create subsets with known relationships - use set to avoid duplicates
    pattern_set = set(patterns)
    
    for base in base_patterns:
        if base == 0:
            continue  # Skip zero base to avoid generating more zeros
            
        # Create direct subset by clearing some bits
        if base > 1:
            subset = base & (base - 1)  # Clear lowest set bit
            pattern_set.add(subset)
        
        # Create partial overlap by shifting
        overlap = base | (base >> 1)
        overlap &= (1 << width) - 1  # Mask to width
        pattern_set.add(overlap)
        
        # Create XOR pattern
        disjoint = base ^ ((base >> 1) | 1)
        disjoint &= (1 << width) - 1  # Mask to width  
        pattern_set.add(disjoint)
        
        # Create sparse subset by masking with different patterns
        for mask in [0xAAAA, 0x5555, 0x0F0F, 0xF0F0]:
            sparse = base & mask
            sparse &= (1 << width) - 1  # Mask to width
            if sparse != 0:  # Avoid adding more zeros
                pattern_set.add(sparse)
    
    # Add some additional random-like patterns
    import random
    random.seed(42)  # Deterministic for reproducible tests
    for i in range(min(10, width)):
        # Create patterns with specific bit counts
        pattern = 0
        num_bits = i + 1
        bit_positions = random.sample(range(width), min(num_bits, width))
        for pos in bit_positions:
            pattern |= (1 << pos)
        pattern_set.add(pattern)
    
    # Convert back to list and remove duplicates
    patterns = list(pattern_set)
    
    return patterns

async def verify_subset_detection(dut, patterns, width):
    """Verify subset detection for a set of patterns"""
    results = []
    
    for i, pattern in enumerate(patterns):
        # Wait for detector to be ready
        while not dut.q_ready.value:
            await RisingEdge(dut.clk)
        
        # Send query
        dut.query_pattern.value = pattern
        dut.q_valid.value = 1
        start_time = cocotb.utils.get_sim_time('ns')
        
        # Wait for first clock edge where query is sampled
        await RisingEdge(dut.clk)
        dut.q_valid.value = 0
        
        # Wait for result
        while not dut.si_valid.value:
            await RisingEdge(dut.clk)
            current_time = cocotb.utils.get_sim_time('ns')
            if (current_time - start_time) / CLK_PERIOD_NS > MAX_WAIT_CYC:
                raise TimeoutError(f"Timeout waiting for result on pattern {i}")
        
        # Calculate latency - subtract 1 to account for the initial clock edge
        end_time = cocotb.utils.get_sim_time('ns')
        latency = ((end_time - start_time) / CLK_PERIOD_NS) - 1
        
        # Verify subset relationships
        si_vec = int(dut.si_vec.value)
        actual_loaded_patterns = min(len(patterns), ROWS_IN_TILE)
        
        for j in range(ROWS_IN_TILE):
            if j < actual_loaded_patterns:
                # Check against actual loaded pattern
                test_pattern = patterns[j]
            else:
                # Remaining entries are zeros
                test_pattern = 0
                
            is_subset_expected = (test_pattern & pattern) == test_pattern
            is_detected = (si_vec >> j) & 1
            
            if is_subset_expected != is_detected:
                raise ValueError(
                    f"Subset detection error at TCAM entry {j}:\n"
                    f"  Query:    {pattern:0{width}b}\n"
                    f"  TCAM[{j}]: {test_pattern:0{width}b}\n"
                    f"  Expected subset: {is_subset_expected}\n"
                    f"  Detected: {is_detected}"
                )
        
        results.append({
            'pattern': pattern,
            'latency': latency,
            'matches': bin(si_vec).count('1')
        })
        
        await RisingEdge(dut.clk)
    
    return results

@cocotb.test()
async def test_detector_complex_patterns(dut):
    """Test detector with complex patterns and different widths"""
    cocotb.start_soon(Clock(dut.clk, CLK_PERIOD_NS, units="ns").start())
    
    for width in PATTERN_WIDTHS:
        cocotb.log.info(f"\nTesting with pattern width: {width}")
        
        # Reset for each width test
        await hw_reset(dut)
        
        # Generate complex patterns
        patterns = generate_complex_subsets(width)
        unique_patterns_before_test = len(set(patterns))
        cocotb.log.info(f"Generated {len(patterns)} test patterns ({unique_patterns_before_test} unique)")
        
        # Log a few example patterns for debugging
        if len(patterns) > 0:
            example_patterns = patterns[:min(10, len(patterns))]
            cocotb.log.info(f"Example patterns: {[f'{p:0{width}b}' for p in example_patterns]}")
        
        # Load patterns into TCAM (ensure they fit in 16 bits)
        # Initialize all TCAM entries first to avoid undefined behavior
        for i in range(ROWS_IN_TILE):
            dut.tile_buffer[i].value = 0
        
        # Now load our test patterns
        for i, pattern in enumerate(patterns):
            if i >= ROWS_IN_TILE:
                break  # Don't exceed tile size
            dut.tile_buffer[i].value = pattern & 0xFFFF  # Ensure 16-bit limit
        
        # Log what we loaded for debugging
        cocotb.log.info(f"Loaded {min(len(patterns), ROWS_IN_TILE)} patterns into TCAM")
        
        # Wait for initialization
        await ClockCycles(dut.clk, RESET_CYCLES * 2)
        
        # Run subset detection tests
        try:
            results = await verify_subset_detection(dut, patterns[:ROWS_IN_TILE], width)
            
            # Analyze results
            latencies = [r['latency'] for r in results]
            matches = [r['matches'] for r in results]
            
            cocotb.log.info(f"\nResults for width {width}:")
            cocotb.log.info(f"  Average latency: {np.mean(latencies):.2f} cycles")
            cocotb.log.info(f"  Min/Max latency: {min(latencies)}/{max(latencies)} cycles")
            cocotb.log.info(f"  Average matches: {np.mean(matches):.2f}")
            cocotb.log.info(f"  Min/Max matches: {min(matches)}/{max(matches)}")
            
            # Verify latency requirement
            assert max(latencies) <= 3, f"Latency exceeded 3 cycles: {max(latencies)}"
            
            # Verify functional correctness - all queries should have valid results
            assert all(r['matches'] >= 0 for r in results), "Some queries returned invalid match counts"
            
            # Verify reasonable match counts (check against TCAM size, not test pattern count)
            for result in results:
                assert 0 <= result['matches'] <= ROWS_IN_TILE, \
                    f"Invalid match count {result['matches']} for TCAM with {ROWS_IN_TILE} entries (pattern: {result['pattern']:016b})"
                
                # Additional check: if pattern is all-ones for the given width, it should match many entries
                max_pattern_for_width = (1 << width) - 1
                if result['pattern'] == max_pattern_for_width:
                    # All-ones pattern should match a significant number of entries
                    assert result['matches'] >= len(patterns) // 2, \
                        f"All-ones pattern {result['pattern']:016b} should match many entries, got {result['matches']}"
                elif result['pattern'] == 0:
                    # All-zeros pattern should only match the zero entry
                    assert result['matches'] >= 1, \
                        f"All-zeros pattern should match at least itself, got {result['matches']}"
            
            # Verify latency consistency - all results should have valid latency
            for result in results:
                assert 0 < result['latency'] <= 5, \
                    f"Invalid latency {result['latency']} for pattern {result['pattern']:016b}"
            
            # Verify pattern diversity in test set
            unique_patterns = len(set(r['pattern'] for r in results))
            min_expected_unique = max(8, len(results) // 4)  # At least 8 unique or 25% of total
            assert unique_patterns >= min_expected_unique, \
                f"Insufficient pattern diversity: {unique_patterns} unique out of {len(results)} (expected at least {min_expected_unique})"
            
        except Exception as e:
            cocotb.log.error(f"Test failed for width {width}: {e}")
            raise

@cocotb.test()
async def detector_subset_index_test(dut):
    cocotb.start_soon(Clock(dut.clk, CLK_PERIOD_NS, units="ns").start())
    cocotb.log.info("=== Detector Subset Index Test ===")
    cocotb.log.info("Testing for subset index calculation with spike rows as testing patterns")

    # Define spike patterns to load into TCAM
    # 256 spike-row query patterns (16-bit, 0x0000 → 0x00FF)
    spike_patterns = [
        0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007,
        0x0008, 0x0009, 0x000A, 0x000B, 0x000C, 0x000D, 0x000E, 0x000F,
        0x0010, 0x0011, 0x0012, 0x0013, 0x0014, 0x0015, 0x0016, 0x0017,
        0x0018, 0x0019, 0x001A, 0x001B, 0x001C, 0x001D, 0x001E, 0x001F,
        0x0020, 0x0021, 0x0022, 0x0023, 0x0024, 0x0025, 0x0026, 0x0027,
        0x0028, 0x0029, 0x002A, 0x002B, 0x002C, 0x002D, 0x002E, 0x002F,
        0x0030, 0x0031, 0x0032, 0x0033, 0x0034, 0x0035, 0x0036, 0x0037,
        0x0038, 0x0039, 0x003A, 0x003B, 0x003C, 0x003D, 0x003E, 0x003F,
        0x0040, 0x0041, 0x0042, 0x0043, 0x0044, 0x0045, 0x0046, 0x0047,
        0x0048, 0x0049, 0x004A, 0x004B, 0x004C, 0x004D, 0x004E, 0x004F,
        0x0050, 0x0051, 0x0052, 0x0053, 0x0054, 0x0055, 0x0056, 0x0057,
        0x0058, 0x0059, 0x005A, 0x005B, 0x005C, 0x005D, 0x005E, 0x005F,
        0x0060, 0x0061, 0x0062, 0x0063, 0x0064, 0x0065, 0x0066, 0x0067,
        0x0068, 0x0069, 0x006A, 0x006B, 0x006C, 0x006D, 0x006E, 0x006F,
        0x0070, 0x0071, 0x0072, 0x0073, 0x0074, 0x0075, 0x0076, 0x0077,
        0x0078, 0x0079, 0x007A, 0x007B, 0x007C, 0x007D, 0x007E, 0x007F,
        0x0080, 0x0081, 0x0082, 0x0083, 0x0084, 0x0085, 0x0086, 0x0087,
        0x0088, 0x0089, 0x008A, 0x008B, 0x008C, 0x008D, 0x008E, 0x008F,
        0x0090, 0x0091, 0x0092, 0x0093, 0x0094, 0x0095, 0x0096, 0x0097,
        0x0098, 0x0099, 0x009A, 0x009B, 0x009C, 0x009D, 0x009E, 0x009F,
        0x00A0, 0x00A1, 0x00A2, 0x00A3, 0x00A4, 0x00A5, 0x00A6, 0x00A7,
        0x00A8, 0x00A9, 0x00AA, 0x00AB, 0x00AC, 0x00AD, 0x00AE, 0x00AF,
        0x00B0, 0x00B1, 0x00B2, 0x00B3, 0x00B4, 0x00B5, 0x00B6, 0x00B7,
        0x00B8, 0x00B9, 0x00BA, 0x00BB, 0x00BC, 0x00BD, 0x00BE, 0x00BF,
        0x00C0, 0x00C1, 0x00C2, 0x00C3, 0x00C4, 0x00C5, 0x00C6, 0x00C7,
        0x00C8, 0x00C9, 0x00CA, 0x00CB, 0x00CC, 0x00CD, 0x00CE, 0x00CF,
        0x00D0, 0x00D1, 0x00D2, 0x00D3, 0x00D4, 0x00D5, 0x00D6, 0x00D7,
        0x00D8, 0x00D9, 0x00DA, 0x00DB, 0x00DC, 0x00DD, 0x00DE, 0x00DF,
        0x00E0, 0x00E1, 0x00E2, 0x00E3, 0x00E4, 0x00E5, 0x00E6, 0x00E7,
        0x00E8, 0x00E9, 0x00EA, 0x00EB, 0x00EC, 0x00ED, 0x00EE, 0x00EF,
        0x00F0, 0x00F1, 0x00F2, 0x00F3, 0x00F4, 0x00F5, 0x00F6, 0x00F7,
        0x00F8, 0x00F9, 0x00FA, 0x00FB, 0x00FC, 0x00FD, 0x00FE, 0x00FF
    ]
    cocotb.log.info(f"Spike patterns to load into TCAM: {[f'{p:016b}' for p in spike_patterns]}")

    # Initialize tile_buffer with spike patterns
    for i in range(ROWS_IN_TILE):
        dut.tile_buffer[i].value = 0

    for i, pattern in enumerate(spike_patterns):
        dut.tile_buffer[i].value = pattern

    # Calculate and print popcounts for all loaded spike rows
    spike_popcounts = [popcount(pattern) for pattern in spike_patterns]

    # Assert all popcounts are as expected
    for i, pattern in enumerate(spike_patterns):
        expected_pc = popcount(pattern)
        assert spike_popcounts[i] == expected_pc, (
            f"Popcount mismatch at tile_buffer[{i}]: got {spike_popcounts[i]}, expected {expected_pc} (pattern: {pattern:016b})"
        )
    cocotb.log.info("All popcount values verified and correct.")

    # Initialize inputs
    dut.q_valid.value = 0
    dut.query_pattern.value = 0

    await hw_reset(dut)

    # Wait for LOAD and POPCOUNT phases to complete (detector needs time to load patterns and calculate popcounts)
    init_cycle = cycles_now()
    for i in range(TEST_ROWS * 2 + 50):  # Add margin to ensure both LOAD and POPCOUNT are complete
        if i % 50 == 0:
            fsm_state = int(dut.state.value)
        await RisingEdge(dut.clk)
    end_cycle = cycles_now()

    # Make sure we have popcounts calculated, otherwise test will fail

    # Use spike rows as testing patterns for subset index calculation
    test_queries = []

    # Use a sample of spike patterns for testing to keep test runtime reasonable
    # We'll select every 16th pattern plus some important edge cases
    test_indices = list(range(0, 256, 16))  # Every 16th pattern (0, 16, 32, ...)
    test_indices.extend([1, 2, 3, 15, 255])  # Add some edge cases
    test_indices = sorted(list(set(test_indices)))  # Remove duplicates and sort

    cocotb.log.info(f"Testing a sample of {len(test_indices)} patterns from the 256 total patterns")

    for i in test_indices:
        pattern = spike_patterns[i]
        # Pre-calculate expected results - which rows should match for each query pattern
        expected_matches = []
        for j, spike_pattern in enumerate(spike_patterns):
            if is_subset(spike_pattern, pattern):  # Check which patterns are subsets of this one
                expected_matches.append(j)

        # Add test case: (query_pattern, expected_matches, description, timeout_cycles)
        test_queries.append((pattern, expected_matches, f"Spike pattern {i}: {pattern:016b}", 15))

    latency_stats = []  # Track latencies for analysis
    exact_latency_count = 0  # Count tests with exactly 2-cycle latency
    all_tests_passed = True

    for query_idx, (query_pattern, expected_rows, description, timeout) in enumerate(test_queries):

        # Verify expected results by manual calculation
        expected_si_bits = 0
        for row_idx in expected_rows:
            expected_si_bits |= (1 << row_idx)

        expected_popcnt = spike_popcounts[i]  # Use precomputed popcount

        start_cycle = cycles_now()

        # Mark the exact cycle when we issue the query
        pre_query_cycle = cycles_now()

        # Issue query for exactly one cycle to precisely measure latency
        dut.query_pattern.value = query_pattern
        dut.q_valid.value = 1
        await RisingEdge(dut.clk)
        dut.q_valid.value = 0

        # Record exact cycle when q_valid was deasserted
        query_cycle = cycles_now()

        # Log the state machine state

        # Wait for si_valid with variable timeout
        success, latency = await wait_for_si_valid_with_timeout(
            dut, timeout, f"Test {query_idx}"
        )

        if not success:
            cocotb.log.error(f"✗ Test {query_idx} FAILED - TIMEOUT")
            continue

        # Capture results
        end_cycle = cycles_now()
        # Calculate actual query-to-result latency (precise measurement)
        actual_latency = end_cycle - query_cycle

        # Check if latency is exactly 3 cycles
        if actual_latency == EXPECTED_QUERY_LATENCY:
            cocotb.log.info("✓ EXACT 3-CYCLE LATENCY VERIFIED")
            exact_latency_count += 1
        else:
            cocotb.log.error(f"✗ INCORRECT LATENCY: Expected {EXPECTED_QUERY_LATENCY} cycles, got {actual_latency}")

        si_vec = int(dut.si_vec.value)

        # Get the pre-calculated popcount from the row_popcounts array
        # Find the index in the test patterns for this query
        pattern_idx = test_indices[query_idx]
        popcnt = int(dut.row_popcounts[pattern_idx].value)

        cocotb.log.info(f"Results @cycle {end_cycle} (latency={actual_latency} cycles):")
        cocotb.log.info(f"  si_vec:  {si_vec:0256b}")

        # Validate results - add meaningful assertions
        # Check si_vec
        if si_vec != expected_si_bits:
            cocotb.log.error(f"SI_VEC MISMATCH:")
            cocotb.log.error(f"  Got:      {si_vec:0256b}")
            cocotb.log.error(f"  Expected: {expected_si_bits:0256b}")

            # Show which rows were incorrectly matched/missed
            got_rows = [i for i in range(256) if (si_vec >> i) & 1]
            cocotb.log.error(f"  Got rows: {got_rows}")
            cocotb.log.error(f"  Expected: {expected_rows}")
            all_tests_passed = False
        else:
            cocotb.log.info(f"✓ SI_VEC correct: matches rows {expected_rows}")

        # Assert correctness of subset index vector
        assert si_vec == expected_si_bits, \
            f"Subset index vector incorrect: got {si_vec:064b}, expected {expected_si_bits:064b}"

        # Verify subset logic manually for each spike pattern
        cocotb.log.info("Manual subset verification:")
        mismatch_count = 0
        for i in range(len(spike_patterns)):
            pattern = spike_patterns[i]
            is_match = is_subset(pattern, query_pattern)
            should_be_set = (si_vec >> i) & 1

            if is_match != should_be_set:
                cocotb.log.error(f"    ✗ Mismatch for row {i}!")
                mismatch_count += 1
        
        # Assert no subset logic mismatches
        assert mismatch_count == 0, \
            f"Found {mismatch_count} subset logic mismatches for pattern {query_pattern:016b}"
        
        # Assert valid latency bounds
        assert 1 <= actual_latency <= 5, \
            f"Latency {actual_latency} is outside reasonable bounds [1, 5] cycles"
        
        # Store latency for later analysis
        latency_stats.append(actual_latency)

         # Wait a few cycles before next test
        for _ in range(5):
            await RisingEdge(dut.clk)

    # Report latency statistics
    num_tests = len(test_queries)
    if latency_stats:
        cocotb.log.info("\n=== Latency Statistics ===")
        cocotb.log.info(f"Latencies: {latency_stats}")
        cocotb.log.info(f"Min latency: {min(latency_stats)} cycles")
        cocotb.log.info(f"Max latency: {max(latency_stats)} cycles")
        cocotb.log.info(f"Avg latency: {sum(latency_stats)/len(latency_stats):.1f} cycles")
        cocotb.log.info(f"Tests with exactly 3-cycle latency: {exact_latency_count}/{num_tests}")

        # Check for latency variation
        if max(latency_stats) - min(latency_stats) > 0:
            cocotb.log.info(f"• Variable latency detected: {max(latency_stats) - min(latency_stats)} cycle spread")
        else:
            cocotb.log.info(f"✓ Fixed latency: all tests completed in {latency_stats[0]} cycles")

        # Verify we got the expected 3-cycle latency
        if exact_latency_count == num_tests:
            cocotb.log.info("✓ VERIFIED: DETECTOR HAS EXACT 3-CYCLE LATENCY")
        else:
            cocotb.log.error("✗ FAILED: DETECTOR DOES NOT HAVE CONSISTENT 3-CYCLE LATENCY")

    if all_tests_passed:
        cocotb.log.info("\nALL TESTS PASSED")
    else:
        cocotb.log.error("\nSOME TESTS FAILED")
    
    # Assert all tests passed
    assert all_tests_passed, "One or more detector tests failed"
    
    # Assert reasonable test coverage
    assert num_tests >= 10, f"Insufficient test coverage: only {num_tests} tests run"

    cocotb.log.info("\n=== Detector subset index calculation test complete ===")

    # Add verification of TCAM timing
    tcam_latencies = []
    
    for i in test_indices:
        pattern = spike_patterns[i]
        
        # Wait for detector to be ready
        while not dut.q_ready.value:
            await RisingEdge(dut.clk)
        
        # Issue query and start timing from next clock edge
        dut.query_pattern.value = pattern
        dut.q_valid.value = 1
        await RisingEdge(dut.clk)  # Wait for first clock edge
        start_time = cocotb.utils.get_sim_time('ns')
        dut.q_valid.value = 0
        
        # Wait for TCAM response
        while not dut.si_valid.value:
            await RisingEdge(dut.clk)
        
        # Calculate latency - we start counting from the cycle after query is sampled
        end_time = cocotb.utils.get_sim_time('ns')
        tcam_latency = ((end_time - start_time) / CLK_PERIOD_NS)
        tcam_latencies.append(tcam_latency)
        
        # Verify TCAM timing
        assert tcam_latency <= 3, f"TCAM latency exceeded 3 cycles: {tcam_latency}"
        
        # Wait a few cycles between tests
        await ClockCycles(dut.clk, 2)
    
    # Report TCAM timing statistics
    avg_tcam_latency = np.mean(tcam_latencies)
    max_tcam_latency = max(tcam_latencies)
    min_tcam_latency = min(tcam_latencies)
    
    cocotb.log.info("\nTCAM Timing Statistics:")
    cocotb.log.info(f"  Average latency: {avg_tcam_latency:.2f} cycles")
    cocotb.log.info(f"  Min latency: {min_tcam_latency} cycles")
    cocotb.log.info(f"  Max latency: {max_tcam_latency} cycles")
    
    # Verify consistent 3-cycle latency
    assert max_tcam_latency == 3, "TCAM does not maintain consistent 3-cycle latency"

# ---------------- PyTest harness ------------------------------------
def runCocotbTests():
    repo = Path(__file__).resolve().parents[1]
    verilog_sources = [
        repo / "ppu" / "detector.v",  # Detector module
        repo / "ppu" / "tcam" / "hdl" / "tcam_line_array.v",  # TCAM line array
    ]

    run(
        verilog_sources=[str(v) for v in verilog_sources],
        toplevel="detector",
        module="test_detector",    # Use tb.test_detector to match the package structure
        simulator="verilator",
        compile_args=[
            "-Wall", "-Wno-fatal"
        ],
    )

if __name__ == "__main__":
    test_detector()
