# Standard Data Structures

### Contenido

* [Vector](#vector)
    * [Modificar](#modificar-vector)
        * push_back(value)
        * pop_back()
        * insert(position, value)
        * erase(iterator1)
        * erase(iterator1, iterator2)
        * vector1.swap(vector2)
        * clear()
        * assign(size, value)


### Vector

* ### Modificar Vector

    * ### push_back(value):
    Agrega el elemento `value` al final del vector.
    ```c++
    vector<int> myvector{ 1, 2, 3, 4, 5 }; 
    myvector.push_back(6); 
    // Vector becomes 1, 2, 3, 4, 5, 6 
    ```

    * ### pop_back():
    Elimina el ultimo elemento del vector.
    ```c++
    vector<int> myvector{ 1, 2, 3, 4, 5 }; 
    myvector.pop_back(); 
    // Vector becomes 1, 2, 3, 4 
    ```

    * ### insert(position, value):
    Agrega el elemento `value` en el indice `position`.
    ```c++
    vector<int> vec = { 10, 20, 30, 40 }; 
    auto it = vec.insert(vec.begin(), 3); 
    vec.insert(it, 2);
    // Vector becomes 2 3 7 10 20 30 40

    vector<int> vec = { 10, 20, 70, 80 }; 
    int x = 50; 
    vec.insert(vec.begin() + 2, { 30, 40, x, 60 }); 
    // Vector becomes 10 20 30 40 50 60 70 80
    ```

    * ### erase(iterator1):
    Elimina el elemento que esta en el `iterator1`.
    * ### erase(iterator1, iterator2):
    Elimina los elementos desde `iterator1` hasta `iterator2`.

    ```c++
    vector<int> myvector{ 1, 2, 3, 4, 5 }; 
    vector<int>::iterator it; 
    it = myvector.begin() + 2; 
    myvector.erase(it);
    // Vector becomes 1 2 4 5

    vector<int> myvector{ 1, 2, 3, 4, 5 }; 
    vector<int>::iterator it1, it2; 
    it1 = myvector.begin(); 
    it2 = myvector.end(); 
    it2--; 
    it2--; 
    myvector.erase(it1, it2); 
    // Vector becomes 4 5
    ```

    * ### vector1.swap(vector2):
    Cambia la referencia de los vectores
    ```c++
    vector<int> vector1{ 1, 2, 3, 4 };
    vector<int> vector2{ 3, 5, 7, 9 }; 
    vector1.swap(vector2); 
    // vector1 becomes 3 5 7 9 
    // vector2 becomes 1 2 3 4 
    ```

    * ### clear():
    Vacia el vector
    ```c++
    vector<int> vector1{ 1, 2, 3, 4 };
    vector1.clear(); 
    // vector1 becomes empty 
    ```

    * ### assign(size, value):
    Asigna nuevos valores a los elementos del vector reemplazando los antiguos. También puede modificar el tamaño del vector si es necesario.

    ```c++
    vector<int> v; 
    v.assign(7, 100);
    // size(): 7
    // Vector becomes 100 100 100 100 100 100 100 
    ```