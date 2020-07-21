# Template C++ for Programming Contest

### Contenido
* [Codeforces](#codeforces)
    * [Codigo Fuente](#codigo-fuente)

### Codeforces

* ### Codigo Fuente

```c++
// Made by Luis Miguel Baez
// es.luismiguelbaez@gmail.com

#include <bits/stdc++.h>
 
using namespace std;

#define endl '\n'
#define precise(n,k) fixed << setprecision(k) << n
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define uint  unsigned int
#define ll    long long
#define ull   unsigned long long
#define ld    long double

#define pii   pair<int, int>
#define piii  pair<int, pair<int, int>>
#define pll   pair<ll, ll>

#define X  first
#define Y  second

#define debug(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

string to_string(string s) {
    return '"' + s + '"';
}

string to_string(bool b) {
    return (b ? "true" : "false");
}
 
template <typename A, typename B>
string to_string(const pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

// add templates here

template <typename T>
string to_string(const vector<T> &v) {
    bool first = true;
    string res = "{";
    for (const T &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string((T)x);
    }
    res += "}";
    return res;
}

template<class T>
void println(const T &data) {
#ifndef ONLINE_JUDGE
    cout << to_string((T)data) << endl;
#endif
}

const int MOD = int(1e9+7);
const int oo  = int(1e9+20);
const ll lloo  = (ll)(1e18)+40;
    
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // your code goes here

    return 0;
}
```

**Compiler:**

```bash
g++ -std=c++17 -Wall -DLOCAL=1 -o sol.o sol.cpp && ./sol.o
```
