#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;

        int left = 0;
        int top = 0;
        int right = matrix[0].size() - 1;
        int bottom = matrix.size() - 1;
        while (left <= right && top <= bottom) {

            printRound(result, matrix, left, top, right, bottom);
            left++;
            top++;
            bottom--;
            right--;
        }

        return result;
    }

    void printRound(vector<int> &result, vector<vector<int>>& matrix, int left, int top, int right, int bottom) {
        if (top == bottom) {
            for (int i = left; i <= right; i++) {
                result.push_back(matrix[top][i]);
            }
            return;
        }
        if (left == right) {
            for (int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][left]);
            }
            return;
        }

        for (int i = left; i < right; i++) {
            result.push_back(matrix[top][i]);
        }

        for (int i = top; i < bottom; i++) {
            result.push_back(matrix[i][right]);
        }

        for (int i = right; i > left; i--) {
            result.push_back(matrix[bottom][i]);
        }

        for (int i = bottom; i > top; i--) {
            result.push_back(matrix[i][left]);
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
