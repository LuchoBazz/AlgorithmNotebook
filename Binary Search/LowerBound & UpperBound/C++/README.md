# LowerBound & UpperBound - C++

## Contenido

* [Contenido](#contenido)
* [Ilustración](#ilustración)
* [Implementación](#implementación)
    * [Iterativa Lower Bound](#iterativa-lower-bound)
    * [Iterativa Upper Bound](#iterativa-upper-bound)
* [Complejidad](#complejidad)

## Ilustración

<img alt="Binary Search" src="https://www.geeksforgeeks.org/wp-content/uploads/Binary-Search.png" width="500">

_Tomado de: Geeks for Geeks_

## Implementación

* ### Iterativa Lower Bound

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

* ### Iterativa Upper Bound

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

## Complejidad

* ![Complejidad de Busqueda](https://i.ibb.co/RzJ8t4m/Log-n.png)