#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//candidates = [2,3,6,7], target = 7
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        this->pathSum = 0;
        this->target = target;

        backtracking(candidates, 0);

        return result;
    }

private:
    void backtracking(vector<int>& candidates, int index) {

        if (pathSum > this->target) {
            return;
        }
        if (pathSum == this->target) {
            result.push_back(path);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            pathSum += candidates[i];
            path.push_back(candidates[i]);

            backtracking(candidates, i);

            path.pop_back();
            pathSum -= candidates[i];
        }
    }

    vector<int> path;
    int pathSum;
    int target;
    vector<vector<int>> result;
};

int main()
{
    Solution sol;
    vector<int> candidates1 = {2,3,6,7};
//    vector<int> candidates2 = {2,3,5};
//    vector<int> candidates3 = {2};
//    vector<int> candidates4 = {1};
//    vector<int> candidates5 = {1};

    vector<vector<int>> result1 = sol.combinationSum(candidates1, 7);
    for (unsigned int i = 0 ; i < result1.size(); i++) {
        for (unsigned int j = 0; j < result1[i].size(); j++) {
            cout << result1[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
