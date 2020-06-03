#define PI   3.141592653589793238462643383279502884L // (2*acos(0.0))
#define eps  1e-9
#define gcd  __gcd

template<typename T>
T lcm(T x, T y ) {return x*(y/gcd(x,y));}