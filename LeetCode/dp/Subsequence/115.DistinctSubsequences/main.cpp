#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        unsigned int len1 = s.size();
        unsigned int len2 = t.size();

        // dp[i][j]表示, 从s中抽取字符(须保持相对前后顺序), 然后凑t, 凑成t的方法数
        vector< vector<unsigned int> > dp(len1, vector<unsigned int>(len2, 0));

        if (s[0] == t[0]) {
            dp[0][0] = 1;
        }
        for (unsigned int i = 1; i < len1; i++) {
            if (s[i] == t[0]) {
                dp[i][0] = dp[i - 1][0] + 1;
            } else {
                dp[i][0] = dp[i - 1][0];
            }
        }
//        for (unsigned int j = 1; j < t.size(); j++) dp[0][j] = 0; // 节省点性能

        for (unsigned int i = 1; i < len1; i++) {
            for (unsigned int j = 1; j < len2; j++) {

                if (s[i] == t[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[len1 - 1][len2 - 1];
    }
};

int main()
{
    Solution sol;
//    string s = "rabbbit";
//    string t = "rabbit";

    string s = "babgbag";
    string t = "bag";

    cout << sol.numDistinct(s, t) << endl;
    return 0;
}
