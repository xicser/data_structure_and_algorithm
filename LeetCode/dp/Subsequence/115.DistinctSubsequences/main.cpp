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
        vector< vector<unsigned int> > dp(len1 + 1, vector<unsigned int>(len2 + 1, 0));

        for (unsigned int i = 0; i < len1 + 1; i++) {
            dp[i][0] = 1;
        }
//        for (unsigned int j = 0; j < t.size(); j++) dp[0][j] = 0; // 节省点性能

        for (unsigned int i = 1; i < len1 + 1; i++) {
            for (unsigned int j = 1; j < len2 + 1; j++) {

                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[len1][len2];
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
