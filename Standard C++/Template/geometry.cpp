#include <bits/stdc++.h>
using namespace std;
#define ld long double
//---------------------------------------------------


#define PI   3.141592653589793238462643383279502884L // (2*acos(0.0))
#define eps  1e-9

typedef ld TP;
struct Point {
    TP x;
    TP y;
    
    Point operator + (Point p) { return {x+p.x, y+p.y};}
    Point operator - (Point p) { return {x-p.x, y-p.y};}
    Point operator * (Point p) { return {x*p.x-y*p.y, x*p.y+y*p.x};}
    Point operator * (TP p) { return {x*p, y*p};}
    Point operator / (TP p) { return {x/p, y/p};}
    bool operator == (Point p) { return x==p.x && y == p.y;}
    bool operator != (Point p) { return x!=p.x && y != p.y;}
    bool operator < (Point p) const { return y<p.y || (y==p.y && x<p.x);}
    bool operator > (Point p) const { return y>p.y || (y==p.y && x>p.x);}
};

// Already in Complex
TP norm(Point p) { return p.x*p.x + p.y*p.y; }
ld abs(Point p)  { return sqrt(norm(p)); }
ld arg(Point p)  { return atan2(p.y, p.x); }


// Aditional Functions

bool cmp(ld x, ld y) {
    return abs(x - y) < eps;
}

string to_string(Point p) {
    return "(" + to_string(p.x) + ", " + to_string(p.y) + ")";
}