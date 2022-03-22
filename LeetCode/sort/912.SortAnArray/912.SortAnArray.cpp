#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        srand((unsigned)time(NULL));
        qSort(nums, 0, nums.size() - 1);

        return nums;
    }

private:
    void qSort(vector<int>& nums, int left, int right) {

        if (left >= right) {
            return;
        }
        int pos = partition(nums, left, right);
        qSort(nums, left, pos - 1);
        qSort(nums, pos + 1, right);
    }

    int partition(vector<int>& nums, int left, int right) {

        int len = right - left + 1;
        int pos = rand() % len + left;  //选取随机主元

        swap(nums[left], nums[pos]);
        int tmp = nums[left];

        while (left < right) {
            while (left < right && nums[right] > tmp) {
                right--;
            }
            nums[left] = nums[right];

            while (left < right && nums[left] <= tmp) {
                left++;
            }
            nums[right] = nums[left];
        }

        nums[left] = tmp;

        return left;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = { 5,1,1,2,0,0 };
    vector<int> result = sol.sortArray(nums);

    for (int i : result) {
        cout << i << endl;
    }
}
