#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {

        int days = prices.size();
        if (days == 1) {
            return 0;
        }

        vector< vector<int> > dp(days, vector<int>(2, 0) );
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for (int i = 1; i < days; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }

        return max(dp[days - 1][0], dp[days - 1][1]);
    }
};

int main()
{
    Solution sol;
    vector<int> prices1 = {1, 3, 2, 8, 4, 9};
    vector<int> prices2 = {1,3,7,5,10,3};

    cout << sol.maxProfit(prices1, 2) << endl;
    cout << sol.maxProfit(prices2, 3) << endl;

    return 0;
}
