#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

        index = 0;
        this->word = word;
        hasFound = false;
        rowCnt = board.size();
        colCnt = board[0].size();

        //表示某个位置是否被访问过
        vector< vector<bool> > visit(rowCnt, vector<bool>(colCnt, false) );

        //搜索各个位置
        for (int i = 0; i < rowCnt; i++) {
            if (hasFound == true) {
                break;
            }

            for (int j = 0; j < colCnt; j++) {

                if (hasFound == true) {
                    break;
                }

                if (word[index] != board[i][j]) {
                    continue;
                }

                index++;
                path.push_back(board[i][j]);
                visit[i][j] = true;
                backTracking(i, j, board, visit);
                path.pop_back();
                visit[i][j] = false;
                index--;

                if (hasFound == true) {
                    break;
                }
            }

            if (hasFound == true) {
                break;
            }
        }

        return hasFound;
    }

private:
    string word;
    int rowCnt;
    int colCnt;
    bool hasFound;
    string path;
    int index;

    void backTracking(int nowRow, int nowCol,
                      vector<vector<char>>& board,
                      vector< vector<bool> >& visit) {

        if (hasFound == true) {
            return;
        }
        if (path.size() == word.size()) {
            if (path == word) {
                hasFound = true;
            }
            return;
        }

        //根据当前位置, 获取下一跳能够到达的所有位置
        vector< vector<int> > nextPos = getNext(nowRow, nowCol, visit);
        for (unsigned int i = 0; i < nextPos.size(); i++) {

            if (hasFound == true) {
                return;
            }

            vector<int> pos = nextPos[i];
            int x = pos[0];
            int y = pos[1];

            if (word[index] != board[x][y]) {
                continue;
            }

            index++;
            visit[x][y] = true;
            path.push_back(board[ x ][ y ]);

            backTracking(x, y, board, visit);

            if (hasFound == true) {
                return;
            }

            index--;
            visit[x][y] = false;
            path.pop_back();
        }
    }

    //根据当前位置, 获取下一跳能够到达的位置
    vector< vector<int> > getNext(int row, int col, vector< vector<bool> >& visit) {

        vector< vector<int> > nextPos;

        if (row - 1 >= 0 && visit[row - 1][col] == false) {
            nextPos.push_back({row - 1, col});
        }
        if (row + 1 <= rowCnt - 1 && visit[row + 1][col] == false) {
            nextPos.push_back({row + 1, col});
        }
        if (col - 1 >= 0 && visit[row][col - 1] == false) {
            nextPos.push_back({row, col - 1});
        }
        if (col + 1 <= colCnt - 1 && visit[row][col + 1] == false) {
            nextPos.push_back({row, col + 1});
        }
        return nextPos;
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
