#include <iostream>

using namespace std;

class Solution {
public:
//    int climbStairs(int n) {
//        if (n == 1) {
//            return 1;
//        }
//        if (n == 2) {
//            return 2;
//        }
//        return climbStairs(n - 1) + climbStairs(n - 2);
//    }

    int climbStairs(int n) {

        if (n <= 2) {
            return n;
        }

        int dp[n + 1];   //第i层楼梯, 一共有dp[i]种上法

        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

int main()
{
    Solution sol;
    cout << sol.climbStairs(3) << endl;

    return 0;
}
