#include <bits/stdc++.h>

using namespace std;

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