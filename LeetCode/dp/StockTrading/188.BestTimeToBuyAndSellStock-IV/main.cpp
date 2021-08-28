#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        int days = prices.size();
        if (days <= 1 || k == 0) {
            return 0;
        }

        vector< vector<int> > dp( days, vector<int>(k * 2, 0) );
        for (int i = 0; i < k * 2; i += 2) {
            dp[0][i] = -prices[0];
        }

        for (int i = 1; i < days; i++) {

            for (int j = 0; j < k * 2; j += 2) {

                //第i天是第j + 1次【持有】状态
                if (j != 0) {
                    dp[i][j] = max( dp[i - 1][j - 1] - prices[i], dp[i - 1][j] );
                } else {
                    dp[i][j] = max(-prices[i], dp[i - 1][j] );
                }

                //第i天是第j + 1次【不持有】状态
                dp[i][j + 1] = max( dp[i - 1][j] + prices[i] , dp[i - 1][j + 1] );
            }

            //保持第一次买入状态
            dp[i][0] = max(-prices[i], dp[i - 1][0] );

            //保持第一次卖出状态
            dp[i][1] = max( dp[i - 1][0] + prices[i], dp[i - 1][1] );
        }

        return dp[days - 1][k * 2 - 1];
    }
};

int main()
{
    Solution sol;
    vector<int> prices1 = {2,4,1};
    vector<int> prices2 = {3,2,6,5,0,3};

    cout << sol.maxProfit(2, prices1) << endl;
    cout << sol.maxProfit(2, prices2) << endl;

    return 0;
}
