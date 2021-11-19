#include <iostream>
#include <vector>

using namespace std;

/*
为了方便叙述，我们称「只出现了一次的元素」为「答案」。
由于数组中的元素都在 int（即 32 位整数）范围内，因此我们可以依次计算答案的每一个二进制位是 0 还是 1
具体地，考虑答案的第 i 个二进制位（i 从 0 开始编号），它可能为 0 或 1。对于数组中非答案的元素，每一个元素都出现了 3 次，
对应着第 i 个二进制位的 3 个 0 或 3 个 1，无论是哪一种情况，它们的和都是 3 的倍数（即和为 0 或 3）。
因此：
答案的第 i 个二进制位就是数组中所有元素的第 i 个二进制位之和除以 3 的余数。

*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int result = 0;
        for (int i = 0; i < 32; i++) {

            int bitSum = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] & (1 << i)) {
                    bitSum += 1;
                }
            }

            int bitResult = bitSum % 3;

            result |= bitResult << i;
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {0,1,0,1,0,1,99};

    cout << sol.singleNumber(nums) << endl;
    return 0;
}
