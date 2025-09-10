#include <bits/stdc++.h>
using namespace std;
#define isComposite(n)  (status[n>>5] & (1 << (n & 31))) 
#define setComposite(n)  (status[n>>5] |= (1 << (n & 31)))


const int N = 100000000; // 1e8
int status[(N>>5) + 1];  // array of integers (bit storage)

void bitwiseSieve(int n) {
    int limit = sqrt(n) + 1;

    for (int i = 3; i <= limit; i += 2) {
        if (!isComposite(i)) {
            for (int j = i*i; j <= n; j += i<<1) {
                setComposite(j);
            }
        }
    }

    cout << 2 << " ";
    for (int i = 3; i <= n; i += 2) {
        if (!isComposite(i)) cout << i << " ";
    }
    cout << endl;
}

int main() {
    bitwiseSieve(100);
    return 0;
}
