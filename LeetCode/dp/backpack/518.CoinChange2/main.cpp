#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int bagSize = amount;

        //dp[i]表示, 装满容量为i的背包, 有多少种装法
        vector<int> dp(bagSize + 1, 0);
        dp[0] = 1;

        //完全背包
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j < bagSize + 1; j++) {
                dp[j] += dp[ j - coins[i] ];
            }
        }

        return dp[bagSize];
    }
};

int main()
{
    Solution sol;
    vector<int> coins = {1, 2, 5};
    cout << sol.change(5, coins) << endl;

    return 0;
}
