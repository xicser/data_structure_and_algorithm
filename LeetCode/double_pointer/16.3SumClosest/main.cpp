#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>


using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        int deltaMin = INT_MAX;
        int result;
        for (unsigned int i = 0; i < nums.size(); i++) {
            int left = i + 1;
            int right = nums.size() - 1;

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            while (left < right) {

                int val = nums[i] + nums[left] + nums[right];
                int deltaCur = abs(val - target);

                //记录与target差值的最小值
                if (deltaCur < deltaMin) {
                    deltaMin = deltaCur;
                    result = val;
                }

                if (val > target) {
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    right--;
                }
                else if (val < target) {
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    left++;
                }
                else {
                    return val;
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
//    vector<int> nums = {-1,2,1,-4};
    vector<int> nums = {-1,0,1,1,55};

    cout << sol.threeSumClosest(nums, 3) << endl;
    return 0;
}
