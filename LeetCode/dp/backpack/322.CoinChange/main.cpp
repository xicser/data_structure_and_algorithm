#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int bagSize = amount;

        int maxValue = INT_MAX - 1;  // - 1 ��ԭ���ǵ��ƹ�ʽ����+1, �ᵼ��int���
        //dp[i]��ʾ, װ������Ϊi�ı���, �����������Ʒ����
        vector<int> dp(bagSize + 1, maxValue);
        dp[0] = 0;

        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j < bagSize + 1; j++) {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }

        return dp[bagSize] == maxValue ? -1 : dp[bagSize];
    }
};

int main()
{
    Solution sol;
    vector<int> coins1 = {1, 2, 5};
    vector<int> coins2 = {2};

    cout << sol.coinChange(coins1, 11) << endl;
    cout << sol.coinChange(coins2, 3) << endl;

    return 0;
}
