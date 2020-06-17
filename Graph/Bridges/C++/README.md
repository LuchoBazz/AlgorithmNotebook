# Bridges Using Tarjan's Algorithm - C++

## Contenido

* [Contenido](#contenido)
* [Ilustración](#ilustración)
* [Implementación Estandar](#implementación-estandar)
* [Time Complexity](#time-complexity)
* [Space Complexity](#space-complexity)

## Ilustración

<img alt="Bridges Using Tarjan's Algorithm - C++" src="https://cdn.emre.me/2020-03-07-bridge.png" width="400">

_Tomado de_: [emre.me](https://emre.me/algorithms/tarjans-algorithm/)

`Bridge I: (2, 5)`

`Bridge II: (2, 3)`

`Bridge III: (3, 4)`

---
`Index: [0 1 2] [3] [4] [5 6 7 8]`

`Order: [1 2 3] [4] [5] [6 7 8 9]`

`Low: - [1 1 1] [4] [5] [6 6 6 6]`

## Implementación Estandar

```c++
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
```

## Time Complexity

```c++
Worst case time complexity:   O(|V| + |E|)
Average case time complexity: O(|V| + |E|)
Best case time complexity:    O(|V| + |E|)

|V|: Number of vertices
|E|: Number of edges
```

## Space Complexity

```c++
O(|V|)

|V|: Number of vertices
```