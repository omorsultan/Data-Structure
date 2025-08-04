#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e6+10;
vector<pair<ll,ll>>g[N];
ll inf =1e18+10;
vector<ll>dist(N,inf);
void dijkstra(ll src)
{
    dist[src]=0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    pq.push({0,src});
    while(!pq.empty())
    {
        ll d = pq.top().first;
        ll node = pq.top().second;
        pq.pop();
        if(d>dist[node])continue;
        for(pair<ll,ll>child : g[node])
        {
           ll nextNode= child.first;
           ll weight = child.second;
           if(weight + d< dist[nextNode])
           {
            dist[nextNode]= d + weight;
            pq.push({dist[nextNode],nextNode});
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
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    dijkstra(1);
    for (ll i =1;i<=n;i++)cout<<dist[i]<<" ";
}