#include <iostream>
#include <vector>

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

//    int climbStairs(int n) {
//
//        if (n <= 2) {
//            return n;
//        }
//
//        int dp[n + 1];   //第i层楼梯, 一共有dp[i]种上法
//
//        dp[1] = 1;
//        dp[2] = 2;
//        for (int i = 3; i <= n; i++) {
//            dp[i] = dp[i - 1] + dp[i - 2];
//        }
//
//        return dp[n];
//    }

    //转换成排列完全背包问题
    int climbStairs(int n) {
        vector<int> things = {1, 2};
        int bagSize = n;

        vector<int> dp(bagSize + 1, 0);
        dp[0] = 1;

        for (int j = 0; j <= bagSize; j++) {
            for (int i = 0; i < things.size(); i++) {
                if (j >= things[i]) {
                    dp[j] += dp[j - things[i]];
                }
            }
        }

        return dp[bagSize];
    }
};

int main()
{
    Solution sol;
    cout << sol.climbStairs(3) << endl;

    return 0;
}
