# BitSet - Standard Library

### Contenido

* [Incluir](#incluir)

* [Metodos](#metodos)
    * void **set(index, flag)**
    * void **set(index)**
    * void **set()**
    * void **bitset_name[index] = flag**
    * bool **all()**
    * bool **none()**
    * int **count()**
    * bool **any()**
    * void **reset()**
    * void **reset(index)**
    * int **size()**
    * bitset\<N\>& **flip()**
    * bitset\<N\>& **flip(index)**
    * bool **test(index)**

* [Operadores](#operadores)
    * **==** and **!=*
    * **^=**
    * **&=**
    * **|=**
    * **\<\<=**
    * **\>\>=**
    * **~**
    * **&**, **|**, **^**




### Incluir

```c++
#include <bitset> // std::bitset
```

* ### Metodos

    * ### void set(index, flag):
    Agrega el valor de `flag (0 o 1)` en la posición `index`
    ```c++
    bitset<10> bit("1010");
    bit.set(7, true);
    cout << bit << endl;
    // 0010001010
    ```

    * ### void set(index):
    Prende el bit de la posición `index`
    ```c++
    bitset<10> bit("1010");
    bit.set(2);
    cout << bit << endl;
    // 0010001110
    ```

    * ### void set():
    Prende todos los bits
    ```c++
    bitset<10> bit("1010");
    bit.set();
    cout << bit << endl;
    // 1111111111
    ```

    * ### void bitset_name[index] = flag
    Agrega el valor de `flag` en el bit de la posición `operator[index]`
    ```c++
    bitset<10> bit(0);

    bit[0] = 1;
    cout << bit << endl;
    // 0000000001
    
    bit[9] = bit[0];
    cout << bit << endl;
    // 1000000001
    ```

    * ### bool all()
    Revisa si tiene todos los bits prendidos
    ```c++
    bitset<10> bit("1111111111");

    cout << bit.all() << endl;
    // true
    
    bit[5] = 0;
    cout << bit.all() << endl;
    // false
    ```

    * ### bool none()
    Revisa si tiene todos los bits apagados
    ```c++
    bitset<10> bit("0000000000");

    cout << bit.none() << endl;
    // true
    
    bit[5] = 1;
    cout << bit.none() << endl;
    // false
    ```

    * ### int count()
    Cuenta el numero de bits del bitset
    ```c++
    bitset<10> bit(10);
    // 0000001010

    cout << bit.count() << endl;
    // 2
    
    bit[8] = 1;
    cout << bit.count() << endl;
    // 3
    ```

    * ### bool any()
    Devuelve `true` si tiene almenos un bit prendido y `false` en caso contrario.
    **Nota:** Es igual a `bit.count() >= 1`
    ```c++
    bitset<10> bit("0");

    cout << bit.any() << endl;
    // false
    
    bit[8] = 1;
    cout << bit.any() << endl;
    // true
    ```

    * ### void reset()
    Apaga todos los bits del bitset
    ```c++
    bitset<10> bit("1111111111");

    cout << bit.reset() << endl;
    // 0000000000
    ```

    * ### void reset(index)
    Apaga el bit de la posición `index`
    ```c++
    bitset<10> bit("1111111111");

    cout << bit.reset(2) << endl;
    // 1111111011
    ```

    * ### int size() 
    Devuelve el tamaño del bitset
    ```c++
    bitset<10> bit1("1111111111");
    cout << bit1.size() << endl;
    // 10
    bitset<5> bit2(0);
    cout << bit2.size() << endl;
    // 5
    ```

    * ### bitset\<N\>& flip()
    Voltea los bits 1 por 0 y los 0 por 1
    ```c++
    bitset<10> bit("1100");
    cout << bit.flip() << endl;
    // 1111110011
    ```

    * ### bitset\<N\>& flip(index) 
    Voltea el bit de la posición `index`
    ```c++
    bitset<10> bit("1100");
    cout << bit.flip(0) << endl;
    // 0000001101
    ```

    * ### bool test(index)
    Verifica si el la posición index hay un bit prendido
    ```c++
    bitset<10> bit("1100");
    cout << bit.test(0) << endl;
    // false
    cout << bit.test(2) << endl;
    // true
    ```

* ### Operadores
    * ### == and !=
    Compara los bitset
    ```c++
    bitset<10> bit_1(10);
    bitset<10> bit_2("1010");
    
    cout << (bit_1 == bit_2) << endl;
    // true
    
    cout << (bit_1 != bit_2) << endl;
    // false
    ```

    * ### ^=

    ```c++
    bitset<10> bit_1("0100");
    bitset<10> bit_2("1010");
    
    cout << (bit_1 ^= bit_2) << endl;
    // 0000001110
    ```

    * ### &=

    ```c++
    bitset<10> bit_1("0110");
    bitset<10> bit_2("1010");
    
    cout << (bit_1 &= bit_2) << endl;
    // 0000000010
    ```

    * ### |=

    ```c++
    bitset<10> bit_1("0110");
    bitset<10> bit_2("1010");
    
    cout << (bit_1 |= bit_2) << endl;
    // 0000001110
    ```

    * ### <<=

    ```c++
    bitset<10> bit_1("1111");
    
    cout << (bit_1 <<= 2) << endl;
    // 0000111100
    ```

    * ### >>=

    ```c++
    bitset<10> bit_1("1111000");
    
    cout << (bit_1 >>= 2) << endl;
    // 0000011110
    ```

    * ### ~

    ```c++
    bitset<10> bit_1("1111000");
    
    cout << ~bit_1 << endl;
    // 1110000111
    ```

    * ### &, |, ^

    ```c++
    bitset<10> bset1(9); // 0000001001
    bitset<10> bset2(3); // 0000000011
    
    cout << (bset1 & bset2) << endl; // 0000000001 
    cout << (bset1 | bset2) << endl; // 0000001011 
    cout << (bset1 ^ bset2) << endl; // 0000001010 
    ```