# Greatest Common Divisor & Least Common Multiple - Java

## Contenido

* [Contenido](#contenido)
* [Algoritmo de Euclides -  Euclid's algorithm](#)
    * [Problema a Resolver](#problema-a-resolver-gcd)
    * [Implementación Recursiva GCD](#implementación-recursiva-gcd)
    * [Implementación Iterativa GCD](#implementación-iterativa-gcd)
    * [Complexity - Algoritmo de Euclides](#complexity---algoritmo-de-euclides)
---

## Algoritmo de Euclides -  Euclid's algorithm

* ### Problema a Resolver GCD
Calcula el Maximo Comun Divisor de dos Numeros

* ### Implementación Recursiva GCD
```java
public int gcd (int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}
```
* ### Implementación Iterativa GCD

```java
public int gcd (int a, int b) {
    int tmp = 0;
    while (b != 0){
        tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}
```

* ### Complexity - Algoritmo de Euclides

![Complexity - Algoritmo de Euclides](https://i.ibb.co/tbm7dxG/log-max-a-b.png)

---
