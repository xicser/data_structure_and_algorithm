#include <iostream>
#include <vector>
#include <stdio.h>
#include <unordered_set>
#include <set>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {

        int row = board.size();
        int col = board[0].size();

        //对边界所有的'O', 进行dfs, 把所有dfs可以搜索到的置为'A'
        for (int i = 0; i < col; i++) {
            //第一行
            if (board[0][i] == 'O') {
                dfs(board, 0, i);
            }

            //最后一行
            if (board[row - 1][i] == 'O') {
                dfs(board, row - 1, i);
            }
        }
        for (int i = 1; i < row - 1; i++) {
            //第一列
            if (board[i][0] == 'O') {
                dfs(board, i, 0);
            }

            //最后一列
            if (board[i][col - 1] == 'O') {
                dfs(board, i, col - 1);
            }
        }

        //最后把整个矩阵不是'A'的变为'X'
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int row, int col) {

        //超范围了
        if (isInArea(board, row, col) == false) {
            return;
        }

        if (board[row][col] == 'X' || board[row][col] == 'A') {
            return;
        }

        board[row][col] = 'A';

        dfs(board, row - 1, col);
        dfs(board, row + 1, col);
        dfs(board, row, col - 1);
        dfs(board, row, col + 1);
    }

    bool isInArea(vector<vector<char>>& board, int row, int col) {

        if (0 <= row && row < board.size() &&
            0 <= col & col < board[0].size()) {
            return true;
        }
        return false;
    }

    void print(vector<vector<char>>& board) {

        int row = board.size();
        int col = board[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
};

int main()
{
    vector< vector<char> > board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    Solution sol;

    sol.print(board);
    sol.solve(board);
    sol.print(board);

    return 0;
}
