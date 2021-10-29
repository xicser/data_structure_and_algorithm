#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        cnt = 1;
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        int left = 0, top = 0, right = n - 1, bottom = n - 1;

        while (left <= right) {
            storeEdge(matrix, left, top, right, bottom);
            left++;
            top++;
            right--;
            bottom--;
        }

        if (n % 2 != 0) {
            matrix[n / 2][n / 2] = cnt;
        }

        return matrix;
    }
private:
    void storeEdge(vector<vector<int>> &matrix, int left, int top, int right, int bottom) {

        //->
        for (int i = left; i < right; i++) {
            matrix[top][i] = cnt;
            cnt++;
        }

        //об
        for (int i = top; i < bottom; i++) {
            matrix[i][right] = cnt;
            cnt++;
        }

        //<-
        for (int i = right; i > left; i--) {
            matrix[bottom][i] = cnt;
            cnt++;
        }

        //ио
        for (int i = bottom; i > top; i--) {
            matrix[i][left] = cnt;
            cnt++;
        }
    }

    static int cnt;
};
int Solution::cnt;

int main()
{
    Solution sol;
    int n = 19;

    vector<vector<int>> result = sol.generateMatrix(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
