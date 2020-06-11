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
    * [Area de un Poligono](#area-de-un-poligono)
    * [Perimetro de un Poligono](#perimetro-de-un-poligono)

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
Distancia Euclideana

<img alt="Distancia Euclideana" src="https://i.ibb.co/xYhjL3Q/Euclidean-s-Distance.jpg" width="250">

_Tomado de:_ [IQ Opengenus](https://iq.opengenus.org/euclidean-vs-manhattan-vs-chebyshev-distance/)

* ### Argumento
```c++
ld arg(Point p)  { return atan2(p.y, p.x); }
```

* ### Producto Punto
```c++
TP dot(Point a, Point b) { return a.x*b.x + a.y*b.y; }
```

![Producto Punto](https://i.ibb.co/xLZPqDz/dot.png)

* ### Producto Cruz
```c++
TP cross(Point a, Point b) { return a.x*b.y - a.y*b.x; }
```

![Producto Cruz](https://i.ibb.co/StDcLPx/cross.png)

* ### Orientación
```c++
TP orient(Point a, Point b, Point c) { return cross(b-a,c-a); }
```

Teniendo los vectores `a=(x1, y1) y b=(x2, y2)` el producto cruz nos dice si b gira a la izquierda (valor positivo), no gira (cero) o gira a la derecha (valor negativo) cuando se coloca directamente después de a.

<img alt="Orientación" src="https://i.ibb.co/nLhSdCz/Orient.png" width="600">

* ### Area de un Poligono

```c++
ld area(vector<Point> points, bool sign = false) {
    int n = points.size();
    ld ans = 0.0;
    
    for(int i = 0; i < n; ++i) {
        ans += cross(points[i], points[(i + 1) % n]);
    }
    ans /= 2.0;
    
    // ans >= 0 (counter-clock wise): Sentido Antihorario
    // ans < 0  (clockwise): Agujas del Reloj
    
    return (!sign)? abs(ans):ans;
}
```


_Shoelace formula_
![Shoelace formula](https://wikimedia.org/api/rest_v1/media/math/render/svg/97b9489b2066a86e294d362aa9160f1a4484ccee)

* ### Perimetro de un Poligono

```c++
// Perimeter de un Poligono
ld perimeter(vector<Point> points) {
    int n = points.size();
    ld ans = 0.0;
    for(int i = 0; i < n; ++i) {
        ans += abs(points[i] - points[(i + 1) % n]);
    }
    return ans;
}
```