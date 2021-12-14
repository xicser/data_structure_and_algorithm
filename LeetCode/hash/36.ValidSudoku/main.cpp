#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int row = board.size();
        int col = board[0].size();
        vector< unordered_set<char> > rowSet(9);
        vector< unordered_set<char> > colSet(9);
        vector< unordered_set<char> > boxSet(9);

        int globalIndex = -1;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {

                globalIndex++;
                char value = board[i][j];
                if (value == '.') {
                    continue;
                }

                //判断同一行有没有出现过
                if (rowSet[i].find(value) == rowSet[i].end()) {
                    rowSet[i].insert(value);
                }
                else {
                    return false;
                }

                //列
                if (colSet[j].find(value) == colSet[j].end()) {
                    colSet[j].insert(value);
                }
                else {
                    return false;
                }

                //块
                int boxIndex = getBoxIndex(globalIndex);
                if (boxSet[boxIndex].find(value) == boxSet[boxIndex].end()) {
                    boxSet[boxIndex].insert(value);
                }
                else {
                    return false;
                }
            }
        }

        return true;
    }

    //根据全局索引计算box索引
    int getBoxIndex(int globalIndex) {

        //先计算行索引
        int boxRowIndex = globalIndex / 27;

        //再计算列索引
        int rowIndex = globalIndex / 9;
        int colIndex = (globalIndex - rowIndex * 9) / 3;

        return boxRowIndex * 3 + colIndex;
    }
};

int main()
{
    vector<vector<char>> board =
        {{'5','3','.','.','7','.','.','.','.'}
        ,{'6','.','.','1','9','5','.','.','.'}
        ,{'.','9','8','.','.','.','.','6','.'}
        ,{'8','.','.','.','6','.','.','.','3'}
        ,{'4','.','.','8','.','3','.','.','1'}
        ,{'7','.','.','.','2','.','.','.','6'}
        ,{'.','6','.','.','.','.','2','8','.'}
        ,{'.','.','.','4','1','9','.','.','5'}
        ,{'.','.','.','.','8','.','.','7','9'}};
    Solution sol;

    cout << sol.isValidSudoku(board) << endl;

    return 0;
}
