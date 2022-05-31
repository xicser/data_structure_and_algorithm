#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {

        vector<vector<bool> > visit(board.size(), vector<bool>(board[0].size(), false));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                bool ret = dfs(board, i, j, visit, word, 0);
                if (ret == true) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    bool dfs(vector<vector<char> >& board, int x, int y, vector<vector<bool> >& visit, const string& word, int index) {

        if (inArea(board, x, y) == false) {
            return false;
        }
        
        if (visit[x][y] == true) {
            return false;
        }

        if (board[x][y] == word[index] && index == word.size() - 1) {
            return true;
        }

        if (board[x][y] != word[index]) {
            return false;
        }

        visit[x][y] = true;

        bool result = dfs(board, x - 1, y, visit, word, index + 1) ||
               dfs(board, x + 1, y, visit, word, index + 1) ||
               dfs(board, x, y - 1, visit, word, index + 1) ||
               dfs(board, x, y + 1, visit, word, index + 1);
        
        visit[x][y] = false;

        return result;
    }

    bool inArea(vector<vector<char> >& board, int x, int y) {

        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) {
            return false;
        }

        return true;
    }
};


int main()
{
    vector<vector<char> > board = {
        {'X', 'Y', 'Z', 'E'},
        {'S', 'F', 'Z', 'S'},
        {'X', 'D', 'E', 'E'},
    };

    Solution sol;
    
    std::cout << sol.exist(board, "XYZZED") << endl;
    std::cout << sol.exist(board, "SEE") << endl;
    std::cout << sol.exist(board, "XYZY") << endl;
}
