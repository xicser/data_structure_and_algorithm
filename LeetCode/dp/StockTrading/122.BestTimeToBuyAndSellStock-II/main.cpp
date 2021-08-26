#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if(prices.size() == 0) {
            return 0;
        }
        int days = prices.size();
        vector< vector<int> > dp(days, vector<int>(2, 0));

        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for (int i = 1; i < days; i++) {

            //��i�첻����
            dp[i][0] = max(dp[i - 1][0],                    // ��i - 1�첻����
                           dp[i - 1][1] + prices[i]);       // ��i - 1�����, ��������ȥ��

            //��i�����
            dp[i][1] = max(dp[i - 1][1],                    // ��i - 1�����
                           dp[i - 1][0] - prices[i]);       // ��i - 1�첻����, ��������
        }

        return max(dp[days - 1][0], dp[days - 1][1]);
    }
};

int main()
{
    Solution sol;
    vector<int> prices1 = {7,1,5,3,6,4};
    vector<int> prices2 = {1,2,3,4,5};
    vector<int> prices3 = {7,6,4,3,1};

    cout << sol.maxProfit(prices1) << endl;
    cout << sol.maxProfit(prices2) << endl;
    cout << sol.maxProfit(prices3) << endl;

    return 0;
}
