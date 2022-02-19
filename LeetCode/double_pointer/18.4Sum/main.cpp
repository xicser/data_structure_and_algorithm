#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//2 2 2 2 2
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < nums.size(); i++) {

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1; j < nums.size(); j++) {

                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    long long sum = (long long)nums[i] + (long long)nums[j] +
                    (long long)nums[left] + (long long) nums[right];
                    if (sum == (long long)target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;

                        left++;
                        right--;
                    }
                    else if (sum > (long long)target) {
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

/*
[1000000000,1000000000,1000000000,1000000000]
0
*/
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
