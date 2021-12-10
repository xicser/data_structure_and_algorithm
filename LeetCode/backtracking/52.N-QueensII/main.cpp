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

            //�ռ����
            result++;
            return;
        }

        //ÿһ����, ��ÿ���е�λ�÷Żʺ�
        for (int i = 0; i < this->edge; i++) {

            //�ȼ���ܲ��ܷ�
            if (isValid(row, i, chessboard) == false) {
                continue; //��֦
            }

            chessboard[row][i] = 'Q';

            backtracking(chessboard, row + 1);

            chessboard[row][i] = '.';
        }
    }
    //��nά����chessboard�ĵ�ǰ(row, col)λ�÷���һ���ʺ�, �Ƿ�Ϸ�
    bool isValid(int row, int col, vector<string>& chessboard) {

        //�в��ü��, ��Ϊһ��һ������, ���ұ����ݵ���

        //�����
        for (int i = 0; i < row; i++) {
            if (chessboard[i][col] == 'Q') {
                return false;
            }
        }

        //�������
        for (int i = row - 1, j = col + 1; i >= 0 && j < this->edge; i--, j++) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }

        //�������
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
