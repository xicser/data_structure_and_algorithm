#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int cuttingRope(int n) {

        if (n == 2) {
            return 1;
        }
        if (n == 3) {
            return 2;
        }

        //dp[i]表示切割长度为n的绳子, 所能得到的最大乘积
        vector<int> dp(n + 1, 0);
        dp[2] = 1;
        dp[3] = 2;

        for (int i = 4; i < dp.size(); i++) {
            for (int j = 2; j < i; j++) {
                dp[i] = max(dp[i], max(j * (i - j),         //把长度为i的绳子, 切出一个j来, 然后不继续切了
                                       j * dp[i - j]));     //把长度为i的绳子, 切出一个j来, 继续切
            }
        }

        return dp[n];
    }
};

int main()
{
    Solution sol;
    cout << sol.cuttingRope(10) << endl;
    
    return 0;
}
