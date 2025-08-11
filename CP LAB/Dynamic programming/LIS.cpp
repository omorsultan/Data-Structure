#include<bits/stdc++.h>
using namespace std;
#define int long long
int  LIS(vector<int>&arr)
{
  vector<int>sub;
  for(int &num:arr)
  {
    auto it = lower_bound(sub.begin(),sub.end(),num);
    if(it==sub.end())sub.push_back(num);
    else *it = num;
  }
  return sub.size();
}
signed main()
{
  int n;cin>>n;
  vector<int>arr(n);
  for(int i=0 ; i<n ; i++)cin>>arr[i];
  cout<<LIS(arr);
}