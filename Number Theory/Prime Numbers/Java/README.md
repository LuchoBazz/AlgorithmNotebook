# Prime Numbers - Java

## Contenido

* [Contenido](#contenido)
* [Criba de Eratostenes - Sieve of Eratosthenes](#criba-de-eratostenes---sieve-of-eratosthenes)
    * [Ilustración Criba](#ilustración-criba)
    * [Implementación Criba](#implementación-criba)
    * [Complexity Criba](#complexity-criba)
* [Factores Primos - Prime Factors](#factores-primos---prime-factors)
     * [Ilustración Factores Primos](#ilustración-factores-primos)
     * [Implementación Factores Primos](#implementación-factores-primos)
     * [Implementación - Pair](#implementación---pair)
     * [Main Factores Primos](#main-factores-primos)
     * [Complexity Factores Primos](#complexity-factores-primos)
* [Verificar si es Numero Primo Eficientemente](#verificar-si-es-numero-primo-eficientemente)
    * [Implementación - Verificar si es Primo](#implementación---verificar-si-es-primo)
    * [Complexity Verificar Numero Primo](#complexity-verificar-numero-primo)

---

## Criba de Eratostenes - Sieve of Eratosthenes

Este algoritmo nos permite calcular todos los numeros prime en un rango dado.

* ### Ilustración Criba

<img alt="Criba de Eratostenes" src="https://upload.wikimedia.org/wikipedia/commons/b/b9/Sieve_of_Eratosthenes_animation.gif" width="400">

* ### Implementación Criba

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

* ### Complexity Criba
![Complexity Criba](https://i.ibb.co/vB43qKr/n-Log-Log-n.png)

---

## Factores Primos - Prime Factors

* ### Ilustración Factores Primos
<img alt="Factores Primos - Prime Factors" src="https://www.mathsisfun.com/numbers/images/factor-tree-48.svg" width="250">

* ### Implementación Factores Primos

```java
public static List<Pair> primeFactors(int number) {
    // criba:
    // Todos los number primos desde [2, number]
    List<Integer> primes = criba(number);
    List<Pair> factors = new ArrayList<>();
    
    for(Integer prime: primes) {
        if(number % prime == 0) {
            int count = 0;
            while(number % prime == 0) {
                number /= prime;
                count++;
            }
            factors.add(new Pair(prime, count));
        }
    }
    return factors;
}
```

* ### Implementación - Pair

```java
static class Pair implements Comparable<Pair> {
    int key;
    int value;

    Pair(int key, int value) {
        this.key = key;
        this.value = value;
    }

    @Override
    public int compareTo(Pair other ) {
        int ans = Integer.compare(this.key, other.value);
        if(ans == 0) {
            ans = Integer.compare(this.key, other.value);
        }
        return ans;
    }
}
```

* ### Main Factores Primos

```java
public static void main(String[] args) {
    int number = 48;
    
    System.out.println("Start Number : " + number);
    
    List<Pair> factors = primeFactors(number);
    
    int prime = 0;
    int factor = 0;
    int num = 1;
    
    for(int i = 0; i < factors.size(); ++i) {
        prime = factors.get(i).key;
        factor =factors.get(i).value;
        num *= (int)Math.pow(prime, factor);
        if(i != factors.size()-1) {
            System.out.print("(" + prime + "^" + factor + ")*");
        } else {
            System.out.println("("+prime + "^" + factor+")");
        }
    }
    
    System.out.println("End Number : " + n);
}
// Output[]:
// Start Number : 48
// (2^4)*(3^1)
// End Number : 48
```

* ### Complexity Factores Primos

![Complexity Criba](https://i.ibb.co/vB43qKr/n-Log-Log-n.png)

---

## Verificar si es Numero Primo Eficientemente

* ### Implementación - Verificar si es Primo

```java
public static boolean isPrime(int number) {
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

* ### Complexity Verificar Numero Primo

![Complexity Verificar Numero Primo](https://i.ibb.co/8Y092Tx/O-sqrt-x.png)
