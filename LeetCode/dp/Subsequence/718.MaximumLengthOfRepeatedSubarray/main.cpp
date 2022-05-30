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

        // dp[i][j] ��ʾA������iλ��(��)֮ǰ, ������nums1[i]��β��������
		// ��
		// B������jλ��(��)֮ǰ, ������nums1[i]��β��������
		// ��ظ�������ĳ���
		//����һ��, ��nums1[0]ǰ���һ�������ַ�A, ��nums2[0]ǰ���һ�������ַ�B
		//A, B���κ�һֱ�ַ������, ��A != B
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
