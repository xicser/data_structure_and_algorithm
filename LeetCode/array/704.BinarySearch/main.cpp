#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return process(0, nums.size() - 1, nums, target);
    }

private:
    int process(int start, int end, vector<int>& nums, int target) {

        if (start > end) {
            return -1;
        }

        int mid = (start + end) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] < target) {
            return process(mid + 1, end, nums, target);
        }
        else {
            return process(start, mid - 1, nums, target);
        }
    }
};

int main()
{
    vector<int> nums = {-1,0,3,5,9,12};
    Solution sol;

    cout << sol.search(nums, 9) << endl;
    cout << sol.search(nums, 2) << endl;
    return 0;
}
