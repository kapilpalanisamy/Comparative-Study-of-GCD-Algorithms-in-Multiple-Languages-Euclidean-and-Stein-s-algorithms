#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>
#include <iomanip>
#include <ctime>

using namespace std;
using namespace chrono;

struct TestInput {
    string label;
    long long a;
    long long b;
};

long long gcdIterative(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

string currentTimestamp() {
    time_t now = time(0);
    char buf[80];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&now));
    return string(buf);
}

int main() {
    vector<TestInput> tests = {
        {"1-digit", 8, 3},
        {"2-digit", 48, 18},
        {"3-digit", 210, 45},
        {"4-digit", 1234, 4321},
        {"5-digit", 12345, 54321},
        {"6-digit", 123456, 789012},
        {"7-digit", 1000001, 7000001},
        {"8-digit", 12345678, 87654321},
        {"9-digit", 123456789, 987654321},
        {"10-digit", 1234567890, 9876543210},
        {"Both same", 55555, 55555},
        {"One is zero", 0, 1234567890},
        {"Large + small", 1, 999999937},
        {"Power of 2", 1048576, 32768},
        {"Large primes", 982451653, 57885161},
        {"11-digit", 12345678901, 10987654321},
        {"12-digit", 123457000000, 210988000000},
        {"13-digit", 1234570000000, 3210990000000},
        {"14-digit", 12345700000000, 43211000000000},
        {"15-digit", 123457000000000, 543211000000000},
    };

    ofstream file("gcd_euclidean_iterative_results.csv");
    file << "Input A\tInput B\tGCD Result\tTime Taken (s)\tTime Taken (\u03bcs)\tTime Taken (ns)\tMemory Used (KB)\tTimestamp\n";

    for (const auto& test : tests) {
        auto start_time = high_resolution_clock::now();
        string timestampStart = currentTimestamp();

        long long result = gcdIterative(test.a, test.b);

        auto end_time = high_resolution_clock::now();
        string timestampEnd = currentTimestamp();

        auto duration_us = duration_cast<microseconds>(end_time - start_time).count();
        auto duration_ns = duration_cast<nanoseconds>(end_time - start_time).count();
        double duration_sec = duration_ns / 1e9;
        string memUsed = "NA";

        // Print to console
        cout << test.a << "\t"
             << test.b << "\t"
             << result << "\t"
             << fixed << setprecision(7) << duration_sec << "\t"
             << duration_us << "\t"
             << duration_ns << "\t"
             << memUsed << "\t"
             << timestampStart << " - " << timestampEnd << endl;

        // Write to CSV
        file << test.a << "\t"
             << test.b << "\t"
             << result << "\t"
             << fixed << setprecision(7) << duration_sec << "\t"
             << duration_us << "\t"
             << duration_ns << "\t"
             << memUsed << "\t"
             << timestampStart << " - " << timestampEnd << "\n";
    }

    file.close();
    cout << "\n✅ CSV file 'gcd_euclidean_iterative_results.csv' generated successfully.\n";
    return 0;
}