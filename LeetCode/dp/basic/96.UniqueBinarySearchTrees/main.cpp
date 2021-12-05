#include <iostream>

using namespace std;

class Solution {
public:
    int numTrees(int n) {

        if (n <= 2) {
            return n;
        }

        int dp[n + 1];  //i个节点构成的搜索二叉树数量为dp[i]
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++) {

            dp[i] = 0;
            //遍历以j为为头节点的二叉搜索树
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }

        return dp[n];
    }
};

int main()
{
    Solution sol;
    cout << sol.numTrees(1) << endl;

    return 0;
}
