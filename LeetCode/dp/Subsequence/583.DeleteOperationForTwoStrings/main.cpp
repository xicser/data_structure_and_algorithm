#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();

        // dp[i][j] 表示A数组中i位置(含)之前
		// 和
		// B数组中j位置(含)之前
		// 把word1变成word2的最小步数
		// 并且在word1前面和word2前面加一个相等的字符, 且该字符和任何一直字符都不相等
		// 加入的这个字符不影响结果
        vector< vector<int> > dp(len1 + 1, vector<int>(len2 + 1, 0) );

        //dp数组初始化
        for (int i = 0; i < len1 + 1; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j < len2 + 1; j++) {
            dp[0][j] = j;
        }

        //计算dp
        for (int i = 1; i < len1 + 1; i++) {
            for (int j = 1; j < len2 + 1; j++) {

                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = min(dp[i - 1][j - 1] + 2,    //同时删
                                   min(dp[i - 1][j] + 1,    //只删除word1
                                   dp[i][j - 1] + 1));      //只删除word2
                }
            }
        }

        return dp[len1][len2];
    }
};

int main()
{
    Solution sol;
//    string text1 = "bl", text2 = "yby";
    string text1 = "sea", text2 = "eat";
//    string text1 = "leetcode", text2 = "etco";

    cout << sol.minDistance(text1, text2) << endl;

    return 0;
}
