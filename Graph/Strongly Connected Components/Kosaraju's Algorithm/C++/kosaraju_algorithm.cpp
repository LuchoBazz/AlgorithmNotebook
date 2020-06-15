// Made by Luis Miguel Baez
// es.luismiguelbaez@gmail.com

#include <bits/stdc++.h>
 
using namespace std;

#define endl '\n'

vector<vector<int>> adj;
vector<vector<int>> radj;
vector<bool> visited;
stack<int> toposort;

int n, m;


void toposort_dfs(int node) {
    visited[node] = true;
    for(int neighbour: adj[node]) {
        if(!visited[neighbour]) {
            toposort_dfs(neighbour);
        }
    }
    toposort.push(node);
}

void fillVisited() {
    for(int i = 0; i < visited.size(); ++i) visited[i] = false;
}

void kosaraju_dfs(int node) {
    visited[node] = true;
    
    cout << node << " ";
    
    for(int neighbour: radj[node]) {
        if(!visited[neighbour]) {
            kosaraju_dfs(neighbour);
        }
    }
}

void kosaraju() {
    for(int node = 0; node < n; ++node) {
        if(!visited[node]) {
            toposort_dfs(node);
        }
    }
    
    fillVisited();
    
    while(toposort.size()) {
        int node = toposort.top();
        toposort.pop();
        
        if(!visited[node]) {
            kosaraju_dfs(node);
            cout << endl;
        }
    }
    
}

    
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int u, v;

    cin >> n >> m;
    
    adj.resize(n);
    radj.resize(n);
    visited.resize(n, false);
    ans.resize(m, false);

    for(int i = 0; i < m; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
    
    kosaraju();

    return 0;
}