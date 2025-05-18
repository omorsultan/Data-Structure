// https://open.kattis.com/problems/shortestpath3
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e6+10;
vector<vector<ll >>g;
ll inf = 1e18+10;
vector<ll>dist(N,inf);
vector<bool>negCycle(N,false);
ll n,m,q,s;
bool bellman(ll src)
{
    dist[src]=0;
    for(ll i=1;i<=n;i++)
    {
        for(vector<ll>child : g)
        {
            ll u=child[0];
            ll v=child[1];
            ll w = child[2];
            if(dist[u]+w<dist[v]&&dist[u]!=inf)
            {
                dist[v]=dist[u]+w;
                if(i==n)return true;
            }
        }
    }
    for(ll i=1;i<=n;i++)
    {
        for(vector<ll>child : g)
        {
            ll u=child[0];
            ll v=child[1];
            ll w = child[2];
            if(dist[u]+w<dist[v]&&dist[u]<inf)
            {
               negCycle[v]=true;
            }
        }
    }
    return false;
}
int main()
{
    bool input = true;
    while(input)
    {
        cin>>n>>m>>q>>s;
        if((n+m+q+s)==0 && s==0){input = false;return 0;}
        g.clear();dist.resize(N,inf);
    for(ll i=0;i<m;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        g.push_back({u,v,w});
    }
    bellman(s);
    for(ll i=0;i<q;i++)
    {
        ll d;cin>>d;
        if(dist[d]==inf)cout<<"Impossible"<<endl;
        else if(negCycle[d]==true)cout<<"-Infinity"<<endl;
        else cout<<dist[d]<<endl;
    }
    cout<<endl;
}
}