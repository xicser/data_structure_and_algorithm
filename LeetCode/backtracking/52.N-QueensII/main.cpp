#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {

        this->result = 0;
        this->edge = n;
        vector<string> chessboard(n, string(n, '.'));
        backtracking(chessboard, 0);

        return this->result;
    }

private:
    int edge;
    int result;

    void backtracking(vector<string>& chessboard, int row) {

        if (row == this->edge) {

            //收集结果
            result++;
            return;
        }

        //每一行中, 给每个列的位置放皇后
        for (int i = 0; i < this->edge; i++) {

            //先检查能不能放
            if (isValid(row, i, chessboard) == false) {
                continue; //剪枝
            }

            chessboard[row][i] = 'Q';

            backtracking(chessboard, row + 1);

            chessboard[row][i] = '.';
        }
    }
    //在n维棋盘chessboard的当前(row, col)位置放置一个皇后, 是否合法
    bool isValid(int row, int col, vector<string>& chessboard) {

        //行不用检查, 因为一层一层向下, 并且被回溯掉了

        //检查列
        for (int i = 0; i < row; i++) {
            if (chessboard[i][col] == 'Q') {
                return false;
            }
        }

        //检查右上
        for (int i = row - 1, j = col + 1; i >= 0 && j < this->edge; i--, j++) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }

        //检查左上
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
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

    cout << sol.totalNQueens(1) << endl;
    return 0;
}
