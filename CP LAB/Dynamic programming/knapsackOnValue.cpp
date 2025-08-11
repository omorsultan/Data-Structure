// submitted by omor_sultan
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e18

signed main() 
{
    int n, W;  cin >> n >> W;
    vector<int> wt(n), val(n);
    for (int i = 0; i < n; i++) {cin >> wt[i];cin>>val[i];}
   int MAX_VAL = n*1000; 
    vector<int> dp(MAX_VAL + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < n; i++) 
        for (int v = MAX_VAL; v >= val[i]; v--) 
            dp[v] = min(dp[v], dp[v - val[i]] + wt[i]);
    int ans = 0;
    for (int v = 0; v <= MAX_VAL; v++) {
        if (dp[v] <= W) ans = v;
    }
    cout <<ans<< endl;
}
