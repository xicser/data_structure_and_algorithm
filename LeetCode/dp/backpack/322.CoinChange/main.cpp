#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int bagSize = amount;

        int maxValue = INT_MAX - 1;  // - 1 的原因是递推公式里有+1, 会导致int溢出
        //dp[i]表示, 装满容量为i的背包, 所需的最少物品个数
        vector<int> dp(bagSize + 1, maxValue);
        dp[0] = 0;

        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j < bagSize + 1; j++) {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }

        return dp[bagSize] == maxValue ? -1 : dp[bagSize];
    }
};

int main()
{
    Solution sol;
    vector<int> coins1 = {1, 2, 5};
    vector<int> coins2 = {2};

    cout << sol.coinChange(coins1, 11) << endl;
    cout << sol.coinChange(coins2, 3) << endl;

    return 0;
}
