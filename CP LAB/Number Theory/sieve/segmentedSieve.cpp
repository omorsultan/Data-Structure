// https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html
#include <bits/stdc++.h>
using namespace std;
#define int long long
int count_primes(int n) {
    const int S = 10000;  // block size

    vector<int> primes;
    int nsqrt = sqrt(n);
    vector<char> is_prime(nsqrt + 2, true);

    // Simple sieve till sqrt(n)
    for (int i = 2; i <= nsqrt; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= nsqrt; j += i)
                is_prime[j] = false;
        }
    }

    int result = 0;
    vector<char> block(S);

    for (int k = 0; k * S <= n; k++) {
        fill(block.begin(), block.end(), true);
        int start = k * S;

        // mark composites inside the block
        for (int p : primes) {
            int start_idx = (start + p - 1) / p;  // ceil(start/p)
            int j = max(start_idx, p) * p - start;
            for (; j < S; j += p)
                block[j] = false;
        }

        if (k == 0) block[0] = block[1] = false;  // mark 0,1 not prime

        for (int i = 0; i < S && start + i <= n; i++) {
            if (block[i]) result++;
        }
    }
    return result;
}

signed main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int totalPrimes = count_primes(n);
    cout << "Total primes up to " << n << " = " << totalPrimes << endl;

    return 0;
}
/* Sample Input/Output:
Enter n: 1000000000
Total primes up to 1000000000 = 50847534
*/