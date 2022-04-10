#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

public:
    int firstMissingPositive(vector<int>& nums) {
        
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            while (1 <= nums[i] && nums[i] <= len &&
                nums[i] != i + 1 &&
                nums[nums[i] - 1] != nums[i]) {

                swap(nums, nums[i] - 1, i);
            }
        }

        for (int i = 0; i < len; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return len + 1;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
