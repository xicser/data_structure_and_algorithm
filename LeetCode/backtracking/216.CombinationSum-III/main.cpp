#include <iostream>
#include <vector>

using namespace std;

//1 2 3 4 5 6 7 8 9
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        this->pathSum = 0;
        backtracking(k, n, 1);
        return result;
    }

private:
    void backtracking(int k, int n, int index) {

        if (path.size() == k) {
            if (pathSum == n) {
                result.push_back(path);
            }
            return;
        }

        for (int i = index; i <= 9 && pathSum + i <= n; i++) {

            path.push_back(i);
            pathSum += i;

            backtracking(k, n, i + 1);

            path.pop_back();
            pathSum -= i;
        }
    }

    vector<vector<int>> result;
    vector<int> path;
    int pathSum;
};

int main()
{
    Solution sol;

    vector<vector<int>> result = sol.combinationSum3(3, 9);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
