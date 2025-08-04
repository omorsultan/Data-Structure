//submitted by omor_sultan
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    
  int N , W;cin>>N>>W;
  vector<int>weight(N),value(N);
  for(int i=0;i<N;i++)
  {
    cin>>weight[i]>>value[i];
  }
  vector<vector<int>>dp(N+1,vector<int>(W+1,0));
  for(int i=1;i<=N;i++)
  {
    for(int w=1;w<=W;w++)
    {
      if(weight[i-1]<=w)
      dp[i][w]=max(dp[i-1][w],dp[i-1][w-weight[i-1]]+value[i-1]);
      else dp[i][w]=dp[i-1][w];
    }
  }
  cout<<dp[N][W];
}
