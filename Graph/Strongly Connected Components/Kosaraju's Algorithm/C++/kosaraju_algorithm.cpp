// Made by Luis Miguel Baez
// es.luismiguelbaez@gmail.com

#include <bits/stdc++.h>
 
using namespace std;


class SCC_Kosaraju {
    vector<vector<int>> adj;
    vector<vector<int>> radj;
    vector<bool> visited;
    stack<int> toposort;
    vector<vector<int>> components;
    int vertex;
public:
    
    SCC_Kosaraju(int vertex) : vertex(vertex) {
        adj.resize(vertex);
        radj.resize(vertex);
        visited.resize(vertex, false);
    }
    
    void addEdge(int from, int to) {
        adj[from].push_back(to);
        radj[to].push_back(from);
    }
    
    // Topological Sort
    void toposort_dfs(int node) {
        visited[node] = true;
        for(int neighbour: adj[node]) {
            if(!visited[neighbour]) {
                toposort_dfs(neighbour);
            }
        }
        toposort.push(node);
    }

    // dfs Standard
    void dfs(int node) {
        visited[node] = true;

        components.back().push_back(node);

        for(int neighbour: radj[node]) {
            if(!visited[neighbour]) {
                dfs(neighbour);
            }
        }
    }

    // Build Algorithm
    vector<vector<int>> build() {
        for(int node = 0; node < vertex; ++node) {
            if(!visited[node]) {
                toposort_dfs(node);
            }
        }

        fill(visited.begin(), visited.end(), false);

        while(!toposort.empty()) {
            int node = toposort.top();
            toposort.pop();
            if(!visited[node]) {
                components.push_back(vector<int>{});
                dfs(node);
            }
        }
        return components;
    }
};


    
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int vertex = 8, edges = 9;

    SCC_Kosaraju scc(vertex);
    
    scc.addEdge(0, 2);
    scc.addEdge(1, 0);
    scc.addEdge(2, 1);
    scc.addEdge(2, 3);
    scc.addEdge(3, 4);
    scc.addEdge(4, 5);
    scc.addEdge(5, 6);
    scc.addEdge(6, 7);
    scc.addEdge(7, 4);
    
    vector<vector<int>> comp = scc.build();
    
    for(int i = 0; i < comp.size(); ++i) {
        for(int node: comp[i]) {
            cout << node << " ";
        }
        cout << endl;
    }
    
    // Out:
    // 0 1 2
    // 3
    // 4 7 6 5

    return 0;
}