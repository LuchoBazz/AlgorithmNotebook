#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
//---------------------------------------------------

// Template Geometry
#define PI   3.141592653589793238462643383279502884L // (2*acos(0.0))
#define eps  1e-9

typedef ll TP;
struct Point {
    TP x;
    TP y;
    
    Point operator + (Point p) { return {x+p.x, y+p.y};}
    Point operator - (Point p) { return {x-p.x, y-p.y};}
    Point operator * (Point p) { return {x*p.x-y*p.y, x*p.y+y*p.x};}
    Point operator * (TP p) { return {x*p, y*p};}
    Point operator / (TP p) { return {x/p, y/p};} // only for floating point
    bool operator == (Point &p) const { return x==p.x && y == p.y;}
    bool operator != (Point &p) const { return !(*this == p);}
    bool operator < (Point &p) const { return x < p.x || (x == p.x && y < p.y);}
    bool operator > (Point &p) const { return x > p.x || (x == p.x && y > p.y);}
    
    // bool operator < (const Point &p) const { return y<p.y || (y==p.y && x < p.x); }
    // bool operator > (const Point &p) const { return y>p.y || (y==p.y && x > p.x); }
};

// Already in Complex
TP norm(Point p) { return p.x*p.x + p.y*p.y; }
ld arg(Point p)  { return atan2(p.y, p.x); }
TP dot(Point a, Point b) { return a.x*b.x + a.y*b.y; }
TP cross(Point a, Point b) { return a.x*b.y - a.y*b.x; }
TP orient(Point a, Point b, Point c) { return cross(b-a,c-a); }

// Distances

// Euclidean Distance
ld abs(Point p)  { return sqrt(norm(p)); }

// Manhattan Distance
ll manhDistance(Point p) { return abs(p.x) + abs(p.y);}
ll manhDistance(Point p1, Point p2) { return abs(p1.x-p2.x) + abs(p1.y-p2.y);}

// Chebyshev Distance
ll chDistance(Point p) { return max(abs(p.x), abs(p.y));}
ll chDistance(Point p1, Point p2) { return max(abs(p1.x-p2.x), abs(p1.y-p2.y));}


// Aditional Functions

int cmp(ld a, ld b) {
    return (a + eps < b ? -1 :(b + eps < a ? 1 : 0));
}

string to_string(Point p) {
    return "(" + to_string(p.x) + ", " + to_string(p.y) + ")";
}