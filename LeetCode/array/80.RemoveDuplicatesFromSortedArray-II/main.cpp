#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return work(nums, 2);
    }

    int work(vector<int>& nums, int k) {
        int len = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i < k) {
                len++;
            }
            else if (nums[i] != nums[len - k]) {
                nums[len] = nums[i];
                len++;
            }
        }

        return len;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {0,0,1,1,1,1,2,3,3};
    int len = sol.removeDuplicates(nums);

    for (int i = 0; i < len; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
