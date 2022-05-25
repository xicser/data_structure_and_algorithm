#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

        vector<vector<bool>> isVisited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                bool ret = dfs(board, isVisited, i, j, word, 0);
                if (ret == true) {
                    return true;
                }
            }
        }

        return false;
    }

    bool dfs(const vector<vector<char>>& board, vector<vector<bool>>& isVisited, int x, int y, const string& word, int index) {
        if (inArea(board, x, y) == false) {
            return false;
        }

        if (isVisited[x][y] == true) {
            return false;
        }

        if (word[index] != board[x][y]) {
            return false;
        }

        if (index == word.size() - 1) {
            return true;
        }

        isVisited[x][y] = true;

        bool ret = dfs(board, isVisited, x - 1, y, word, index + 1) ||
            dfs(board, isVisited, x + 1, y, word, index + 1) ||
            dfs(board, isVisited, x, y - 1, word, index + 1) ||
            dfs(board, isVisited, x, y + 1, word, index + 1);

        isVisited[x][y] = false;

        return ret;
    }

    bool inArea(const vector<vector<char>>& board, int row, int col) {

        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size()) {
            return false;
        }

        return true;
    }
};

int main()
{
    Solution sol;
    sol.exist();
}
