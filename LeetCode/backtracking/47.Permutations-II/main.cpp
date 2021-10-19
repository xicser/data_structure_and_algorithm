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

        //��¼ͬһ���ù���
        unordered_set<int> levelUsed;

        //ÿ�ζ��������nums, �ĸ�û�ù������ĸ�
        for (unsigned int i = 0; i < nums.size(); i++) {

            if (used[i] == false) {

                //ͬһ�㲻�����ظ���
                if (levelUsed.find(nums[i]) != levelUsed.end()) {
                    continue;
                }
                else {
                    levelUsed.insert(nums[i]);
                }

                path.push_back(nums[i]);
                used[i] = true;  //����Ѿ��ù�
            }
            else {
                continue;
            }

            backtracking(nums, used);

            //����
            used[i] = false;
            path.pop_back();
        }
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result1 = sol.permuteUnique(nums);
    for (unsigned int i = 0 ; i < result1.size(); i++) {
        for (unsigned int j = 0; j < result1[i].size(); j++) {
            cout << result1[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
