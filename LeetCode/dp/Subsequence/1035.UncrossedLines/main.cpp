#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int res = 0;

        vector< vector<int> > dp(len1, vector<int>(len2, 0) );

        //dp数组初始化
        for (int i = 0; i < len1; i++) {
            if (nums1[i] == nums2[0]) {
                dp[i][0] = 1;
                res = 1;
                for (int k = i + 1; k < len1; k++) {
                    dp[k][0] = 1;
                }
            }
        }
        for (int j = 0; j < len2; j++) {
            if (nums1[0] == nums2[j]) {
                dp[0][j] = 1;
                res = 1;
                for (int k = j + 1; k < len2; k++) {
                    dp[0][k] = 1;
                }
            }
        }

        for (int i = 1; i < len1; i++) {
            for (int j = 1; j < len2; j++) {

                if (nums1[i] == nums2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    res = max(res, dp[i][j]);
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    res = max(res, dp[i][j]);
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
//    vector<int> nums1 = {2,5,1,2,5}, nums2 = {10,5,2,1,5,2};
    vector<int> nums1 = {1,3,7,1,7,5}, nums2 = {1,9,2,5,1};

    cout << sol.maxUncrossedLines(nums1, nums2) << endl;

    return 0;
}
