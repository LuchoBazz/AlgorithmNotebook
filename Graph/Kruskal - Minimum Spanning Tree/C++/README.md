# Algoritmo de Kruskal - Minimum Spanning Tree

### Contenido

* [Ilustración](#ilustración)
* [Problema a Resolver](#problema-a-resolver)
* [Implementación](#implementación)
* [Complejidad](#complejidad)

### Ilustración
<img alt="Algoritmo de Kruskal" src="https://upload.wikimedia.org/wikipedia/commons/d/d2/Minimum_spanning_tree.svg" width="300"> [3] Wikipedia

### Problema a Resolver

* Encontrar un árbol recubridor mínimo en un grafo conexo y ponderado.

* Es decir, busca un subconjunto de aristas que, formando un árbol, incluyen todos los vértices y donde el valor de la suma de todas las aristas del árbol es el mínimo.



### Implementación

```C++
#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int  u, v, w;

    bool operator<(struct Edge other) {
        return w < other.w;
    }
};

class DisjointSet {
public:

    vector<int> parent;
    vector<int> ranks; // Longitud de Cada Conjunto de Edge

    DisjointSet(int n): parent(n), ranks(n) {
        for(int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int x) { 
        if (parent[x] != x) { 
            parent[x] = find(parent[x]); 
        } 
        return parent[x]; 
    }


    bool join(int x, int y) { 
        int xRoot = find(x);
        int yRoot = find(y); 

        if (xRoot == yRoot){ 
            return false; 
        }

        if (ranks[xRoot] < ranks[yRoot]){ 
            parent[xRoot] = yRoot; 
        } else if (ranks[yRoot] < ranks[xRoot]) {
            parent[yRoot] = xRoot; 
        } else { 
            parent[yRoot] = xRoot; 
            ranks[xRoot] = ranks[xRoot] + 1; 
        } 
        return true;
    };

    bool check(int a, int b) {
        return find(a) == find(b);
    }
};



class Kruskal {
public: 

    vector<struct Edge> E;
    vector<struct Edge> KruskalVector;
    int totalWeightKruskal = 0;
    int vertexNumber, edgeNumber;

    Kruskal(int v, int e): vertexNumber(v), edgeNumber(e) {}

    void addEdge(struct Edge edge) {
        E.push_back(edge);
    }

    int build() {

        DisjointSet dsu(edgeNumber);

        sort(E.begin(), E.end());
        

        int totalWeight = 0;

        for(struct Edge e : E) {
            if(dsu.find(e.u) != dsu.find(e.v)) {
                KruskalVector.push_back(e);
                totalWeight += e.w;
                dsu.join(e.u, e.v);
            }
        }
        totalWeightKruskal = totalWeight;
        return totalWeight;
    }

};

int main() {
    
    int vertexNumber = 9, edgeNumber = 14;
    Kruskal kruskal(vertexNumber, edgeNumber);


    kruskal.addEdge({0, 1, 4}); 
    kruskal.addEdge({0, 7, 8}); 
    kruskal.addEdge({1, 2, 8}); 
    kruskal.addEdge({1, 7, 11}); 
    kruskal.addEdge({2, 3, 7}); 
    kruskal.addEdge({2, 8, 2}); 
    kruskal.addEdge({2, 5, 4}); 
    kruskal.addEdge({3, 4, 9}); 
    kruskal.addEdge({3, 5, 14}); 
    kruskal.addEdge({4, 5, 10}); 
    kruskal.addEdge({5, 6, 2}); 
    kruskal.addEdge({6, 7, 1}); 
    kruskal.addEdge({6, 8, 6}); 
    kruskal.addEdge({7, 8, 7});

    int totalWeight = kruskal.build();

    cout<<"Total Weight : "<<totalWeight<<endl;


    for(struct Edge e: kruskal.KruskalVector) {
        cout<<"Edge("<<e.u<<", "<<e.v<<", "<<e.w<<")"<<endl;
    }

    return EXIT_SUCCESS;
}

// Total Weight : 37
// Edge(6, 7, 1)
// Edge(2, 8, 2)
// Edge(5, 6, 2)
// Edge(0, 1, 4)
// Edge(2, 5, 4)
// Edge(2, 3, 7)
// Edge(0, 7, 8)
// Edge(3, 4, 9)
```

<img alt="Algoritmo de Kruskal" src="https://www.geeksforgeeks.org//wp-content/uploads/Fig-11.jpg" width="350"> [4] GeeksForGeeks

### Complejidad
![complexity](http://latex.codecogs.com/gif.latex?O%5Cleft%28E%5Ccdot%20log%5Cleft%28E%5Cright%29%5C%3A&plus;%5C%3AE%5Ccdot%20log%5Cleft%28V%5Cright%29%5Cright%29)
