#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        if (nums.size() == 1) {
            return nums[0];
        }

        int result = -1;

        //dp[i][0]��ʾ, 0��i֮��, ��i��β�����������С�˻�
        //dp[i][1]��ʾ, 0��i֮��, ��i��β������������˻�
        vector< vector<int> > dp(nums.size(), vector<int>(2, 0));
        dp[0][0] = nums[0];
        dp[0][1] = nums[0];
        result = max(result, dp[0][1]);
        for (int i = 1; i < nums.size(); i++) {

            dp[i][0] = min( dp[i - 1][0] * nums[i], min(dp[i - 1][1] * nums[i], nums[i]) );
            dp[i][1] = max( dp[i - 1][0] * nums[i], max(dp[i - 1][1] * nums[i], nums[i]) );

            result = max(result, dp[i][1]);
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2,-1,1,1};

    cout << sol.maxProduct(nums) << endl;

    return 0;
}
