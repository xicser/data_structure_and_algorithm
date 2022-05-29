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
        int start, end;
        vector< vector<int> > dp(len, vector<int>(len, 0));

        for (int i = len - 1; i >= 0; i--) {
            for (int j = i; j < len; j++) {

                if (s[i] != s[j]) {
                    dp[i][j] = 0;
                }
                else {
                    //对角线
                    if (i == j) {
                        dp[i][j] = 1;
                    }
                    else if (j - i == 1) {
                        dp[i][j] = 2;
                    }
                    else {
                        if (dp[i + 1][j - 1] != 0) {
                            dp[i][j] = dp[i + 1][j - 1] + 2;
                        }
                        else {
                            dp[i][j] = 0;
                        }
                    }
                }

                if (resultLen < dp[i][j]) {
                    resultLen = dp[i][j];
                    start = i;
                    end = j;
                }
            }
        }

        return s.substr(start, end - start + 1);
    }
};

int main()
{
    Solution sol;

    cout << sol.longestPalindrome("a") << endl;
    return 0;
}
