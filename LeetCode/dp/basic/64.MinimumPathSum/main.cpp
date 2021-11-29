#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));

        int sum = 0;
        for (int j = 0; j < col; j++) {
            sum += grid[0][j];
            dp[0][j] = sum;
        }
        sum = 0;
        for (int i = 0; i < row; i++) {
            sum += grid[i][0];
            dp[i][0] = sum;
        }

        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                dp[i][j] = min( dp[i - 1][j], dp[i][j - 1] ) + grid[i][j];
            }
        }

        return dp[row - 1][col - 1];
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
