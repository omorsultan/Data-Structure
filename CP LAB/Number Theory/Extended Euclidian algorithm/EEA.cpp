/* video link : https://www.youtube.com/watch?v=-uFc7-wOplM&t=40s&ab_channel=ShrenikJain */
#include <bits/stdc++.h>
using namespace std;

// Iterative Extended Euclidean Algorithm
// Returns gcd(a, b) and sets s, t such that a*s + b*t = gcd(a, b)
long long extendedGCD(long long a, long long b, long long &s, long long &t) {
    long long s0 = 1, t0 = 0;
    long long s1 = 0, t1 = 1;
    long long r0 = a, r1 = b;

    while (r1 != 0) {
        long long q = r0 / r1;

        long long r2 = r0 - q * r1;
        r0 = r1;
        r1 = r2;

        long long s2 = s0 - q * s1;
        s0 = s1;
        s1 = s2;

        long long t2 = t0 - q * t1;
        t0 = t1;
        t1 = t2;
    }

    s = s0;
    t = t0;
    return r0; // gcd
}

int main() {
    long long a, b;
    cout << "Enter a and b: ";
    cin >> a >> b;

    long long s, t;
    long long g = extendedGCD(a, b, s, t);

    cout << "GCD(" << a << ", " << b << ") = " << g << "\n";
    cout << "Coefficients: s = " << s << ", t = " << t << "\n";
    cout << "Check: " << a << "*" << s << " + " << b << "*" << t << " = " << a*s + b*t << "\n";

    return 0;
}
