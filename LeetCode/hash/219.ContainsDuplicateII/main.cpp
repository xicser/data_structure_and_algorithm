#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        //滑动窗口
        unordered_set<int> winSet;

        for (int i = 0; i < nums.size(); i++) {

            //count查询winSet是否存在nums[i]
            if (!winSet.count(nums[i])) {
                winSet.insert(nums[i]);
            }
            else {
                return true;
            }

            //窗口超范围了, 去除窗口最开始那个元素
            if (winSet.size() > k) {
                winSet.erase(nums[i - k]);
            }
        }

        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};
                    //  0  1  2  3
    cout << sol.containsNearbyDuplicate(nums, 3) << endl;
    return 0;
}
