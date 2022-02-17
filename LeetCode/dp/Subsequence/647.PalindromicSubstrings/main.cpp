#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {

        int len  = s.size();
        int result = 0;

        //dp[i][j]表示 [i] -> [j] 之间的子串是否为回文串
        vector< vector<bool> > dp(len, vector<bool>(len, false) );

        for (int i = len - 1; i >= 0; i--) {
            for (int j = i; j < len; j++) {
                if (s[i] != s[j]) {
                    dp[i][j] = false;
                }
                else {
                    //对角线上的元素
                    if (i == j) {
                        result++;
                        dp[i][j] = true;
                    }
                    //只相差一个位置
                    else if (j - i == 1) {
                        result++;
                        dp[i][j] = true;
                    }
                    //两头相等, 还要看中间是否相等
                    else {
                        if (dp[i + 1][j - 1] == true) {
                            result++;
                            dp[i][j] = true;
                        }
                        else {
                            dp[i][j] = false;
                        }
                    }
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    string s1 = "abc";
    string s2 = "aaa";
    cout << sol.countSubstrings(s1) << endl;
    cout << sol.countSubstrings(s2) << endl;

    return 0;
}
