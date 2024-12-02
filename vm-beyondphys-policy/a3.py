import random
import argparse

def generate_trace_without_locality(size=15):
    trace = []
    all_addresses = list(range(1, 11))  # Example address range [1, 10]
    for _ in range(size):
        trace.append(random.choice(all_addresses))
    return trace

def main():
    parser = argparse.ArgumentParser(description="Generate memory access trace for paging-policy.py")
    parser.add_argument('-s', '--size', type=int, default=15, help="Length of the trace")
    args = parser.parse_args()
    
    trace = generate_trace_without_locality(size=args.size)
    print(",".join(map(str, trace)))

if __name__ == "__main__":
    main()