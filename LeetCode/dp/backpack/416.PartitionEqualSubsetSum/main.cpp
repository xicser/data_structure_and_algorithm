#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int target = 0;
        for (unsigned int i = 0 ; i < nums.size(); i++) {
            target += nums[i];
        }
        if (target % 2 != 0) {
            return false;
        }
        target /= 2;

        // 转换成背包问题: 装到target容量的背包中, 恰好装满
        vector<int> dp(target + 1, 0);

        for (unsigned int i = 0; i < nums.size(); i++) {
            for (int j = target; j >= nums[i]; j--) {
                dp[j] = max(dp[j], dp[ j - nums[i] ] + nums[i]);
            }
        }

        if (target == dp[target]) {
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
