#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != val) {
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
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int len = sol.removeElement(nums, 2);

    cout << "size = " << len << endl;
    for (int i = 0; i < len; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;


    return 0;
}
