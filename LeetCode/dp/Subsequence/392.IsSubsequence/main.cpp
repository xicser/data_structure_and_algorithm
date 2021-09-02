#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {

        int len1 = s.size();
        int len2 = t.size();

        if (len1 == 0) {
            return false;
        }
        if (len1 > len2) {
            return false;
        }

        vector< vector<int> > dp(len1, vector<int>(len2, 0) );

        for (int i = 0; i < len1; i++) {
            if (s[i] == t[0]) {
                dp[i][0] = 1;
                for (int k = i + 1; k < len1; k++) {
                    dp[k][0] = 1;
                }
                break;
            }
        }
        for (int j = 0; j < len2; j++) {
            if (s[0] == t[j]) {
                dp[0][j] = 1;
                for (int k = j + 1; k < len2; k++) {
                    dp[0][k] = 1;
                }
                break;
            }
        }

        for (int i = 1; i < len1; i++) {
            for (int j = 1; j < len2; j++) {

                if (s[i] == t[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return dp[len1 - 1][len2 - 1] == len1;
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
