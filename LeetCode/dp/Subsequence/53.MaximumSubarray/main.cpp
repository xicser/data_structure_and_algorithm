#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int res = 0;
        int len = nums.size();
        vector<int> dp(len, 0);
        dp[0] = nums[0];
        res = dp[0];

        for (int i = 1; i < len; i++) {
            int value = dp[i - 1] + nums[i];
            dp[i] = max(value, nums[i]);
            res = max(res, dp[i]);
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    cout << sol.maxSubArray(nums) << endl;


    return 0;
}
