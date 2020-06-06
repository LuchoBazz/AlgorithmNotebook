# Vectores 2D - Geometria Computacional en C++

## Contenido

* [Contenido](#contenido)
* [Ilustración](#ilustración)
* [Operaciones Fundamentales](#operaciones-fundamentales)
    * [Suma de Vectores (+)](#suma-de-vectores-)
    * [Resta de Vectores (-)](#resta-de-vectores--)
    * [Multiplicación de Vectores (*)](#multiplicación-de-vectores-)
    * [Multiplicación por escalar de Vectores (*)](#multiplicación-por-escalar-de-vectores-)
    * [División por escalar de Vectores (/)](#división-por-escalar-de-vectores-)
    ---
    * [Norma](#norma)
    * [Valor Absoluto](#valor-absoluto)
    * [Argumento](#argumento)
    * [Producto Punto](#producto-punto)
    * [Producto Cruz](#producto-cruz)
    * [Orientación](#orientación)

* [Time Complexity](#time-complexity)

## Ilustración

## Operaciones Fundamentales

* ### Suma de Vectores (+)
```c++
Point operator + (Point p) { return {x+p.x, y+p.y};}
```

* ### Resta de Vectores (-)
```c++
Point operator - (Point p) { return {x-p.x, y-p.y};}
```


* ### Multiplicación de Vectores (*)
```c++
Point operator * (Point p) { return {x*p.x-y*p.y, x*p.y+y*p.x};}
```

* ### Multiplicación por escalar de Vectores (*)
```c++
Point operator * (TP p) { return {x*p, y*p};}
```

* ### División por escalar de Vectores (/)
```c++
Point operator / (TP p) { return {x/p, y/p};} // only for floating point
```

----

* ### Norma
```c++
TP norm(Point p) { return p.x*p.x + p.y*p.y; }
```

* ### Valor Absoluto
```c++
ld abs(Point p)  { return sqrt(norm(p)); }
```

* ### Argumento
```c++
ld arg(Point p)  { return atan2(p.y, p.x); }
```

* ### Producto Punto
```c++
TP dot(Point a, Point b) { return a.x*b.x + a.y*b.y; }
```

* ### Producto Cruz
```c++
TP cross(Point a, Point b) { return a.x*b.y - a.y*b.x; }
```

* ### Orientación
```c++
TP orient(Point a, Point b, Point c) { return cross(b-a,c-a); }
```
