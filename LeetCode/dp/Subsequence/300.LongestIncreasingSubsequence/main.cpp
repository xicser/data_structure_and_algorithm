#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) {
            return 1;
        }

        int res = 0;
        vector<int> dp(len, 1); //考虑前i个元素, 以nums[i]结尾的最长上升子序列的长度为dp[i]

        for (int i = 1; i < len; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            res = max(res, dp[i]);
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {10,9,2,5,3,7,101,18};
    vector<int> nums2 = {0,1,0,3,2,3};
    vector<int> nums3 = {7,7,7,7,7,7,7};
    vector<int> nums4 = {4, 10, 4, 3, 8, 9};
                       //0   1  2  3  4  5
    cout << sol.lengthOfLIS(nums1) << endl;
    cout << sol.lengthOfLIS(nums2) << endl;
    cout << sol.lengthOfLIS(nums3) << endl;
    cout << sol.lengthOfLIS(nums4) << endl;

    return 0;
}
