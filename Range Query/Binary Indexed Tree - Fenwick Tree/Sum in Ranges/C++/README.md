# Binary Indexed Tree - Fenwick Tree - Sum in Ranges - C++

## Contenido

* [Contenido](#contenido)
* [Ilustración](#ilustración)
* [Implementación](#implementación)
    * [Build](#build)
    * [Update](#update)
    * [Get Sum](#get-sum)
* [Time Complexity](#time-complexity)
* [Space Complexity](#space-complexity)

## Ilustración

<img alt="Binary Indexed Tree - Fenwick Tree" src="https://raw.githubusercontent.com/e-maxx-eng/e-maxx-eng/master/img/binary_indexed_tree.png" width="400">

_Tomado de:_ [CP algorithms](https://cp-algorithms.com/data_structures/fenwick.html)

## Implementación

* ## Build

```c++
n = data.size();
tree.resize(n+1, 0);

for(int i = 0; i < n; ++i) {
    update(n, i, data[i]);
}
```

* ## Update

```c++

// Private
void update(int n, int index, int value) {
    index += 1;
    while(index <= n) {
        tree[index] += value;
        index += index & (-index);
    }
}

// Public
void update(int index, int value) {
    int val = data[index];
    
    int diff = abs(val - value);
    
    if(value > val) {
        diff = abs(diff);
    } else {
        diff = -abs(diff);
    }
    
    data[index] = value;
    update(n, index, diff);
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
