#include <iostream>
#include <string>
#include <vector>

using namespace std;

// "22 6"
class Solution {
public:
    int numDecodings(string s) {
        //只要含有前导0, 结果就是0
        if (s[0] == '0') {
            return 0;
        }
        int len = s.size();
        if (len == 1) {
            //只要含有前导0, 结果就是0
            if (s[0] == '0') {
                return 0;
            }
            return 1;
        }

        //dp[i]表示[0] -> [i]之间, 的解码方法数
        vector<int> dp(len, 0);
        dp[0] = 1;

        int a = s[1] - '0';
        int b = (s[0] - '0') * 10 + (s[1] - '0');
        //1位置的数当作单独的一个解码方法
        if (1 <= a && a <= 9) {
            dp[1] = 1;
        }
        //1位置和0位置的数共同当作一个解码方法
        if (10 <= b && b <= 26) {
            dp[1] += 1;
        }

        for (int i = 2; i < len; i++) {
            int a = s[i] - '0';
            int b = (s[i - 1] - '0') * 10 + (s[i] - '0');

            //i位置的数当作单独的一个解码方法
            if (1 <= a && a <= 9) {
                dp[i] = dp[i - 1];
            }
            //i位置和i - 1位置的数共同当作一个解码方法
            if (10 <= b && b <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[len - 1];
    }
};

int main()
{
    Solution sol;
    std::cout << sol.numDecodings("123208") << endl;
}
