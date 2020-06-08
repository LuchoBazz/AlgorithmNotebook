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
    int n = values.size();
    int low = 0, high = n - 1;
    int mid = 0;
    
    while (low <= high) {
        mid = low + (high - low ) / 2;
        
        if(values[mid] == target) {
            return mid;
        }
        
        if(target < values[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    // Not Found
    return -1;
}
```

* **Implementacion 2**

```c++
int search(vector<int> &values, int target) {
    int n = values.size();
    int low = 0, high = n - 1;
    int mid = 0;
    
    while (high - low > 1) {
        mid = (low + high) / 2;
        if(target < values[mid]) {
            high = mid;
        } else {
            low = mid;
        }
    }
    
    if(values[low] == target) {
        return low;
    } else if(values[high] == target) {
        return high;
    }
    // Not Found
    return -1;
}
```

* **Implementacion 3**

```c++
int binarySearch(vector<int> &values, int target) {
    int n = values.size();
    int index = 0;
    
    // O(log2(n))
    for (int jump = n; jump >= 1; jump /= 2) {
        while (index+jump < n && values[index+jump] <= target) {
            index += jump;
        }
    }
    if(values[index] == target) return index;
    
    return -1;
}
```

* ### Recursiva

```c++
int search(vector<int> &values, int target) {
    return search(values, 0, values.size() - 1, target);
}

int search(vector<int> &values, int low, int high, int target) {
    if(low <= high) {
        int mid = low + (high - low / 2);
        
        if(values[mid] == target) {
            return mid;
        }
        
        if(target < values[mid]) {
            return search(values, low, mid - 1, target);
        } else {
            return search(values, mid + 1, high, target);
        }
    }
    // Not Found
    return -1;
}
```

## Time Complexity

* ![Complejidad de Busqueda](https://i.ibb.co/RzJ8t4m/Log-n.png)