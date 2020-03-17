# Template C++ for Programming Contest

### Contenido
* [Codeforces](#codeforces)
    * [Codigo Fuente](#codigo-fuente)

### Codeforces

* ### Codigo Fuente
```c++
#include <bits/stdc++.h>
 
using namespace std;

#define precise(n,k) fixed<<setprecision(k)<<n

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #else
        #define endl '\n'
    #endif

    // your code goes here
 
   return EXIT_SUCCESS;
}
```

**Compiler:**

```bash
g++ -std=c++17 -Wall -DLOCAL=1 -o index.o index.cpp && ./index.o
```
