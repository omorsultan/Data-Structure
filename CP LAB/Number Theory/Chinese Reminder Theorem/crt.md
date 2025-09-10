# Chinese Remainder Theorem (CRT)

---

## 🔹 System of Congruences

Solve a system:

```
x ≡ a1 (mod m1)
x ≡ a2 (mod m2)
x ≡ a3 (mod m3)
...
x ≡ ak (mod mk)
```

where all moduli m1, m2, ..., mk are **pairwise coprime**.

---

### 🔹 Theorem

If moduli are pairwise coprime, the system has a **unique solution modulo**

```
M = m1 * m2 * ... * mk
```

---

### 🔹 Formula (CRT)

1. Compute total modulus:

```
M = m1 * m2 * ... * mk
```

2. For each congruence, compute:

```
Mi = M / mi
```

3. Find inverse:

```
invi = Mi^-1 (mod mi)
```

4. Solution:

```
x = Σ (ai * Mi * invi)  (mod M)
```

---

### 🔹 Example

Solve:

```
x ≡ 2 (mod 3)
x ≡ 3 (mod 4)
x ≡ 2 (mod 5)
```

**Step 1: Total modulus**

```
M = 3 * 4 * 5 = 60
```

**Step 2: Compute Mi and inverse**

* Modulus 3: M1 = 60 / 3 = 20, inverse = 20^-1 (mod 3) = 2
* Modulus 4: M2 = 60 / 4 = 15, inverse = 15^-1 (mod 4) = 3
* Modulus 5: M3 = 60 / 5 = 12, inverse = 12^-1 (mod 5) = 3

**Step 3: Plug into formula**

```
x = 2*20*2 + 3*15*3 + 2*12*3
x = 80 + 135 + 72 = 287
```

**Step 4: Reduce modulo M**

```
x ≡ 287 (mod 60) ≡ 47 (mod 60)
```

✅ Final solution:

```
x ≡ 47 (mod 60)
```

---

### 🔹 Summary

* CRT combines multiple modular equations into one.
* Works **only if moduli are pairwise coprime**.
* Formula uses modular inverses with respect to each modulus.
