
// This the 1st time code . It gonna be wrong

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5+10;
vector<ll>g[N];
vector<ll>visited(N);
vector<ll>ans;

void dfs(ll src)
{
    visited[src]=1;
    ans.push_back(src);
    for(ll child : g[src]){
        if(!visited[child])dfs(child);
    }
    
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        ll u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    for(ll i = 0 ;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}