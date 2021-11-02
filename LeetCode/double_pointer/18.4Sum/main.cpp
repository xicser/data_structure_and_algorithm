#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        if (nums.size() < 4) {
            return {};
        }

        sort(nums.begin(), nums.end()); //先排序
        vector<vector<int>> result;
        for (unsigned int i = 0; i < nums.size(); i++) {

            //去重
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (unsigned int j = i + 1; j < nums.size(); j++) {

                //去重
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                int left = j + 1;
                int right = nums.size() - 1;

                while (left < right) {
                    long long tempVal = (long long)nums[i] + (long long)nums[j] + (long long)nums[left] + (long long)nums[right];
                    if (tempVal == target) {
                        result.push_back( {nums[i], nums[j], nums[left], nums[right]} );

                        //去重
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;

                        left++;
                        right--;
                    }
                    else if (tempVal > target) {
                        right--;
                    }
                    else {
                        left++;
                    }
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {1000000000,1000000000,1000000000,1000000000};

    vector<vector<int>> result1 = sol.fourSum(nums1, 0);
    for (int i = 0; i < result1.size(); i++) {
        for (int j = 0; j < result1[i].size(); j++) {
            cout << result1[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
