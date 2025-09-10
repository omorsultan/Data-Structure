#include <bits/stdc++.h>
using namespace std;
long long m = 1e9 + 7; // modulus

long long binpow(long long a, long long b) {
    long long result = 1;
    while (b > 0) {
        if (b & 1) result = (result * a) % m; // multiply when bit is 1
        a = (a * a) % m; // square a
        b >>= 1; // divide b by 2
    }
    return result;
}

int main() {
    long long a, b;
    cout << "Enter a and b: ";
    cin >> a >> b;

    cout << a << "^" << b << " = " << binpow(a, b) << endl;
    return 0;
}
