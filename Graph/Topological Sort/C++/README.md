# Topological Sort - C++

## Contenido

* [Contenido](#contenido)
* [Ilustración](#ilustración)
* [Implementación Estandar](#implementación-estandar)
* [Implementación Detectando Circulos](#implementación-detectando-circulos)
* [Time Complexity](#time-complexity)
* [Space Complexity](#space-complexity)
## Ilustración

<img alt="dfs" src="https://i.ibb.co/wMkwV5Y/Topological-Sort.png" width="300">

`Sorted: 0 1 4 3 6 2 5`

## Implementación Estandar

```c++
vector<vector<int>> adj;
vector<bool> visited;
vector<int> toposort;

// Topological Sort - Without detecting cycles
// Standard Implementation
void dfs(int node) {
    if(visited[node]) return;
    visited[node] = true;
    for(int neighbour: adj[node]) {
        dfs(neighbour);
    }
    toposort.push_back(node);
}
```
## Implementación Detectando Circulos

```c++
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