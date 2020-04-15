# Depth-first search (DFS) in Graphs - c++

## Contenido

* [Contenido](#contenido)
* [Ilustración](#ilustración)
* [Implementación](#implementación)
* [Complejidad](#complejidad)

## Ilustración

<img alt="dfs" src="https://www3.cs.stonybrook.edu/~skiena/combinatorica/animations/anim/dfs.gif" width="300">

_Tomado de:_ [CS Stonybrook](https://www3.cs.stonybrook.edu/~skiena/combinatorica/animations/search.html)

## Implementación

```c++
// N: number of nodes
const int N = 1e+5;

vector<int> adj[N];
bool visited[N];

void dfs(int node) {
    visited[s] = true;
    // process node node
    for (auto neighboor: adj[node]) {
        if(!visited[neighboor]) {
            dfs(neighboor);
        }
    }
}

int main() {
    vector<pair<int, int>> edges {
        {1, 2},
        {1, 3},
        {2, 5},
        {3, 4},
        {4, 5}
    };

    for(auto [x, y]: edges) {
        // Directed
        adj[x].push_back(y);
        
        // for Undirected
        // adj[y].push_back(x);
    }

    int start = 1;

    dfs(start);

    return 0;
}
```


## Complejidad

* <img alt="DFS in Graph" src="https://i.ibb.co/brG8ZMM/O-n.png" width="50">