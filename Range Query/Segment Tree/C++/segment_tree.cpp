#include <bits/stdc++.h>

using namespace std;

const int oo  = int(1e9 + 20);

class SegmentTree {
    int NEUTRAL;
    int n;
    vector<int> tree;
    function <int(int, int)> func;
public:
    
    SegmentTree(vector<int> values, function <int(int, int)> f, int neutral) {
        func = static_cast<function <int(int, int)>> (f);
        NEUTRAL = neutral;
        
        n = values.size();
        tree.resize(n*2);
        // Build
        for (int i=0; i < n; i++){
            tree[n+i] = values[i];
        }
        for (int i = n - 1; i > 0; --i) {
            tree[i] = func(tree[i<<1], tree[i<<1 | 1]);
        }
    }
    
    void update(int index, int value) {
        tree[index+n] = value;
        index = index + n;
        for (int i = index; i > 1; i >>= 1){
            tree[i>>1] = func(tree[i], tree[i^1]);
        }
    }
    
    int query(int l, int r) {
        int ans = NEUTRAL;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) {
                ans = func(ans, tree[l++]);
            }
            if (r&1) {
                ans = func(ans, tree[--r]);
            }
        }
        return ans;
    }
};

int myMax(int x, int y) {
    return max(x, y);
}

int main() {

    SegmentTree st(val, myMax, -oo);

    return 0;
}