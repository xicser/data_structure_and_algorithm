#include <iostream>
#include <set>
#include <queue>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {

        vector<long long> dp(n + 1);
        dp[1] = 1;
        int index2 = 1, index3 = 1, index5 = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[index2] * 2,
                    min(dp[index3] * 3, dp[index5] * 5));

            if (dp[i] == dp[index2] * 2) {
                index2++;
            }
            if (dp[i] == dp[index3] * 3) {
                index3++;
            }
            if (dp[i] == dp[index5] * 5) {
                index5++;
            }
        }

        return dp[n];
    }
};

int main()
{
    Solution sol;

    cout << sol.nthUglyNumber(10) << endl;
    return 0;
}
