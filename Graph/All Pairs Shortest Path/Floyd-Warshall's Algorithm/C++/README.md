# Floyd-Warshall's Algorithm

### Contenido
* [Problema](#problema)
* [Implementación Estandar](#implementación-estandar)
* [Time Complexity](#time-complexity)
* [Space Complexity](#space-complexity)

### Problema

Distancia mas corta entre todos con todos los nodos

<img alt="Algoritmo de Floyd-Warshall" src="https://cdncontribute.geeksforgeeks.org/wp-content/uploads/dijikstra.png" width="400">

_Tomado de_ [Geeks for Geeks](https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/)

### Implementación Estandar

**Approach:** `Dynamic Programming`

```c++
int n = graph.size();

for(int k = 0; k < n; ++k) {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
        }
    }
}
```

## Time Complexity

```c++
Worst case time complexity:   O(|V|^3)
Average case time complexity: O(|V|^3)
Best case time complexity:    O(|V|^3)

|V|: Number of vertices
```

## Space Complexity

```c++
O(|V|^2)

|V|: Number of vertices
```