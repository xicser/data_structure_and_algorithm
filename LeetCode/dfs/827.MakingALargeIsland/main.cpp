#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
private:
    unordered_map<int, int> areaMap;  //<陆地编号, 面积>
    unordered_set<int> islandIndex;
    int index;
public:
    int largestIsland(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        index = 2;  //从2开始编号

        bool enteredIsland = false;
        //遍历出所有陆地的面积, 然后存放到areaMap中
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    enteredIsland = true;
                    int area = calArea(grid, i, j);
                    areaMap[index] = area;
                    index++;
                }
            }
        }
        //没有陆地
        if (enteredIsland == false) {
            return 1;
        }

        bool enteredSea = false;
        int result = 0;
        //再遍历海洋
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 0) {
                    enteredSea = true;
                    islandIndex.clear();
                    findNeighbor(grid, islandIndex, i, j);
                    if (islandIndex.size() == 0) { //周围全是海洋
                        continue;
                    }
                    int areaTmp = 1;
                    for (auto it = islandIndex.begin(); it != islandIndex.end(); it++) {
                        int index = *it;
                        areaTmp += areaMap[index];
                    }
                    result = max(result, areaTmp);
                }
            }
        }

        //如果没有海洋
        if (enteredSea == false) {
            return areaMap[2];
        }

        return result;
    }

    void findNeighbor(vector<vector<int>>& grid,
                      unordered_set<int>& islandIndex,
                      int row, int col) {

        if (isInArea(grid, row - 1, col) && grid[row - 1][col] != 0) {
            islandIndex.insert(grid[row - 1][col]);
        }
        if (isInArea(grid, row + 1, col) && grid[row + 1][col] != 0) {
            islandIndex.insert(grid[row + 1][col]);
        }
        if (isInArea(grid, row, col - 1) && grid[row][col- 1] != 0) {
            islandIndex.insert(grid[row][col - 1]);
        }
        if (isInArea(grid, row, col + 1) && grid[row][col + 1] != 0) {
            islandIndex.insert(grid[row][col + 1]);
        }
    }

    int calArea(vector<vector<int>>& grid, int row, int col) {

        if (isInArea(grid, row, col) == false) {
            return 0;
        }

        if (grid[row][col] != 1) {
            return 0;
        }

        grid[row][col] = index;  //标记访问过 标记索引

        return 1 + calArea(grid, row - 1, col) +
                   calArea(grid, row + 1, col) +
                   calArea(grid, row, col - 1) +
                   calArea(grid, row, col + 1);
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
    vector<vector<int>> grid = {{1,1,0,1,0,0,0,0,1,0,0,0,1,0,1,1,1,1,0,1,0,1,0,0,0,1,0,1,1,1,0,0,1,1,0,1,1,0,1,0,1,1,0,1,0,0,0,1,1,0,1,1,1,1,1,1,1,1,1,1,0,0,1,0,1,1,0,1,1,1,1,0,1,1,0,0,1,0,0,0,0,1,1,1,1,0,1,0,0,1,0},{0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,1,0,1,0,1,0,0,1,0,0,0,0,0,0,1,0,0,1,1,0,0,0,1,0,1,1,0,0,0,0,1,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,1,1,1,0,0,1,0,1,0,1,1,0,1,1},{0,0,1,1,1,0,0,0,0,1,0,0,1,0,1,1,1,1,0,0,0,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,0,1,1,1,0,1,1,0,1,1,1,0,0,1,0,1,1,0,0,0,1,1,0,0,1,0,1,0,1,0,1,0,1,0,0,0,0,1,1,0,1,0,0,0,1,1,1,1,1,1,1,1,0,0,1},{0,0,1,0,1,1,0,0,1,1,0,0,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,0,1,0,1,0,1,1,1,1,0,1,1,0,1,1,0,1,0,1,0,0,1,1,0,1,1,1,1,1,0,0,1,1,1,1,0,1,0,1,1,1,1,0,0,0,1,1,1,0,1,1,1,1,0,0,0,0,1,1,1,0,1,0},{0,1,1,1,0,1,0,0,0,1,1,1,0,0,1,0,0,0,1,1,1,0,0,1,1,0,1,1,0,1,0,1,1,1,0,1,0,1,1,0,1,0,0,0,1,1,0,1,0,1,1,1,1,0,1,0,1,1,0,1,1,1,1,1,1,1,0,1,1,0,1,0,1,1,0,0,1,0,0,0,1,1,1,0,0,1,0,1,1,0,1},{1,0,1,0,1,1,0,0,0,1,1,1,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,1,0,0,0,0,0,0,0,1,1,0,0,1,0,0,1,1,1,0,0,1,1,0,0,1,1,1,1,0,1,1,1,0,1,1,1,0,0,0,0,1,0,1,0,1,1},{1,0,1,0,0,0,1,0,0,1,0,1,1,1,1,0,0,1,1,1,0,0,0,1,0,1,1,1,1,1,1,0,1,1,1,0,1,1,0,1,0,0,1,0,0,0,1,1,1,1,0,0,1,0,0,1,0,0,0,1,1,1,0,1,1,0,0,1,0,1,1,1,0,0,1,1,0,0,1,0,0,1,1,1,1,0,1,0,0,0,1},{1,1,0,1,1,0,0,1,0,1,1,1,1,0,0,0,1,0,0,1,0,1,0,1,0,1,1,0,0,0,1,0,1,0,0,1,0,1,1,0,1,1,0,0,1,1,1,1,0,0,1,0,0,0,0,0,0,0,1,1,1,0,0,0,0,1,1,0,0,0,1,0,1,1,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0,0,1},{1,0,1,1,0,1,1,0,1,1,0,0,0,0,1,0,0,1,1,0,0,1,1,0,1,1,0,0,0,1,0,0,1,0,1,0,1,1,0,1,1,0,1,0,1,0,0,1,0,1,1,0,0,1,1,0,0,1,1,1,1,0,0,0,1,1,1,1,1,0,0,1,1,1,0,0,1,0,0,0,1,0,1,1,1,1,0,0,0,0,1},{1,1,1,1,1,0,1,1,0,0,1,0,0,1,1,1,1,0,0,1,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,0,1,0,1,1,1,1,1,0,0,1,1,1,0,1,1,1,0,1,0,1,1,0,0,0,1,0,1,0,1,0,1,1,1,1,0,1,1,0,0,1,1,0,1,1,1,1,0,1,1,0,1,0,1,0},{0,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,0,0,1,1,1,0,1,0,0,1,1,0,1,0,0,1,1,1,1,0,0,0,1,0,0,0,1,0,1,1,1,1,0,1,0,0,1,0,0,1,1,1,1,0,0,0,1,0,0,1,1,0,1,0,1,0,0,0,0,0,1,1,0,0,1,0,1,0,0,0,0,1,1,1},{0,0,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,0,0,1,0,1,0,0,1,1,0,0,1,1,1,1,1,0,0,1,1,0,1,0,0,1,1,0,1,0,0,0,0,1,1,1,0,0,1,0,0,1,1,1,0,0,1,1,0,1,0,0,1,0,0,1,0,1,0,0,0,1,0,0,0,0,1,0,1,0,0},{0,1,0,0,1,1,1,1,1,1,0,1,1,1,0,0,0,1,1,1,1,1,0,1,1,0,1,1,0,0,0,0,1,1,1,1,1,0,0,1,1,0,1,1,0,1,1,1,0,1,1,1,1,0,0,0,0,0,1,1,1,0,1,0,1,0,0,1,0,0,1,0,0,1,0,1,1,1,0,1,1,1,1,0,1,0,0,0,0,1,1},{0,1,1,0,1,0,1,0,1,1,1,0,1,1,1,0,0,0,1,1,1,0,0,1,0,1,0,0,0,1,1,1,1,1,0,0,1,1,0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,1,1,0,0,1,0,1,0,1,1,0,1,1,1,0,0,0,0,0,1,0,0,1,1,0,0,0,1,0,0,0,1,1,0,1,0,1,1},{1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,1,1,1,1,0,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,0,0,1,1,1,1,1,0,1,0,0,1,1,1,1,1,1,0,1,1,0,0,0,1,0,1,0,1,1,1,0,1,0,0,0,0,0,0,1,1,1,0,0,0,1,0,0,0,1},{1,1,0,1,1,1,0,1,1,0,0,1,1,1,0,0,1,0,1,1,1,0,0,1,1,0,0,0,0,0,0,1,1,0,0,1,0,1,0,0,0,0,0,1,1,0,1,0,0,0,1,1,1,1,0,1,0,0,1,0,1,1,1,0,1,1,1,0,0,0,1,1,1,0,0,1,0,0,1,1,1,1,0,0,1,1,0,0,0,1,1},{0,0,0,1,0,1,0,1,0,0,1,1,1,0,1,1,0,1,0,0,0,1,1,0,1,0,0,1,0,0,0,1,1,1,0,1,0,1,1,1,1,1,1,0,0,1,1,0,1,0,1,0,0,0,0,0,1,1,1,0,1,1,1,1,1,0,0,1,0,1,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,1,0,1,1,1,0},{0,0,1,0,0,1,1,0,0,1,1,1,0,1,0,1,1,1,1,0,0,0,1,0,0,1,1,0,1,1,1,1,1,0,0,0,1,1,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,0,1,0,0,1,0,0,1,1,1,0,1,1,0,1,0,1,0,1,0,0,1,0,1,0,1,1,1,0,1,1,1,0,1,1,0,0,0},{0,1,0,0,1,0,1,0,1,1,1,1,0,1,0,1,1,0,0,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,1,1,0,1,0,1,0,0,0,1,1,1,0,1,1,0,1,0,0,0,0,0,0,0,1,1,1,0,0,1,1,0,0,0,1,0,1,1,1,1,0,1,1,1,0,0,0,0,0,1,1,1,1,1,0,1},{1,0,1,1,0,0,1,1,1,1,1,0,0,1,0,0,0,1,0,1,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,1,0,0,0,1,0,0,0,0,1,0,0,0,0,1,1,0,0,0,1,0,1,1,0,0,1,0,1,0,0,1,0,1,1,1,0,0,1,0,1,1,1,0,0,0,0,1,0,0,0,1,1,1,0,0,1},{0,1,0,0,0,0,1,0,1,0,1,0,1,0,0,0,1,1,1,1,1,1,1,0,0,1,0,0,0,0,1,0,0,1,0,0,0,1,1,1,0,1,1,0,1,1,0,0,0,0,0,0,1,0,1,0,0,1,0,0,0,1,0,0,0,0,1,0,1,1,0,1,1,0,1,1,1,0,1,1,1,1,1,1,0,1,1,0,1,0,0},{1,1,1,1,0,0,0,0,1,1,0,1,0,1,1,1,1,0,1,0,1,1,1,0,0,0,0,1,1,0,1,0,0,1,1,1,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,0,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,0,1,0,0,0,1},{0,0,1,1,0,0,0,0,1,1,1,0,1,0,0,0,1,1,0,1,0,0,1,0,0,1,1,0,0,0,1,1,0,1,0,0,0,0,1,1,0,0,1,1,0,0,0,1,1,1,1,1,1,0,0,1,1,1,1,0,1,1,0,0,1,0,0,0,0,1,1,1,1,1,1,0,1,0,0,0,1,0,0,1,1,1,1,1,1,1,1},{1,0,0,1,0,0,1,0,1,0,0,1,0,0,1,0,0,1,1,1,0,1,1,1,0,0,1,1,1,0,1,1,0,1,1,0,1,1,0,0,1,1,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,1,0,1,0,1,0,0,0,1,0,0,0,1,1,0,1,0,0,1,1,1,0,1,1,0,1,1,0,1,1},{0,0,1,0,0,0,1,1,1,1,0,1,0,0,0,1,1,1,1,0,1,1,1,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,1,1,0,0,1,1,0,0,1,0,1,1,0,1,0,0,1,0,1,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,1,1,1,0,1,1,0,1,0,0},{0,0,1,0,0,1,0,0,1,0,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,0,0,0,1,1,1,0,1,0,1,0,1,0,1,0,0,1,1,1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,1,1,1,1,0,1,0,0,0,0,1,0,0,0,0,1,1,0,1,1,1,1,0,0},{0,1,1,0,1,1,0,1,1,0,1,1,0,0,0,0,0,1,1,0,0,1,1,0,1,0,1,1,1,1,1,1,1,0,0,1,1,0,0,0,1,1,0,1,0,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,0,0,1,0,0,0,0,1,0,1,0,1,0,0,0,0,1,1,1,0,1,1,1,0,0,1,0,0,0,1,1},{1,0,0,0,0,0,1,0,0,0,0,0,1,1,0,1,1,0,0,1,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,1,0,0,1,0,0,1,1,1,1,1,0,1,0,1,1,0,0,1,1,0,0,0,1,1,1,1,0,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,1,0,0,0,0,1,0,0,1,1,1,0,0},{0,1,0,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,0,0,1,0,1,0,0,0,0,0,1,0,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,1,0,1,0,0,1,0,0,0,1,0,1,1,0,0,1,1,0,0,0,0,0,0,1,0,0,0,1,0,1,1,0,0,1,0,0,0,0,0,1,0,1,0,0},{1,1,0,0,1,0,0,1,1,0,0,1,1,0,1,1,1,0,1,0,1,0,1,1,1,1,0,0,0,0,1,0,0,1,0,1,1,0,0,0,1,1,0,1,1,1,0,0,0,1,0,1,1,1,1,0,1,1,0,1,0,0,0,0,1,1,1,1,0,0,0,1,1,0,0,1,1,1,0,0,1,0,0,1,0,1,0,1,0,0,0},{1,1,0,1,0,0,1,0,0,0,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,0,1,0,1,1,1,1,0,0,0,0,0,0,0,1,0,0,0,1,0,1,1,0,0,0,1,0,1,0,0,1,0,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,0,1,0,1,1},{1,1,1,0,1,1,0,0,0,0,0,1,1,0,1,1,1,1,0,0,0,1,0,0,1,1,1,0,0,1,1,0,1,1,0,1,1,0,1,0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,1,1,0,0,0,0,1,0,0,0,1,0,1,1,1,1,0,1,0,1,1,1,0,1,0,1},{0,1,1,0,1,1,1,0,1,0,0,0,1,0,0,1,1,0,1,1,0,1,1,1,0,1,1,0,1,1,0,0,0,0,0,1,0,1,1,1,1,0,1,1,1,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,1,1,1,0,0,1,0,1,0,0,0,0,1,0,1,1,0,0,0,1,1,0,1,1,0,0},{0,0,0,1,0,1,1,0,1,0,1,0,0,1,0,1,1,1,0,0,1,0,1,0,0,1,0,1,1,1,0,1,0,0,0,0,1,0,0,1,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,0,1,1,0,1,0,1,0,1,0,1,0,1},{0,0,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0,1,0,0,0,0,1,1,0,0,1,0,0,1,1,1,1,0,1,1,1,0,0,1,0,0,0,1,0,0,1,0,0,1,1,0,0,1,0,0,1,1,0,1,0,0,1,1,1,1,1,0,0,1,0,1,1,0,0,0,0,0,1,1,0,1,1},{0,0,0,1,0,1,1,0,1,1,1,0,1,1,0,0,1,1,0,0,0,1,0,0,0,0,1,0,0,1,0,1,1,0,0,0,0,0,0,1,0,1,0,0,1,1,1,0,1,1,1,1,0,0,0,0,0,1,1,0,0,0,1,0,0,1,0,0,0,0,1,1,0,1,1,0,1,0,0,1,0,1,0,1,0,1,1,1,1,1,0},{0,0,0,0,0,1,1,1,0,1,1,0,0,0,0,1,1,1,1,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,1,1,1,0,1,0,1,0,1,1,0,0,0,1,1,1,0,1,0,1,1,1,1,0,1,1,1,1,0,1,1,0,1,0,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,0,1,1,0,1,0},{0,1,1,0,0,1,1,0,1,1,1,0,1,0,1,1,1,1,1,1,0,0,1,0,0,1,0,1,1,0,0,1,0,1,1,0,1,0,1,1,0,1,0,0,1,1,1,0,1,0,1,1,0,0,0,1,0,0,1,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,1,0,1,0,1,1,1,1,1,1,1,0,1,1,0},{0,1,0,0,1,1,1,0,0,1,0,1,1,0,0,1,1,0,1,1,1,0,1,1,0,1,1,0,1,0,0,1,0,0,0,0,0,1,0,1,0,1,0,0,1,0,1,0,0,0,1,0,0,0,1,1,0,1,0,0,1,1,1,1,0,0,0,0,0,1,0,1,0,1,1,1,1,1,1,0,1,1,0,1,1,1,0,1,0,0,0},{1,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0,1,0,0,1,0,0,1,1,0,1,0,1,1,1,1,0,1,0,0,0,1,0,1,0,0,1,0,1,1,1,0,1,0,0,1,0,0,0,0,1,1,1,1,1,0,0,1,0,1,1,1,1,0,1,0,0,0,0,0,0,1,1,1,1,1,0,0,0,1,1,0,1,0,1},{0,0,0,1,0,0,0,1,0,1,1,1,1,1,1,1,0,0,0,0,1,0,0,1,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,0,1,1,1,1,0,0,1,0,1,1,0,0,1,0,1,1,1,0,0,1,0,1,1,0,0,0,1,1,0,0,0,1,1,1,1,1,0,1,1,1,0,0,0,1,0,0,0,1,1,1},{1,0,1,1,1,1,1,0,1,1,0,1,0,1,1,0,0,1,0,1,1,0,1,1,1,1,0,1,1,1,1,0,0,0,0,1,0,1,1,0,1,0,1,0,0,0,0,1,1,1,1,1,1,0,0,0,1,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,1,1,0,0,1,1,0,0,0,1,0,0,0,0},{0,0,0,0,0,1,0,0,1,0,0,1,1,0,1,0,1,0,1,0,0,1,0,1,1,0,1,1,1,1,1,0,0,1,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,1,0,1,1,0,0,1,0,0,0,0,0,1,1,0,1,1,1,1,0,1,1,0,0,0,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0},{1,0,1,0,0,1,1,0,0,1,1,1,1,1,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,0,0,1,0,1,1,1,0,0,0,0,0,0,1,1,0,1,0,0,0,1,0,1,0,0,1,0,1,0,0,1,1,0,0,1,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,0,1,1,1},{0,0,0,0,1,0,1,1,0,1,0,0,0,0,0,0,1,1,0,1,0,0,0,0,1,1,0,1,1,0,1,1,0,1,1,0,0,1,1,0,0,1,0,1,1,0,0,0,0,1,1,1,0,0,0,1,0,0,0,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,0,1,0,0,1,1,0,0,1,1,1,0,1,0,1},{0,1,1,0,0,1,1,0,1,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,1,1,1,0,1,1,0,0,0,0,1,1,0,1,1,1,0,0,0,0,0,1,0,0,0,1,0,1,1,1,0,1,0,0,1,1,0,0,0,1,0,0,1,1,1,1,1,1,0,0,0},{1,1,0,0,0,1,0,0,0,1,0,0,1,1,0,1,0,0,1,1,0,0,0,0,0,1,0,1,0,1,1,0,0,0,1,0,1,0,0,0,1,0,0,1,1,0,0,1,0,0,1,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,0,1,0,0,1,0,1,1,0,0,1,1,0,0,0,0,0,1,0,0,0,1,1,1,1},{0,0,1,0,1,1,0,1,0,1,0,0,0,1,0,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,0,0,1,0,0,0,1,1,0,0,1,0,1,0,1,1,1,1,0,0,1,0,0,1,0,1,1,1,1,0,1,0,1,0,0,1,1,1,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1},{1,1,0,1,1,1,0,1,0,0,1,0,0,0,0,0,1,0,0,0,1,1,1,1,0,0,1,0,1,1,1,1,0,0,0,1,1,0,1,1,1,0,1,1,0,1,0,0,1,1,0,0,1,1,1,0,0,1,1,0,1,1,1,0,1,1,0,0,0,1,1,0,0,1,0,1,1,0,1,1,1,0,0,1,0,0,1,0,1,0,0},{0,0,0,1,0,1,1,1,0,1,0,1,1,0,0,1,1,0,1,1,1,1,1,0,0,0,0,0,1,1,0,1,0,1,1,1,0,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,1,1,1,0,1,1,0,0,0,1,1,0,0,1,0,1,1,1,1,1,0},{0,0,1,1,0,1,0,0,1,0,1,0,1,0,0,0,0,1,0,0,1,1,1,0,1,0,1,0,1,1,1,0,0,0,1,1,0,1,1,0,1,1,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,1,0,1,1,1,0,1,1,0,0,1,1,0,1,0,1,1,1,0,0,1,1,0,0,1,0,1,0,1,1,0},{0,0,0,0,0,1,1,0,0,0,1,1,1,0,0,1,0,0,1,0,1,1,0,1,0,1,1,0,0,0,0,1,1,1,0,1,0,0,1,1,1,0,0,1,1,1,0,1,0,1,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,1,0,0,1,0,0,1,0,1,0,0,1},{1,1,1,1,0,1,1,1,1,1,1,0,0,1,1,0,1,0,1,1,0,0,0,1,0,1,1,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,1,1,0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,0,0,0,0,1,0,0,0},{0,1,1,0,1,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,1,1,1,0,1,0,1,1,1,0,1,1,1,1,1,0,0,1,0,0,0,0,1,1,0,0,1,0,1,1,1,1,1,0,0,0,1,0,1,0,1,1,0,1,1,1,1,0,0,0,0,0,1,1,0,0,1,1,1,1,1,1,0,1,0,0,1,0,1},{0,0,1,0,1,0,1,1,0,0,1,0,1,0,1,1,0,1,0,0,1,1,1,0,0,0,0,0,1,1,1,1,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,1,0,1,0,0,1,0,0,0,0,0,0,1,1,0,0,1,1,1,0,1,1,0,1,0,0,1,0,0},{1,0,1,1,0,1,1,1,1,1,0,1,0,1,0,1,1,1,1,0,1,1,0,0,0,1,1,1,0,0,1,1,0,0,0,0,0,1,1,0,1,1,1,1,0,1,1,1,1,1,1,0,1,0,0,0,0,1,0,0,1,0,1,1,0,0,0,0,0,1,0,0,0,1,1,1,0,0,1,0,0,0,0,0,1,0,0,0,1,0,1},{0,0,0,1,0,0,0,1,0,0,1,0,0,1,1,1,1,1,1,1,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,0,1,1,0,0,0,0,0,1,0,1,0,0,1,0,1,0,0,0,1,1,1,1,1,0,0,1,0,1,0,1,0,0,1,0,1,1,0,1,1,1,1,0,0,1,0,1},{0,0,0,1,0,0,0,0,1,1,1,0,0,0,1,1,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,1,0,0,1,0,0,1,0,1,1,1,1,1,0,1,1,1,0,0,1,1,0,1,1,1,0,1,1,1,1,0,1,1,1,1,0,1,1,0,0,0,1,1,1,0,0,0,0,1,1,0,1,1,0,0,0,1,0,1,1},{1,0,0,0,0,0,1,1,1,0,1,0,1,1,1,0,1,1,0,0,0,0,1,1,1,0,0,0,0,1,1,1,1,0,1,0,0,1,0,1,0,1,0,1,1,1,0,0,0,1,0,1,1,0,0,0,1,0,1,0,1,0,1,0,0,0,1,1,1,0,1,0,0,0,0,1,1,0,0,0,1,0,0,1,0,1,0,1,1,1,1},{1,0,1,0,1,1,1,1,0,0,1,1,1,0,1,0,0,1,1,0,0,1,0,1,1,1,0,1,0,0,0,0,1,0,1,0,1,1,1,1,0,0,0,1,0,1,0,1,1,1,1,1,1,0,1,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,1,1,0,0,0,1,0,0,1,0,1,1,1,1,0,1,0,1,1},{0,0,0,0,0,1,0,0,1,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,1,1,1,0,1,0,0,1,1,1,0,1,1,1,0,0,1,1,1,1,0,1,1,0,0,0,1,1,0,1,0,0,0,1,1,0,1,0,0,1,1,1,1,1,0,0,0,1,1,1,0,1,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0},{0,0,1,0,1,0,1,1,1,1,0,0,1,1,0,1,0,0,1,1,1,0,1,1,1,1,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,1,0,0,0,1,0,0,0,1,0,1,1,1,1,0,1,0,1,0,1,1,1,0,0,1,0,1,1,0,1,1},{1,1,0,1,0,1,1,1,1,1,0,0,0,0,1,0,0,0,0,0,1,1,0,0,1,1,0,1,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,1,1,1,0,1,1,0,1,0,1,1,1,0,1,0,0,0,0,1,0,1,1,0,1,0,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1},{1,0,0,1,1,1,1,0,0,0,0,0,1,0,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,1,0,0,1,1,1,1,0,1,1,0,1,0,0,1,0,0,1,0,0,1,0,1,1,0,0,0,1,0,0,1,1,0,1,0,1,0,1,1,1,0,0,1,1,1,1,0,0,1,0,1,0,1,0,1},{0,0,1,0,1,0,1,0,0,0,1,0,0,1,1,0,0,1,1,0,1,1,0,1,0,0,1,1,0,0,1,0,1,1,0,1,0,0,1,1,1,1,0,0,1,0,0,1,0,1,1,0,0,0,1,0,1,1,1,1,0,0,1,0,0,0,0,0,1,0,1,1,0,0,0,0,0,1,0,0,1,1,0,1,1,1,0,1,0,0,1},{1,0,1,0,1,1,1,1,0,0,1,1,0,1,1,0,0,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,1,0,0,0,1,1,1,0,0,0,0,0,1,1,1,0,0,1,0,1,0,1,1,1,1,0,1,1,0,0,1,1,1,0,1,0,1,1,1,1,0,1,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0,1,0},{1,0,1,0,0,1,0,1,0,1,1,0,0,1,0,0,1,0,0,0,0,1,1,1,1,1,0,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,0,0,1,1,0,0,1,0,0,1,0,0,1,1,0,0,0,0,1,1,0,1,0,1,0,1,1,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,0,0,1,1,0,0},{0,1,1,1,1,0,0,0,0,1,1,0,0,0,0,0,0,1,0,1,0,0,1,1,1,1,1,0,1,1,0,1,1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,1,0,0,0,0,0,1,1,1,1,0,1,0,1,0,0,1,1,0,1,1,0,1,1,0,1,1,0,0,0,1,0,0,1,0},{0,1,0,0,0,1,1,0,1,0,0,0,1,1,1,0,1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,0,1,1,0,1,0,0,0,1,0,0,1,0,1,0,1,0,0,1,0,1,1,1,0,1,0,0,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1,1,1,0,0,1,1,0,1,0,0,0,1,1,0,1,1,1,1},{0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,0,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,1,0,0,1,0,1,1,1,1,1,1,0,1,1,0,0,0,0,1,0,1,1,1,1,1,1,0,1,0,0,1,0,1,0,0,0,0,1,0,0,1,1,1,0,0,0,1,1,0,0,1,0,0,1,1,0,1,0,0,1},{0,1,1,1,1,0,0,0,0,0,1,0,0,1,0,0,0,1,1,1,1,0,1,1,0,1,0,1,1,1,0,1,0,0,0,1,0,0,0,0,1,0,1,1,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,1,0,0,1,1,1,1,1,1,1,0,1,1,0,0,1,1,0,1,1,0,0,0,0,0,0,1,0,1,1,0},{1,1,1,1,1,0,0,1,1,0,1,0,0,1,1,1,0,0,0,0,0,1,1,1,1,0,0,1,1,1,1,1,0,1,1,1,0,0,1,1,0,0,1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,1,0,1,1,0,0,1,1,1,1,0,1,1,0,0,0,0,1,1,1,0,0,0,0,0,1,0,1,0,1,1,0,0,0},{0,1,0,1,0,1,1,1,0,0,0,1,1,1,0,0,0,1,0,0,1,0,0,0,1,1,1,0,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,1,0,1,0,0,0,0,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1,0,1,0,0,1,0,0,1,1,1,0,1,0,1,0,1,1,1,0,0,1,1},{0,1,1,0,1,0,0,0,1,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,1,1,0,0,0,0,1,1,1,0,1,0,1,0,0,1,0,1,1,1,1,0,0,1,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,1,1,0,1,1,1,1,0,0,0,1,1,1,1,0,1,0,0,1},{0,0,1,0,1,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,1,1,0,0,1,1,0,1,0,1,1,1,0,0,0,0,1,1,0,1,0,1,1,1,1,1,1,1,1,0,0,1,0,1,1,0,1,1,1,0,0,0,1,1,0,0,1,0,1,1,1,1,0,1,1,0,1,0,1,1,0,1,0,0,1,1,0,0,1,1,0},{0,1,1,1,1,1,1,0,1,0,0,1,0,0,1,1,0,0,0,0,1,1,0,1,1,1,0,1,1,0,0,1,1,1,1,1,0,1,1,1,0,1,0,0,1,0,0,1,0,1,1,0,1,0,0,1,0,1,1,0,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,0,0,1,0,0,0,1,0,0,0,0,0,0,1,1},{1,1,0,0,0,1,1,1,1,1,0,0,0,0,1,0,0,1,1,1,0,0,0,1,1,0,0,1,0,0,1,1,0,1,1,0,0,0,0,0,1,1,1,0,1,1,0,1,0,0,0,1,0,1,1,1,1,0,0,0,0,1,0,1,1,0,1,1,1,1,1,0,0,0,0,0,0,1,1,0,1,1,1,0,1,1,0,0,0,0,1},{0,0,0,0,1,1,0,0,0,1,1,0,0,0,1,1,0,0,1,1,0,1,1,0,0,0,1,0,1,1,1,0,1,1,1,1,0,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1,1,0,0,1,0,0,0,1,0,1,1,0,1,0,1,1,1,0,0,0,0,0,0,0,0,1,0,1,1,1,0,0,0,1,1,0,0,1},{1,1,0,1,1,0,0,0,1,1,0,1,1,1,0,1,0,1,0,0,0,1,1,0,0,1,1,1,1,1,0,0,0,1,1,0,0,1,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,1,0,1,0,0,1,0,0,1,0,1,0,0,0,1,0,0,0,0,1,0,1,1,1},{0,0,1,0,0,1,1,1,1,1,0,1,1,1,0,0,0,0,1,1,0,1,1,0,0,1,1,0,1,1,0,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,0,1,1,1,0,1,1,1,0,0,1,1,0,1,1,1,0,1,0,1,0,0,1,0,1,1,1,1,0,0,0,0,0,1,0,0,1,1,1},{0,1,0,1,0,0,1,0,0,1,0,0,1,1,1,0,1,1,0,0,1,1,1,0,0,1,1,0,0,1,0,0,1,0,1,1,1,1,0,0,1,1,1,0,1,1,0,0,0,1,0,0,1,1,1,0,1,0,1,1,1,1,0,1,0,1,0,1,0,1,0,0,0,1,1,1,0,1,1,0,1,0,0,0,0,1,1,1,0,0,0},{1,0,0,1,0,1,0,1,1,1,0,1,1,0,1,1,0,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,0,1,1,0,0,0,0,1,0,1,1,1,0,0,0,0,1,0,1,1,1,0,0,1,1,0,0,1,1,1,0,1,1,0,1,0,0,1,1,1,0,0,1,1,1,1,1,0,0,0,1,1,0,1,1,0,0},{1,1,1,1,0,0,1,0,0,0,0,0,1,1,0,1,1,0,1,0,0,0,1,0,0,1,1,0,0,1,0,1,0,1,1,0,1,1,1,1,1,1,1,0,1,1,0,0,0,1,1,0,0,1,1,0,0,1,0,0,0,0,0,1,1,0,1,0,0,0,0,0,1,0,0,0,1,1,1,0,0,1,0,0,0,1,1,1,0,0,0},{1,1,0,1,1,0,1,0,0,0,1,0,1,1,1,1,1,1,1,0,0,0,1,0,0,0,0,0,0,1,0,1,1,0,0,0,1,1,0,1,0,1,0,1,1,1,1,0,0,1,1,0,1,1,1,1,0,1,1,0,0,0,1,0,0,1,1,0,0,0,1,1,1,1,0,0,1,1,1,1,0,1,0,1,0,1,0,1,1,0,0},{1,0,1,0,0,0,0,1,1,0,0,1,0,1,0,0,1,1,0,1,0,0,0,1,0,1,0,1,1,0,0,0,0,1,1,1,0,1,1,0,0,1,0,0,1,1,1,1,1,0,1,0,0,1,1,0,0,1,1,1,0,0,0,1,1,0,0,1,1,1,1,0,0,0,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,0,1},{1,0,0,1,1,1,0,1,1,1,0,0,0,1,1,0,1,0,0,1,1,0,1,0,1,0,1,0,0,0,1,1,1,0,1,1,1,0,1,0,0,0,0,0,0,1,0,1,1,0,1,1,0,0,0,0,0,1,1,0,1,0,0,0,1,1,0,1,0,0,1,0,0,1,1,1,0,1,1,0,1,0,0,0,1,0,0,0,0,1,1},{1,1,0,1,0,1,1,0,0,1,1,0,1,0,0,1,0,0,1,0,1,1,0,1,0,1,0,0,1,0,1,0,0,1,0,1,0,1,0,0,1,1,0,1,0,1,1,0,1,0,1,0,1,1,0,1,1,1,0,0,0,1,0,1,1,0,0,0,1,1,1,1,0,1,0,0,1,1,1,1,0,0,1,0,1,0,0,0,1,0,1},{0,0,1,0,0,0,1,1,0,1,1,0,1,0,0,0,0,0,0,1,0,1,0,1,0,0,0,1,1,0,0,0,0,0,0,0,1,0,0,1,0,0,1,1,1,0,0,0,1,0,0,0,0,0,0,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1,0,0,1,1,1,0,0,1,1,0,0,0,0,1},{1,0,1,1,0,0,0,1,1,0,1,0,1,1,1,0,0,0,1,1,1,0,1,1,1,0,1,1,0,1,1,1,1,0,0,1,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,1,0,1,1,0,1,0,1,1,1,1,1,1,0,1,1,0,0,0,1,0,0,0,0,1,0,1,1,0,0,0,1},{0,0,1,0,0,1,1,1,1,1,0,1,1,0,0,1,0,0,0,0,0,1,0,1,0,1,1,0,0,1,0,0,0,0,1,0,0,0,0,0,1,1,1,1,1,0,1,0,0,1,0,1,0,0,0,0,1,0,1,1,1,1,0,1,1,0,0,0,1,0,0,0,1,0,0,1,1,1,0,1,0,1,0,1,1,0,0,0,0,1,1},{1,0,1,1,0,0,1,0,1,1,1,0,0,0,0,1,0,1,0,0,1,1,1,0,0,1,0,1,0,0,1,1,1,1,1,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,1,1,1,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,1,0,0,0,0,0,1,0,0,1,0,1,1,1,1,0,1,0}};
    int row = grid.size();
    int col = grid[0].size();

    Solution sol;
    cout << sol.largestIsland(grid) << endl;

    return 0;
}
