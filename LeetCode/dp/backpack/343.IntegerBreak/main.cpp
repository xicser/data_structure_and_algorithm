#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {

        if (n <= 2) {
            return 1;
        }

        vector<int> dp(n + 1, -1);  //dp[i] 拆分数字i, 得到的最大乘积

        dp[2] = 1;

        for (int i = 3; i <= n; i++) {
            for (int j = 1; j <= i / 2; j++) {
                dp[i] =  max(dp[i], j * dp[i - j] );
            }
        }

        return dp[n];
    }
};

int main()
{
    Solution sol;

    cout << sol.integerBreak(2) << endl;
    cout << sol.integerBreak(4) << endl;
    cout << sol.integerBreak(10) << endl;

    return 0;
}
