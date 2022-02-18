#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {

        int left = 0, right = nums.size() - 1;

        //忽略nums尾部和nums[0]相等的元素, 使其恢复二段性(能够判断mid位置在左半段还是右半段)
        while (right >= 0 && nums[0] == nums[right]) {
            right--;
        }
        //全部相等, 直接返回
        if (right < 0 && nums[0] == target) {
            return true;
        }

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return true;
            }

            //mid落在nums的左半段
            if (nums[mid] >= nums[left]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            //mid落在nums的右半段
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }

        return false;
    }
};

int main()
{
    vector<int> nums = { 1 };
    Solution sol;

    std::cout << sol.search(nums, 1) << endl;
}
