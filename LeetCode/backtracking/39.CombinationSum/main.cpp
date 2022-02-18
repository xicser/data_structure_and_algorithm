#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//candidates = [2,3,6,7], target = 7
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        pathSum = 0;
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0);

        return result;
    }

private:
    vector<int> path;
    vector<vector<int>> result;
    int pathSum;

    void backtracking(vector<int>& candidates, int target, int startIndex) {

        if (pathSum == target) {
            result.push_back(path);
            return;
        }
        else if (pathSum > target) {
            return;
        }

        for (unsigned int i = startIndex; i < candidates.size()
            && pathSum + candidates[i] <= target; i++) {

            path.push_back(candidates[i]);
            pathSum += candidates[i];

            backtracking(candidates, target, i);

            path.pop_back();
            pathSum -= candidates[i];
        }
    }
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
