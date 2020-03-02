# Binary Search - java

## Contenido

* [Contenido](#contenido)
* [Ilustración](#ilustración)
* [Implementación](#implementación)
    * [Iterativa](#iterativa)
    * [Recursiva](#recursiva)
* [Complejidad](#complejidad)

## Ilustración

<img alt="Binary Search" src="https://www.geeksforgeeks.org/wp-content/uploads/Binary-Search.png" width="500">

_Tomado de: Geeks for Geeks_

## Implementación

* ### Iterativa

```java

public int search(int[] nums, int target) {
    int left = 0, right = nums.length - 1;
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

* ### Recursiva

```java

```

## Complejidad

* ![Complejidad de Busqueda](https://i.ibb.co/RzJ8t4m/Log-n.png)