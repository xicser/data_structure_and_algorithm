#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int right = matrix.size() * matrix[0].size() - 1;
        int mid;
        int rowCnt = matrix.size();
        int colCnt = matrix[0].size();

        while (left <= right) {
            mid = (left + right) / 2;
            int midVal = matrix[mid / colCnt][mid % colCnt];
            if (midVal == target) {
                return true;
            }
            else if (midVal > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return false;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout << sol.searchMatrix(matrix, 13) << endl;

    return 0;
}
