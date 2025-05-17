#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll N = 1e6 +10;
vector<ll>g[N];
vector<ll>vis(N);
vector<ll>ans;
void bfs(ll s)
{
    vis[s]=1;
    queue<ll>q;
    q.push(s);
    while(!q.empty())
    {
        ll u = q.front();
        q.pop();
        ans.push_back(u);
        for(ll child:g[u])
        {
            if(!vis[child])
            {
                vis[child]=1;
                q.push(child);
            }
        }
    }
}
int main()
{
    ll n,m;
    cin>>n>>m;
    for(ll i=0;i<m;i++)
    {
        ll u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs(1);
    for(ll i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}