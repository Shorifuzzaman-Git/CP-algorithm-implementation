//krushkals algorithm
//time complexity = O(m log(m))

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
vector<vector<int>>g;
int parent[N];
vector<int>Rank(N,0);
int n,m;

void makeSet(int n){
    for(int i=1;i<=n;i++){
        parent[i]=i;
        // Rank[i]=0;
    }
}

int findParent(int node){
    if(parent[node]==node)return node;
    return parent[node]=findParent(parent[node]);
}

void Union(int u,int v){
    u=findParent(u);
    v=findParent(v);

    if(Rank[u]<Rank[v]){
        parent[u]=v;
    }
    else if(Rank[u]>Rank[v]){
        parent[v]=u;
    }
    else{
        parent[u]=v;
        Rank[u]++;
    }
}

int MST(){
    int minWeight=0,count=0;
    for(auto it:g){
        int w=it[0];
        int u=it[1];
        int v=it[2];

        u=findParent(u);
        v=findParent(v);
        if(u!=v && count<n){
            Union(u,v);
            minWeight+=w;
            count++;
        }
    }
    return minWeight;
}

int main()
{
    cin>>n>>m;
    makeSet(n);
    while (m--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g.push_back({w,u,v});
    }
    sort(g.begin(),g.end()); //O(m log(m))
    int ans=MST();
    cout<<ans;
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