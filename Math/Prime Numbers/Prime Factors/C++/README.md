# Prime Factors - C++

## Contenido

* [Contenido](#contenido)
* [Ilustración](#ilustración)
* [Implementación](#implementación)
* [Time Complexity](#time-complexity)


## Ilustración

<img alt="Prime Factors" src="https://www.mathsisfun.com/numbers/images/factor-tree-48.svg" width="200">

_Tomada de_ [MathSisfun](https://www.mathsisfun.com/prime-factorization.html)

Este algoritmo calcula todos los factores primos de un numero.

### Implementación

```c++
vector<int> primeFactors(int number)  {
    vector<int> factors;
    
    // Print the number of 2s that divide n  
    while (number % 2 == 0) {  
        factors.push_back(2);
        number = number / 2;  
    }  
  
    // number must be odd at this point. So we can skip  
    // one element (Note i = i + 2)  
    for (int i = 3; i*i <= number; i += 2) {  
        // While i divides number, print i and divide n  
        while (number % i == 0) {  
            factors.push_back(i);
            number = number / i;  
        }  
    }  
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2  
    if (number > 2)  {
        factors.push_back(number);
    }
    return factors;
}
```

## Time Complexity

```c++
O(sqrt(n))

Donde n es el numero dado
```