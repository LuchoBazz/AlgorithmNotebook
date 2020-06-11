# Vectores 2D - Geometria Computacional en C++

## Contenido

* [Contenido](#contenido)
* [Ilustración](#ilustración)
* [Convex Hull](#convex-hull)
* [Time Complexity](#time-complexity)

## Ilustración

![]()

<img alt="Convex Hull Monotone Chain (Andrew's algorithm) I" src="https://upload.wikimedia.org/wikipedia/commons/9/9a/Animation_depicting_the_Monotone_algorithm.gif" width="300">


_Tomado de:_ [wikibooks](https://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain)

![Convex Hull Monotone Chain (Andrew's algorithm) II](https://upload.wikimedia.org/wikipedia/commons/d/d5/UpperAndLowerConvexHulls.png)

_Tomado de:_ [wikibooks](https://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain)

## Convex Hull

```c++
vector<Point> convex_hull(vector<Point> points) {
    int n = points.size();
    if(n <= 1) return points;
    vector<Point> hull;

    // Sorting Points
    sort(points.begin(), points.end());

    // it=0: Upper Hull
    // it=1: Lower Hull
    for(int it = 0; it < 2; ++it) {
        int sz = hull.size();
        for(int i = 0; i < n; ++i) {
            // if colineal are needed, use < and remove repeated points
            while(hull.size()>=sz+2 && orient(hull[hull.size()-2], hull.back(), points[i]) <= 0) {
                hull.pop_back();
            }
            hull.push_back(points[i]);
        }
        // Eliminating repeating points, start and end point
        hull.pop_back();
        reverse(points.begin(), points.end());
    }

    // removing duplicate points
    if(hull.size()==2 && hull[0]==hull[1]) hull.pop_back();

    return hull;
}
```

### Time Complexity

`n*log2(n)`

`n: Es el numero de puntos en el poligono`