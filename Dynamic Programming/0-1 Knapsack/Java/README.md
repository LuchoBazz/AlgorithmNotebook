# 0-1 Knapsack - Java
Considere que un ladrón entra en una casa para robar y lleva una mochila. Hay un número fijo de artículos en el hogar, cada uno con su propio peso y valor. Joyas, con menos peso y mayor valor en comparación con las mesas, con menos valor pero mucho más pesadas. Para agregar combustible al fuego, el ladrón tiene una mochila vieja que tiene una capacidad limitada. Obviamente, no puede dividir la mesa por la mitad o las joyas en 3/4. Él lo toma o lo deja. [Source](https://www.hackerearth.com/de/practice/notes/the-knapsack-problem/)

## Contenido

* [Contenido](#contenido)
* [Ilustración](#ilustración)
* [Implementación Recursiva - Top-Down](#implementación-recursiva---top-down)
* [Implementación Iterativa - Bottom-Up](#implementación-iterativa---bottom-up)
* [Time Complexity](#time-complexity)
* [Space Complexity](#space-complexity)

## Ilustración

<img alt="0-1 Knapsack" src="https://he-s3.s3.amazonaws.com/media/uploads/82d724d.png" width="300"> [[From Hackerearth]](https://www.hackerearth.com/de/practice/notes/the-knapsack-problem/)

## Implementación Recursiva - Top-Down


```java

```

## Implementación Iterativa - Bottom-Up

<img alt="0-1 Knapsack" src="https://he-s3.s3.amazonaws.com/media/uploads/2e5714c.png" width="500">[[From Hackerearth]](https://www.hackerearth.com/de/practice/notes/the-knapsack-problem/)


```java
int[] val = {10, 40, 30, 50};
int[] wt =  {5, 4, 6, 3};
int n = val.length;
int w = 10;
int[][] dp = new int[n + 1][w + 1];

// Llenar de ceros la columna j=0
for(int i = 0; i <= n; ++i) {
    dp[i][0] = 0;
}

// Llenar de ceros la fila i=0
for(int j = 0; j <= w; ++j) {
    dp[0][j] = 0;
}


for(int i = 1; i <= n; ++i) { // Item i
    for(int j = 1; j <= w; ++j) { // Weight j
        // Maximos pesos de items anteriores
        int maxWithOutCurr = dp[i-1][j];
        // Item Actual
        int maxWithCurr = 0;

        // Verificamos si el item actual cabe en la mochila
        if(wt[i-1] <= j) {
            // Item Actual + Otro anterior item
            // peso item actual + peso otro anterior item
            // caben en la mochila
            maxWithCurr = val[i-1] + dp[i-1][j-wt[i-1]];
        }
        // Maximo peso
        dp[i][j] = Math.max(maxWithOutCurr, maxWithCurr);
    }
}

out.println(dp[n][w]);
```

## Time Complexity

![O n * m](https://i.ibb.co/JKyfG3Y/O-n-m.png)

## Space Complexity

![O n * m](https://i.ibb.co/JKyfG3Y/O-n-m.png)