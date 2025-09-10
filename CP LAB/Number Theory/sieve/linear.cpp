#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> primes;
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= n; i++) {
        if (isPrime[i])
            primes.push_back(i);

        for (int p : primes) {
           
            if (i * p > n) break;
//              cout<<i<<" "<<p<<" "<<i*p<<endl; // for understanding
            isPrime[i * p] = false;
            if (i % p == 0) break; // ensures each composite marked once
        }
    }

    cout << "Primes up to " << n << " are:\n";
    for (int p : primes) cout << p << " ";
    cout << "\nTotal primes = " << primes.size() << endl;

    return 0;
}
