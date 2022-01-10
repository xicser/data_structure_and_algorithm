#include <iostream>
#include <vector>

using namespace std;

//4,5,6,7,0,1,2
class Solution {
public:
    int findMin(vector<int>& nums) {

        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            //mid落在了左半段
            if (nums[mid] >= nums[0]) {
                left = mid + 1;
            }
            //mid落在了右半段
            else {
                right = mid;
            }
        }

        //返回夹出来的位置
        return min(nums[left], 
                    nums[0]);  //有可能旋转了n次, 恰好和原数组一样了
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
