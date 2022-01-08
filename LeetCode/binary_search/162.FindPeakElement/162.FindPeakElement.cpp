#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        if (nums.size() == 1) {
            return 0;
        }

        int left = 0, right = nums.size() - 1;
        int mid = 0;

        //边界判断
        if (nums[0] > nums[1]) {
            return 0;
        }
        if (nums[right] > nums[right - 1]) {
            return right;
        }

        while (left < right) {
            mid = (left + right) / 2;

            if (nums[mid] < nums[mid - 1]) {
                //往左侧二分
                right = mid;
            }
            else if (nums[mid] < nums[mid + 1]) {
                //往右侧二分
                left = mid;
            }
            else {
                break;
            }
        }

        return mid;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
