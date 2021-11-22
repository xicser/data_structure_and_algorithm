#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        this->result = 0;
        int row = grid.size();
        int col = grid[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    getArea(grid, i, j);
                    return result;
                }
            }
        }

        return result;
    }

private:
    int result;
    void getArea(vector<vector<int>>& grid, int row, int col) {

        //超范围了
        if (isInArea(grid, row, col) == false) {
            this->result++;
            return;
        }

        //如果已经被访问过
        if (grid[row][col] == 2) {
            return;
        }
        //如果是海洋
        if (grid[row][col] == 0) {
            this->result++;
            return;
        }

        grid[row][col] = 2;

        getArea(grid, row - 1, col);
        getArea(grid, row + 1, col);
        getArea(grid, row, col - 1);
        getArea(grid, row, col + 1);
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
        {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    cout << sol.islandPerimeter(grid) << endl;

    return 0;
}
