#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// -1 -1 0 -1 -1 2
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        if (nums.size() == 0) {
            return {};
        }

        vector< vector<int> > result;
        sort(nums.begin(), nums.end());

        for (unsigned int i = 0; i < nums.size() - 1; i++) {

            //当前这个nums[i]已经大于0, 后面不可能出现结果了
            if (nums[i] > 0) {
                return result;
            }

            //去重
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {

                if (nums[i] + nums[left] + nums[right] > 0) {
                    right--;
                }
                else if (nums[i] + nums[left] + nums[right] < 0) {
                    left++;
                }
                else {
                    result.push_back({nums[i], nums[left], nums[right]});

                    //去重
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    while (left < right && nums[left] == nums[left + 1]) left++;

                    left++;
                    right--;
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {0};
    vector<vector<int>> result = sol.threeSum(nums);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
