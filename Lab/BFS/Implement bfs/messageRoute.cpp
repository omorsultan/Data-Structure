#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll N = 1e6+10;
vector<ll>g[N];
vector<ll>vis(N);
vector<ll>ans;
ll parent[N];
void bfs(ll s,ll n)
{
   
    vis[s]=1;
    queue<ll>q;
    q.push(s);
    while(!q.empty())
    {
        ll u = q.front();
        q.pop();
      if(u==n)return;
        for(ll child : g[u])
        {
            if(!vis[child])
            {
                vis[child]=1;
                q.push(child);
                  parent[child]=u;
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
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
   
    bfs(1,n);
    if(!vis[n])cout<<"IMPOSSIBLE";
    else
    {
        while(n)
        {
            ans.push_back(n);
            n=parent[n];
        }
        cout<<ans.size()<<endl;
        for(ll i=ans.size()-1;i>=0;i--)
        {
            cout<<ans[i]<<" ";
        }
    }
    
}