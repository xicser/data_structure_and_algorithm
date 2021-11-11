#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

        rowCnt = board.size();
        colCnt = board[0].size();

        //表示某个位置是否被访问过
        vector< vector<bool> > visit(rowCnt, vector<bool>(colCnt, false) );

        //从各个位置开始搜索
        for (int i = 0; i < rowCnt; i++) {
            for (int j = 0; j < colCnt; j++) {
                if (dfs(board, visit, i, j, word, 0) == true) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    int rowCnt;
    int colCnt;

    bool dfs(vector<vector<char>>& board, vector< vector<bool> >& visit,
             int x, int y,
             string &word, int pos)
    {
        //范围超出棋盘边界了, 或者已经被访问过了
        if (x < 0 || y < 0 || x >= rowCnt || y >= colCnt || visit[x][y] == true) {
            return false;
        }

        if (board[x][y] != word[pos]) {
            return false;
        }

        if (pos == word.size() - 1) {
            return true;
        }

        //记录已经被访问
        visit[x][y] = true;

        bool result = dfs(board, visit, x - 1, y, word, pos + 1) ||   //上
               dfs(board, visit, x + 1, y, word, pos + 1) ||   //下
               dfs(board, visit, x, y - 1, word, pos + 1) ||   //左
               dfs(board, visit, x, y + 1, word, pos + 1);     //右

        //回溯
        visit[x][y] = false;

        return result;
    }
};

int main()
{
    Solution sol;
    vector<vector<char>> board = {  {'A','A','A','A','A','A'},
                                    {'A','A','A','A','A','A'},
                                    {'A','A','A','A','A','A'},
                                    {'A','A','A','A','A','A'},
                                    {'A','A','A','A','A','A'},
                                    {'A','A','A','A','A','A'}};
    string word = "AAAAAAAAAAAAAAB";

    cout << sol.exist(board, word) << endl;
    return 0;
}
