#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int result = nums[0];

        //dp[i]: [0] -> [i]范围内, 以[i]结尾的连续子数组的最大和
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            dp[i] = max(dp[i - 1] + nums[i],        //加上nums[i]之后的值, 可能变小, 也可能变大
                        nums[i]);

            result = max(result, dp[i]);
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    cout << sol.maxSubArray(nums) << endl;


    return 0;
}
