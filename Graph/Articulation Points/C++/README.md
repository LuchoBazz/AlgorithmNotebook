# Articulation Points (or Cut Vertices) - Tarjan's Algorithm - C++

## Contenido

* [Contenido](#contenido)
* [Ilustración](#ilustración)
* [Implementación Estandar](#implementación-estandar)
* [Time Complexity](#time-complexity)
* [Space Complexity](#space-complexity)

## Ilustración

<img alt="Articulation Points (or Cut Vertices) - Tarjan's Algorithm - C++" src="https://cdn.emre.me/2020-03-07-articulation-point.png" width="400">

_Tomado de_: [emre.me](https://emre.me/algorithms/tarjans-algorithm/)

`Articulation Point I: 2`

`Articulation Point II: 3`

`Articulation Point III: 5`

---
`Index: [0 1 2] [3] [4] [5] [6 7 8]`

`Order: [1 2 3] [4] [5] [6] [7 8 9]`

`Low: - [1 1 1] [3] [4] [3] [6 6 6]`

## Implementación Estandar

```c++
vector<vector<int>> adj;
vector<bool> visited;
vector<int> low;
// Order in which it was visited
vector<int> order;
vector<bool> points;
// Count the components
int counter = 0;
// Number of Vertex
int vertex;

void dfs(int node, int parent = -1) {
    visited[node] = true;
    low[node] = order[node] = ++counter;

    int children = 0;

    for(int &neighbour: adj[node]) {

        if(!visited[neighbour]) {
            children++;

            dfs(neighbour, node);

            low[node] = min(low[node], low[neighbour]);
            
            // Conditions #1
            if(parent != -1 && order[node] <= low[neighbour]) {
                points[node] = true;
            }
        } else {
            low[node] = min(low[node], order[neighbour]);
        }
    }
    
    // Conditions #2
    if(parent == -1 && children > 1) {
        points[node] = true;
    }
}

vector<int> build() {
    for(int node = 0; node < vertex; ++node) {
        if(!visited[node]) {
            dfs(node);
        }
    }
    
    vector<int> output;
    
    for(int node = 0; node < vertex; ++node) {
        if(points[node]) {
            output.push_back(node);
        }
    }
    return output;
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