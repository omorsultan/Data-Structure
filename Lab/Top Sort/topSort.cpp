#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e6+10;
vector<ll>g[N];
vector<ll>ans;
void topSort(ll* ind,ll n)
{
  queue<ll>q;
  for(ll i=1;i<=n;i++)if(ind[i]==0)q.push(i);
  while(!q.empty())
  {
    ll u=q.front();
    q.pop();
    ans.push_back(u);
    for(ll child : g[u])
    {
       ind[child]--;
       if(ind[child]==0)q.push(child); 
    }
  }
}
int main()
{
  ll n,m;
  cin>>n>>m;
  ll index[n+10]={0};
  for(ll i=0;i<m;i++)
  {
    ll u,v;cin>>u>>v;
    // cin>>u>>v;
    g[u].push_back(v);
    index[v]++;
  }
  topSort(index,n);
  if(ans.size()!=n)cout<<-1<<endl;
  else 
  {
    for(ll i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
  }
}