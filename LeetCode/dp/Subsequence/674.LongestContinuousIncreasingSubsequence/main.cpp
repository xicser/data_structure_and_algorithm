#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {

        int len = nums.size();
        if (len == 1) {
            return 1;
        }
        int maxHistory = -1;

        vector<int> dp(len, 0);
        dp[0] = 1;

        for (unsigned int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            }
            else {
                maxHistory = max(maxHistory, dp[i - 1]);
                dp[i] = 1;
            }
        }

        return max(maxHistory, dp[len - 1]);
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
