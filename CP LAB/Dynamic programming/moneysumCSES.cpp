#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;cin>>n;
  vector<int>coins(n);
  int sum = 0  , count = 0;
  for(int i=0;i<n;i++)cin>>coins[i],sum+=coins[i];
  vector<int>dp(sum+1,0);
  dp[0]=1;
  for(int &coin:coins)
  {
    for(int i=sum;i>=coin;i--)
    {
      dp[i]=max(dp[i],dp[i-coin]);
    }
  }
 
  vector<int>v;
  for(int i=1;i<=sum;i++)
  if(dp[i]>=1)v.push_back(i),count++;
  cout<<count<<endl;
  for(int &num:v)cout<<num<<" ";
  
}