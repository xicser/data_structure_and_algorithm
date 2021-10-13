#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {

        int len = prices.size();

        //dp[i][0]: 第i天不持有股票的最大利润
        //dp[i][1]: 第i天持有股票的最大利润
        vector< vector<int> >dp(len, vector<int>(2, 0) );

        dp[0][0] = 0;
        dp[0][1] = -prices[0] - fee;
        for (int i = 1; i < len; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i] - fee);
        }

        return max(dp[len - 1][0], dp[len - 1][1]);
    }
};

int main()
{
    Solution sol;
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    cout << sol.maxProfit(prices, 2) << endl;

    return 0;
}
