#include <iostream>
#include <string>
#include <vector>

using namespace std;

//求最长公共子序列长度l, 若l==s.size(), 表明是
class Solution {
public:
    bool isSubsequence(string s, string t) {

        int len1 = s.size();
        int len2 = t.size();

        int result = 1;

        vector< vector<int> > dp(len1 + 1, vector<int>(len2 + 1, 1) );

        for (int i = 1; i < len1 + 1; i++) {
            for (int j = 1; j < len2 + 1; j++) {

                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }

                result = max(result, dp[i][j]);
            }
        }

        result -= 1;
        if (result == s.size()) {
            return true;
        }

        return false;
    }
};

int main()
{
    Solution sol;
    string s = "abc";
    string t = "ahbgdc";

    cout << sol.isSubsequence(s, t) << endl;

    return 0;
}
