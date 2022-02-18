#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        backtracking(nums, 0);
        result.push_back({});
        return result;
    }

private:

    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int>& nums, int startIndex) {

        if (startIndex == nums.size()) {
            return;
        }

        for (int i = startIndex; i < nums.size(); i++) {

            path.push_back(nums[i]);

            result.push_back(path);

            backtracking(nums, i + 1);

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
