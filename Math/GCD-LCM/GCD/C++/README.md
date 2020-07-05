# Greatest Common Divisor - C++

Calcula el Maximo Comun Divisor de dos Numeros

## Contenido

* [Contenido](#contenido)
* [Implementacion Recursiva](#implementacion-recursiva)
* [Implementacion Iterativa](#implementacion-iterativa)
* [Time Complexity](#time-complexity)
* [Space Complexity](#space-complexity)

### Implementacion Recursiva

```c++
// Euclid's algorithm
int gcd (int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}
```

### Implementacion Iterativa

```c++
int gcd (int a, int b) {
    int tmp = 0;
    while (b != 0){
        tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
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








---

## Algoritmo de Euclides Extendido - Ecuacion Diofantica

![Ecuacion Diofantica](https://i.ibb.co/Pzx2dzC/Ecuacion-Diofantica.png)

```java
int a = 25, b = 10;
Tuple tuple = extended_euclidean(25, 10);
println(a+"*"+tuple.y+"+"+b+"*"+tuple.x+"="+tuple.gcd);
// 25*1+10*-2=5
```

* ### Implementación Recursiva Euclides Extendido

```java
public static Tuple extended_euclidean(int a, int b) {
    if(a == 0) return new Tuple(b, 0, 1);

    Tuple tuple = extended_euclidean(b % a, a);
    int gcd=tuple.gcd, x=tuple.x, y=tuple.y;

    return new Tuple(gcd, (x - (b/a) * y), y);
}

static class Tuple {
    int gcd;
    int x;
    int y;

    Tuple(int gcd, int y, int x) {
        this.gcd = gcd;
        this.x = x;
        this.y = y;
    }
}
```

* ### Implementación Iterativa Euclides Extendido

```java
//main
int a = 10, b = 25;
Tuple tuple = xgcd(a, b);
println(a+"*"+tuple.y+"+"+b+"*"+tuple.x+"="+tuple.gcd);
//10*-2+25*1=5

// xgcd
public static Tuple xgcd(int a, int b) {
    int x0 = 1, x1 = 0, y0 = 0, y1 = 1;
    int q, r, tmp;

    while(b != 0) {
        q = a / b;
        r = a % b;
        tmp = x1;
        x1 = x0 - q * x1;
        x0 = tmp;
        tmp = y1;
        y1 = y0 - q * y1;
        y0 = tmp;
        a = b;
        b = r;
    }
    
    return new Tuple(a, x0, y0);
}
```

* ### Complexity Euclides Extendido

![Complexity - Algoritmo de Euclides Extendido](https://i.ibb.co/tbm7dxG/log-max-a-b.png)
