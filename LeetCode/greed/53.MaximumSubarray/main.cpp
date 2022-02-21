#include <iostream>
#include <vector>

using namespace std;

//-2, 1, -3, 4, -1, 2, 1, -5, 4
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        if (nums.size() == 1) {
            return nums[0];
        }

        // dp[i]表示[0...i]之间, 最大子序和
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int result = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);

            result = max(result, dp[i]);
        }

        return result;
    }
};

int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution sol;
    cout << sol.maxSubArray(nums) << endl;

    return 0;
}
