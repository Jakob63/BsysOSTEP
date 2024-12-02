import random
import argparse

def generate_trace(size=15, locality=False):
    """
    Generates a randomized trace of memory accesses with optional locality.
    
    Parameters:
    - size (int): Length of the trace.
    - locality (bool): If True, introduces locality by repeating some addresses.

    Returns:
    - list: Generated memory access trace.
    """
    trace = []
    all_addresses = list(range(1, 15))  # Example address range [1, 10]
    
    if locality:
        # With locality: choose some "hot" addresses that appear more frequently
        frequent_addresses = [1, 2, 3]  # Addresses with higher locality
        for _ in range(size):
            if random.random() < 0.5:
                trace.append(random.choice(frequent_addresses))
            else:
                trace.append(random.choice(all_addresses))
    else:
        # Without locality: purely random addresses within the range
        for _ in range(size):
            trace.append(random.choice(all_addresses))
    
    return trace

def main():
    parser = argparse.ArgumentParser(description="Generate memory access trace for paging-policy.py")
    parser.add_argument('-s', '--size', type=int, default=15, help="Length of the trace")
    parser.add_argument('-l', '--locality', action='store_true', help="Enable locality in the trace")
    args = parser.parse_args()
    
    trace = generate_trace(size=args.size, locality=args.locality)
    print(",".join(map(str, trace)))

if __name__ == "__main__":
    main()