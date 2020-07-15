# Distancias 2D - Geometria Computacional en C++

## Contenido

* [Contenido](#contenido)
* [Ilustración](#ilustración)
* [Distancias](#distancias)
    * [Euclidean Distance](#euclidean-distance)
    * [Manhattan Distance](#manhattan-distance)
    * [Chebyshev Distance](#chebyshev-distance)

## Ilustración

![Euclidean vs Manhattan vs Chebyshev Distance](https://iq.opengenus.org/content/images/2018/12/distance.jpg)
_Tomado de:_ [IQ Opengenus](https://iq.opengenus.org/euclidean-vs-manhattan-vs-chebyshev-distance/)

## Distancias

* ### Euclidean Distance

```c++
TP norm(Point p) { return p.x*p.x + p.y*p.y; }
ld abs(Point p)  { return sqrt(norm(p)); }
```

* ### Manhattan Distance

```c++
ll manh_distance(Point p) { return abs(p.x) + abs(p.y);}
ll manh_distance(Point p1, Point p2) { return abs(p1.x-p2.x) + abs(p1.y-p2.y);}
```

* ### Chebyshev Distance

```c++
ll ch_distance(Point p) { return max(abs(p.x), abs(p.y));}
ll ch_distance(Point p1, Point p2) { return max(abs(p1.x-p2.x), abs(p1.y-p2.y));}
```
