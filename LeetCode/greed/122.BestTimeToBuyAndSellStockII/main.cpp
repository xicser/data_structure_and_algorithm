#include <iostream>
#include <vector>

using namespace std;

//prices = [7,1,5,3,6,4]
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int pSize = prices.size();
        vector< vector<int> > dp(pSize, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for (int i = 1; i < pSize; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }

        return max(dp[pSize - 1][0], dp[pSize - 1][1]);
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
