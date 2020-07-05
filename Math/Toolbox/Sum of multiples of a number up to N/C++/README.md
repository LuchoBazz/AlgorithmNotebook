# Sum of Multiples of a number up to N - C++

* Calcula la suma de todos los divisores de `number` desde `1` hasta `N` incluyendolo.

## Contenido

* [Contenido](#contenido)
* [Implementacion](#implementacion)
* [Time Complexity](#time-complexity)
* [Space Complexity](#space-complexity)

**Ejemplo:** Todos los divisores de 3 desde 1 hasta 12.

`sum_multiple(3, 12) = 3+6+9+12 = 30`.

```c++
int sum_multiple(int number, int N) {
    // Number of multiples 
    int m = N / number;

    // sum of first m natural numbers 
    int sum = m*(m + 1) / 2;

    // sum of multiples
    return number*sum;
}
```

### Time Complexity

```c++
O(1)
```

### Space Complexity

```c++
O(1)
```