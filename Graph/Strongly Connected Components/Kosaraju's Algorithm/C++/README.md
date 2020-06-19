# Kosaraju's Algorithm - C++

## Contenido

* [Contenido](#contenido)
* [Ilustración](#ilustración)
* [Implementación Estandar](#implementación-estandar)
* [Time Complexity](#time-complexity)
* [Space Complexity](#space-complexity)
## Ilustración

<img alt="Kosaraju's Algorithm" src="https://iq.opengenus.org/content/images/2019/03/Tarjan1.png" width="400">

_Tomado de_: [iq.opengenus](https://iq.opengenus.org/tarjans-algorithm/)

`Component I: [1 2 3]`

`Component II: [4]`

`Component III: [5 6 7 8]`

## Implementación Estandar

```c++
vector<vector<int>> adj;
vector<vector<int>> radj;
vector<bool> visited;
stack<int> toposort;
vector<vector<int>> components; // Answer - SCC
int vertex; // Number of Vertex

// First
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

// Second
// dfs Standard - Reverse Adj
void dfs(int node) {
    visited[node] = true;
    components.back().push_back(node);
    for(int neighbour: radj[node]) {
        if(!visited[neighbour]) {
            dfs(neighbour);
        }
    }
}

// Third
// Build Algorithm
vector<vector<int>> build() {
    // Topological Sort
    for(int node = 0; node < vertex; ++node) {
        if(!visited[node]) {
            toposort_dfs(node);
        }
    }

    // Reset - Visited
    fill(visited.begin(), visited.end(), false);

    // In the topological order run the reverse dfs
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


// adj[from].push_back(to);
// radj[to].push_back(from);
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