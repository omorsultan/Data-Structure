//submitted by omor_sultan
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
int n,x;cin>>n>>x;
int c[n];
for(int i=0;i<n;i++)cin>>c[i];
vector<int>dp(x+1,1000009);
dp[0]=0;
for(int i=1;i<=x;i++)
{
  for(int j=0;j<n;j++)
  {
    int coins = c[j];
    if(i-coins>=0)
    dp[i]=min(dp[i],dp[i-coins]+1);
  }
}
if(dp[x]!=1000009)
cout<<dp[x];
else cout<<-1;
}
