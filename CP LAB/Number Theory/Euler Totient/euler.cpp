#include <bits/stdc++.h>
using namespace std;

vector<long long> computeTotient(int n) {
    vector<long long> phi(n + 1);
    for (int i = 0; i <= n; i++) phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) { // i is prime
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    return phi;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<long long> phi = computeTotient(n);
    cout << "Euler's Totient function for numbers 1 to " << n << ":\n";
    for (int i = 1; i <= n; i++)
        cout << "φ(" << i << ") = " << phi[i] << "\n";

    return 0;
}
