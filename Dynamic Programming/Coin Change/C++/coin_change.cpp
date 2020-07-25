#include <bits/stdc++.h>
 
using namespace std;

class CoinChange {
public:

    vector<int> memo;
    
    int coinChange(vector<int>& coins, int amount) {
        memo.resize(amount+1, -1);
        int answer = solve(coins, amount);
        return (answer==INT_MAX)?-1:answer;
    }
    
    int solve(vector<int>& coins, int amount) {
        if(amount < 0) return INT_MAX;
        if(amount == 0) return 0;
        
        if(memo[amount] != -1) return memo[amount];
        
        int minimum = INT_MAX;
        int curr;
        
        for(int coin: coins) {
            curr = solve(coins, amount - coin);
            minimum = min(minimum, ((curr==INT_MAX)?INT_MAX:curr+1));
        }
        memo[amount] = minimum;
        return memo[amount];
    }
};

int main() {
    CoinChange cc;

    vector<int> coins{1, 2, 5};
    int amount = 11;

    cout<<cc.coinChange(coins, amount)<<endl;
    // 3
    return 0;
}