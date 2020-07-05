# Criba de Eratostenes - Sieve of Eratosthenes - Java

## Contenido

* [Contenido](#contenido)
* [Ilustración](#ilustración)
* [Criba de Eratostenes - Sieve of Eratosthenes](#criba-de-eratostenes---sieve-of-eratosthenes)
* [Implementación Criba](#implementación-criba)
* [Time Complexity](#time-complexity)
* [Space Complexity](#space-complexity)


## Ilustración

<img alt="Criba de Eratostenes" src="https://upload.wikimedia.org/wikipedia/commons/b/b9/Sieve_of_Eratosthenes_animation.gif" width="400">


## Criba de Eratostenes - Sieve of Eratosthenes

Este algoritmo nos permite calcular todos los numeros prime en un rango dado.

### Implementación Criba

```java
public List<Integer> criba(int n) {
    boolean[] isPrime = new boolean[n];
    
    for(int i = 4; i <= n; i += 2) {
        isPrime[i] = true;
    }
    
    for(int p = 3; p <= n; p += 2) {
        if(!isPrime[p]) {
            for(int j = 2*p; j < n;j += p) {
                isPrime[j] = true;
            }
        }
    }
    
    List<Integer> primes = new ArrayList<>();
    
    for(int i = 2; i < isPrime.length; ++i) {
        if(!isPrime[i]) {
            primes.add(i);
        }
    }
    return primes;
}
```

## Time Complexity

```c++
O(n*log2(log2(n)))

Donde n es el numero dado
```

## Space Complexity

```c++
O(n)
Donde n es el numero dado
```