# Binary Indexed Tree - Fenwick Tree - Sum in Ranges - C++

## Contenido

* [Contenido](#contenido)
* [Ilustración](#ilustración)
* [Implementación](#implementación)
    * [Build](#build)
    * [Sum](#sum)
    * [Get Sum](#get-sum)
* [Time Complexity](#time-complexity)
* [Space Complexity](#space-complexity)

## Ilustración

<img alt="Binary Indexed Tree - Fenwick Tree" src="https://raw.githubusercontent.com/e-maxx-eng/e-maxx-eng/master/img/binary_indexed_tree.png" width="400">

_Tomado de:_ [CP algorithms](https://cp-algorithms.com/data_structures/fenwick.html)

## Implementación

* ## Build

```c++
Fenwick(int n) : n(n) {
    tree.resize(n+1, 0);
}

Fenwick(vector<int> values) : n(values.size()) {
    tree.resize(n+1, 0);
    
    for(int i = 0; i < n; ++i) {
        sum(n, i, values[i]);
    }
}
```

* ## Sum

```c++
// Private
void sum(int n, int index, int value) {
    index += 1;
    while(index <= n) {
        tree[index] += value;
        index += index & (-index);
    }
}

// Public
void sum(int index, int value) {
    sum(n, index, value);
}
```

* ## Get Sum

```c++
int get(int index) {
    index += 1;
    int sum = 0;
    while(index > 0) {
        sum += tree[index];
        index -= index & (-index);
    }        
    return sum;
}

// [Left, right]

// get(right) - get(left-1);
```


## Time Complexity

* `Update`

    ![Complejidad de Insertar](https://i.ibb.co/RzJ8t4m/Log-n.png)

* `get`

    ![Complejidad de Insertar](https://i.ibb.co/RzJ8t4m/Log-n.png)

## Space Complexity

* <img alt="Fenwick Tree" src="https://i.ibb.co/brG8ZMM/O-n.png" width="50">
