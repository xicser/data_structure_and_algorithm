#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int bagSize = amount;
        int thingsCnt = coins.size();

        vector<int> dp(bagSize + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < thingsCnt; i++) {
            for (int j = coins[i]; j <= bagSize; j++) {
                dp[j] += dp[j - coins[i]];
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
