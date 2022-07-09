#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int result = 0;
        int row = grid.size();
        int col = grid[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    result = max(result, getArea(grid, i, j));
                }
            }
        }

        return result;
    }

private:
    int getArea(vector<vector<int>>& grid, int row, int col) {

        //超范围了
        if (isInArea(grid, row, col) == false) {
            return 0;
        }

        if (grid[row][col] == 2 ||         //如果已经被访问过
            grid[row][col] == 0)           //如果是海洋
        {
            return 0;
        }

        //标记当前位置已经被访问过
        grid[row][col] = 2;

        int areaUp = getArea(grid, row - 1, col);
        int areaDown = getArea(grid, row + 1, col);
        int areaLeft = getArea(grid, row, col - 1);
        int areaRight = getArea(grid, row, col + 1);

        //上下左右
        return 1 + areaUp + areaDown + areaLeft + areaRight;
    }

    //判断当前是否在格子里
    bool isInArea(vector<vector<int>>& grid, int row, int col) {

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
    vector<vector<int>> grid =
        {{0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}};

    cout << sol.maxAreaOfIsland(grid) << endl;
    return 0;
}
