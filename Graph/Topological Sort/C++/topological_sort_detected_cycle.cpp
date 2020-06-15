#include<bits/stdc++.h>

using namespace std;

// Tested: https://leetcode.com/problems/course-schedule-ii/

vector<vector<int>> adj;
vector<bool> visited;
vector<bool> onstack;
vector<int> toposort;

// Implementation I
// Topological Sort - Detecting Cycles
void dfs(int node, bool &isCyclic) {
    if(isCyclic) return;
    
    visited[node] = true;
    onstack[node] = true;

    for(int neighbour: adj[node]) {
        if (visited[neighbour] && onstack[neighbour]) {
            // There is a cycle
            isCyclic = true;
            return;
        }
        if(!visited[neighbour]) {
            dfs(neighbour, isCyclic);
        }
    }

    onstack[node] = false;
    toposort.push_back(node);
}

// Implementattion II
// Topological Sort - Detecting Cycles
bool dfs(int node) {
    visited[node] = true;
    onstack[node] = true;
    
    for(int neighbour: adj[node]) {
        if(visited[neighbour] && onstack[neighbour]) {
            // There is a circle
            return true;
        } else if(!visited[neighbour] && dfs(neighbour)) {
            // There is a circle
            return true;
        }
    }
    onstack[node] = false;
    toposort.push_back(node);
    return false;
}

int main() {
    
    // Number of vertices
    // Labeled 0 ... n-1
    int n = 7;

    adj.resize(n);
    visited.resize(n, false);
    onstack.resize(n, false);
    
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
    
    bool isCyclic = false;
    
    // O(|V| + |E|)
    // |V|: Number of vertices
    // |E|: Number of edges

    // Implementation I
    for(int node = 0; node < n; ++node) {
        if(!visited[node]) {
            // Implementation I
            dfs(node, isCyclic);

            // Implementation II
            // isCyclic = isCyclic || dfs(node);

            if(isCyclic) break;
        }
    }
    
    if(isCyclic) {
        toposort.clear();
        cout << "There is a cycle" << endl;
    } else {
        reverse(toposort.begin(), toposort.end());
        
        for(int i = 0; i < toposort.size(); ++i) {
            cout << toposort[i] << " ";
        }
        cout << endl;
        // Out:
        // 0 1 4 3 6 2 5
    }

    return 0;
}