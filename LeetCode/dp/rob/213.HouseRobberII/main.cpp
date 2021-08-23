#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {

        int len = nums.size();
        if (len == 1) {
            return nums[0];
        }
        if (len == 2) {
            return max(nums[0], nums[1]);
        }
        if (len == 3) {
            return max(max(nums[0], nums[1]), nums[2]);
        }

        //偷最后一家
        int value1 = nums[len - 1] + robCommon(nums.data() + 1, len - 3);

        //不偷最后一家
        int value2 = robCommon(nums.data(), len - 1);

        return max(value1, value2);
    }

private:
    int robCommon(int *nums, int len) {

        if (len == 1) {
            return nums[0];
        }
        if (len == 2) {
            return max(nums[0], nums[1]);
        }

        vector<int> dp(len, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i <= len - 1; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[len - 1];
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {2,3,2};
    vector<int> nums2 = {1,2,3,1};
    vector<int> nums3 = {0};

    cout << sol.rob(nums1) << endl;
    cout << sol.rob(nums2) << endl;
    cout << sol.rob(nums3) << endl;

    return 0;
}
