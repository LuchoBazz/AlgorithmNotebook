# 0-1 Knapsack - C++
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

```c++
// Top-Down
class Knapsack {
public:
    vector<vector<long long>> dp;

    long long solve(vector<long long> &val, vector<long long> &wt, int item, int capacity) {
        // Casos base
        if(item <= 0 || capacity <= 0) return 0;

        if(dp[item][capacity] != -1) return dp[item][capacity];
        
        int itemCurr = item - 1;
        // Maximos items acumulado
        long long lastMax = solve(val, wt, item-1, capacity);
        long long currMax = 0;

        if(wt[itemCurr] <= capacity) {
            // Valor del item actual + el mejor item que cabe en la mochila
            currMax = val[itemCurr] + solve(val, wt, item - 1, capacity-wt[itemCurr]);
        }

        dp[item][capacity] = max(lastMax, currMax);
        return dp[item][capacity];
    }
};

int main() {
    vector<int> val{10, 40, 30, 50};
    vector<int> wt{5, 4, 6, 3};
    int n = val.size();
    int w = 10;
    Knapsack ks;

    ks.dp.resize(n+1, vector<long long>(w+1, -1));
    cout<<ks.solve(val, wt, n, w)<<endl;
    // 90
    return 0;
}
```

## Implementación Iterativa - Bottom-Up

<img alt="0-1 Knapsack" src="https://he-s3.s3.amazonaws.com/media/uploads/2e5714c.png" width="500">[[From Hackerearth]](https://www.hackerearth.com/de/practice/notes/the-knapsack-problem/)


```c++
class Knapsack {
public:
    int knapsack(vector<int> &val, vector<int> &wt,int n, int w) {

        vector<vector<long long>> dp(n+1, vector<long long>(w+1, 0));

        for(int item = 1; item <= n; ++item) { // item i
            for(int capacity = 1; capacity <= w; ++capacity) { // capacity j

                int itemCurr = item - 1;
                // Maximos items acumulado
                long long lastMax = dp[itemCurr][capacity];
                long long currMax = 0;

                if(wt[itemCurr] <= capacity) {
                    // Valor del item actual + el mejor item que cabe en la mochila
                    currMax = val[itemCurr] + dp[item - 1][capacity-wt[itemCurr]];
                }
                dp[item][capacity] = max(lastMax, currMax);
            }
        }

        return dp[n][w];
    }
};

int main() {
    vector<int> val{10, 40, 30, 50};
    vector<int> wt{5, 4, 6, 3};
    int n = val.size();
    int k = 10;
    Knapsack ks;
    cout<<ks.knapsack(val, wt, n, k)<<endl;
    // 90
    return 0;
}
```

## Time Complexity

![O n * m](https://i.ibb.co/JKyfG3Y/O-n-m.png)

## Space Complexity

![O n * m](https://i.ibb.co/JKyfG3Y/O-n-m.png)