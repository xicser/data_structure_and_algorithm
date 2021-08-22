#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {

        int bagSize = target;
        int thingsCount = nums.size();

        vector<unsigned int> dp(bagSize + 1, 0);
        dp[0] = 1;

        for (int j = 0; j <= bagSize; j++) {
            for (int i = 0; i < thingsCount; i++) {
                if (j >= nums[i]) {
                    dp[j] += dp[j - nums[i]];
                }
            }
        }

        return dp[bagSize];
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {9};

    cout << sol.combinationSum4(nums1, 4) << endl;
    cout << sol.combinationSum4(nums2, 3) << endl;

    return 0;
}
