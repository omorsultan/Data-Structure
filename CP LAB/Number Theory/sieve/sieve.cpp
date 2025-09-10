#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    // Step 1: Initialize all numbers as prime
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime

    // Step 2: Sieve process
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }

    // Step 3: Collect and print primes
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i])
            primes.push_back(i);
    }

    cout << "Primes up to " << n << " are:\n";
    for (int p : primes) cout << p << " ";
    cout << "\nTotal primes = " << primes.size() << endl;

    return 0;
}
/* Sample Input/Output:
Enter n: 50
Primes up to 50 are:
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47
Total primes = 15
*/