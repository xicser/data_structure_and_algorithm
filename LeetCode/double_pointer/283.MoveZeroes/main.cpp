#include <iostream>
#include <vector>

using namespace std;

//0,1,0,3,12
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int zero = 0;
        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != 0) {
                nums[slow++] = nums[fast];
            }
            else {
                zero++;
            }
        }

        //ฒน0
        for (int i = 0; i < zero; i++) {
            nums[slow++] = 0;
        }
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {0,1,0,3,12};
    sol.moveZeroes(nums);

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
