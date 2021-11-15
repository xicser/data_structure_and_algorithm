#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int row = matrix.size();
        int col = matrix[0].size();

        vector<bool> zeroRows(row, false);
        vector<bool> zeroCols(col, false);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 0) {
                    zeroRows[i] = true;
                    zeroCols[j] = true;
                }
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {

                if (zeroRows[i] == true) {
                    matrix[i][j] = 0;
                }
                if (zeroCols[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
