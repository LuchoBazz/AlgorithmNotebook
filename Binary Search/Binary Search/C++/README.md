# Binary Search - java

## Contenido

* [Contenido](#contenido)
* [Ilustración](#ilustración)
* [Implementación](#implementación)
    * [Iterativa](#iterativa)
    * [Recursiva](#recursiva)
* [Time Complexity](#time-complexity)

## Ilustración

<img alt="Binary Search" src="https://www.geeksforgeeks.org/wp-content/uploads/Binary-Search.png" width="500">

_Tomado de: Geeks for Geeks_

## Implementación

* ### Iterativa

* **Implementacion 1**

```c++
int search(vector<int> &values, int target) {
    int left = 0, right = values.size() - 1;
    int mid = 0;
    
    while (left <= right) {
        mid = left + (right - left ) / 2;
        
        if(nums[mid] == target) {
            return mid;
        }
        
        if(target < nums[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    // Not Found
    return -1;
}
```

* **Implementacion 2**

```c++
int binarySearch(vector<int> &values, int target) {
    int n = values.size();
    int k = 0;
    
    for (int a = n; a >= 1; a /= 2) {
        while (k+a < n && values[k+a] <= target) {
            k += a;
        }
    }
    if(values[k] == target) return k;
    
    return -1;
}
```

* ### Recursiva

```c++
int search(vector<int> &values, int target) {
    return search(values, 0, values.size() - 1, target);
    
}

int search(vector<int> &values, int left, int right, int target) {
    if(left <= right) {
        int mid = left + (right - left / 2);
        
        if(values[mid] == target) {
            return mid;
        }
        
        if(target < values[mid]) {
            return search(values, left, mid - 1, target);
        } else {
            return search(values, mid + 1, right, target);
        }
    }
    // Not Found
    return -1;
}
```

## Time Complexity

* ![Complejidad de Busqueda](https://i.ibb.co/RzJ8t4m/Log-n.png)