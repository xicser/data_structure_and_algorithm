#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        //dp[i][0]: nums[0] -> nums[i] 范围内, 连续子数组最小乘积
        //dp[i][1]: nums[0] -> nums[i] 范围内, 连续子数组最大乘积
        vector< vector<int> >dp (nums.size(), vector<int>(2, 0));
        dp[0][0] = nums[0];
        dp[0][1] = nums[0];

        int maxVal = nums[0];
        for (unsigned int i = 1; i < nums.size(); i++) {
            dp[i][0] = min(dp[i - 1][0] * nums[i], min(dp[i - 1][1] * nums[i], nums[i]) );
            dp[i][1] = max(dp[i - 1][0] * nums[i], max(dp[i - 1][1] * nums[i], nums[i]) );

            maxVal = max(maxVal, dp[i][1]);
        }

        return maxVal;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-2};

    cout << sol.maxProduct(nums) << endl;

    return 0;
}
