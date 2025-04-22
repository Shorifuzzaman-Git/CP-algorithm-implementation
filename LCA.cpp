//Complexity O(n)

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

vector<int>g[N];
vector<int>par(N);

void dfs(int node,int p){ //run n times
    par[node]=p;
    for(auto child:g[node]){
        if(child==p)continue;
        dfs(child,node);
    }
}

vector<int> path(int node){ //run n times
    vector<int>ans;
    while (node!=-1){
        ans.push_back(node);
        node=par[node];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1,-1);
    int x,y;
    cin>>x>>y;

    vector<int>path_x=path(x);
    vector<int>path_y=path(y);

    int min_length =min(path_x.size(),path_y.size());
    int lca=-1;
    for(int i=0;i<min_length;i++){
        if(path_x[i]==path_y[i]){
            lca=path_x[i];
        }
        else{
            break;
        }
    }
    cout<<lca<<endl;

}

// 12
// 1 2
// 1 3
// 1 13
// 2 5
// 5 6
// 5 7
// 5 8
// 8 12
// 3 4
// 4 9
// 4 10
// 10 11
// 6 7

//output 5