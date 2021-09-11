#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        int len1 = text1.size();
        int len2 = text2.size();
        int res;

        // dp[i][j] 表示A数组中i位置(含)之前
		// 和
		// B数组中j位置(含)之前
		// 最长重复子序列的长度
        vector< vector<int> > dp(len1 + 1, vector<int>(len2 + 1, 1) );

        //dp数组初始化
        res = 1;

        for (int i = 1; i < len1 + 1; i++) {
            for (int j = 1; j < len2 + 1; j++) {

                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }

                res = max(res, dp[i][j]);
            }
        }

        return res - 1;
    }
};

int main()
{
    Solution sol;
    string text1 = "bl", text2 = "yby";

    cout << sol.longestCommonSubsequence(text1, text2) << endl;

    return 0;
}
