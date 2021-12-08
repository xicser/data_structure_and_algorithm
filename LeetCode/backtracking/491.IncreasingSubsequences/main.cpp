#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

//4,6,7,7
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {

        backtracking(0, nums);
        return result;
    }

private:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(int startIdx, vector<int>& nums) {

        if (startIdx == nums.size()) {
            return;
        }

        unordered_set<int> hasUsed;  //同层去重
        for (int i = startIdx; i < nums.size(); i++) {

            //同层去重
            if (hasUsed.find(nums[i]) == hasUsed.end()) {
                hasUsed.insert(nums[i]);
            }
            else {
                continue;
            }

            //第一个肯定是要放进来的
            if (path.size() == 0) {
                path.push_back(nums[i]);
            }
            else {
                if (path[path.size() - 1] <= nums[i]) {
                    path.push_back(nums[i]);
                }
                else {
                    continue;
                }
            }

            //收集结果
            if (path.size() >= 2) {
                result.push_back(path);
            }

            backtracking(i + 1, nums);
            path.pop_back();
        }
    }
};

int main()
{
    vector<int> nums = {4,4,3,2,1};   //4,4,3,2,1
    Solution sol;

    vector<vector<int>> result = sol.findSubsequences(nums);

    for (int i = 0; i < result.size(); i++) {
        cout << '[';
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << ']';
        cout << endl;
    }

    return 0;
}
