#include <iostream>
using namespace std;

// Function to find modular inverse of a modulo m using EEA
int modInverse(int a, int m) {
    int s = 1, t = 0, s1 = 0, t1 = 1;
    int b = m;
    int a0 = a;

    while (b != 0) {
        int q = a / b;
        int r = a % b;

        int s_next = s - q * s1;
        int t_next = t - q * t1;

        s = s1; t = t1;
        s1 = s_next; t1 = t_next;

        a = b;
        b = r;
    }

    if (a != 1) return -1; // inverse does not exist
    return (s % m + m) % m; // make positive
}

// CRT Function
int CRT(int a[], int m[], int n) {
    long long M = 1;
    for (int i = 0; i < n; i++) M *= m[i]; // total modulus

    long long x = 0;
    for (int i = 0; i < n; i++) {
        long long Mi = M / m[i];
        long long inv = modInverse(Mi % m[i], m[i]); // inverse of Mi modulo m[i]
        x += (long long)a[i] * Mi * inv;
    }

    x %= M; // reduce modulo total M
    return (x + M) % M; // ensure positive
}

int main() {
    int n;
    cout << "Enter number of congruences: ";
    cin >> n;

    int a[n], m[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter a[" << i << "] and m[" << i << "]: ";
        cin >> a[i] >> m[i];
    }

    int result = CRT(a, m, n);
    cout << "The solution x ≡ " << result << " (mod ";
    long long M = 1;
    for(int i=0;i<n;i++) M *= m[i];
    cout << M << ")" << endl;

    return 0;
}
