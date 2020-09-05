#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> longest_path;

void dfs(int node) {
    visited[node] = true;
    for(int neighbor: adj[node]) {
        if(!visited[neighbor]) { 
            dfs(neighbor);
        }
        longest_path[node] = max(longest_path[node], 1 + longest_path[neighbor]);
    }
}

auto main() -> int {
    int n = 4;
    adj.resize(n);
    visited.resize(n, false);
    longest_path.resize(n, 0);

    // https://www.geeksforgeeks.org/longest-path-in-a-directed-acyclic-graph-dynamic-programming/
    // https://img.atcoder.jp/dp/longest_0_muffet.png

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[2].push_back(1);
    adj[1].push_back(3);
    adj[2].push_back(3);

    for(int node = 0; node < n; ++node) {
        if(!visited[node]) {
            dfs(node);
        }
    }
    
    for(int &x: longest_path) cout << x << " ";
    // Index:        0 1 2 3
    // longest_path: 3 1 2 0 

    cout << *max_element(longest_path.begin(), longest_path.end()) << endl;

    return 0;
}