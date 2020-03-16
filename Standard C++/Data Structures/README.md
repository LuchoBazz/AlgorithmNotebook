# Standard Data Structures

### Contenido

* [Vector](#vector)
    * [Modificar Vector](#modificar-vector)
        * push_back(value)
        * pop_back()
        * insert(position, value)
        * erase(iterator1)
        * erase(iterator1, iterator2)
        * vector1.swap(vector2)
        * clear()
        * assign(size, value)
    * [Acceder a elementos de un Vector](#acceder-a-elementos-de-un-vector)
        * operator[index] o at(index)
        * front()
        * back()
        * data()
    * [Capacidad de un Vector](#capacidad-de-un-vector)


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

* ### Acceder a elementos de un Vector
    * ### operator[index] o at(index)
    Devuelve el valor que esta en el indice `index`.

    ```c++
    vector<int> myvector {3, 4, 1, 7, 5}; 
    // index              0  1  2  3  4
    cout << myvector[3]; // or
    cout<<myvector.at(3)>>
    // 7 
    ```

    * ### front()
    Devuelve el valor del primer elemento en el vector
    ```c++
    vector<int> myvector {3, 4, 1, 7, 5}; 
    // index              0  1  2  3  4
    myvector.front();
    // 3
    ```

    * ### back()
    Devuelve el valor del ultimo elemento en el vector
    ```c++
    vector<int> myvector {3, 4, 1, 7, 5}; 
    // index              0  1  2  3  4
    myvector.front();
    // 5
    ```

    * ### data()
    Devuelve el puntero de memoria del primer elemento
    
    ```c++
    vector<int> vec = { 10, 20, 30, 40, 50 }; 
    int* pos = vec.data();
    cout<<*pos;
    // 10
    cout<<*pos++;
    // 20
    ```

* ### Capacidad de un Vector
    * ### size()
    Numero de elementos en el vector
    ```c++
    vector<int> vector1{0, 1, 2, 3 ,4 ,5};
    vector1.size();
    // 6
    ```

    * ### empty()
    Devuelve `true` si el vector esta vacio y `false` en otro caso

    ```c++
    vector<int> vector1;
    vector1.empty()
    // true
    ```

    * ### capacity()
    Devuelve el tamaño del espacio de almacenamiento actualmente asignado para el vector, expresado en términos de elementos.

    ```c++
    vector<int> v; 
    for (int i = 0; i < 10; i++) { 
        v.push_back(i * 10); 
    } 
  
    cout << "size() " << v.size(); 
    cout << "capacity() " << v.capacity();
    // size() 10
    // capacity() 16
    ```

    * ### resize()
    La función altera el contenido del contenedor real insertando o eliminando los elementos del mismo. Sucede así,

    * Si el valor dado de n es menor que el tamaño actual, entonces elimina elementos

    * Si n es más grande que el tamaño actual del contenedor, los próximos elementos se agregan al final del vector.

    ```c++
    vector<int> vector1{1, 2, 3, 4 ,5, 6, 7};
    vector1.resize(4);
    // Vector becomes 1 2 3 4 5

    vector<int> vector1{1, 2, 3};
    vector1.resize(6);
    // Vector becomes 1 2 3 0 0 0

    vector<int> vector1{1, 2, 3};
    vector1.resize(6, -1);
    // Vector becomes 1 2 3 -1 -1 -1
    ```

    * ### reserve()
    Reserva espacio de memoria en el sistema

    ```c++
    vector<int> vec;
    vec.reserve(100);
    vec.size();     // 0
    vec.capacity(); // 100
    ```
