#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        this->pathSum = 0;
        backtracking(k, n, 1);
        return result;
    }

private:
    void backtracking(int k, int n, int index) {

        //这个if控制树的深度
        if (path.size() == k) {
            if (pathSum == n) {
                result.push_back(path);
                return;
            }
            else {
                return;
            }
        }

        //for (int i = index; i <= 9; i++) {
        for (int i = index; i <= 9 && pathSum + i <= n; i++) {   //剪枝优化

            pathSum += i;
            path.push_back(i);
            backtracking(k, n, i + 1);

            //回溯
            pathSum -= i;
            path.pop_back();
        }
    }

    vector<vector<int>> result;
    vector<int> path;
    int pathSum;
};

int main()
{
    Solution sol;

    vector<vector<int>> result = sol.combinationSum3(9, 45);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
