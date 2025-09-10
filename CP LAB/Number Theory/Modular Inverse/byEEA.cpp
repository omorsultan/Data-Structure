/* Modular inverse বের করার ২টা main method আছে:
    1. EEA (Extended Euclidean Algorithm) – সব ক্ষেত্রে কাজ করে।
    2. Binary Exponentiation (Fast Power) – যখন modulus 𝑚
         prime number হয় (Fermat's Little Theorem use হয়)।
*/
#include <iostream>
using namespace std;

// Iterative Extended Euclidean Algorithm
int modInverse(int a, int m) {
    int s = 1, t = 0;
    int s1 = 0, t1 = 1;
    int b = m;

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

    if (a != 1) return -1; // inverse doesn't exist
    return (s % m + m) % m; // make it positive
}

int main() {
    int a, m;
    cout << "Enter a and modulus m: ";
    cin >> a >> m;

    int inv = modInverse(a, m);
    if (inv == -1)
        cout << "Modular inverse does not exist" << endl;
    else
        cout << "Modular inverse of " << a << " modulo " << m << " is " << inv << endl;

    return 0;
}
