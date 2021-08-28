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

        vector< vector<int> > dp(days, vector<int>(2, 0) );

        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[1][0] = max(dp[0][0], dp[0][1] + prices[1]);
        dp[1][1] = max(dp[0][1], -prices[1]);
        for (int i = 2; i < days; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]);
        }

        return max(dp[days - 1][0], dp[days - 1][1]);
    }
};

int main()
{
    Solution sol;
    vector<int> prices1 = {1,2,3,0,2};
//    vector<int> prices2 = {1,2,3,4,5};
//    vector<int> prices3 = {7,6,4,3,1};

    cout << sol.maxProfit(prices1) << endl;
//    cout << sol.maxProfit(prices2) << endl;
//    cout << sol.maxProfit(prices3) << endl;

    return 0;
}
