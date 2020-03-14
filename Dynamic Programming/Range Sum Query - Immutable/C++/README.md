# Range Sum Query - Immutable

## Contenido

* [Contenido](#contenido)
* [Ilustración](#ilustración)
* [Implementación](#implementación)
* [Complejidad](#complejidad)

## Ilustración

|arr| 1 | 3 | -2 | 6 | 8  |
|---|---|---|----|---|----|
|dp| 1 | 4 | 2  | 8 | 16 |

**Ejemplos:**
* `range(0, 3)` es igual a `dp[3]`
* `range(1, 3)` es igual a `dp[3]-dp[0]`
* `range(2, 4)` es igual a `dp[4] - dp[1]`

## Implementación

```java
class Range {
public:

    vector<int> dp;

    Range(vector<int>& nums) {
        if(nums.size() == 0) return;
        
        dp.resize(nums.size());
        
        dp[0] = nums[0];
        
        for(int i = 1; i < nums.size(); ++i) {
            dp[i] = dp[i - 1] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        if(i==0) return dp[j];

        return dp[j] - dp[i-1];
    }
};
```

## Complejidad

![O de n](https://i.ibb.co/wsr7QLX/O-n.png)