#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }

private:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int>& nums, vector<bool> &used) {

        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        //记录同层某个数是否被用过
        unordered_set<int> levelUsed;

        //每次都遍历这个nums, 哪个没用过就用哪个
        for (unsigned int i = 0; i < nums.size(); i++) {

            if (used[i] == false) {

                //同层没被用过
                if (levelUsed.find(nums[i]) == levelUsed.end()) {

                    levelUsed.insert(nums[i]);
                    path.push_back(nums[i]);
                    used[i] = true;  //标记已经用过
                }
                else {
                    continue;
                }
            }
            else {
                continue;
            }

            backtracking(nums, used);

            //回溯
            used[i] = false;
            path.pop_back();
        }
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 1, 2};

    vector<vector<int>> result1 = sol.permuteUnique(nums);
    for (unsigned int i = 0 ; i < result1.size(); i++) {
        for (unsigned int j = 0; j < result1[i].size(); j++) {
            cout << result1[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
