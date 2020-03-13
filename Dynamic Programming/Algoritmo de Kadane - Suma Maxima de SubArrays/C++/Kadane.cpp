#include <bits/stdc++.h>

using namespace std;

class Kadane {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        vector<int> dp(nums.size(), 0);
        
        dp[0] = nums[0];
        int sum = dp[0];
        
        for(int i = 1; i < nums.size(); ++i) {
            dp[i] = max(dp[i-1], 0) + nums[i];
            sum = max(sum, max(dp[i], nums[i]));
        }
        
        return sum;
    }
};

int main() {
    Kadane kadane;

    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout<<kadane.maxSubArray(nums)<<endl;
    // Out:
    // 6

    return EXIT_SUCCESS;
}