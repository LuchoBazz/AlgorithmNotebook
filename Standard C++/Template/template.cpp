#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define precise(n,k) fixed << setprecision(k) << n
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
 
#define debug(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
 
void println(const vector<int> &data) {
    cout << "data<int>: [";
    for(int i = 0; i < data.size(); ++i) {
        cout << data[i] << ", "[i == data.size() - 1];
    }
    cout << "]" <<endl;
}
 
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned long double uld;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;

const int INF = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    // your code goes here
 
   return EXIT_SUCCESS;
}