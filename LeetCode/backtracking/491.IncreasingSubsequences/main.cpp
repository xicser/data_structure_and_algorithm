#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

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

        unordered_set<int> hasUsed;
        for (int i = startIdx; i < nums.size(); i++) {

            //���ͬһ����, ��ǰ��nums[i]�Ƿ��ù�, Ŀ����ȥ��
            if (hasUsed.find(nums[i]) != hasUsed.end()) {
                continue;
            }
            else {
                hasUsed.insert(nums[i]);
            }

            if (path.size() == 0) {
                path.push_back(nums[i]);
            }
            else if (path.size() >= 1 && nums[i] >= path[path.size() - 1]) {
                path.push_back(nums[i]);
            }
            else {
                continue;
            }

            if (path.size() >= 2) {
                result.push_back(path);  //�ռ����Ľڵ�
            }

            backtracking(i + 1, nums);
            path.pop_back();
        }

    }
};

int main()
{
    vector<int> nums = {4,4,3,2,1};
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
