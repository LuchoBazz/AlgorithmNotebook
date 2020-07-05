# Least Common Multiple - C++

Calcula el Minimo Comun Multiplo de dos Numeros

## Contenido

* [Contenido](#contenido)
* [Implementacion](#implementacion)
* [Time Complexity](#time-complexity)
* [Space Complexity](#space-complexity)

### Implementacion

```c++
int lcm(int a, int b) {  
    return (a*b)/gcd(a, b);  
}
```

### Time Complexity

```c++
O( log(min(a, b)) )

Donde a y b son los parametros de lcm(a, b)
```

### Space Complexity

```c++
O(1)
```