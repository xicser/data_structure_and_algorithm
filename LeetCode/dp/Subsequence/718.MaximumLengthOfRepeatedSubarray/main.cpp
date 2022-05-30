#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {

        int len1 = nums1.size();
        int len2 = nums2.size();
        int res = 0;

        // dp[i][j] 表示A数组中i位置(含)之前, 必须以nums1[i]结尾的子数组
		// 和
		// B数组中j位置(含)之前, 必须以nums1[i]结尾的子数组
		// 最长重复子数组的长度
		//想象一下, 给nums1[0]前面加一个特殊字符A, 给nums2[0]前面加一个特殊字符B
		//A, B与任何一直字符不相等, 且A != B
        vector< vector<int> > dp(len1 + 1, vector<int>(len2 + 1, 0));

        for (int i = 1; i < len1 + 1; i++) {
            for (int j = 1; j < len2 + 1; j++) {

                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }

                res = max(res, dp[i][j]);
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {1,2,3,2,1};
    vector<int> nums2 = {3,2,1,4,7};

    vector<int> nums3 = {1,2,3,2,8};
    vector<int> nums4 = {5,6,1,4,7};

    cout << sol.findLength(nums1, nums2) << endl;
    cout << sol.findLength(nums3, nums4) << endl;

    return 0;
}
