#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
//---------------------------------------------------

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
ld abs(Point p)  { return sqrt(norm(p)); }
ld arg(Point p)  { return atan2(p.y, p.x); }

TP dot(Point a, Point b) { return a.x*b.x + a.y*b.y; }
TP cross(Point a, Point b) { return a.x*b.y - a.y*b.x; }
TP orient(Point a, Point b, Point c) { return cross(b-a,c-a); }


// Aditional Functions

int cmp(ld a, ld b) {
    return (a + eps < b ? -1 :(b + eps < a ? 1 : 0));
}

string to_string(Point p) {
    return "(" + to_string(p.x) + ", " + to_string(p.y) + ")";
}

ld area(vector<Point> points, bool sign = false) {
    int n = points.size();
    ld ans = 0.0;
    
    for(int i = 0; i < n; ++i) {
        ans += cross(points[i], points[(i + 1) % n]);
    }
    ans /= 2.0;
    
    return (sign)?ans: abs(ans);
}