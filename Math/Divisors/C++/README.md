# Find all divisors of a number - C++

## Contenido

* [Contenido](#contenido)
* [Implementacion](#implementacion)
* [Time Complexity](#time-complexity)

### Implementacion

```c++
vector<int> divisors(int number) {
    vector<int> solutions;
    // 1 <= i <= sqrt(number)
    for (int i = 1; i <= sqrt(number); ++i) {
        if (number % i == 0) { // if i is divisor of number
            if (number/i == i) {
                // if i*i == number
                solutions.push_back(i);
            } else {
                // x=i, y=number/i
                // if x*y==number
                solutions.push_back(i);
                solutions.push_back(number/i);
            }
        }
    }
    return solutions;
}
```

### Time Complexity

```c++
O( sqrt(n) )

donde n es el numero dado
```