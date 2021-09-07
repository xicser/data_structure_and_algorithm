#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len  = s.size();
        vector< vector<int> > dp(len, vector<int>(len, 0) );

        int res = 0;
        for (int i = len - 1; i >= 0; i--) {
            for (int j = i; j < len; j++) {
                if (s[i] != s[j]) {
                    if (j - i == 1) {
                        dp[i][j] = 1;
                        res = max(res, dp[i][j]);
                    }
                    else {
                        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                        res = max(res, dp[i][j]);
                    }
                }
                else {
                    if (i == j) {
                        dp[i][j] = 1;
                        res = max(res, dp[i][j]);
                    }
                    else if (j - i == 1) {
                        dp[i][j] = 2;
                        res = max(res, dp[i][j]);
                    }
                    else {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                        res = max(res, dp[i][j]);
                    }
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    string s1 = "bbbab";
    string s2 = "cbbd";

    cout << sol.longestPalindromeSubseq(s1) << endl;
    cout << sol.longestPalindromeSubseq(s2) << endl;

    return 0;
}
