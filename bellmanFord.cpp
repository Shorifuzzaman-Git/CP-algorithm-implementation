//bellman ford algorithm
//time complexity = O(n*m)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
vector<vector<int>> g;
int dis[N];
int flag = 0;
int n, m;
void bellmanFord(int src)
{
    dis[src] = 0;
    // for (n-1) loop
    for (int i = 0; i < n - 1; i++){
        for (auto it : g){  //for every node
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if (dis[u] + w < dis[v]){
                dis[v] = dis[u] + w;
            }
        }
    }

    // check negative cycle
    for (auto it : g){
        int u = it[0];
        int v = it[1];
        int w = it[2];
        if (dis[u] + w < dis[v]){
            flag = 1;
        }
    }
}
int main()
{
    fill(dis, dis + N, INT_MAX);
    cin >> n >> m;
    while (m--){
        int u, v, w;
        cin >> u >> v >> w;
        g.push_back({u, v, w});
    }
    bellmanFord(1);
    if (flag == 0){
        for (int i = 1; i <= n; i++){
            cout << dis[i] << ' ';
        }
        cout << endl;
    }
    else{
        cout <<"shortest path not posible"<< endl;
    }
}

// negative value
//  6 9
//  1 2 6
//  1 3 4
//  1 4 5
//  3 2 -2
//  4 3 -2
//  2 5 -1
//  3 5 3
//  4 6 -1
//  5 6 3

// negative value with negative cycle
//  4 5
//  1 2 1
//  1 3 2
//  2 3 2
//  3 4 2
//  4 2 -5