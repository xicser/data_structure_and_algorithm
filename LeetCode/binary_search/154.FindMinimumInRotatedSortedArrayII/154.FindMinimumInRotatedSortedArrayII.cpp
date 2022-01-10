#include <iostream>
#include <vector>

using namespace std;

//4,5,6,7,0,1,4
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        //去除最右边的和nums[0]相等的元素, 恢复二分性
        while (right >= 0 && nums[0] == nums[right]) {
            right--;
        }

        while (left < right) { // ?

            int mid = left + (right - left) / 2;

            //在左边
            if (nums[mid] >= nums[0]) {
                left = mid + 1;
            }
            //在右边
            else {
                right = mid;
            }
        }

        return min(nums[left], nums[0]);
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
