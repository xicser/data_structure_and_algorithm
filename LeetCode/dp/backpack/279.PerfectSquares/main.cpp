#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSquares(int n) {

        int bagSize = n;

        //dp[i]表示装满容量为i的背包, 需要的最少背包个数
        vector<int> dp(bagSize + 1, INT_MAX);

        //dp数组初始化
        dp[0] = 0;

        //遍历物品
        for (int i = 1; i <= n; i++) {

            //遍历背包
            for (int j = (i * i); j < bagSize + 1; j++) {

                dp[j] = min(dp[j], dp[j - i * i] + 1);
            }
        }

        return dp[bagSize];
    }
};

int main()
{
    Solution sol;
    cout << sol.numSquares(12) << endl;
    cout << sol.numSquares(13) << endl;

    return 0;
}
