/* Modular inverse বের করার ২টা main method আছে:
    1. EEA (Extended Euclidean Algorithm) – সব ক্ষেত্রে কাজ করে।
    2. Binary Exponentiation (Fast Power) – যখন modulus 𝑚
         prime number হয় (Fermat's Little Theorem use হয়)।
*/
#include <iostream>
using namespace std;

// Binary Exponentiation
long long power(long long a, long long b, long long m) {
    long long res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

// Modular inverse (when m is prime)
long long modInverse(long long a, long long m) {
    return power(a, m - 2, m); // Fermat's Little Theorem
}

int main() {
    long long a, m;
    cout << "Enter a and prime modulus m: ";
    cin >> a >> m;

    cout << "Modular inverse of " << a << " modulo " << m 
         << " is " << modInverse(a, m) << endl;

    return 0;
}
