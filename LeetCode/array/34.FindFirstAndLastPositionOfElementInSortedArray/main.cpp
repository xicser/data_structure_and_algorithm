#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

//        if (processExist(0, nums.size() - 1, nums, target) == -1) {
//            return {-1, -1};
//        }

//        int left = processLeft(0, nums.size() - 1, nums, target);
//        int right = processRight(0, nums.size() - 1, nums, target);
//        if (left == -1 || right == -1) {
//            return {-1, -1};
//        }
//
//        return {left, right};


        return {findLeft(0, nums.size() - 1, nums, target), findRight(0, nums.size() - 1, nums, target)};
    }

    int findLeft(int start, int end, vector<int>& nums, int target) {

        int pos = -1;
        while (start <= end) {

            int mid = (start + end) / 2;
            if (nums[mid] == target) {
                pos = mid;
                end = mid - 1;
            }
            else if (nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return pos;
    }

    int findRight(int start, int end, vector<int>& nums, int target) {
        int pos = -1;

        while (start <= end) {

            int mid = (start + end) / 2;
            if (nums[mid] == target) {
                pos = mid;
                start = mid + 1;
            }
            else if (nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return pos;
    }


//    int processExist(int start, int end, vector<int>& nums, int target) {
//
//        if (start > end) {
//            return -1;
//        }
//
//        int mid = (start + end) / 2;
//        if (nums[mid] == target) {
//            return mid;
//        }
//        else if (nums[mid] < target) {
//            return processExist(mid + 1, end, nums, target);
//        }
//        else {
//            return processExist(start, mid - 1, nums, target);
//        }
//    }
//
//    // >= target??????????????????
//    int processLeft(int start, int end, vector<int>& nums, int target) {
//
//        int pos = end;
//        while (start <= end) {
//
//            int mid = (start + end) / 2;
//            if (nums[mid] >= target) {
//                pos = mid;
//                end = mid - 1;
//            }
//            else {
//                start = mid + 1;
//            }
//        }
//
//        if (pos == nums.size() - 1 && nums[nums.size() - 1] < target) {
//            return -1;
//        }
//        return pos;
//    }
//
//    // <= target??????????????????
//    int processRight(int start, int end, vector<int>& nums, int target) {
//
//        int pos = 0;
//        while (start <= end) {
//
//            int mid = (start + end) / 2;
//            if (nums[mid] <= target) {
//                pos = mid;
//                start = mid + 1;
//            }
//            else {
//                end = mid - 1;
//            }
//        }
//
//        if (pos == 0 && nums[0] > target) {
//            return -1;
//        }
//        return pos;
//    }
};

int main()
{
    Solution sol;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
                     // 0  1  2  3  4   5
    vector<int> result = sol.searchRange(nums, 10);

    cout << result[0] << " " << result[1] << endl;

//    cout << sol.findRight(0, nums.size() - 1, nums, 56) << endl;
//    cout << sol.processRight(0, nums.size() - 1, nums, -3) << endl;

    return 0;
}
