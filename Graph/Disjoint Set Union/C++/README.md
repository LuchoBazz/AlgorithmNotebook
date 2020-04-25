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

class DisjointSet {
    vector<int> parent;
    int components;

public:
    DisjointSet(int n): parent(n) {
        components = n;
        for(int i = 0; i < n; ++i) parent[i] = i;
    }

    void join(int left, int right) {
        int x = find(left);
        int y = find(right);

        if(x == y) return;

        parents[y] = x;

        components--;
    }

    int find(int x){
        if(x != parents[x]) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }

    bool isConnected(int a, int b){
        return find(a) == find(b);
    }

    int getComponents() {
        return components;
    }
};

int main() {

    int n = 5;

    DisjointSet dsu(n);

    dsu.join(0, 2); 

    dsu.join(4, 2); 

    dsu.join(3, 1); 

    if (dsu.isConnected(4, 0)){
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    } 

    if (dsu.isConnected(1, 0)) {
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
    vector<int> parent;
    vector<int> sizes;
    int components;

public:
    DisjointSet(int n): parent(n), sizes(n) {
        components = n;
        for(int i = 0; i < n; ++i) {
            parent[i] = i;
            sizes[i] = 1;
        }
    }

    int find(int x) { 
        if (parent[x] != x) { 
            parent[x] = find(parent[x]); 
        } 
        return parent[x]; 
    }


    void join(int left, int left) { 
        int x = find(left);
        int y = find(right);

        if(x == y) return;

        if(sizes[x] < sizes[y]) {
            sizes[y] += sizes[x];
            parents[x] = y;
        } else if(sizes[x] >= sizes[y]) {
            sizes[x] += sizes[y];
            parents[y] = x;
        }

        this.components--;
    };

    bool isConnected(int a, int b) {
        return find(a) == find(b);
    }

    int getComponents() {
        return components;
    }
};

int main() {
    
    int n = 5;

    DisjointSet dsu(n);

    dsu.join(0, 2); 

    dsu.join(4, 2); 

    dsu.join(3, 1); 

    if (dsu.isConnected(4, 0)){
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    } 

    if (dsu.isConnected(1, 0)) {
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