#include <bits/stdc++.h>
using namespace std;
#define ll long long

// --------------------------------------------------------------------

typedef ll T;
struct Point {
    int x;
    int y;

    Point operator-(Point a) {return {x-a.x, y-a.y};}
    bool operator==(Point a) {return x==a.x&&y==a.y;}
    bool operator<(Point a) {
        return x<a.x || (x==a.x && y < a.x);
    }
};

T cross(Point a, Point b) {return a.x*b.y - a.y*b.x;}
T orient(Point a, Point b, Point c) {return cross(b-a, c-a);}

vector<Point> convex_hull(vector<Point> points) {
    int n = points.size();
    vector<Point> hull;

    // Sorting Points
    sort(points.begin(), points.end());

    // it=1: Upper Hull
    // it=2: Lower Hull
    for(int it = 0; it < 2; ++it) {
        int sz = hull.size();
        for(int i = 0; i < n; ++i) {
            while(hull.size()>=sz+2 && orient(hull[hull.size()-2], hull.back(), points[i]) >= 0) {
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
