#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        int dp[m][n];   //到达[m][n]位置, 可以走的路径数

        //dp数组初始化
        bool flag = true;
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0] == 0 && flag == true) {
                dp[i][0] = 1;
            } else {
                flag = false;
                dp[i][0] = 0;
            }
        }
        flag = true;
        for (int i = 0; i < n; i++) {
            if (obstacleGrid[0][i] == 0 && flag == true) {
                dp[0][i] = 1;
            } else {
                flag = false;
                dp[0][i] = 0;
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};

int main()
{
    Solution sol;
    vector< vector<int> > obstacleGrid;
    int arr[][3] = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };

    for (int i = 0; i < 3; i++) {
        vector<int> vecTmp;
        vecTmp.clear();
        for (int j = 0; j < 3; j++) {
            vecTmp.push_back(arr[i][j]);
        }
        obstacleGrid.push_back(vecTmp);
    }

    cout << sol.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}
