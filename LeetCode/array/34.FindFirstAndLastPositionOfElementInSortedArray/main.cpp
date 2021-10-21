#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        if (processExist(0, nums.size() - 1, nums, target) == -1) {
            return {-1, -1};
        }

        int left = processLeft(0, nums.size() - 1, nums, target);
        int right = processRight(0, nums.size() - 1, nums, target);
        if (left == -1 || right == -1) {
            return {-1, -1};
        }

        return {left, right};
    }

    int processExist(int start, int end, vector<int>& nums, int target) {

        if (start > end) {
            return -1;
        }

        int mid = (start + end) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] < target) {
            return processExist(mid + 1, end, nums, target);
        }
        else {
            return processExist(start, mid - 1, nums, target);
        }
    }

    // >= target的最左侧位置
    int processLeft(int start, int end, vector<int>& nums, int target) {

        int pos = end;
        while (start <= end) {

            int mid = (start + end) / 2;
            if (nums[mid] >= target) {
                pos = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        if (pos == nums.size() - 1 && nums[nums.size() - 1] < target) {
            return -1;
        }
        return pos;
    }

    // <= target的最右侧位置
    int processRight(int start, int end, vector<int>& nums, int target) {

        int pos = 0;
        while (start <= end) {

            int mid = (start + end) / 2;
            if (nums[mid] <= target) {
                pos = mid;
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        if (pos == 0 && nums[0] > target) {
            return -1;
        }
        return pos;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
                     // 0  1  2  3  4   5
    vector<int> result = sol.searchRange(nums, 6);

    cout << result[0] << " " << result[1] << endl;

//    cout << sol.processLeft(0, nums.size() - 1, nums, 8) << endl;
//    cout << sol.processRight(0, nums.size() - 1, nums, -3) << endl;

    return 0;
}
