//submitted by omor_sultan
#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{ 
int n;cin>>n;

int a[3][n];
int dp[3][n];

for(int i=0; i<n; i++)
{
  cin>>a[0][i]>>a[1][i]>>a[2][i];
}
dp[0][0]=a[0][0];
dp[1][0]=a[1][0];
dp[2][0]=a[2][0];

for(int i=1 ; i<n; i++)
{
  dp[0][i]=a[0][i]+max(dp[1][i-1],dp[2][i-1]);
  dp[1][i]=a[1][i]+max(dp[0][i-1],dp[2][i-1]);
  dp[2][i]=a[2][i]+max(dp[0][i-1],dp[1][i-1]);
}
int ans = max({dp[0][n-1],dp[1][n-1],dp[2][n-1]});
cout<<ans<<endl;

}
