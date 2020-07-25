#include <bits/stdc++.h>

using namespace std;

class Range {
public:

    vector<int> dp;

    Range(vector<int>& nums) {
        if(nums.size() == 0) return;
        
        dp.resize(nums.size());
        
        dp[0] = nums[0];
        
        for(int i = 1; i < nums.size(); ++i) {
            dp[i] = dp[i - 1] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        if(i==0) return dp[j];
        
        return dp[j] - dp[i-1];
    }
};

int main() {
    vector<int> arr{1, 3, -2, 6, 8};

    // Preprocessing O(N)
    Range range(arr);

    // Queries O(1)
    cout<<range.sumRange(1, 3)<<endl;
    // Out: 7
}