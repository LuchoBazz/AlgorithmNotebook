# Algoritmo de Floyd-Warshall

### Contenido
* [Implementación en C++](#implementación-en-c)
* [Problema](#problema)

### Problema

Distancia mas corta entre dos Nodos

<img alt="Algoritmo de Floyd-Warshall" src="https://cdncontribute.geeksforgeeks.org/wp-content/uploads/dijikstra.png" width="400">

### Implementación en C++

```c++
#include <bits/stdc++.h>

using namespace std;


#define INF 200000000

typedef vector<vector<int>> vvi;

class FloydWarshall {
public:

  vvi graph;

  vvi build() {
    int n = graph.size();

    for(int k = 0; k < n; ++k) {
      for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
          graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
        }
      }
    }

    return graph;
  }

};

int main() {
    
  FloydWarshall fw;
  
  fw.graph = {
    {INF, 4, INF, INF, INF, INF, INF, 8, INF },
    {4, INF, 8, INF, INF, INF, INF, 11, INF },
    {INF, 8, INF, 7, INF, 4, INF, INF, 2 },
    {INF, INF, 7, INF, 9, 14, INF, INF, INF },
    {INF, INF, INF, 9, INF, 10, INF, INF, INF },
    {INF, INF, 4, 14, 10, INF, 2, INF, INF },
    {INF, INF, INF, INF, INF, 2, INF, 1, 6 },
    {8, 11, INF, INF, INF, INF, 1, INF, 7 },
    {INF, INF, 2, INF, INF, INF, 6, 7, INF }
  };

  

  fw.build();

  // Imprimir Grafo
  for(int i = 0; i < fw.graph.size(); ++i) {
    cout<<i<<" |";
    for(int j = 0; j < fw.graph.size(); ++j) {
      cout<<fw.graph[i][j]<<" ";
    }
    cout<<endl;
  }
  // 0 |8 4 12 19 21 11 9 8 14 
  // 1 |4 8 8 15 22 12 12 11 10 
  // 2 |12 8 4 7 14 4 6 7 2 
  // 3 |19 15 7 14 9 11 13 14 9 
  // 4 |21 22 14 9 18 10 12 13 16 
  // 5 |11 12 4 11 10 4 2 3 6 
  // 6 |9 12 6 13 12 2 2 1 6 
  // 7 |8 11 7 14 13 3 1 2 7 
  // 8 |14 10 2 9 16 6 6 7 4 

  return 0;
}
```