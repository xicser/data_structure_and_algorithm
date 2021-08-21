#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int bagSize = amount;
        int thingCnt = coins.size();

        int max = INT_MAX - 5;
        vector<int> dp(bagSize + 1, max);
        dp[0] = 0;

        for (int i = 0; i < thingCnt; i++) {
            for (int j = coins[i]; j <= bagSize; j++) {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }

        return dp[bagSize] == max ? -1 : dp[bagSize];
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
