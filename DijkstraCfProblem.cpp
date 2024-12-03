#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int

const int N=1e5+10;
vector<pair<int,int>>g[N];
int d[N];
set<pair<int,int>>s;
int p[N];

bool dijkstra(int src,int n){
    d[src]=0;
    p[src]=-1;
    s.insert({0,src});
    while (!s.empty())
    {
        auto it=*s.begin();
        int node=it.second;
        int node_dis=it.first;
        if(node==n)return true;
        s.erase(it);
        for(auto child:g[node]){
            if(node_dis+child.second<d[child.first]){
                d[child.first]=node_dis+child.second;
                s.insert({d[child.first],child.first});
                p[child.first]=node;
            }
        }
    } 
    return false; 
}
int main() {
    fill(d,d+N,INT_MAX);
    fill(p,p+N,-1);
    ll n,m;
    cin>>n>>m;
    while (m--)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    if(dijkstra(1,n)){
        vector<int>par;
        for(int i=n;i>0;i=p[i])par.pb(i);
        reverse(par.begin(),par.end());
        for(int i=0;i<par.size();i++)cout<<par[i]<<' ';
    }else cout<<-1<<endl; 
}