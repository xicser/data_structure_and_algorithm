#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        int row = matrix.size();
        int col = matrix[0].size();

        int maxSide = 0;
        //dp[i][j]表示以[i][j]位置为右下角的的正方形的边长
        //为了方便处理, 加一行和一列 全是0
        vector< vector<int> > dp(row + 1, vector<int>(col + 1, 0));

        for (int i = 1; i < row + 1; i++) {
            for (int j = 1; j < col + 1; j++) {

                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = min(dp[i - 1][j - 1],        //左上
                               min(dp[i - 1][j],            //上
                                   dp[i][j - 1])) + 1;      //左

                    maxSide = max(maxSide, dp[i][j]);
                }
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
