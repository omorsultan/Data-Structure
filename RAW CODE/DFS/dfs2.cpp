#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e6+10;
vector<ll >g[N];
vector<ll>vis(N);
vector<ll>ans;
void dfs(ll s)
{
    vis[s]=1;
    ans.push_back(s);
    for(ll child : g[s])
    {
        if(!vis[child])dfs(child);
    }
}
int main()
{
    ll n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    for(ll i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}