#include <bits/stdc++.h>
using namespace std;

// Sieve to precompute primes up to limit
vector<int> sieve(int limit) {
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= limit; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i)
                isPrime[j] = false;
        }
    }
    vector<int> primes;
    for (int i = 2; i <= limit; i++)
        if (isPrime[i]) primes.push_back(i);
    return primes;
}

// Prime factorization using precomputed primes
void primeFactorization(long long n, const vector<int> &primes) {
    for (int p : primes) {
        if (1LL * p * p > n) break;
        while (n % p == 0) {
            cout << p << " ";
            n /= p;
        }
    }
    if (n > 1) cout << n; // remaining prime
}

int main() {
    long long n;
    cout << "Enter number: ";
    cin >> n;

    int limit = sqrt(n) + 1;
    vector<int> primes = sieve(limit);

    cout << "Prime factors: ";
    primeFactorization(n, primes);
    cout << endl;

    return 0;
}
