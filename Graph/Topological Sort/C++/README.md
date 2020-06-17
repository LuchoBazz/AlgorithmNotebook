# Topological Sort - C++

## Contenido

* [Contenido](#contenido)
* [Ilustración](#ilustración)
* [Implementación Estandar - dfs](#implementación-estandar---dfs)
* [Implementación Detectando Circulos - dfs](#implementación-detectando-circulos---dfs)
* [Kahn's algorithm - bfs](#)
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

## Kahn's algorithm

```c++
vector<int> kahn(bool &isCyclic) {
    int n, m;
    cin >> n >> m;

    vector<int> indegree(n);
    vector<vector<int>> adj(n);
    vector<int> toposort;

    for(int i = 0; i < m; ++i) {
        cin >> from >> to;
        adj[from].push_back(to);
        indegree[to]++;
    }

    queue<int> Q;

    for(int i = 0; i < nodes; ++i) {
        if(indegree[i] == 0) Q.push(i);
    }

    int count = 0;

    while(!Q.empty()) {
        int node = Q.front(); Q.pop();

        toposort.push_back(node);

        for(int neighbour: adj[node]) {
            indegree[neighbour]--;
            if(indegree[neighbour] == 0) {
                Q.push(neighbour);
            }
        }
        count++;
    }

    if(count != nodes) {
        // There exists a cycle in the graph
        isCyclic = true;
        return vector<int> {};
    }
    return toposort;
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