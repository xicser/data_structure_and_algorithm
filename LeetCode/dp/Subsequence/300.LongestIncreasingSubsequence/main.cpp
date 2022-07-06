#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int> dp(nums.size(), 1);
        dp[0] = 1;

        int result = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            result = max(result, dp[i]);
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {10,9,2,5,3,7,101,18};
    vector<int> nums2 = {0,1,0,3,2,3};
    vector<int> nums3 = {7,7,7,7,7,7,7};
    vector<int> nums4 = {0};
                       //0   1  2  3  4  5
    cout << sol.lengthOfLIS(nums1) << endl;
    cout << sol.lengthOfLIS(nums2) << endl;
    cout << sol.lengthOfLIS(nums3) << endl;
    cout << sol.lengthOfLIS(nums4) << endl;

    return 0;
}
