# It is Power of N

Verifica si `number` es potencia de `N`.

## Contenido

* [Contenido](#contenido)
* [Implementacion](#implementacion)
* [Time Complexity](#time-complexity)
* [Space Complexity](#space-complexity)

### Implementacion

```c++
bool isPowerOfN(int number, int N) { 
    if(number == 0 || (number!=1 && N == 0)) return false; 
    else if(N == 1) return true;
    
    while(number != 1) {  
        if(number % N != 0)  {
            return false; 
        }
        number = number / N;  
    } 
    return true; 
} 
```

### Time Complexity

```c++
O(n)
```

### Space Complexity

```c++
O(1)
```