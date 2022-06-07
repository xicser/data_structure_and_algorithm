#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        int row = matrix.size();
        int col = matrix[0].size();

        int maxSide = 0;

        //dp[i][j]表示, 以[i][j]为右下角的数值全为1的正方形的最大边长
        //为了方便处理, 统一加一行一列0, 不影响结果
        vector< vector<int> > dp(row + 1, vector<int>(col + 1, 0) );

        for (int i = 1; i < row + 1; i++) {
            for (int j = 1; j < col + 1; j++) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                }
                maxSide = max(dp[i][j], maxSide);
            }
        }

        return maxSide * maxSide;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
