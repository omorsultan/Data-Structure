//submitted by omor_sultan
#include<bits/stdc++.h>
using namespace std;
signed main() {
    string a, b;
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) 
     for (int j = 1; j <= m; j++) 
        if (a[i - 1] == b[j - 1])   dp[i][j] = 1 + dp[i - 1][j - 1];
        else  dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        
    string lcs = "";
    int i = n, j = m;
    while(i > 0 && j > 0) {
        if(a[i-1] == b[j-1]) 
          lcs += a[i-1], i--, j--;
        else if(dp[i-1][j] > dp[i][j-1]) i--;
        else  j--;
    }
    reverse(lcs.begin(), lcs.end());
    cout << lcs << endl;
}
