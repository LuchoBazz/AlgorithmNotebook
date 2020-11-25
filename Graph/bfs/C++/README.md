# Breadth-first search (DFS) in Graphs - c++

## Contenido

* [Contenido](#contenido)
* [Ilustración](#ilustración)
* [Implementación](#implementación)
* [Complejidad](#complejidad)

## Ilustración

<img alt="bfs" src="https://www3.cs.stonybrook.edu/~skiena/combinatorica/animations/anim/bfs.gif" width="300">

_Tomado de:_ [CS Stonybrook](https://www3.cs.stonybrook.edu/~skiena/combinatorica/animations/search.html)

<img alt="BFS" src="https://cdn.emre.me/2019-09-15-graph-code.png" width="400">

_Tomado de_: [emre.me](https://emre.me/data-structures/graphs/)

## Implementación

```c++
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

vector<vector<int>> adj;
vector<bool> visited;
vector<int> dist;
const int oo = int(1e9);

void bfs(int start) {
    visited[start] = true;
    dist[start] = 0;

    queue<int> q;
    q.push(start);

    while(!q.empty()) {
        int node = q.front(); q.pop();
        for(int neighbor: adj[node]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    // Number of Vertex
    int vertex = 6;
    
    adj.resize(vertex);
    visited.resize(vertex, false);
    dist.resize(vertex, oo);
    
    vector<pair<int, int>> edges {
        {0, 1},
        {0, 2},
        {1, 2},
        {2, 3},
        {2, 4},
        {4, 5}
    };

    for(auto [x, y]: edges) {
        // Directed
        adj[x].push_back(y);
        
        // for Undirected
        adj[y].push_back(x);
    }

    int start = 0;

    bfs(start);
    
    for(int i = 0; i < vertex; ++i) {
        cout << i << " " <<dist[i] << endl;
    }

    // dist
    // i    | dist[i]
    // ---------------
    // 0    | 0
    // 1    | 1
    // 2    | 1
    // 3    | 2
    // 4    | 2
    // 5    | 3

    return 0;
}
```


## Complejidad

* <img alt="DFS in Graph" src="https://i.ibb.co/brG8ZMM/O-n.png" width="50">