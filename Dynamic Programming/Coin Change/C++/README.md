# Coin Change - C++

## Contenido

* [Contenido](#contenido)
* [Implementación Recursiva](#implementación-recursiva)

## Implementación Recursiva

```c++
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
```

## Complexity

* ### Time Complexity

    <img alt="Coin Change" src="https://i.ibb.co/brG8ZMM/O-n.png" width="50">