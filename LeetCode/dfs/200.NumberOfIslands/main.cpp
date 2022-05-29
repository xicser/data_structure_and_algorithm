#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        int row = grid.size();
        int col = grid[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1') {
                    getIslandCnt(grid, i, j);
                    result++;
                }
            }
        }

        return result;
    }

private:
    void getIslandCnt(vector<vector<char>>& grid, int row, int col) {

        //超范围了
        if (isInArea(grid, row, col) == false) {
            return;
        }

        //海
        if (grid[row][col] == '0') {
            return;
        }

        //已经被访问过
        if (grid[row][col] == '2') {
            return;
        }

        grid[row][col] = '2';

        getIslandCnt(grid, row - 1, col);
        getIslandCnt(grid, row + 1, col);
        getIslandCnt(grid, row, col - 1);
        getIslandCnt(grid, row, col + 1);
    }

    //判断当前是否在格子里
    bool isInArea(vector<vector<char>>& grid, int row, int col) {

        if (0 <= row && (row <= grid.size() - 1) &&
            0 <= col && (col <= grid[0].size() - 1)) {
            return true;
        }

        return false;
    }
};

int main()
{
    Solution sol;
    vector<vector<char>> grid = {
      {'1','1','1','1','0'},
      {'1','1','0','1','0'},
      {'1','1','0','0','0'},
      {'0','0','0','0','0'}};

    cout << sol.numIslands(grid) << endl;
    return 0;
}
