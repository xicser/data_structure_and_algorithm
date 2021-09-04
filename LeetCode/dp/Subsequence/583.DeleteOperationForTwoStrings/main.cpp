#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        int res = 0;

        // dp[i][j] 表示A数组中i位置(含)之前
		// 和
		// B数组中j位置(含)之前
		// 最长重复子序列的长度
        vector< vector<int> > dp(len1, vector<int>(len2, 0) );

        //dp数组初始化
        for (int i = 0; i < len1; i++) {
            if (word1[i] == word2[0]) {
                dp[i][0] = 1;
                res = 1;
                for (int k = i + 1; k < len1; k++) {
                    dp[k][0] = 1;
                }
            }
        }
        for (int j = 0; j < len2; j++) {
            if (word1[0] == word2[j]) {
                dp[0][j] = 1;
                res = 1;
                for (int k = j + 1; k < len2; k++) {
                    dp[0][k] = 1;
                }
            }
        }

        for (int i = 1; i < len1; i++) {
            for (int j = 1; j < len2; j++) {

                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    res = max(res, dp[i][j]);
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    res = max(res, dp[i][j]);
                }
            }
        }

        return len1 - res + len2 - res;
    }
};

int main()
{
    Solution sol;
//    string text1 = "bl", text2 = "yby";
//    string text1 = "sea", text2 = "eat";
    string text1 = "leetcode", text2 = "etco";

    cout << sol.minDistance(text1, text2) << endl;

    return 0;
}
