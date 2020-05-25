# Lower_Bound & Upper_Bound - Standard Library

### Contenido

* [Incluir](#incluir)

* [Lower_Bound & Upper_Bound](#lower_bound--upper_bound)

### Incluir

```c++
#include <algorithm> // std::algorithm
```

* ### Lower_Bound & Upper_Bound

    * Case 1
    ```c++
    // indexes:    0  1  2  3  4  5  6  7  8  9   10
    vector<int> v {1, 2, 3, 3, 3, 3, 4, 4, 7, 10, 12};
    
    int target = 3;
    
    vector<int>::iterator lower, upper; 
    
    lower = lower_bound (v.begin(), v.end(), target);  
    upper = upper_bound (v.begin(), v.end(), target);
    
    cout << "Lower: " << (lower - v.begin()) << '\n';
    cout << "Upper: " << (upper - v.begin()) << '\n';

    // Target: 3

    // Lower: 2
    // Upper: 6
    ```

    * Case 2
    ```c++
    // indexes:    0  1  2  3  4  5  6  7  8  9   10
    vector<int> v {1, 2, 3, 3, 3, 3, 4, 4, 7, 10, 12};
    
    int target = -10;
    
    vector<int>::iterator lower, upper; 
    
    lower = lower_bound (v.begin(), v.end(), target);  
    upper = upper_bound (v.begin(), v.end(), target);
    
    cout << "Lower: " << (lower - v.begin()) << '\n';
    cout << "Upper: " << (upper - v.begin()) << '\n';

    // Target: -10

    // Lower: 0
    // Upper: 0
    ```

    * Case 3
    ```c++

    // indexes:    0  1  2  3  4  5  6  7  8  9   10
    vector<int> v {1, 2, 3, 3, 3, 3, 4, 4, 7, 10, 12};
    
    int target = 100;
    
    vector<int>::iterator lower, upper; 
    
    lower = lower_bound (v.begin(), v.end(), target);  
    upper = upper_bound (v.begin(), v.end(), target);
    
    cout << "Lower: " << (lower - v.begin()) << '\n';
    cout << "Upper: " << (upper - v.begin()) << '\n'; 

    // Target: 100

    // Lower: 11
    // Upper: 11
    ```

    * Case 4

    ```c++
    // indexes:    0  1  2  3  4  5  6  7  8  9   10
    vector<int> v {1, 2, 3, 3, 3, 3, 4, 4, 7, 10, 12};
    
    int target = 8;
    
    vector<int>::iterator lower, upper; 
    
    lower = lower_bound (v.begin(), v.end(), target);  
    upper = upper_bound (v.begin(), v.end(), target);
    
    cout << "Lower: " << (lower - v.begin()) << '\n';
    cout << "Upper: " << (upper - v.begin()) << '\n';

    // Target: 8

    // Lower: 9
    // Upper: 9
    ```

    * Case 5
    ```c++
    // indexes:    0  1  2  3  4  5  6  7  8  9   10
    vector<int> v {1, 2, 3, 3, 3, 3, 4, 4, 7, 10, 12};
    
    int target = 1;
    
    vector<int>::iterator lower, upper; 
    
    lower = lower_bound (v.begin(), v.end(), target);  
    upper = upper_bound (v.begin(), v.end(), target);
    
    cout << "Lower: " << (lower - v.begin()) << '\n';
    cout << "Upper: " << (upper - v.begin()) << '\n';

    // Target: 1

    // Lower: 0
    // Upper: 1
    ```