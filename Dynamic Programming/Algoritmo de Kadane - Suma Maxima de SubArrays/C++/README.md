# Algoritmo de Kadane - Suma Maxima de SubArrays - C++

El problema de la subArray máxima es la tarea de encontrar el subArray contigua dentro de una vector unidimensional, un `[1 ... n]`, de números que tiene la suma más grande.

## Contenido

* [Contenido](#contenido)
* [Ilustración](#ilustración)
* [Implementación](#implementación)
* [Complejidad](#complejidad)

## Ilustración

<img alt="Algoritmo de Kadane - Suma Maxima de SubArrays" src="https://miro.medium.com/max/653/1*li8Wlm3ZpInWLvpJ3yE9Iw.png" width="500"> _Tomada de_ [[4] Medium](https://medium.com/@rsinghal757/kadanes-algorithm-dynamic-programming-how-and-why-does-it-work-3fd8849ed73d)


## Implementación

```c++
class Kadane {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        vector<int> dp(nums.size(), 0);
        
        dp[0] = nums[0];
        int sum = dp[0];
        
        for(int i = 1; i < nums.size(); ++i) {
            dp[i] = max(dp[i-1], 0) + nums[i];
            sum = max(sum, max(dp[i], nums[i]));
        }
        
        return sum;
    }
};
```

## Complejidad

<img alt="Algoritmo de Kadane" src="https://i.ibb.co/brG8ZMM/O-n.png" width="50">