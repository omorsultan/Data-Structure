#include <bits/stdc++.h>
using namespace std;

void primeFactorization(long long n) {
    for (long long i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }
    if (n > 1) cout << n; // remaining prime
}

int main() {
    long long n;
    cout << "Enter number: ";
    cin >> n;

    cout << "Prime factors: ";
    primeFactorization(n);
    cout << endl;

    return 0;
}
