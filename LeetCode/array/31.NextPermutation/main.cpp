#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int left = -1;
        int right;

        if (nums.size() == 1) {
            return;
        }

        //自右向左找出排列中第一个比右边小的数字
        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i - 1] < nums[i]) {
                left = i - 1;
                break;
            }
        }

        if (left == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        //在该数字后面的数字中找出比nums[left]大的最小的那个
        int maxtemp = INT_MAX;
        for (unsigned int i = left + 1; i < nums.size(); i++) {
            if (nums[i] > nums[left] && nums[i] <= maxtemp) {
                right = i;
                maxtemp = nums[i];
            }
        }

        swap(nums[left], nums[right]);
        reverse(nums.begin() + left + 1, nums.end());
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2,3,1,3,3};
                    // [2,3,3,1,3]
                     // 0  1  2  3  4  5  6  7  8
    sol.nextPermutation(nums);

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    return 0;
}
