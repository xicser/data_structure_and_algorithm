#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        //和是个奇数
        if (sum % 2 != 0) {
            return false;
        }

        int bagSize = sum / 2;

        //01背包滚动数组
        vector<int> dp(bagSize + 1, 0);

        //开始01背包
        for (int i = 0; i < nums.size(); i++) {
            for (int j = bagSize; j >= nums[i]; j--) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }

        //尽最大可能装, 刚好装满
        if (dp[bagSize] == bagSize) {
            return true;
        }

        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {1, 5, 11, 5};
    vector<int> nums2 = {1, 2, 3, 5};

    cout << sol.canPartition(nums1) << endl;
    cout << sol.canPartition(nums2) << endl;

    return 0;
}
