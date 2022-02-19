#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int p0 = 0;  //p0之前的都是0
        int p2 = nums.size() - 1; //p2之后的都是2

        int i = 0;
        while (i <= p2) {
            if (nums[i] == 0) {
                swap(nums, i, p0);
                p0++;
                i++;
            }
            else if (nums[i] == 2) {
                swap(nums, i, p2);
                p2--;
            }
            else {
                i++;
            }
        }
    }

private:
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};

int main()
{
    vector<int> nums = {2,0,2,1,1,0};
    Solution sol;
    sol.sortColors(nums);

    for (int i : nums) {
        cout << i << " ";
    }

    return 0;
}
