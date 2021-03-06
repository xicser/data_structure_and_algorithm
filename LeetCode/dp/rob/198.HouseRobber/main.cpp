#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {

        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }

		// dp[i]: 考虑下标i(包括i)以内的房屋, 最多可以偷窃的金额为dp[i]
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (unsigned int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }

        return dp[nums.size() - 1];
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {1,2,3,1};
    vector<int> nums2 = {2,7,9,3,1};

    cout << sol.rob(nums1) << endl;
    cout << sol.rob(nums2) << endl;

    return 0;
}
