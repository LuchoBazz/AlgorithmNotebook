# Disjoint Set Union en C++

## Contenido

* [Ilustración](#ilustración)
* [Problema a Resolver](#problema-a-resolver)
* Implementación C++
    * [Implementación sin compresión de rango](#implementación-sin-compresión-de-rango)
    * [Implementación con compresión de rango](#implementación-con-compresión-de-rango)

## Ilustración

<img alt="Disjoint Set Union" src="https://camo.githubusercontent.com/2b417de95d5ec1479170a9d8de450b6f35825b02/68747470733a2f2f69302e77702e636f6d2f616c676f726974686d732e7475746f7269616c686f72697a6f6e2e636f6d2f66696c65732f323031382f30342f4469736a6f696e742d536574732d6578616d706c652e706e673f73736c3d31" width="300">

## Problema a Resolver

* Siendo `u`, `v` dos nodos, Saber si el nodo `u` y `v` estan conectados.

* Para Grafos no dirigidos

## Implementación sin compresión de rango

```c++
#include <bits/stdc++.h>

using namespace std;

class DisjointSet{
public:

    vector<int> parent;

    DisjointSet(int n): parent(n) {
        for(int i = 0; i < n; ++i) parent[i] = i;
    }

    void join(int a, int b) {
        parent[find(b)] = find(a);
    }

    int find(int a){
        return (a == parent[a]) ? a : parent[a] = find(parent[a]); 
    }

    bool check(int a, int b){
        return find(a) == find(b);
    }
};

int main() {

    int n = 5;

    DisjointSet dsu(n);

    dsu.join(0, 2); 

    dsu.join(4, 2); 

    dsu.join(3, 1); 

    if (dsu.check(4, 0)){
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    } 

    if (dsu.check(1, 0)) {
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
    
    // Out:
    // YES
    // NO

    return 0;
}
```

## Implementación con compresión de rango

```c++
#include <bits/stdc++.h>

using namespace std;

class DisjointSet {
public:

    vector<int> parent;
    vector<int> ranks;

    DisjointSet(int n): parent(n), ranks(n) {
        for(int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int x) { 
        if (parent[x] != x) { 
            parent[x] = find(parent[x]); 
        } 
        return parent[x]; 
    }


    void join(int x, int y) { 
        int xRoot = find(x);
        int yRoot = find(y); 

        if (xRoot == yRoot){ 
            return; 
        }

        if (ranks[xRoot] < ranks[yRoot]){ 
            parent[xRoot] = yRoot; 
        } else if (ranks[yRoot] < ranks[xRoot]) {
            parent[yRoot] = xRoot; 
        } else { 
            parent[yRoot] = xRoot; 
            ranks[xRoot] = ranks[xRoot] + 1; 
        } 
    };

    bool check(int a, int b) {
        return find(a) == find(b);
    }
};

int main() {
    
    int n = 5;

    DisjointSet dsu(n);

    dsu.join(0, 2); 

    dsu.join(4, 2); 

    dsu.join(3, 1); 

    if (dsu.check(4, 0)){
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    } 

    if (dsu.check(1, 0)) {
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
    
    // Out:
    // YES
    // NO

    return 0;
}
```