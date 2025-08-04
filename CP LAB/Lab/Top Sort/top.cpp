#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>ans;
const ll N = 1e6+10;
vector<ll>g[N];
ll n,m;
void topSort(ll *ind, ll n)
{
  queue<ll>q;
  for(ll i=1;i<=n;i++)if(ind[i]==0)q.push(i);
  while(!q.empty())
  {
    ll u = q.front();
    q.pop();
    ans.push_back(u);
    for(ll child:g[u])
    {
      ind[child]--;
      if(ind[child]==0)q.push(child);
    }
  }
}
int main()
{
  cin>>n>>m;
  ll ind[n+10]={0};
  ind[0]=-1;
  for(ll i = 0;i<m;i++)
  {
    ll u,v;cin>>u>>v;
    g[u].push_back(v);
    ind[v]++;
  }
  topSort(ind,n);
  if(n==ans.size())
  {
    for(ll i=0;i<n;i++)
    {
      cout<<ans[i]<<" ";
    }
  }
  else cout<<"IMPOSSIBLE";

}