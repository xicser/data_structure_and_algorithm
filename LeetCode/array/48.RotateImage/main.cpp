#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        //先关于主对角线对称
        int top = 0, left = 0, right = matrix.size() - 1, bottom = right;
        while (top < bottom) {
            flipMainDiagonal(top, left, right, bottom, matrix);

            left++;
            right--;
            top++;
            bottom--;
        }

        //再左右反转
        int colLeft = 0, colRight = matrix.size() - 1;
        while (colLeft < colRight) {
            flipLeftRight(colLeft, colRight, matrix);

            colLeft++;
            colRight--;
        }
    }

    //关于主对角线对称
    void flipMainDiagonal(int top, int left, int right, int bottom, vector<vector<int>>& matrix) {

        for (int i = left + 1, j = top + 1; i <= right; i++, j++) {
            swap(matrix[top][i], matrix[j][left]);
        }

        for (int i = top + 1, j = left + 1; i < bottom; i++, j++) {
            swap(matrix[i][right], matrix[bottom][j]);
        }
    }

    //左右反转
    void flipLeftRight(int colLeft, int colRight, vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            swap(matrix[i][colLeft], matrix[i][colRight]);
        }
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 2},
                                  {3, 4}};
    Solution sol;
    sol.rotate(matrix);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
