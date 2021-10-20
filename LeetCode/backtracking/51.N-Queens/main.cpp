#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {

        vector<string> chessboard(n, string(n, '.'));   //棋盘的一种放置方法, 相当于以前的path
        backtracking(n, 0, chessboard);
        return result;
    }

private:
    vector<vector<string>> result;

    void backtracking(int n, int row, vector<string>& chessboard) {

        if (row == n) {
            result.push_back(chessboard);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isValid(n, row, col, chessboard) == false) {
                continue;
            }

            chessboard[row][col] = 'Q';
            backtracking(n, row + 1, chessboard);
            //回溯
            chessboard[row][col] = '.';
        }
    }

    //在n维棋盘chessboard的当前(row, col)位置放置一个皇后, 是否合法
    bool isValid(int n, int row, int col, vector<string>& chessboard) {

        //检查行
//        for (int i = 0; i < col; i++) {
//            if (chessboard[row][i] == 'Q') {
//                return false;
//            }
//        }

        //检查列
        for (int i = 0; i < row; i++) {
            if (chessboard[i][col] == 'Q') {
                return false;
            }
        }

        //检查45度是否有皇后
        for (int i = row - 1, j = col - 1; i >=0 && j >= 0; i--, j--) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        //检查135度是否有皇后
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution sol;
    vector<vector<string>> result = sol.solveNQueens(4);

    for (unsigned int i = 0; i < result.size(); i++) {
        for (unsigned int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
