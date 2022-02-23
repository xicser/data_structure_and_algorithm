#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_set<int> winSet;

        int left = 0, right = 0;

        while (right < nums.size()) {

            if (winSet.count(nums[right]) != 0) {
                return true;
            }

            winSet.insert(nums[right]);
            right++;

            if (right - left == k + 1) {
                winSet.erase(nums[left]);
                left++;
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
