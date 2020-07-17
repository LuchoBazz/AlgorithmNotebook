# Segment Tree - C++

## Contenido

* [Contenido](#contenido)
* [Ilustración](#ilustración)
* [Implementación](#implementación)
    * [Build](#build)
    * [Update](#update)
    * [Query](#query)
* [Time Complexity](#time-complexity)
* [Space Complexity](#space-complexity)

## Ilustración

<img alt="Binary Indexed Tree - Fenwick Tree" src="https://3.bp.blogspot.com/-h5cVM97Q11k/WNIS63q1XdI/AAAAAAAAHOo/DliBFmee5O8Woadr_oxSucj3OdqUOyLPACLcB/s1600/Count%2BInversions%2B-%2BSegment%2BTree.png" width="600">

_Tomado de:_ [Programmer Coach](https://www.programmercoach.com/2017/03/programming-interview-pearls-count_10.html)

## Implementación

* ## Build

```c++
build(vector<int> values) {
    n = values.size();
    tree.resize(n*2);
    // Build
    for (int i=0; i < n; i++){
        tree[n+i] = values[i];
    }
    for (int i = n - 1; i > 0; --i) {
        tree[i] = func(tree[i<<1], tree[i<<1 | 1]);
    }
}
```

* ## Update

```c++
void update(int index, int value) {
    tree[index+n] = value;
    index = index + n;
    for (int i = index; i > 1; i >>= 1){
        tree[i>>1] = func(tree[i], tree[i^1]);
    }
}
```

* ## Query

```c++
int query(int l, int r) {
    int ans = NEUTRAL;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) {
            ans = func(ans, tree[l++]);
        }
        if (r&1) {
            ans = func(ans, tree[--r]);
        }
    }
    return ans;
}
```


## Time Complexity

* ### Build

```
O(n)

Donde n es el numero de elementos de vector
```

* ### Update

```
O(log2(n))

Donde n es el numero de elementos de vector
```

* ### Query

```
O(log2(n))

Donde n es el numero de elementos de vector
```

## Space Complexity

```
O(n)

Donde n es el numero de elementos de vector
```