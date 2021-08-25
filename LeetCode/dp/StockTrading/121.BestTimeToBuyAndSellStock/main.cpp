#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if (prices.size() == 0) {
            return 0;
        }
        int days = prices.size();
        vector< vector<int> > dp(days, vector<int>(2, 0));
        // dp[i][0] 表示第i天 不持有 股票所获得的最大利润
        // dp[i][1] 表示第i天   持有 股票所获得的最大利润

        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < days; i++) {

            dp[i][0] = max(dp[i - 1][0],                //昨天就不持有
                           dp[i - 1][1] + prices[i]);   //昨天持有, 今天卖了

            dp[i][1] = max(dp[i - 1][1],                //昨天就持有
                           -prices[i]);                 //昨天不持有, 今天买入
        }

        return max(dp[days - 1][0], dp[days - 1][1]);
    }
};

int main()
{
    Solution sol;
    vector<int> prices1 = {7,1,5,3,6,4};
    vector<int> prices2 = {7,6,4,3,1};

    cout << sol.maxProfit(prices1) << endl;
    cout << sol.maxProfit(prices2) << endl;

    return 0;
}
