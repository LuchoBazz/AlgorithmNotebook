// Distances

// Euclidean Distance
ld abs(Point p)  { return sqrt(norm(p)); }

// Manhattan Distance
ll manhDistance(Point p) { return abs(p.x) + abs(p.y);}
ll manhDistance(Point p1, Point p2) { return abs(p1.x-p2.x) + abs(p1.y-p2.y);}

// Chebyshev Distance
ll chDistance(Point p) { return max(abs(p.x), abs(p.y));}
ll chDistance(Point p1, Point p2) { return max(abs(p1.x-p2.x), abs(p1.y-p2.y));}
