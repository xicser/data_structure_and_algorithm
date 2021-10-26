#include <iostream>
#include <vector>

using namespace std;

/*
题目说的有序数组，有三种情况。

（1）全是负数
-6，-5，-4，-3，-2

（2）全是正数
1，3，4，5，6，7

（3）有正有负
-3，-2，0，5，6，7

仔细观察，我们就可知道，不管是（1）（2）（3）的哪种情况，元素的平方最大值一定产生在原数组的最左边或者最右边。
题目要求我们生成一个平方数组，从小到大排好序返回，我们这里已经能够确定平方最大值的产生位置了。
我们将最大值放入平方数组的最后一个位置就好了。

*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        vector<int> result(nums.size(), 0);
        int left = 0, right = nums.size() - 1;
        int resultIndex = right;

        while (left <= right) {
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];

            if (leftSquare > rightSquare) {
                result[resultIndex] = leftSquare;
                resultIndex--;
                left++;
            }
            else {
                result[resultIndex] = rightSquare;
                resultIndex--;
                right--;
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-4,-1,0,3,10};

    vector<int> result = sol.sortedSquares(nums);
    for (int i = 0; i < result.size(); i ++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
