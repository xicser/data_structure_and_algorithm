#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int days = prices.size();
        if (days == 1) {
            return 0;
        }

        //dp[i][0]:  第i天, 保持第一次 买入 状态
        //dp[i][1]:  第i天, 保持第一次 卖出 状态
        //dp[i][2]:  第i天, 保持第二次 买入 状态
        //dp[i][3]:  第i天, 保持第二次 卖出 状态
        vector< vector<int> > dp(days, vector<int>(4, 0) );
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = -prices[0];
        dp[0][3] = 0;

        for (int i = 1; i < days; i++) {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);

            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] - prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] + prices[i]);
        }

        return max( max(dp[days - 1][0], dp[days - 1][1]), max(dp[days - 1][2], dp[days - 1][3]) );
    }
};

int main()
{
    Solution sol;
    vector<int> prices1 = {3,3,5,0,0,3,1,4};
    vector<int> prices2 = {1,2,3,4,5};
    vector<int> prices3 = {7,6,4,3,1};

    cout << sol.maxProfit(prices1) << endl;
    cout << sol.maxProfit(prices2) << endl;
    cout << sol.maxProfit(prices3) << endl;

    return 0;
}
