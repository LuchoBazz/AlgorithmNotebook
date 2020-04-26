# Minimum Path Sum in a Matrix - C++

## Contenido

* [Contenido](#contenido)
* [Implementación NxM Space](#implementación-nxm)
* [Implementación M Space](#implementación-m-space)

## Implementación NxM Space

```c++
class Solution {
    const int oo = INT_MAX/2;
    
    bool canGoRight(int j, int m) {return (j+1)<m;}
    bool canGoDown(int i, int n) {return (i+1)<n;}
    
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 0;
        
        const int n = grid.size();
        const int m = grid[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, oo));
        
        dp[n-1][m-1] = grid[n-1][m-1];
        
        for(int i = n-1; i>=0; i--) {
            for(int j = m-1; j >= 0; j--) {
                
                if((canGoDown(i, n)) {
                    dp[i][j] = min(oo, dp[i+1][j] + grid[i][j]);
                }
                
                if((canGoRight(j, m)) {
                    dp[i][j] = min(dp[i][j], dp[i][j+1] + grid[i][j]);
                }
            }
        }
        return dp[0][0];
    }
};
```

## Complexity NxM Space

* ### Time Complexity

    ![Minimum Path Sum in a Matrix Time](https://i.ibb.co/qmWPJ5h/O-NxM.png)

* ### Space Complexity

    ![Minimum Path Sum in a Matrix Time](https://i.ibb.co/qmWPJ5h/O-NxM.png)

Donde:

* ![Filas](https://i.ibb.co/7VQ1d5H/N.png) Numero de Filas

* ![Columnas](https://i.ibb.co/ChyfF7f/M.png) Numero de Columnas

## Implementación M Space

**Nota:** Usando el truco de las dos Columnas

```c++
class Solution {
    const int oo = INT_MAX/2;
    
    bool canGoRight(int j, int m) {return (j+1)<m;}
    bool canGoDown(int i, int n) {return (i+1)<n;}
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 0;
        
        const int n = grid.size();
        const int m = grid[0].size();
        
        vector<vector<int>> dp(2, vector<int>(m, oo));
        
        dp[(n-1)&1][m-1] = grid[n-1][m-1];
        
        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j >= 0; j--) {
                
                // i&1 -> si es una fila par, use la posición 0
                // y si es impar usa la 1

                if(canGoDown(i, n)) {
                    
                    dp[i&1][j] = min(oo, dp[!(i&1)][j]+grid[i][j]);
                }
                
                if(canGoRight(j, m)) {
                    dp[i&1][j] = min(dp[i&1][j], dp[i&1][j+1]+grid[i][j]);
                }
            }
        }
        return dp[0][0];
    }
};
```

## Complexity M Space

* ### Time Complexity

    ![Minimum Path Sum in a Matrix Time](https://i.ibb.co/qmWPJ5h/O-NxM.png)

* ### Space Complexity

    ![Minimum Path Sum in a Matrix Time](https://i.ibb.co/WVwwDVB/O-M.png)

Donde:

* ![Filas](https://i.ibb.co/7VQ1d5H/N.png) Numero de Filas

* ![Columnas](https://i.ibb.co/ChyfF7f/M.png) Numero de Columnas