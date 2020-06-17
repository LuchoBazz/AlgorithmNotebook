// Made by Luis Miguel Baez
// es.luismiguelbaez@gmail.com

#include <bits/stdc++.h>
 
using namespace std;

// https://codeforces.com/blog/entry/71146
// https://www.geeksforgeeks.org/bridge-in-a-graph/

class Bridges {
    vector<vector<int>> adj;
    vector<bool> visited;
    vector<int> low;
    // Order in which it was visited
    vector<int> order;
    // Answer:
    vector<pair<int, int>> bridges;
    // Number of Vertex
    int vertex;
    // Count the components
    int cnt;
public:
    
    Bridges(int vertex) : vertex(vertex), cnt(0) {
        low.clear();     
        order.clear();    
        visited.clear();
        
        adj.resize(vertex);
        low.resize(vertex, 0);
        order.resize(vertex, 0);
        visited.resize(vertex, false);
    }
    
    void addEdge(int left, int right) {
        adj[left].push_back(right);
        adj[right].push_back(left);
    }
    
    void dfs(int node, int parent = -1) {
        visited[node] = true;
        order[node] = low[node] = ++cnt; 
        
        for (int neighbour: adj[node]) { 
            if (!visited[neighbour]) { 
                dfs(neighbour, node); 
                low[node] = min(low[node], low[neighbour]);

                if (low[neighbour] > order[node]) {
                    bridges.push_back({node, neighbour});
                }
            } else if (neighbour != parent)  {
                low[node] = min(low[node], order[neighbour]); 
            }
        }
    }

    vector<pair<int, int>> build() {
        cnt = 0;
        for (int node = 0; node < adj.size(); node++) {
            if (!visited[node]) {
                dfs(node);
            }
        }
        return bridges;
    }
};


int main() {
    int vertex = 9, edges = 10;
    
    Bridges B(vertex);
    
    B.addEdge(0, 1);
    B.addEdge(0, 2);
    B.addEdge(1, 2);
    B.addEdge(2, 3);
    B.addEdge(3, 4);
    B.addEdge(2, 5);
    B.addEdge(5, 6);
    B.addEdge(6, 7);
    B.addEdge(7, 8);
    B.addEdge(8, 5);
    
    vector<pair<int, int>> bridges = B.build();
    
    for(pair<int, int> bridge: bridges) {
        cout << bridge.first << " " << bridge.second << endl;
    }
    
    // Out:
    // 3 4
    // 2 3
    // 2 5

    // ----------------------------

    // Index: [0 1 2] [3] [4] [5 6 7 8]
    // Order: [1 2 3] [4] [5] [6 7 8 9]
    // Low:   [1 1 1] [4] [5] [6 6 6 6]

    return 0;
}
