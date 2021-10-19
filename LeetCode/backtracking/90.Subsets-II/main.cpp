#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

/*
[[],[4],[4,4],[4,4,4],[4,4,4,1],[4,4,4,1,4],[4,4,4,4],[4,4,1],[4,4,1,4],[4,1],[4,1,4],[1],[1,4]]
预期结果：
[[],[1],[1,4],[1,4,4],[1,4,4,4],[1,4,4,4,4],[4],[4,4],[4,4,4],[4,4,4,4]]
*/

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        result.push_back({});
        backtracking(0, nums);
        return result;
    }

private:
    vector< vector<int> > result;
    vector<int> path;

    void backtracking(int startIndex, vector<int>& nums) {

        if (startIndex == nums.size()) {
            return;
        }

        unordered_set<int> levelUsed;
        for (int i = startIndex; i < nums.size(); i++) {

            //同层去重
            if (levelUsed.find(nums[i]) != levelUsed.end()) {
                continue;
            }
            else {
                levelUsed.insert(nums[i]);
            }

            path.push_back(nums[i]);

            result.push_back(path);     //收集搜索树的节点

            backtracking(i + 1, nums);

            path.pop_back();

        }
    }
};

int main()
{
    vector<int> nums = {4,4,4,1,4};
    Solution sol;

    vector<vector<int>> result = sol.subsetsWithDup(nums);

    for (unsigned int i = 0; i < result.size(); i++) {
        cout << '[';
        for (unsigned int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << ']';
        cout << endl;
    }

    return 0;
}
