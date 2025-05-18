#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>>g;
ll inf = 1e18+10;
const ll N = 1e6+10;
ll n,m;
vector<ll>dist(N,inf);
bool bellman(ll src)
{
    dist[src]=0;
    for(ll i=1;i<=n;i++)
    {
        for(vector<ll>child : g)
        {
            ll u=child[0];
            ll v=child[1];
            ll w=child[2];
            if(dist[u]+w<dist[v]&&dist[u]!=inf)
            {
                dist[v]=dist[u]+w;
                if(i==n)return true;
            }
        }
    } return false;
}
int main()
{
    cin>>n>>m;
    for(ll i=0;i<m;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
       g.push_back({u,v,w});
    }
   
    if(!bellman(1))
    for(ll i=1;i<=n;i++)cout<<dist[i]<<" ";
    else cout<<-1;
    
}