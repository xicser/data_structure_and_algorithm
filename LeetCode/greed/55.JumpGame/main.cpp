#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {

        if (nums.size() == 1) {
            return true;
        }
        if (nums[0] == 0) {
            return false;
        }

        int farestIndex = -1;
        for (int i = 0; i < nums.size(); i++) {

            //记录能够到达的最远位置
            farestIndex = max(farestIndex, i + nums[i]);

            //如果当前能够到达的最远位置就是i, 且nums[i]没有可以走的步子了
            if (farestIndex == i && nums[i] == 0) {
                break;
            }
        }

        if (farestIndex >= nums.size() - 1) {
            return true;
        }

        return false;
    }
};

// [0, 2, 3]
//  0  1  2
int main()
{
    Solution sol;
    vector<int> nums1 = {2,3,1,1,4};
    vector<int> nums2 = {3, 2, 1, 0, 4, 8};
                      // 0  1  2  3  4  5

    cout << sol.canJump(nums1) << endl;
    cout << sol.canJump(nums2) << endl;

    return 0;
}
