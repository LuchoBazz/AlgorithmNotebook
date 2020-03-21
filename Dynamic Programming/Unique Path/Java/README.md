# Unique Paths - Java

Un robot está ubicado en la esquina superior izquierda de una cuadrícula m x n (marcada `Start` en el diagrama a continuación).

El robot solo puede moverse hacia abajo o hacia la derecha en cualquier momento. El robot está tratando de llegar a la esquina inferior derecha de la cuadrícula (marcado `Finish` en el diagrama a continuación).

¿Cuántos caminos únicos posibles hay?

## Contenido

* [Contenido](#contenido)
* [Ilustración](#ilustración)
* [Implementación Recursiva - Top-Down](#implementación-recursiva---top-down)
* [Implementación Iterativa - Bottom-Up](#implementación-iterativa---bottom-up)
* [Time Complexity](#time-complexity)
* [Space Complexity](#space-complexity)

## Ilustración

<img alt="Unique Paths" src="https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png" width="400">

## Implementación Recursiva - Top-Down


```java
class Solution {
    
    private Integer[][] dp;
    
    public int uniquePaths(int m, int n) {
        dp = new Integer[n][m];
        return startMoving(0, 0, n, m);
    }
    
    public int startMoving(int coordN, int coordM, int n, int m) {
        if(isFinished(coordN, coordM, n, m)) {
            return 1;
        }
        
        if(dp[coordN][coordM] != null) return dp[coordN][coordM];
        
        int count = 0;
        
        if(canGoRigth(coordM, m)) {
            count += startMoving(coordN, coordM+1, n, m);
        }
        
        if(canGoDown(coordN, n)) {
            count += startMoving(coordN+1, coordM, n, m);
        }
        
        dp[coordN][coordM] = count;
        return (int)dp[coordN][coordM];
    }
    
    public boolean canGoDown(int coordN, int n) {
        return (coordN + 1) < n;
    }
    
    public boolean canGoRigth(int coordM, int m) {
        return (coordM + 1) < m;
    }
    
    public boolean isFinished(int coordN, int coordM, int n, int m) {
        return (coordN==(n-1)) && (coordM==(m-1));
    }
}
```

## Implementación Iterativa - Bottom-Up

```java
class Solution {
    public int uniquePaths(int m, int n) {
        int[][] dp = new int[n][m];
        
        for(int i = 0; i < n; ++i) {
            dp[i][0] = 1;
        }
        
        for(int j = 0; j < m; ++j) {
            dp[0][j] = 1;
        }
        
        for(int i = 1; i < n; ++i) {
            for(int j = 1; j < m; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }
}
```

## Time Complexity

![O n * m](https://i.ibb.co/JKyfG3Y/O-n-m.png)

## Space Complexity

![O n * m](https://i.ibb.co/JKyfG3Y/O-n-m.png)