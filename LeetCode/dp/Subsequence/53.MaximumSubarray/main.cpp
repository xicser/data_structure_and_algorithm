#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int result = nums[0];

        //dp[i]: [0] -> [i]��Χ��, ��[i]��β�����������������
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            dp[i] = max(dp[i - 1] + nums[i],        //����nums[i]֮���ֵ, ���ܱ�С, Ҳ���ܱ��
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
