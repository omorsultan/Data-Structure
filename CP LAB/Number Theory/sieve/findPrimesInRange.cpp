#include <bits/stdc++.h>
using namespace std;
#define int long long
// Simple sieve up to sqrt(R)
vector<int> simpleSieve(int limit) {
    vector<char> mark(limit + 1, true);
    vector<int> primes;

    for (int i = 2; i * i <= limit; i++) {
        if (mark[i]) {
            for (int j = i * i; j <= limit; j += i)
                mark[j] = false;
        }
    }
    for (int i = 2; i <= limit; i++) {
        if (mark[i]) primes.push_back(i);
    }
    return primes;
}

// Segmented sieve for range [L, R]
vector<long long> segmentedSieve(long long L, long long R) {
    long long limit = sqrt(R) + 1;
    vector<int> primes = simpleSieve(limit);

    vector<char> isPrime(R - L + 1, true);

    for (int p : primes) {
        long long start = max(p * 1LL * p, ((L + p - 1) / p) * 1LL * p);
        for (long long j = start; j <= R; j += p) {
            isPrime[j - L] = false;
        }
    }

    if (L == 1) isPrime[0] = false;

    vector<long long> result;
    for (long long i = 0; i <= R - L; i++) {
        if (isPrime[i]) result.push_back(L + i);
    }
    return result;
}

signed main() {
    long long L, R;
    cout << "Enter range [L R]: ";
    cin >> L >> R;

    vector<long long> primes = segmentedSieve(L, R);

    cout << "Primes in range [" << L << ", " << R << "] are:\n";
    for (long long p : primes) cout << p << " ";
    cout << "\nTotal primes = " << primes.size() << endl;

    return 0;
}
/* Sample Input/Output:
Enter range [L R]: 100000000 100000009
Primes in range [100000000, 100000009] are:
100000007
Total primes = 1
*/