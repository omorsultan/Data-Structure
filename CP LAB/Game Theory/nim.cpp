#include <bits/stdc++.h>
using namespace std;

// Function to calculate nim-sum
int calculateNimSum(vector<int>& piles) {
    int nimSum = 0;
    for (int pile : piles) {
        nimSum ^= pile; // XOR all pile sizes
    }
    return nimSum;
}

// Function to find best move
pair<int,int> findBestMove(vector<int>& piles) {
    int nimSum = calculateNimSum(piles);
    if (nimSum == 0) {
        return {-1, -1}; // No winning move
    }

    // Try to find a pile to reduce
    for (int i = 0; i < piles.size(); i++) {
        int target = piles[i] ^ nimSum;
        if (target < piles[i]) {
            // Reduce pile[i] to target
            return {i, target};
        }
    }
    return {-1, -1}; 
}

int main() {
    int n;
    cout << "Enter number of piles: ";
    cin >> n;

    vector<int> piles(n);
    cout << "Enter pile sizes: ";
    for (int i = 0; i < n; i++) {
        cin >> piles[i];
    }

    int nimSum = calculateNimSum(piles);
    cout << "\nInitial Nim Sum: " << nimSum << "\n";

    if (nimSum == 0) {
        cout << "This is a losing position. Second player will win.\n";
    } else {
        cout << "This is a winning position. First player can win.\n";
        auto bestMove = findBestMove(piles);
        if (bestMove.first != -1) {
            cout << "Best move: Reduce pile " << bestMove.first+1
                 << " from " << piles[bestMove.first] 
                 << " to " << bestMove.second << "\n";
        }
    }
    return 0;
}
