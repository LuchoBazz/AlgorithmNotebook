# Big O Notation

## Contenido

* [Contenido](#contenido)
* [Ilustración ](#ilustración)
* [Cálculos para n Elementos](#cálculos-para-n-elementos)
* [Complejidad de las operaciones de estructuras de datos](#complejidad-de-las-operaciones-de-estructuras-de-datos)
* [Complejidad de algoritmos de ordenamiento de arreglos](#complejidad-de-algoritmos-de-ordenamiento-de-arreglos)

---

## Ilustración 
Orden de crecimiento de los algoritmos especificados en la notación O Big.

![Gráficas de Notación O grande ](https://i.ibb.co/dphmpgg/big-o-graph.png)

Fuente: [Big O Notation](http://bigocheatsheet.com/).

## Cálculos para n Elementos

A continuación se muestra la lista de algunas de las notaciones de Big O más utilizadas y sus comparaciones de rendimiento 
frente a diferentes tamaños de los datos de entrada.

| Notación O grande | Cálculos para 10 elementos | Cálculos para 100 elementos | Cálculos para 1000 elementos |
| ----------------- | -------------------------- | --------------------------- | ---------------------------- |
| **O(1)**          | 1                          | 1                           | 1                            |
| **O(log N)**      | 3                          | 6                           | 9                            |
| **O(N)**          | 10                         | 100                         | 1000                         |
| **O(N log N)**    | 30                         | 600                         | 9000                         |
| **O(N^2)**        | 100                        | 10000                       | 1000000                      |
| **O(2^N)**        | 1024                       | 1.26e+29                    | 1.07e+301                    |
| **O(N!)**         | 3628800                    | 9.3e+157                    | 4.02e+2567                   |

## Complejidad de las operaciones de estructuras de datos

| Estructura de Datos            | Accesso | Busqueda | Inserción | Borrado | Comentarios                                                     |
| ------------------------------ | :-----: | :------: | :-------: | :-----: | :-------------------------------------------------------------- |
| **Colección**                  |    1    |    n     |     n     |    n    |                                                                 |
| **Stack**                      |    n    |    n     |     1     |    1    |                                                                 |
| **Cola**                       |    n    |    n     |     1     |    1    |                                                                 |
| **Lista enlazada**             |    n    |    n     |     1     |    1    |                                                                 |
| **Tabla hash**                 |    -    |    n     |     n     |    n    | En caso de función hash perfecta los costos serían O(1)         |
| **Búsqueda por Árbol binario** |    n    |    n     |     n     |    n    | En el caso de un árbol equilibrado, los costos serían O(log(n)) |
| **Árbol B**                    | log(n)  |  log(n)  |  log(n)   | log(n)  |                                                                 |
| **Árbol Rojo-Negro**           | log(n)  |  log(n)  |  log(n)   | log(n)  |                                                                 |
| **Árbol AVL**                  | log(n)  |  log(n)  |  log(n)   | log(n)  |                                                                 |
| **Filtro de Bloom**            |    -    |    1     |     1     |    -    | Falsos positivos son posibles durante la búsqueda               |

## Complejidad de algoritmos de ordenamiento de arreglos

| Nombre                           | Mejor         | Promedio                | Pero                        | Memorya | Estable | Comentarios                                                   |
| -------------------------------- | :-----------: | :---------------------: | :-------------------------: | :-----: | :-----: | :------------------------------------------------------------ |
| **Ordenamiento de burbuja**      |       n       |      n<sup>2</sup>      |        n<sup>2</sup>        |   1     |  Si     |                                                               |
| **Ordenamiento por inserción**   |       n       |      n<sup>2</sup>      |        n<sup>2</sup>        |   1     |  Si     |                                                               |
| **Ordenamiento por selección**   | n<sup>2</sup> |      n<sup>2</sup>      |        n<sup>2</sup>        |   1     |   No    |                                                               |
| **Ordenamiento por Heap**        | n&nbsp;log(n) |      n&nbsp;log(n)      |        n&nbsp;log(n)        |   1     |   No    |                                                               |
| **Ordenamiento por mezcla**      | n&nbsp;log(n) |      n&nbsp;log(n)      |        n&nbsp;log(n)        |   n     |  Si     |                                                               |
| **Quicksort**                    | n&nbsp;log(n) |      n&nbsp;log(n)      |        n<sup>2</sup>        | log(n)  |   No    | Quicksort utiliza O(log(n)) de espacio en el stack         |
| **Shellsort**                    | n&nbsp;log(n) | depende de la secuencia de huecos | n&nbsp;(log(n))<sup>2</sup> |   1   |   No   |                                                               |
| **Ordenamiento por cuentas**     |     n + r     |          n + r          |            n + r            | n + r   |  Si     | r - mayor número en el arreglo                                |
| **Ordenamiento Radix**           |    n \* k     |         n \* k          |           n \* k            | n + k   |  Si     | k - largo de la llave más larga        