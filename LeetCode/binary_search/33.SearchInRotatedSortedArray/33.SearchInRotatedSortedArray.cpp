#include <iostream>
#include <vector>

using namespace std;

//Input: nums = [4,5,6,7,   0,1,2], target = 0
class Solution {
public:
    int search(vector<int>& nums, int target) {

        int left = 0, right = nums.size() - 1;
        while (left <= right) {

            int mid = left + (right - left) / 2;

            //找到了
            if (nums[mid] == target) {
                return mid;
            }

            //mid落在左半段
            if (nums[mid] >= nums[left]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            //mid落在右半段
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }

        return -1; //没找到
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
