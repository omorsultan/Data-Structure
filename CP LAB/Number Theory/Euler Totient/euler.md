# Euler's Totient Function (φ(n))

---

## 🔹 What is Euler’s Totient Function?

For a number `n`, φ(n) = count of integers from 1 to n that are **coprime with n**.

**Coprime:** Two numbers a and b are coprime if GCD(a, b) = 1.

**Example:** n = 9

Numbers ≤ 9: 1, 2, 3, 4, 5, 6, 7, 8, 9

Coprime with 9: 1, 2, 4, 5, 7, 8 → 6 numbers

So, φ(9) = 6

---

## 🔹 Properties

* φ(p) = p - 1, if p is prime
* φ(a \* b) = φ(a) \* φ(b), if GCD(a, b) = 1 (multiplicative property)
* If n = p1^a1 \* p2^a2 \* ... \* pk^ak (prime factorization):

```
φ(n) = n * (1 - 1/p1) * (1 - 1/p2) * ... * (1 - 1/pk)
```

---

## 🔹 How to Compute φ(n)

### 1. Using Prime Factorization

* Factorize n into primes.
* Apply formula: φ(n) = n \* Π(1 - 1/p)

**Example:** n = 12 = 2^2 \* 3^1

```
φ(12) = 12 * (1 - 1/2) * (1 - 1/3) = 12 * 1/2 * 2/3 = 4
```

### 2. Using Sieve for All Numbers ≤ n (Efficient)

* Precompute φ\[1..n] in O(n log log n) using modified Sieve of Eratosthenes.

**C++ Code: Compute φ for all numbers ≤ n**

```cpp
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
```

**Example Run:**

```
Enter n: 10
φ(1) = 1
φ(2) = 1
φ(3) = 2
φ(4) = 2
φ(5) = 4
φ(6) = 2
φ(7) = 6
φ(8) = 4
φ(9) = 6
φ(10) = 4
```

---

✅ **Notes:**

* O(n log log n) method is very fast for large n.
* Useful in GCD sum problems, modular arithmetic, and number theory problems.
