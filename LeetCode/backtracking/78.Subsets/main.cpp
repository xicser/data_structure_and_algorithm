#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        backtracking(0, nums);
        result.push_back({});
        return result;
    }

private:

    vector<vector<int>> result;
    vector<int> path;

    void backtracking(int startIdx, vector<int>& nums) {

        if (startIdx == nums.size()) {
            return;
        }

        for (int i = startIdx; i < nums.size(); i++) {
            path.push_back(nums[i]);

            //收集结果
            result.push_back(path);

            backtracking(i + 1, nums);

            path.pop_back();
        }
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};
    Solution sol;

    vector<vector<int>> result = sol.subsets(nums);

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
