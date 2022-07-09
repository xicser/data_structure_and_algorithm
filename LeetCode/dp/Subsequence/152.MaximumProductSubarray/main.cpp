#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        if (nums.size() == 1) {
            return nums[0];
        }

        int result = INT_MIN;
        //dp[i][0]表示最小乘积
        //dp[i][1]表示最大乘积
        vector< vector<int> > dp(nums.size(), vector<int>(2, 0));
        dp[0][0] = nums[0];
        dp[0][1] = nums[0];
        result = max(max(dp[0][0], dp[0][1]), result);

        for (int i = 1; i < nums.size(); i++) {
            dp[i][0] = min(min(dp[i - 1][0] * nums[i], dp[i - 1][1] * nums[i]), nums[i]);
            dp[i][1] = max(max(dp[i - 1][0] * nums[i], dp[i - 1][1] * nums[i]), nums[i]);

            result = max(max(dp[i][0], dp[i][1]), result);
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2,3,-2,4};

    cout << sol.maxProduct(nums) << endl;

    return 0;
}
