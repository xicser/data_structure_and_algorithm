#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];   //到达[m][n]位置, 可以走的路径数

        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }
        for (int i = 0; i < n; i++) {
            dp[0][i] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};

int main()
{
    Solution sol;
    cout << sol.uniquePaths(3, 7) << endl;
    cout << sol.uniquePaths(3, 2) << endl;
    cout << sol.uniquePaths(7, 3) << endl;
    cout << sol.uniquePaths(3, 3) << endl;

    return 0;
}
