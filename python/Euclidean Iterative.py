import time
from datetime import datetime
import pandas as pd
import tracemalloc

# Example GCD method: Euclidean Iterative
def gcd_method(a, b):
    while b:
        a, b = b, a % b
    return a

# Input test cases
test_inputs = [
    ("1-digit", 8, 3),
    ("2-digit", 48, 18),
    ("3-digit", 210, 45),
    ("4-digit", 1234, 4321),
    ("5-digit", 12345, 54321),
    ("6-digit", 123456, 789012),
    ("7-digit", 1000001, 7000001),
    ("8-digit", 12345678, 87654321),
    ("9-digit", 123456789, 987654321),
    ("10-digit", 1234567890, 9876543210),
    ("Both same", 55555, 55555),
    ("One is zero", 0, 1234567890),
    ("Large + small", 1, 999999937),
    ("Power of 2 values", 1048576, 32768),
    ("Large prime pair", 982451653, 57885161),
    ("11-digit", 12345678901, 10987654321),
    ("12-digit", int(1.23457e11), int(2.10988e11)),
    ("13-digit", int(1.23457e12), int(3.21099e12)),
    ("14-digit", int(1.23457e13), int(4.3211e13)),
    ("15-digit", int(1.23457e14), int(5.43211e14)),
]

results = []

for label, a, b in test_inputs:
    tracemalloc.start()

    start_time = datetime.now()
    start_perf = time.perf_counter()
    start_ns = time.perf_counter_ns()

    result = gcd_method(a, b)

    end_perf = time.perf_counter()
    end_ns = time.perf_counter_ns()
    end_time = datetime.now()

    current, peak = tracemalloc.get_traced_memory()
    memory_kb = peak / 1024  # Convert to KB
    tracemalloc.stop()

    print(f"\n--- {label} ---")
    print(f"Input A: {a}")
    print(f"Input B: {b}")
    print(f"GCD Result: {result}")
    print(f"Time Taken (seconds): {end_perf - start_perf:.10f}")
    print(f"Time Taken (nanoseconds): {end_ns - start_ns} ns")
    print(f"Memory Used: {memory_kb:.2f} KB")
    print(f"Timestamp: {start_time.strftime('%Y-%m-%d %H:%M:%S')} - {end_time.strftime('%Y-%m-%d %H:%M:%S')}")

    results.append({
        "Input Size / Pattern": label,
        "Input A": a,
        "Input B": b,
        "GCD Result": result,
        "Time Taken (s)": f"{end_perf - start_perf:.10f}",
        "Time Taken (ns)": end_ns - start_ns,
        "Memory Used (KB)": f"{memory_kb:.2f}",
        "Timestamp": f"{start_time.strftime('%Y-%m-%d %H:%M:%S')} - {end_time.strftime('%Y-%m-%d %H:%M:%S')}"
    })

# Save results to Excel
df = pd.DataFrame(results)
df.to_excel("gcd_method_with_memory.xlsx", index=False)
print("\nResults saved to 'gcd_method_with_memory.xlsx'")
