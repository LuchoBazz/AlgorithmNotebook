# Math - ToolBox - C++

## Contenido

* [Contenido](#contenido)

### Suma de múltiplos de un número hasta N

* Calcula la suma de todos los divisores de `number` desde `1` hasta `N` incluyendolo.

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

### Es Potencia de N

Verifica si `number` es potencia de `N`.

```c++
bool isPowerOfN(int number, int N) { 
    if(number == 0) {
        return false; 
    }

    while(number != 1) {  
        if(number % N != 0)  {
            return false; 
        }
        number = number / N;  
    } 
    return true; 
} 
```