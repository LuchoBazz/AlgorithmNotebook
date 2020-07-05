# Primality Test - C++

## Contenido

* [Contenido](#contenido)
    * [Implementacion I](#implementacion-i)
    * [Implementacion II](#implementacion-ii)
    * [Implementacion III](#implementacion-iii)
* [Time Complexity](#time-complexity)
* [Space Complexity](#space-complexity)

* ## Implementacion I

```c++
bool isPrime(int x) {
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0) {
            return false;
        }
    }
    return true;
}
```

* ## Implementacion II

**Nota:** _Implementación anterior mejorada_

```c++
bool isPrime(int x) {
    if(x==2 || x==3) return true;
    if(x % 2 == 0 || x % 3 == 0) return false;
    
    for (int d = 3; d * d <= x; d += 2) {
        if (x % d == 0) {
            return false;
        }
    }
    return true;
}
```

* ## Implementacion III

**Nota:** _Mejor Implementación de las tres_

```c++
bool isPrime(int number) {
    if(number <= 0) return false;
    else if(number <= 3) return true;

    if(number%2==0 || number%3==0) return false;

    for(int i = 5; i*i <= number; i += 6) {
        if(number%i==0 || number%(i+2)==0) {
            return false;
        }
    }
    return true;
}
```

## Time Complexity

```c++
O(sqrt(n))

Donde n es el numero a verificar
```

## Space Complexity

```c++
O(1)
```