//disjoint set union

#include <bits/stdc++.h>
using namespace std;
const int N=1e3;
int parent[N],Rank[N];

int findParent(int node){
    if(parent[node]==node){
        return node;
    }
    return parent[node]=findParent(parent[node]);
}

void unionSet(int u,int v){
    u=findParent(u);
    v=findParent(v);

    if(Rank[u]<Rank[v]){
        parent[u]=v;
    }
    else if(Rank[u]>Rank[v]){
        parent[v]=u;
    }
    else{
        parent[v]=u;
        Rank[u]++;
    }
}

int main(){
    int n,m;
    cin>>n>>m;//node,edge
    
    for(int i=1;i<=n;i++){
        parent[i]=i;
        Rank[i]=0;
    }

    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        unionSet(u,v);
    }
    
    for(int i=1;i<=n;i++){
        cout<<"parent of "<<i<<" = "<<parent[i]<<endl;
    }
}


// 7 6
// 1 2
// 2 3
// 4 5
// 6 7
// 5 6
// 3 7