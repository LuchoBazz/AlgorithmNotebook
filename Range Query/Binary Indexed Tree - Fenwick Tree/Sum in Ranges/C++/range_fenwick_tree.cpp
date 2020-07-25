#include <bits/stdc++.h>

using namespace std;

class Fenwick {
    vector<int> tree;
    vector<int> data;
    int n;
    
    void update(int n, int index, int value) {
        index += 1;
        while(index <= n) {
            tree[index] += value;
            index += index & (-index);
        }
    }
public:
    
    Fenwick(vector<int> data) : data(data) {
        n = data.size();
        tree.resize(n+1, 0);
        
        for(int i = 0; i < n; ++i) {
            update(n, i, data[i]);
        }
    }
    
    void update(int index, int value) {
        int val = data[index];
        
        int diff = abs(val - value);
        
        if(value > val) {
            diff = abs(diff);
        } else {
            diff = -abs(diff);
        }
        
        data[index] = value;
        update(n, index, diff);
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


class RangeQuery {
    Fenwick fenwick;
public:
    RangeQuery(vector<int>& nums) : fenwick(nums) {}
    
    void update(int i, int val) {
        fenwick.update(i, val);
    }
    
    int sumRange(int i, int j) {
        return fenwick.get(j) - fenwick.get(i-1);
    }
};


int main() {

    vector<int> values {1, 3, 5};

    RangeQuery rquery(values);

    cout << rquery.sumRange(0, 2) << endl; // 9

    rquery.update(1, 2); // {1, 2, 5}

    cout << rquery.sumRange(0, 2) << endl; // 8


    return 0;
}