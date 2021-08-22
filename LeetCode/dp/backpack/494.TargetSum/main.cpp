#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (unsigned int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if ((target + sum) % 2 != 0 || target > sum) {
            return 0;
        }

        int bagSize = (target + sum) / 2;

        //定义dp数组
        vector<int> dp(bagSize + 1, 0);

        //dp数组初始化
        dp[0] = 1;

        //01背包
        for (int i = 0; i < nums.size(); i++) {
            for (int j = bagSize; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }

        return dp[bagSize];
    }
};

int main()
{
    vector<int> nums1 = {1, 1,1,1,1};
    vector<int> nums2 = {0,0, 0,0,0,0,0,0,1};

    Solution sol;
    cout << sol.findTargetSumWays(nums1, 3) << endl;
    cout << sol.findTargetSumWays(nums2, 1) << endl;


    return 0;
}
