#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if (nums.size() == 1) {
            return 1;
        }
        if (nums.size() == 0) {
            return 0;
        }

        int slow = 1;  // == 1表示长度至少都是1
        for (unsigned int fast = 1; fast < nums.size(); fast++) {
            if (nums[fast] != nums[fast - 1]) {
                nums[slow] = nums[fast];
                slow++;
            }
        }

        return slow;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 1, 1};
    int len = sol.removeDuplicates(nums);

    cout << "size = " << len << endl;
    for (int i = 0; i < len; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
