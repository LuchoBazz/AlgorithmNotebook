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
public class Knapsack {
    Integer[][] dp;

    int solve(int[] val, int[] wt, int item, int capacity) {
        if(item <= 0 || capacity <= 0) return 0;

        if(dp[item][capacity] != null) return dp[item][capacity];

        int itemCurr = item - 1;
        // Maximos items acumulado
        int lastMax = solve(val, wt, item-1, capacity);
        int currMax = 0;

        if(wt[itemCurr] <= capacity) {
            // Valor del item actual + el mejor item que cabe en la mochila
            currMax = val[itemCurr] + solve(val, wt, item - 1, capacity-wt[itemCurr]);
        }

        dp[item][capacity] = Math.max(lastMax, currMax);
        return dp[item][capacity];
    }

    public static void main(String[] args) {

        int[] val = {10, 40, 30, 50};
        int[] wt =  {5, 4, 6, 3};
        int n = val.length;
        int w = 10;

        Knapsack ks = new Knapsack();

        ks.dp = new Integer[n+1][w+1];
        System.out.println(ks.solve(val, wt, n, w));
        // 90
    }
}
```

## Implementación Iterativa - Bottom-Up

<img alt="0-1 Knapsack" src="https://he-s3.s3.amazonaws.com/media/uploads/2e5714c.png" width="500">[[From Hackerearth]](https://www.hackerearth.com/de/practice/notes/the-knapsack-problem/)


```java
public class Knapsack {
    public int knapsack(int[] val, int[] wt, int n, int w) {

        int[][] dp = new int[n + 1][w + 1];

        // Llenar de ceros la columna j=0
        for(int i = 0; i <= n; ++i) {
            dp[i][0] = 0;
        }

        // Llenar de ceros la fila i=0
        for(int j = 0; j <= w; ++j) {
            dp[0][j] = 0;
        }

        for(int item = 1; item <= n; ++item) { // item i
            for(int capacity = 1; capacity <= w; ++capacity) { // capacity j

                int itemCurr = item - 1;
                // Maximos items acumulado
                long lastMax = dp[itemCurr][capacity];
                long currMax = 0;

                if(wt[itemCurr] <= capacity) {
                    // Valor del item actual + el mejor item que cabe en la mochila
                    currMax = val[itemCurr] + dp[item - 1][capacity-wt[itemCurr]];
                }
                dp[item][capacity] = Math.max(lastMax, currMax);
            }
        }

        return dp[n][w];
    }

    public static void main(String[] args) {

        int[] val = {10, 40, 30, 50};
        int[] wt =  {5, 4, 6, 3};
        int n = val.length;
        int w = 10;

        Knapsack ks = new Knapsack();
        System.out.println(ks.knapsack(val, wt, n, w));
        // 90
    }
}
```

## Time Complexity

![O n * m](https://i.ibb.co/JKyfG3Y/O-n-m.png)

## Space Complexity

![O n * m](https://i.ibb.co/JKyfG3Y/O-n-m.png)