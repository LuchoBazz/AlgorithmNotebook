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
#define piii  tuple<int, int, int>
#define pll   pair<ll, ll>
#define plll  tuple<ll, ll, ll>

#define F  first
#define S  second

// add template here

const int MOD = int(1e9+7);
const int oo  = int(1e9+20);
const ll lloo  = (ll)(1e18)+40;
    
auto main() -> int {
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
