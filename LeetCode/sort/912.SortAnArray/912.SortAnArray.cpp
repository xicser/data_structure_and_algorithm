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
            //右边的都>主元
            while (left < right && nums[right] > tmp) {
                right--;
            }
            nums[left] = nums[right];

            //左边的都<=主元
            while (left < right && nums[left] <= tmp) {
                left++;
            }
            nums[right] = nums[left];
        }

        nums[left] = tmp;

        return left;
    }

public:
    //求第k小的数
    int minK(vector<int>& nums, int left, int right, int k) {

        if (left == right) {
            return nums[left];
        }

        int index = partition(nums, left, right);
        
        //index + 1表示当前位置(含)之前一共有几个数
        int leftCnt = index - left + 1;

        //index的位置恰好是第k小的数
        if (leftCnt == k) {
            return nums[index];
        }
        else if (leftCnt > k) {
            //在左侧找第k小的数
            return minK(nums, left, index - 1, k);
        }
        else {
            //在右侧找找(k - index - 1)小的数
            return minK(nums, index + 1, right, k - index - 1);
        }
    }
};

int main()
{
    Solution sol;
    //vector<int> nums1 = { 5,1,1,2,0,0 };
    //vector<int> result = sol.sortArray(nums1);

    //for (int i : result) {
    //    cout << i << endl;
    //}

    vector<int> nums2 = { 1, 2, 2, 3, 4, 5, 6, 7, 8 };
    cout << sol.minK(nums2, 0, nums2.size() - 1, 9) << endl;

    return 0;
}
