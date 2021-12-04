#include <iostream>
#include <vector>

using namespace std;

//参照只能买卖两次那道题, 扩展到k次交易
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        int days = prices.size();
        if (days <= 1 || k == 0) {
            return 0;
        }

        int maxPro = INT_MIN;
        vector< vector<int> > dp( days, vector<int>(k * 2, 0) );
        for (int i = 0; i < k * 2; i += 2) {
            dp[0][i] = -prices[0];
        }

        for (int i = 1; i < days; i++) {

            for (int j = 0; j < k * 2; j += 2) {

                if (j == 0) {
                    dp[i][j] = max(dp[i - 1][0], -prices[i]);
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
                }

                dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] + prices[i]);

                maxPro = max(max(maxPro, dp[i][j]), dp[i][j + 1]);
            }
        }

        return maxPro;
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
