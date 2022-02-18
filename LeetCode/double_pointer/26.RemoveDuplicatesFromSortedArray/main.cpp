#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if (nums.size() <= 1) {
            return nums.size();
        }

        int slow = 1;
        for (int fast = 1; fast < nums.size(); fast++) {
            if (nums[fast] != nums[fast - 1]) {
                nums[slow++] = nums[fast];
            }
        }

        return slow;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {0,0};
    int len = sol.removeDuplicates(nums);

    cout << "size = " << len << endl;
    for (int i = 0; i < len; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
