# :pushpin: Algorithm Notebook

Este repositorio contiene una recopilación de algorimtos y estructuras de datos populares codificados en Java y C++.

Cada algoritmo y estructura de datos tiene su propio _README_ con explicaciones relacionadas y enlaces de referencias.

*☝ Nótese que este proyecto está pensado con fines de aprendizaje,
y **no** para ser usado en producción.*

## Algoritmos

Un algoritmo es una especificación inequívoca de cómo resolver una clase de problemas. Es un conjunto de reglas que definen con precisión una secuencia de operaciones.

`P` - Principiante, `I` - Intermedio, `A` - Avanzado

* **Strings**
    * `P` [Hamming Distance](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/String/Hamming%20Distance) - número de posiciones en las que los símbolos son diferentes
    * `I` [Longest Common Subsequence](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/String/Longest%20Common%20Subsequence)
    * `I` [Longest Common SubString](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/String/Longest%20Common%20SubString)
    * `I` [Trie (Prefix Tree)](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/String/Trie)
    * `I` [Knuth–Morris–Pratt Algorithm (KMP Algorithm)](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/String/KMP) - búsqueda de subcadenas (coincidencia de patrones) 
    * `A` [Levenshtein Distance](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/String/Levenshtein%20Distance) distancia mínima de edición entre dos strings

* **Busquedas**
    * `P` [Búsqueda Binaria](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/Binary%20Search) -  búsqueda en una lista ordenada

* **Matemáticas**
    * `P` [Greatest Common Divisor - Euclides](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/Number%20Theory/GCD%20%26%20LCM) - calcular el máximo común divisor (MCD)
    * `P` [Least Common Multiple](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/Number%20Theory/GCD%20%26%20LCM) - calcular el minimo común multiplo (MCM)
    * `P` [Algoritmo de Euclides Extendido](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/Number%20Theory/GCD%20%26%20LCM)
    * `P` [Criba de Eratostenes - Sieve of Eratosthenes](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/Number%20Theory/Prime%20Numbers) - encontrar todos los números primos hasta un límite dado
    * `P` [Factores Primos - Prime Factors](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/Number%20Theory/Prime%20Numbers) - encontrar todos los factores primos y sus multiplicidades de un numero
    * `P` [Verificar si es Numero Primo](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/Number%20Theory/Prime%20Numbers) - verificar si un numero es primo de forma eficiente

* **Arboles**
    * `I` [Lowest Common Ancestor of a Binary Search Tree](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/Tree/Lowest%20Common%20Ancestor%20-%20BST) - encontrar el ancestro común más bajo

* **Programación Dinamica**
    * `P` [Algoritmo de Kadane - Suma Maxima de SubArrays](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/Dynamic%20Programming/Algoritmo%20de%20Kadane%20-%20Suma%20Maxima%20de%20SubArrays) - Encontrar un sub array cuya suma sea maxima
    * `P` [Range Sum Query - Immutable](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/Dynamic%20Programming/Range%20Sum%20Query%20-%20Immutable) - Realizar sumas entre rangos para un array immutable

    * `A` [Aliens Trick](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/Dynamic%20Programming/Aliens%20Trick) - Dado un array y un `k`, encontrar k sub arrays cuya suma sea maxima

