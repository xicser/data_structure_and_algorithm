#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

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

        //每次都遍历这个nums, 哪个没用过就用哪个
        for (unsigned int i = 0; i < nums.size(); i++) {

            if (used[i] == false) {
                path.push_back(nums[i]);
                used[i] = true;  //标记已经用过
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
    vector<int> nums = {1,2,3};

    vector<vector<int>> result1 = sol.permute(nums);
    for (unsigned int i = 0 ; i < result1.size(); i++) {
        for (unsigned int j = 0; j < result1[i].size(); j++) {
            cout << result1[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
