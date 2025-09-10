# Linear Sieve (Euler’s Sieve) সহজে বোঝা

## Idea

- Normal sieve এ একটি composite number অনেক বার mark হয়।  
- Linear sieve এ প্রত্যেক composite number ঠিক একবারই mark হয়।  
- তাই এটা **O(n)** সময়ে কাজ করে।  

## কিভাবে কাজ করে

1. একটা `primes` vector রাখো → সব prime numbers রাখার জন্য।  
2. একটা `isPrime[n+1]` array রাখো → কোন number prime কিনা দেখার জন্য।  

## Step by step

1. 2 থেকে n পর্যন্ত loop চালাও।  
2. যদি i prime হয় → `primes` এ push করো।  
3. প্রতিটি prime `p` এর জন্য:  
   - যদি `i * p > n` → break।  
   - `i * p` mark করো composite হিসেবে।  
   - যদি `i % p == 0` → break (এটি নিশ্চিত করে যে, প্রতিটি composite একবারেই mark হবে)।  

## উদাহরণ (n = 10)

i = 2 → prime → primes = [2]
2*2 = 4 → mark composite

i = 3 → prime → primes = [2,3]
32 = 6 → mark composite
33 = 9 → mark composite

i = 4 → already composite → skip

i = 5 → prime → primes = [2,3,5]
শেষ পর্যন্ত primes = [2,3,5,7]
## সুবিধা

- প্রতিটি composite একবারেই mark হয়।  
- Normal sieve → O(n log log n)  
- Linear sieve → O(n) → বড় n এর জন্য অনেক দ্রুত।  
