# Template C++ for Programming Contest

### Contenido
* [Codeforces](#codeforces)
    * [Codigo Fuente](#codigo-fuente)

### Codeforces

* ### Codigo Fuente

```c++
// Made by Luis Miguel Baez
// lmbaeza@unal.edu.co

#include <bits/stdc++.h>
 
using namespace std;

#define debug(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

template<class T>
void println(const vector<T> &data) {
    int n = data.size();
    
    cout << "values: [";
    for(int i = 0; i < data.size(); ++i) {
        if(i != (n-1)) {
            cout << data[i] << ", ";
        } else {
            cout << data[i];
        }
    }
    cout << "]" <<endl;
}
 
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

#define F  first
#define S  second
#define PB push_back
#define MP make_pair

#define PI   (2*acos(0.0))
#define gcd  __gcd
#define eps  1e-9

const int MOD = 1e9+7;
const int oo  = int(1e9 + 20);
const int noo = -oo;
const ll inf  = 2e18+11;
    
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
