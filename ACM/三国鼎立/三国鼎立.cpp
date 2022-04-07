#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    int n, m;
    vector< vector<char> > board;

    void printBoard() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

public:
    void getInput() {
        cin >> n >> m;
        vector< vector<char> > board(n, vector<char>(m));

        getchar();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char c = getchar();

                board[i][j] = c;
            }
            getchar();
        }

        this->board = board;
    }

    void solve() {

        int cnt = 0;
        for (int i = 0; i < this->n; i++) {
            for (int j = 0; j < this->m; j++) {
                if (board[i][j] != 'Q') {
                    cnt++;
                    dfs(i, j, board, board[i][j]);
                }
            }
        }

        cout << cnt << endl;
    }

    void dfs(int x, int y, vector< vector<char> >& board, char c) {

        if (isInArea(x, y) == false) {
            return;
        }

        if (board[x][y] == 'Q') {
            return;
        }

        if (board[x][y] != c) {
            return;
        }

        if (board[x][y] == c) {
            board[x][y] = 'Q';
        }

        dfs(x - 1, y, board, c);
        dfs(x + 1, y, board, c);
        dfs(x, y - 1, board, c);
        dfs(x, y + 1, board, c);
    }

    //判断当前位置是否在board里
    bool isInArea(int x, int y) {

        if (x < 0 || y < 0 || x >= n || y >= m) {
            return false;
        }

        return true;
    }
};

int main()
{
    Solution sol;

    sol.getInput();
    sol.solve();

}
