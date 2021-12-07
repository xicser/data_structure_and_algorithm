#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

//1, 1, 2, 5, 6, 7, 10   target = 8
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        //必须先排序
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

        if (pathSum == target) {
            result.push_back(path);
        }
        else if (pathSum > target) {
            return;
        }

        //同层去重
        unordered_set<int> hasUsed;

        for (int i = startIndex; i < candidates.size() && pathSum + candidates[i] <= target; i++) {

            //如果本层中, 这一个数之前已经用过, 就不要再用了
            if (hasUsed.find(candidates[i]) == hasUsed.end()) {
                path.push_back(candidates[i]);
                pathSum += candidates[i];
                hasUsed.insert(candidates[i]);  //放入set, 表示这个数已经用过了
            }
            else {
                continue;
            }

            backtracking(i + 1, candidates);

            path.pop_back();
            pathSum -= candidates[i];
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
