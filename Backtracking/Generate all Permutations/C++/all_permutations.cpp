#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> solutions;
vector<bool> chosen;
vector<int> permutation;

void backtracking(vector<int> &nums) {
    if(permutation.size() == nums.size()) {
        solutions.push_back(permutation);
    } else {
        for(int i = 0; i < nums.size(); ++i)  {
            if(chosen[i]) continue;
            permutation.push_back(nums[i]);
            chosen[i] = true;
            backtracking(nums);
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

int main() {

    vector<int> nums {1, 2, 3};

    int n = nums.size();
    chosen.resize(n, false);
    backtracking(nums);
    
    // solutions:
    // [
    //     [1,2,3],
    //     [1,3,2],
    //     [2,1,3],
    //     [2,3,1],
    //     [3,1,2],
    //     [3,2,1]
    // ]

    for(vector<int> &permutation: solutions) {
        for(int value: permutation) {
            cout << value << " ";
        }
        cout << endl;
    }

    // Out:
    // 1 2 3 
    // 1 3 2 
    // 2 1 3 
    // 2 3 1 
    // 3 1 2 
    // 3 2 1 

    return 0;
}