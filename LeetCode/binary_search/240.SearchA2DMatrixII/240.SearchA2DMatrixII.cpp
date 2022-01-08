#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    bool searchRow(vector<int>& row, int target) {

        int left = 0, right = row.size() - 1;
        int mid = 0;
        while (left <= right) {

            mid = (left + right) / 2;
            
            if (row[mid] == target) {
                return true;
            }
            else if (row[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] > target) {
                continue;
            }
            if (searchRow(matrix[i], target) == true) {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
