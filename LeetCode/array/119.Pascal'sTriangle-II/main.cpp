#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> result;

        for (int i = 0; i < rowIndex + 1; i++) {

            vector<int> resultRow(i + 1, 1);
            for (int j = 0; j < i + 1; j++) {
                if (j == 0 || j == i) {
                    continue;
                }
                resultRow[j] = result[i - 1][j - 1] + result[i - 1][j];
            }
            result.push_back(resultRow);
        }

        return result[rowIndex];
    }
};

int main()
{
    Solution sol;
    vector<int> rowResult = sol.getRow(1);
    for (int i = 0; i < rowResult.size(); i++) {
        cout << rowResult[i] << " ";
    }
    cout << endl;

    return 0;
}
