#include <iostream>
#include <vector>

using namespace std;

// 输入：A = [1,1,1,0,  0,0,1,1,1,1], K = 0
/*
重点：题意转换。把「最多可以把 K 个 0 变成 1，求仅包含 1 的最长子数组的长度」转换为 「找出一个最长的子数组，该子数组内最多允许有 K 个 0 」。
*/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        //记录当前窗口中0的个数
        int winZeroCnt = 0;

        int result = 0;
        int left = 0, right = 0;
        while (right < nums.size()) {
            if (nums[right] == 0) {
                winZeroCnt++;
            }
            right++;

            //等待第一个不满足的
            while (winZeroCnt > k) {

                if (nums[left] == 0) {
                    winZeroCnt--;
                }
                left++;
            }

            //记录最大的那个
            int winSize = right - left;
            result = max(result, winSize);
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = { 1,1,1,1,1,0,1,1,1,1 };
    
    std::cout << endl << sol.longestOnes(nums, 0) << endl;
}
