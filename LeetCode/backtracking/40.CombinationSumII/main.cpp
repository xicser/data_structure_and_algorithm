#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        //必须先去重
        sort(candidates.begin(), candidates.end());
        this->target = target;
        this->pathSum = 0;

        backtracking(0, candidates);

        return result;
    }

private:
    vector<vector<int>> result;
    vector<int> path;
    int pathSum;
    int target;

    void backtracking(int startIndex, vector<int>& candidates) {

        if (pathSum == this->target) {
            result.push_back(path);
            return;
        }
        else if (pathSum > this->target) {
            return;
        }

        unordered_set<int> hasUsed;
        for (unsigned int i = startIndex; i < candidates.size() && candidates[i] + pathSum <= target; i++) {

            //如果本层的这个数字candidates[i]被用过, 那么就不要再用了
            if (hasUsed.find(candidates[i]) != hasUsed.end()) {
                continue;
            } else {
                hasUsed.insert(candidates[i]);
            }

            pathSum += candidates[i];
            path.push_back(candidates[i]);

            backtracking(i + 1, candidates);

            pathSum -= candidates[i];
            path.pop_back();
        }
    }
};

int main()
{
    Solution sol;
    vector<int> candidates1 = {10, 1, 2, 7, 6, 1, 5};

    vector<vector<int>> result1 = sol.combinationSum2(candidates1, 8);
    for (unsigned int i = 0 ; i < result1.size(); i++) {
        for (unsigned int j = 0; j < result1[i].size(); j++) {
            cout << result1[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
