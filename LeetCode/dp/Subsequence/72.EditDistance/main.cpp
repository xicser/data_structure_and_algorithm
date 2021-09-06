#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {

        int len1 = word1.size();
        int len2 = word2.size();
        if (len1 == 0) {
            return len2;
        }
        if (len2 == 0) {
            return len1;
        }

        //dp[i][j]表示将word1转换成word2所需要的最小步骤
        vector< vector<int> > dp(len1 + 1, vector<int>(len2 + 1, 0));

        //dp数组初始化
        for (int i = 1; i < len1 + 1; i++) {
            dp[i][0] = i;
        }
        for (int j = 1; j < len2 + 1; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i < len1 + 1; i++) {
            for (int j = 1; j < len2 + 1; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = min(dp[i][j - 1] + 1, min(dp[i - 1][j] + 1, dp[i - 1][j - 1] + 1));
                }
            }
        }

        return dp[len1][len2];
    }
};

int main()
{
    Solution sol;
    string word1 = "horse";
    string word2 = "ros";

    string word3 = "a";
    string word4 = "ab";

    cout << sol.minDistance(word1, word2) << endl;

    cout << sol.minDistance(word3, word4) << endl;


    return 0;
}