* **Graphs**
    * `P` [Depth-first search (DFS)](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/Graph/dfs)

    * `I` [Breadth-first search (DFS)](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/Graph/bfs)

    * `I` [Dijkstra's Algorithm](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/Graph/Dijkstra) - encontrar los caminos más cortos a todos los vértices del grafo desde un solo vértice

    * `I` [Save Path - Dijkstra](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/Graph/Save%20Path%20-%20Dijkstra) - encontrar los caminos más cortos y la ruta a todos los vértices del grafo desde un solo vértice

    * `I` [Disjoint Set Union](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/Graph/Disjoint%20Set%20Union) - Verificar conectividad de dos nodos de un grafo óptimamente

    * `I` [Algoritmo de Floyd-Warshall](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/Graph/Algoritmo%20de%20Floyd-Warshall) encontrar los caminos más cortos entre todos los pares de vértices

    * `I` [Algoritmo de Kruskal - Minimum Spanning Tree](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/Graph/Kruskal%20-%20Minimum%20Spanning%20Tree) encontrar el árbol de cubrimiento mínimo (MST) para un grafo no dirigido ponderado

    * `I` [Topological Sort](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/Graph/Topological%20Sort) Metodo para Ordenar los vertices de un Grafo Dirigido

    * `I` [Bridges](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/Graph/Bridges) Algoritmo para encontrar los puentes de un Grafo no Dirigido

    * `I` [Kosaraju's Algorithm - SCC](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/Graph/Strongly%20Connected%20Components/Kosaraju's%20Algorithm) Algoritmo para encontrar los componentes fuertemente conexos en un Grafo Dirigido

    * `I` [Tarjan's Algorithm - SCC](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/Graph/Strongly%20Connected%20Components/Tarjan's%20Algorithm) Algoritmo para encontrar los componentes fuertemente conexos en un Grafo Dirigido

* **Geometry**
    * `P` [Operaciones entre Vectores 2D (+-*/)](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/Geometry/Vector%202D)

    * `P` [Producto Punto de Vectores 2D](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/Geometry/Vector%202D)

    * `P` [Producto Cruz de Vectores 2D](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/Geometry/Vector%202D)

    * `P` [Orientación de Vectores 2D](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/Geometry/Vector%202D)

    * `P` [Distancia Euclideana 2D](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/Geometry/Vector%202D)

    * `P` [Distancia Manhattan 2D](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/Geometry/Vector%202D)

    * `P` [Distancia Chebyshev 2D](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/Geometry/Vector%202D)

    * `I` [Area de un Poligono](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/Geometry/Vector%202D)

    * `I` [Perimetro de un Poligono](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/Geometry/Vector%202D)
    
    * `A` [Convex Hull - Monotone Chain](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/Geometry/Convex%20Hull/Monotone%20Chain)


## Estructuras de Datos

Una estructura de datos es una forma particular de organizar y almacenar datos en un ordenador para que puedan accederse y modificarse de forma eficiente. Más concretamente, una estructura de datos es un conjunto de valores de datos, las relaciones entre ellos y las funciones u operaciones que se pueden aplicar a los datos.

`P` - Principiante, `I` - Intermedio, `A` - Avanzado

* **Grafos**
    * `I` [Algoritmo de Floyd-Warshall](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/Graph/Algoritmo%20de%20Floyd-Warshall) - encontrar los caminos más cortos entre todos los pares de vértices
    * `I` [Disjoint Set Union](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/Graph/Disjoint%20Set%20Union)
    * `I` [Kruskal - Minimum Spanning Tree](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/Graph/Kruskal%20-%20Minimum%20Spanning%20Tree) - encontrar el árbol de cubrimiento mínimo (MST) para un grafo no dirigido ponderado

* **Arboles**
    * `I` [Binary Search Tree](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/Tree/%20Binary%20Search%20Tree)
    * `I` [N-ary Tree](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/Tree/%20N-ary%20Tree)
    * `I` [Trie (Prefix Tree)](https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/String/Trie)

## :books: Libros

* :blue_book: [Competitive Programmer’s Handbook by Antti Laaksonen](https://cses.fi/book/book.pdf)
* :blue_book: [Handbook of geometry for competitive programmers by Victor Lecomte](https://vlecomte.github.io/cp-geo.pdf)

## :bookmark_tabs: Paginas de Consulta

* :scroll: [Geeks For Geeks](https://www.geeksforgeeks.org)

* :scroll: [Codeforces](https://codeforces.com/blog/entry/57282)

* :scroll: [CP Algorithms](https://cp-algorithms.com/)

* :scroll: [A Bit of CS](https://abitofcs.blogspot.com/)

* :scroll: [Techie Delight](https://www.techiedelight.com/)

* :scroll: [Emre.me](https://emre.me/)

* :scroll: [Iq OpenGenus](https://iq.opengenus.org/)