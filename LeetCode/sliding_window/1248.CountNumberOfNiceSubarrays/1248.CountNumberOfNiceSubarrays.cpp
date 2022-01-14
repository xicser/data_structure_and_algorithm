#include <iostream>
#include <vector>

using namespace std;

//nums = [1,1,2,1,1], k = 3
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        int result = 0;
        int left = 0, right;

        //直接让left和right指向第一个奇数位置
        while (left < nums.size() && (nums[left] & 1) == 0) {
            left++;
        }
        right = left;

        int winOddCnt = 0;  //记录窗口中奇数个数
        while (right < nums.size()) {
            if ((nums[right] & 1) != 0) {
                winOddCnt++;
            }
            right++;

            if (winOddCnt == k) {

                //统计窗口中第1个奇数左边有多少个偶数
                int leftEvenCnt = 0;
                int indexLeft = left - 1;
                while (indexLeft >= 0 && (nums[indexLeft] & 1) == 0) {
                    leftEvenCnt++;
                    indexLeft--;
                }

                //统计窗口中最后一个奇数右边有多少个偶数
                int rightEvenCnt = 0;
                int indexRight = right;
                while (indexRight < nums.size() && (nums[indexRight] & 1) == 0)  {
                    rightEvenCnt++;
                    indexRight++;
                }

                //结果加和
                int resultWin = (leftEvenCnt + 1) * (rightEvenCnt + 1);
                result += resultWin;

                //窗口往右, left指针偏移到之前窗口左边第一个奇数的下一个奇数位置
                left++;
                while (left < nums.size() && (nums[left] & 1) == 0) {
                    left++;
                }
                winOddCnt--;
            }
        }

        return result;
    }
};

int main()
{
    vector<int> nums = { 1, 1, 1, 1, 1 };
    Solution sol;
    cout << sol.numberOfSubarrays(nums, 1) << endl;
}
