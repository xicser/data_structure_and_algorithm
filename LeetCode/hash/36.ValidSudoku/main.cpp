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

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {

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
                int boxIndex = getBoxIndex(i, j);
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

    //根据行列索引索引计算box索引
    int getBoxIndex(int row, int col) {

        if (0 <= row && row <= 2) {
            if (0 <= col && col <= 2) {
                return 0;
            }
            else if (3 <= col && col <= 5) {
                return 1;
            }
            else {
                return 2;
            }
        }
        else if (3 <= row && row <= 5) {
            if (0 <= col && col <= 2) {
                return 3;
            }
            else if (3 <= col && col <= 5) {
                return 4;
            }
            else {
                return 5;
            }
        }
        else {
            if (0 <= col && col <= 2) {
                return 6;
            }
            else if (3 <= col && col <= 5) {
                return 7;
            }
            else {
                return 8;
            }
        }
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
