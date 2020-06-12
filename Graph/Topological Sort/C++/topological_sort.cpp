#include<bits/stdc++.h>

using namespace std;

// Tested: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_4_B

vector<vector<int>> adj;
vector<bool> visited;
vector<int> toposort;

// Topological Sort - Without detecting cycles
// Standard Implementation
void dfs(int node) {
    if(visited[node]) return;
    visited[node] = true;
    for(int neighbour: adj[node]) {
        dfs(neighbour);
    }
    toposort.push_back(node);
}

int main() {
    
    // Number of vertices
    // Labeled 0 ... n-1
    int n = 7;
    
    adj.resize(n);
    visited.resize(n, false);

    
    // Undirected Graph
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(3);
    adj[1].push_back(3);
    adj[1].push_back(4);
    adj[3].push_back(2);
    adj[4].push_back(3);
    adj[2].push_back(5);
    adj[3].push_back(5);
    adj[3].push_back(6);
    adj[4].push_back(6);
    adj[6].push_back(5);
    
    // O(|V| + |E|)
    // |V|: Number of vertices
    // |E|: Number of edges
    for(int node = 0; node < n; ++node) {
        if(!visited[node]) {
            dfs(node);
        }
    }
    
    reverse(toposort.begin(), toposort.end());
    
    for(int i = 0; i < toposort.size(); ++i) {
        cout << toposort[i] << " ";
    }
    cout << endl;
    // Out:
    // 0 1 4 3 6 2 5
    
    return 0;
}