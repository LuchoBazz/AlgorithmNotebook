# Generate all Permutations - C++

Calcular todas las permutaciones de los valores de un vector

## Contenido

* [Contenido](#contenido)
* [Implementacion](#implementacion)
* [Time Complexity](#time-complexity)
* [Space Complexity](#space-complexity)

### Implementacion

```c++
vector<vector<int>> solutions;
vector<bool> chosen;
vector<int> permutation;

void backtracking(vector<int> &nums) {
    if(permutation.size() == nums.size()) {
        solutions.push_back(permutation);
    } else {
        for(int i = 0; i < nums.size(); ++i)  {
            if(chosen[i]) continue;
            permutation.push_back(nums[i]);
            chosen[i] = true;
            backtracking(nums);
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

// Main
int n = nums.size();
chosen.resize(n, false);
backtracking(nums);
```

### Time Complexity

```c++
O(n!)

Donde n es el numero de bits
```

### Space Complexity

```
Si no almaceno los resultados en un vector
O(n)

Si almaceno los resultados en un vector
O(n!)

Donde n es el numero de datos del vector
```