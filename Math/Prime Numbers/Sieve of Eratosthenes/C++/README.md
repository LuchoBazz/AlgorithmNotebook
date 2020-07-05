# Criba de Eratostenes - Sieve of Eratosthenes - C++

## Contenido

* [Contenido](#contenido)
* [Ilustración](#ilustración)
* [Criba de Eratostenes - Sieve of Eratosthenes](#criba-de-eratostenes---sieve-of-eratosthenes)
* [Implementación](#implementación)
* [Time Complexity](#time-complexity)
* [Space Complexity](#space-complexity)


## Ilustración

<img alt="Criba de Eratostenes" src="https://upload.wikimedia.org/wikipedia/commons/b/b9/Sieve_of_Eratosthenes_animation.gif" width="400">

## Criba de Eratostenes - Sieve of Eratosthenes

Este algoritmo nos permite calcular todos los numeros prime en un rango dado.

### Implementación

```c++
vector<int> sieve(int number) {
    vector<bool> is_prime(number+1, false);

    for(int i = 4; i <= number; i += 2) {
        is_prime[i] = true;
    }

    for(int prime = 3; prime <= number; prime += 2) {
        if(!is_prime[prime]) {
            for(int j = prime*2; j <= number; j += prime) {
                is_prime[j] = true;
            }
        }
    }

    vector<int> primes;
    for(int i = 2; i <= number; ++i) {
        if(!is_prime[i]) primes.push_back(i);
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