#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {

        int result = 1;
        //dp[i]��ʾ����nums[0] -> [i]�����Χ��, ��i��β��, ��������������鳤��
        vector<int> dp(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            }
            result = max(result, dp[i]);
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {1,3,5,4,7};
    vector<int> nums2 = {2,2,2,2,2};
    vector<int> nums3 = {1,3,5,7};

    cout << sol.findLengthOfLCIS(nums1) << endl;
    cout << sol.findLengthOfLCIS(nums2) << endl;
    cout << sol.findLengthOfLCIS(nums3) << endl;

    return 0;
}
