#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSquares(int n) {

        int bagSize = n;
        vector<int> dp(bagSize + 1, INT_MAX - 5);
        dp[0] = 0;

        //完全背包
        for (unsigned int i = 1; i * i <= n; i++) {
            for (int j = i * i; j <= bagSize; j++) {
                dp[j] = min(dp[j], dp[ j - i * i ] + 1);
            }
        }

        return dp[bagSize];
    }
};

int main()
{
    Solution sol;
    cout << sol.numSquares(12) << endl;
    cout << sol.numSquares(13) << endl;

    return 0;
}
