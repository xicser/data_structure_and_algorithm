#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {

        unordered_map<int, int> mapValCnt;

        //统计每种数字出现的次数
        for (unsigned int i = 0; i < nums.size(); i++) {
            mapValCnt[ nums[i] ]++;
        }
        vector<int> number;
        number.push_back(0);
        for (auto it = mapValCnt.begin(); it != mapValCnt.end(); it++) {
            number.push_back(it->first);
        }
        sort(number.begin(), number.end());

        // dp[i]表示到i这个位置, 能偷的最大钱数
        vector<int> dp(number.size(), 0);

        //dp数组初始化
        dp[1] = number[1] * mapValCnt[ number[1] ];

        //遍历
        for (unsigned int i = 2; i < number.size(); i++) {

            //会报警
            if (number[i] - number[i - 1] == 1) {
                dp[i] = max(dp[i - 2] + number[i] * mapValCnt[ number[i] ],  //偷第i个
                            dp[i - 1]);  //不偷第i个
            }
            //不会报警直接就偷
            else {
                dp[i] = dp[i - 1] + number[i] * mapValCnt[ number[i] ];
            }
        }

        return dp[number.size() - 1];
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {0};

    cout << sol.deleteAndEarn(nums) << endl;

    return 0;
}
