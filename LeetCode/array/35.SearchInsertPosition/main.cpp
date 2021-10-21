#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return process(0, nums.size() - 1, nums, target);
    }

private:
    int process(int start, int end, vector<int>& nums, int target) {

        if (end < start) {
            return end + 1;
        }

        int mid = (start + end) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] > target) {
            return process(start, mid - 1, nums, target);
        }
        else {
            return process(mid + 1, end, nums, target);
        }
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1,3,5,6};
    cout << sol.searchInsert(nums, 0) << endl;


    return 0;
}
