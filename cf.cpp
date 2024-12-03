#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Function to perform BFS and find the path from start to end node
vector<int> bfsPath(int start, int end, const vector<vector<int>>& adjList) {
    if (start == end) {
        return {start};
    }

    queue<int> q;
    vector<bool> visited(adjList.size(), false);
    unordered_map<int, int> parent;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : adjList[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = current;
                q.push(neighbor);

                if (neighbor == end) {
                    vector<int> path;
                    for (int node = end; node != start; node = parent[node]) {
                        path.push_back(node);
                    }
                    path.push_back(start);
                    reverse(path.begin(), path.end());
                    return path;
                }
            }
        }
    }

    return {};
}

int main() {
    int nodes, edges;
    cout << "Enter the number of nodes: ";
    cin >> nodes;

    vector<vector<int>> adjList(nodes);

    cout << "Enter the number of edges: ";
    cin >> edges;

    cout << "Enter each edge as a pair of nodes (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);  // If the graph is undirected
    }

    int start, end;
    cout << "Enter the start node: ";
    cin >> start;
    cout << "Enter the end node: ";
    cin >> end;

    vector<int> path = bfsPath(start, end, adjList);

    if (!path.empty()) {
        cout << "Path from " << start << " to " << end << ": ";
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "No path found from " << start << " to " << end << endl;
    }

    return 0;
}
