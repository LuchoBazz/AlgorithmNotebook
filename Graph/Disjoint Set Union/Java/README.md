# Disjoint Set Union en C++

## Contenido

* [Ilustración](#ilustración)
* [Problema a Resolver](#problema-a-resolver)
* Implementación Java
    * [Implementación SIN compresión de ruta](#implementación-sin-compresión-de-ruta)
    * [Implementación CON compresión de ruta](#implementación-con-compresión-de-ruta)
* [Complexity - SIN Compresión](#complexity---sin-compresión)
* [Complexity - CON Compresión](#complexity---con-compresión)

## Ilustración

<img alt="Disjoint Set Union" src="https://camo.githubusercontent.com/2b417de95d5ec1479170a9d8de450b6f35825b02/68747470733a2f2f69302e77702e636f6d2f616c676f726974686d732e7475746f7269616c686f72697a6f6e2e636f6d2f66696c65732f323031382f30342f4469736a6f696e742d536574732d6578616d706c652e706e673f73736c3d31" width="300">

## Problema a Resolver

* Siendo `u`, `v` dos nodos, Saber si el nodo `u` y `v` estan conectados.

* Para Grafos no dirigidos

## Implementación SIN compresión de ruta

```java
 class DisjointSetUnion {
    private int[] parents;
    private int components;

    public DisjointSetUnion(int size) {
        this.parents = new int[size];
        this.components = size;

        for(int i = 0; i < size; ++i) {
            this.parents[i] = i;
        }
    }

    public int find(int x) {
        if(x != parents[x]) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }

    public void join(int left, int right) {
        int x = find(left);
        int y = find(right);

        if(x == y) return;

        parents[y] = x;

        this.components--;
    }

    public int getComponents() {
        return this.components;
    }

    public boolean isConnected(int left, int right) {
        return find(left) == find(right);
    }
}

public static void main (String[] args) {
    int N = 10;
    DisjointSetUnion dsu = new DisjointSetUnion(N);
    
    dsu.join(0, 2); 

    dsu.join(4, 2); 

    dsu.join(3, 1); 

    if (dsu.isConnected(4, 0)){
        out.println("YES");
    } else {
        out.println("NO");
    } 

    if (dsu.isConnected(1, 0)) {
        out.println("YES");
    } else {
        out.println("NO");
    }
    // Out:
    // YES
    // NO
}
```

## Implementación CON compresión de ruta

**Nota:** Usando `Path Compression`

```java
class DisjointSetUnion {
    private int[] sizes;
    private int[] parents;
    private int components;

    public DisjointSetUnion(int size) {
        this.sizes = new int[size];
        this.parents = new int[size];
        this.components = size;

        for(int i = 0; i < size; ++i) {
            this.parents[i] = i;
            this.sizes[i] = 1;
        }
    }

    public int find(int x) {
        if(x != parents[x]) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }

    public void join(int left, int right) {
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
    }

    public boolean isConnected(int left, int right) {
        return find(left) == find(right);
    }

    public int getComponents() {
        return this.components;
    }
}

public static void main (String[] args) {
    int N = 10;
    DisjointSetUnion dsu = new DisjointSetUnion(N);
    
    dsu.join(0, 2); 

    dsu.join(4, 2); 

    dsu.join(3, 1); 

    if (dsu.isConnected(4, 0)){
        out.println("YES");
    } else {
        out.println("NO");
    } 

    if (dsu.isConnected(1, 0)) {
        out.println("YES");
    } else {
        out.println("NO");
    }
    // Out:
    // YES
    // NO
}
```

## Complexity - SIN Compresión

* ### Time Complexity
    * `Find`
        
        <img alt="Algoritmo de Kadane" src="https://i.ibb.co/brG8ZMM/O-n.png" width="50">
    * `Union`

        <img alt="Algoritmo de Kadane" src="https://i.ibb.co/brG8ZMM/O-n.png" width="50">
* ### Space Complexity
    * <img alt="Algoritmo de Kadane" src="https://i.ibb.co/brG8ZMM/O-n.png" width="50">

## Complexity - CON Compresión
* ### Time Complexity
    * `Find`
        
        ![Time Complexity - Union Find CON Compresión](https://i.ibb.co/RzJ8t4m/Log-n.png)
    * `Union`

        ![Time Complexity - Union Find SIN Compresión](https://i.ibb.co/RzJ8t4m/Log-n.png)
* ### Space Complexity
    * <img alt="Algoritmo de Kadane" src="https://i.ibb.co/brG8ZMM/O-n.png" width="50">
