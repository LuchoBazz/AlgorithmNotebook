#include <bits/stdc++.h>

using namespace std;

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


class OptimizedSolution {
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