#include <bits/stdc++.h>

using namespace std;

class Fenwick {
    vector<int> tree;
    int n;
public:
    
    Fenwick(int n) : n(n) {
        tree.resize(n+1, 0);
    }

    Fenwick(vector<int> values) : n(values.size()) {
        tree.resize(n+1, 0);
        
        for(int i = 0; i < n; ++i) {
            sum(n, i, values[i]);
        }
    }
    
    void sum(int index, int value) {
        sum(n, index, value);
    }

    void sum(int n, int index, int value) {
        index += 1;
        while(index <= n) {
            tree[index] += value;
            index += index & (-index);
        }
    }
    
    int get(int index) {
        index += 1;
        int sum = 0;
        while(index > 0) {
            sum += tree[index];
            index -= index & (-index);
        }        
        return sum;
    }
};

int main() {
    vector<int> values {1, 3, 5};
    //                  0  1  2 

    Fenwick fenwick(values);

    cout << fenwick.get(2) << endl; // 9

    fenwick.sum(1, 2);

    cout << fenwick.get(2) << endl; // 11

    return 0;
}