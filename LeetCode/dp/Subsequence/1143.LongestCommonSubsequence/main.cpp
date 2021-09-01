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
        int res = 0;

        vector< vector<int> > dp(len1, vector<int>(len2, 0) );

        //dp数组初始化
        for (int i = 0; i < len1; i++) {
            if (text1[i] == text2[0]) {
                dp[i][0] = 1;
                res = 1;
                for (int k = i + 1; k < len1; k++) {
                    dp[k][0] = 1;
                }
            }
        }
        for (int j = 0; j < len2; j++) {
            if (text1[0] == text2[j]) {
                dp[0][j] = 1;
                res = 1;
                for (int k = j + 1; k < len2; k++) {
                    dp[0][k] = 1;
                }
            }
        }

        for (int i = 1; i < len1; i++) {
            for (int j = 1; j < len2; j++) {

                if (text1[i] == text2[j]) {
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
    string text1 = "bl", text2 = "yby";

    cout << sol.longestCommonSubsequence(text1, text2) << endl;

    return 0;
}
