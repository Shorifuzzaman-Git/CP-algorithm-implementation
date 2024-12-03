//mice and maze UVA problem

#include<bits/stdc++.h>
using namespace std;
const int N=1e5;

vector<pair<int,int>>g[N];
int dis[N];
set<pair<int,int>>s;

void func(int src){
    dis[src]=0;
    s.insert({dis[src],src});
    while (!s.empty())
    {
        auto top=*s.begin();
        int node=top.second;
        int nodeDis=top.first;
        s.erase(top);
        for(auto neighber:g[node]){
            if(nodeDis+neighber.second<dis[neighber.first]){
                dis[neighber.first]=nodeDis+neighber.second;
                s.insert({dis[neighber.first],neighber.first});
            }
        }
    }
}

int main(){
    //freopen("input.txt","r",stdin);

    int T;
    cin>>T;
    //cout<<endl;
    for(int i=1;i<=T;i++){
        fill(dis,dis+N,INT_MAX);
        int n,ex,t,m;
        cin>>n>>ex>>t>>m;
        while (m--)
        {
            int u,v,w;
            cin>>u>>v>>w;
            g[u].push_back({v,w});
        }
        func(ex);
        int count=0;
        for(int i=1;i<=n;i++){
            if(dis[i]<=t){
                count++;
            }
        }
        if(i>1)cout<<endl;
        cout<<count<<endl;
    }
}

// 2
// 4
// 2
// 1
// 8
// 1 2 1
// 1 3 1
// 2 1 1
// 2 4 1
// 3 1 1
// 3 4 1
// 4 2 1
// 4 3 1
// 4
// 2
// 1
// 8
// 1 2 1
// 1 3 1
// 2 1 1
// 2 4 1
// 3 1 1
// 3 4 1
// 4 2 1
// 4 3 1
