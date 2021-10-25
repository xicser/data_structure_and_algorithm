#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++) {

            if (nums[fast] != 0) {
                nums[slow] = nums[fast];
                slow++;
            }
        }

        //ฒน0
        for (int i = slow; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {0};
    sol.moveZeroes(nums);

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
