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

        //dp[i][j]表示, 从下标为[0 - i]的物品中任意取, 放进容量为j的背包, 价值总和最大是多少
        int row = nums.size();
        int col = target + 1;
        vector< vector<int> > dp(row, vector<int>(col, 0));

        //dp数组初始化
        for (int j = 1; j < col; j++) {
            if (nums[0] <= j) {
                dp[0][j] = nums[0];
            }
        }

        //01背包
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (j < nums[i]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
                }
            }
        }

        if (target == dp[row - 1][target]) {
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
