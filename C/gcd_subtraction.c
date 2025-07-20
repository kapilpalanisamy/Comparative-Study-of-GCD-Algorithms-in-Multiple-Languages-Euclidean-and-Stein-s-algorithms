#include <stdio.h>
#include <time.h>

typedef long long ll;

typedef struct {
    const char* label;
    ll a;
    ll b;
} TestInput;

// GCD using Repeated Subtraction
ll gcd_subtraction(ll a, ll b) {
    if (a == 0) return b;
    if (b == 0) return a;
    while (a != b) {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}

// Timestamp generator
char* get_timestamp() {
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    static char buf[64];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", t);
    return buf;
}

int main() {
    TestInput tests[] = {
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
        {"11-digit", 12345678901LL, 10987654321LL},
        {"12-digit", 123457000000LL, 210988000000LL},
        {"13-digit", 1234570000000LL, 3210990000000LL},
        {"14-digit", 12345700000000LL, 43211000000000LL},
        {"15-digit", 123457000000000LL, 543211000000000LL},
    };

    int n = sizeof(tests) / sizeof(tests[0]);

    printf("Input A\tInput B\tGCD Result\tTime (s)\tTime (ns)\tTimestamp\n");

    for (int i = 0; i < n; i++) {
        clock_t start = clock();
        char* timestamp_start = get_timestamp();

        ll result = gcd_subtraction(tests[i].a, tests[i].b);

        clock_t end = clock();
        char* timestamp_end = get_timestamp();

        double time_sec = (double)(end - start) / CLOCKS_PER_SEC;
        long long time_ns = (long long)((end - start) * (1e9 / CLOCKS_PER_SEC));

        printf("%lld\t%lld\t%lld\t%.9f\t%lld\t%s - %s\n",
               tests[i].a, tests[i].b, result,
               time_sec, time_ns,
               timestamp_start, timestamp_end);
    }

    return 0;
}
