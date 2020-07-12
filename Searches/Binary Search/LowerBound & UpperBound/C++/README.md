# LowerBound & UpperBound - C++

## Contenido

* [Contenido](#contenido)
* [Ilustración](#ilustración)
* [Implementación](#implementación)
    * [Iterativa Lower Bound](#iterativa-lower-bound)
    * [Iterativa Upper Bound](#iterativa-upper-bound)
* [Time Complexity](#time-complexity)

## Ilustración

<img alt="Binary Search" src="https://www.geeksforgeeks.org/wp-content/uploads/Binary-Search.png" width="500">

_Tomado de: Geeks for Geeks_

## Implementación

* ### Iterativa Lower Bound

* **Implementacion 1**
```c++
int lowerBound(vector<int> &values, int target) {
    int n = values.size();
    int low=0, high=n-1, mid;
    
    while(low <= high) {
        mid = (low + high) / 2;
        
        if(values[mid] < target) {
          low = mid + 1;  
        } else {
            high = mid - 1;
        }
    }
    
    return low;
}
```

* **Implementacion 2**

```c++
int lowerBound(vector<int> &values, int target) {
    int n = values.size();
    int k = -1;
    for (int a = n; a >= 1; a /= 2) {
        while (k+a < n && values[k+a] < target) {
            k += a;
        }
    }
    return k+1;
}
```

* ### Iterativa Upper Bound

* **Implementacion 1**

```c++
int upperBound(vector<int> &values, int target) {
    int n = values.size();
    int low=0, high=n-1, mid;
    
    while(low <= high) {
        mid = (low + high) / 2;
        
        if(values[mid] <= target) {
          low = mid + 1;  
        } else {
            high = mid - 1;
        }
    }
    
    return low;
}
```

* **Implementacion 2**

```c++
int upperBound(vector<int> &values, int target) {
    int n = values.size();
    int k = -1;
    for (int a = n; a >= 1; a /= 2) {
        while (k+a < n && values[k+a] <= target) {
            k += a;
        }
    }
    return k+1;
}
```

## Time Complexity

* ![Complejidad de Busqueda](https://i.ibb.co/RzJ8t4m/Log-n.png)