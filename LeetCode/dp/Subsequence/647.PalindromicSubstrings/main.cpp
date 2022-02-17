#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {

        int len  = s.size();
        int result = 0;

        //dp[i][j]��ʾ [i] -> [j] ֮����Ӵ��Ƿ�Ϊ���Ĵ�
        vector< vector<bool> > dp(len, vector<bool>(len, false) );

        for (int i = len - 1; i >= 0; i--) {
            for (int j = i; j < len; j++) {
                if (s[i] != s[j]) {
                    dp[i][j] = false;
                }
                else {
                    //�Խ����ϵ�Ԫ��
                    if (i == j) {
                        result++;
                        dp[i][j] = true;
                    }
                    //ֻ���һ��λ��
                    else if (j - i == 1) {
                        result++;
                        dp[i][j] = true;
                    }
                    //��ͷ���, ��Ҫ���м��Ƿ����
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
