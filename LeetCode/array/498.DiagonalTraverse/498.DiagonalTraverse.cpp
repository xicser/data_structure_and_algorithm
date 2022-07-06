#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:

    bool direction = true;  // == true 表示从左下角向右上角遍历
    int index = 0;

    // 从左下角向右上角遍历
    void printLine_mode1(vector<vector<int>>& mat, vector<int>& result, int left, int bottom, int right, int top) {

        while (left <= right) {

            result[index++] = mat[bottom][left];

            left++;
            bottom--;
        }
    }

    // 从右上角向左下角遍历
    void printLine_mode2(vector<vector<int>>& mat, vector<int>& result, int right, int top, int left, int bottom) {

        while (right >= left) {

            result[index++] = mat[top][right];

            right--;
            top++;
        }
    }

public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

        int rowCnt = mat.size();
        int colCnt = mat[0].size();
        vector<int> result(rowCnt * colCnt);

        int start = 0;
        for (; start < rowCnt; start++) {
            if (direction == true) {
                printLine_mode1(mat, result, 0, start, start, 0);
                direction = false;
            }
            else {
                printLine_mode2(mat, result, start, 0, 0, start);
                direction = true;
            }
        }

        int left = 1, bottom = rowCnt - 1;
        int right = start, top = 0;
        for (int i = right; i < colCnt; i++) {
            if (direction == true) {
                printLine_mode1(mat, result, left, bottom, right, top);
                direction = false;
            }
            else {
                printLine_mode2(mat, result, right, top, left, bottom);
                direction = true;
            }
        }

        right = colCnt - 1;
        top = 1;
        bottom = 0;
        for (int i = left; i < colCnt; i++) {
            if (direction == true) {
                printLine_mode1(mat, result, left, bottom, right, top);
                direction = false;
            }
            else {
                printLine_mode2(mat, result, right, top, left, bottom);
                direction = true;
            }
        }

        return result;
    }
};

int main()
{
    vector<vector<int>> mat = { {1,2,3}, {4,5,6}, {7,8,9}};
    Solution sol;
    vector<int> result = sol.findDiagonalOrder(mat);
    
    for (int i : result) {
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}

