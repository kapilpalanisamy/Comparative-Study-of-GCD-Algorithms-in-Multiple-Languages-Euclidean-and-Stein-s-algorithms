Comparative Study of GCD Algorithms in Multiple Languages
Overview
This project benchmarks and compares six methods for computing the greatest common divisor (GCD):
Euclidean Iterative, Euclidean Recursive, Stein’s Iterative, Stein’s Recursive, Subtraction Method, and Built-in functions—all implemented in Python, Java, C, and C++.
Performance is evaluated across various input sizes, providing practical insights for algorithm and language selection.

Algorithms Covered
Euclidean Algorithm (Iterative)

Euclidean Algorithm (Recursive)

Stein’s Algorithm (Iterative)

Stein’s Algorithm (Recursive)

Subtraction-Based GCD

Built-in GCD Functions

Features
Multi-language benchmarks: Python, Java, C, C++

Detailed timing analysis

Input edge cases tested

Comprehensive tables and performance graphs

Getting Started
Prerequisites
Python 3.x

Java (JDK 8+)

GCC (for C) and G++ (for C++)

Excel or spreadsheet software (for data/graph viewing)

Structure
/
├── python/
│   ├── gcd_euclid_iter.py
│   ├── gcd_euclid_rec.py
│   ├── gcd_stein_iter.py
│   ├── gcd_stein_rec.py
│   ├── gcd_subtraction.py
│   └── gcd_builtin.py
├── java/
│   └── GCDAlgorithms.java
├── c/
│   └── gcd_algorithms.c
├── cpp/
│   └── gcd_algorithms.cpp
├── benchmarks/
│   └── results.xlsx
├── blog/
│   └── Comparative-Study-of-GCD-Algorithms-in-Multiple-Languages.pdf
└── README.md
Running Benchmarks
Compile/run each implementation according to the folder instructions.

Use the supplied benchmark scripts or methods inside each language’s directory.

Enter the results in the provided Excel sheet or your own template for analysis and graphing.

Benchmark Setup
System: Intel i5 11th Gen, 8GB RAM, 512GB SSD, 4GB Nvidia GTX 1650

Runtime Environment: As specified in blog/report for each language

Results Overview
C and C++ offer superior performance, especially with built-in functions

Euclidean iterative method is generally fastest for manual implementations

Subtraction method is not recommended for large numbers due to poor efficiency

Built-in methods in each language are highly optimized and preferred for production

Author
Kapil P
Email: kapilpalanisamy73@gmail.com

For full analysis, code, and benchmarking data, see the accompanying blog PDF and code directories.
