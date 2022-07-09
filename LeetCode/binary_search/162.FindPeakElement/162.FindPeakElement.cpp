#include <iostream>
#include <vector>

using namespace std;

// nums = [1,2,3,1]
class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        if (nums.size() == 1) {
            return 0;
        }

        int left = 0, right = nums.size() - 1;

        //边界判断
        if (nums[0] > nums[1]) {
            return 0;
        }
        if (nums[right] > nums[right - 1]) {
            return right;
        }

        int mid = 0;
        while (left < right) {
            mid = left + (right - left) / 2;

            if (nums[mid] < nums[mid - 1]) {
                right = mid;
            }
            else if (nums[mid] < nums[mid + 1]) {
                left = mid;
            }
            else {
                return mid;
            }
        }

        return mid;
    }
};

int main()
{
    vector<int> nums = {6, 5, 4, 3, 2, 3, 2};
    Solution sol;
    cout << sol.findPeakElement(nums) << endl;
}
