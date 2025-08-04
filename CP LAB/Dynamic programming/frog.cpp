//submitted by omor_sultan
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10;
int t[N];
int calculate(int a[],int i)
{
  if(i==0)return 0;
  if(t[i]!=-1)return t[i];
  int cost = INT_MAX;
  
  cost = min(cost,calculate(a,i-1)+abs(a[i-1]-a[i]));
  if(i>1) cost = min(cost, calculate(a,i-2)+abs(a[i-2]-a[i]));
  return t[i]=cost;
}
signed main()
{ 
int n;cin>>n;
int a[n];
for(int i=0;i<n;i++)
cin>>a[i];

 memset(t,-1,sizeof(t));

  cout<<calculate(a,n-1);

}
