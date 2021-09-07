#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {

        int len  = s.size();
        vector< vector<bool> > dp(len, vector<bool>(len, false) );

        int res = 0;
        for (int i = len - 1; i >= 0; i--) {
            for (int j = i; j < len; j++) {
                if (s[i] != s[j]) {
                    dp[i][j] = false;
                }
                else {
                    if (i == j) {
                        dp[i][j] = true;
                        res++;
                    }
                    else if (j - i == 1) {
                        dp[i][j] = true;
                        res++;
                    }
                    else if (dp[i + 1][j - 1] == true) {
                        dp[i][j] = true;
                        res++;
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
    string s1 = "abc";
    string s2 = "aaa";
    cout << sol.countSubstrings(s1) << endl;
    cout << sol.countSubstrings(s2) << endl;

    return 0;
}
