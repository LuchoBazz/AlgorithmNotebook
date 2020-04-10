# Breadth-first search (DFS) in Graphs - c++

## Contenido

* [Contenido](#contenido)
* [Ilustración](#ilustración)
* [Implementación](#implementación)
* [Complejidad](#complejidad)

## Ilustración

<img alt="bfs" src="https://www3.cs.stonybrook.edu/~skiena/combinatorica/animations/anim/bfs.gif" width="300">

_Tomado de:_ [CS Stonybrook](https://www3.cs.stonybrook.edu/~skiena/combinatorica/animations/search.html)

## Implementación

```c++
// N: number of nodes
const int N = 1e+5;

vector<int> adj[N];
bool visited[N];
int distance[N];

void bfs(int node) {
    visited[node] = true;
    distance[node] = 0;

    queue<int> q;
    q.push(node);

    int curr;
    while(q.size() > 0) {
        curr = q.front(); q.pop();

        for(int neighboor: adj[curr]) {
            if(!visited[neighboor]) {
                visited[neighboor] = true;
                distance[neighboor] = distance[curr] + 1;
                q.push(neighboor);
            }
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

    // distance
    // i    | distance[i]
    // ---------------
    // 1    | 0
    // 2    | 1
    // 3    | 2
    // 4    | 1
    // 5    | 2
    // 6    | 3

    return 0;
}
```


## Complejidad

* <img alt="DFS in Graph" src="https://i.ibb.co/brG8ZMM/O-n.png" width="50">