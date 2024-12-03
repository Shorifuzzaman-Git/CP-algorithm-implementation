//prims algorithm
//time complexity = O(m log(m)), same as dijkstra algorithm
//prims easy > krushkals
#include<bits/stdc++.h>
using namespace std;

const int N=1e3;
int n,m;
vector<vector<int>>g[N];
vector<int>dis(N,INT_MAX),parent(N,-1);
vector<int>vis(N,0);
int cost=0;

void primsMST(int src){
    set<vector<int>>s;//({dis,src})
    dis[src]=0;
    s.insert({0,src});
    
    while(!s.empty()){
        auto it=*s.begin();
        int node=it[1];
        int v=parent[it[1]];
        int nodeDis=it[0];
        vis[node]=1;
        s.erase(it);

        cout<<node<<' '<<v<<' '<<nodeDis<<endl; //node->parent->weight
        cost+=nodeDis;
        for(auto neighber : g[node]){  //g[0] or neighber[0]=node, g[1] or neighber[1]=weight
            if(vis[neighber[0]]==1){
                continue;
            }
            if(dis[neighber[0]]> neighber[1]){
                s.erase({dis[neighber[0]],neighber[0]});
                dis[neighber[0]]=neighber[1];
                s.insert({dis[neighber[0]],neighber[0]});
                parent[neighber[0]]=node;
            }
        }
    }
    cout<<cost;
}

int main(){
    cin>>n>>m;
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    primsMST(1);
    //cout<<cost;
}

// 6 9
// 1 2 1
// 1 3 5
// 2 3 4
// 2 4 6
// 3 4 2
// 3 5 3
// 4 5 1
// 4 6 4
// 5 6 3