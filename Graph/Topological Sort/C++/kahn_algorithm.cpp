#include<bits/stdc++.h>

using namespace std;

class KahnTopoSort {
    vector<vector<int>> adj;
    vector<int> indegree;
    vector<int> toposort;
    int nodes;
    bool solved;
    bool isCyclic;
public:
    
    KahnTopoSort(int n) : nodes(n) {
        adj.resize(n);
        indegree.resize(n, 0);
        solved = false;
        isCyclic = false;
    }
    
    void addEdge(int from, int to) {
        adj[from].push_back(to);
        indegree[to]++;
        solved = false;
        isCyclic = false;
    }
    
    vector<int> sort() {
        if(solved) return toposort;
        toposort.clear();
        
        queue<int> Q;
        
        vector<int> in_degree(indegree.begin(), indegree.end());
    
        for(int i = 0; i < nodes; ++i) {
            if(in_degree[i] == 0) Q.push(i);
        }


        int count = 0;

        while(!Q.empty()) {
            int node = Q.front(); Q.pop();
            toposort.push_back(node);
            for(int neighbour: adj[node]) {
                in_degree[neighbour]--;
                if(in_degree[neighbour] == 0) {
                    Q.push(neighbour);
                }
            }
            count++;
        }
        
        solved = true;

        if(count != nodes) {
            // There exists a cycle in the graph
            isCyclic = true;
            return vector<int> {};
        }

        return toposort;
    }

    bool getIsCyclic() {
        sort();
        return isCyclic;
    }
    
};

int main() {
    
    int vertex = 7;
    
    KahnTopoSort ts(vertex);
    
    ts.addEdge(0, 1);
    ts.addEdge(0, 2);
    ts.addEdge(0, 3);
    ts.addEdge(0, 4);
    ts.addEdge(1, 3);
    ts.addEdge(1, 4);
    ts.addEdge(2, 3);
    
    vector<int> toposort = ts.sort();
    
    for(int i = 0; i < toposort.size(); ++i) {
        cout << toposort[i] << " ";
    }
    // Out:
    // 0 5 6 1 2 4 3
    
    return 0;
}