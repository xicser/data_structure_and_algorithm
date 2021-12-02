#include <iostream>
#include <string>
#include <vector>

using namespace std;

//最长的回文子串
class Solution {
public:
    string longestPalindrome(string s) {

        int len = s.size();
        int resultLen = -1;
        int startPos, endPos;

        //dp[i][j]表示 从[i]开始 -> 至[j]结束 的 回文子串 的长度
        vector< vector<int> > dp(len, vector<int>(len, 0));

        for (int i = len - 1; i >= 0; i--) {
            for (int j = i; j < len; j++) {

                if (s[i] != s[j]) {
                    dp[i][j] = 0;
                }
                else {
                    if (i == j) {
                        dp[i][j] = 1;
                    }
                    else if (j - i == 1) {
                        dp[i][j] = 2;
                    }
                    else {

                        if (dp[i + 1][j - 1] == j - i - 1) {
                            dp[i][j] = dp[i + 1][j - 1] + 2;
                        }
                        else {
                            dp[i][j] = 0;
                        }
                    }
                }

                //记录长最长的那个回文子串
                if (resultLen < dp[i][j]) {
                    startPos = i;
                    endPos = j;
                    resultLen = dp[i][j];
                }
            }
        }

        return s.substr(startPos, endPos - startPos + 1);;
    }
};

int main()
{
    Solution sol;

    cout << sol.longestPalindrome("babad") << endl;
    return 0;
}
