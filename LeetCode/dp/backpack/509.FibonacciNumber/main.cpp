#include <iostream>

using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n < 2) {
            return n;
        }

        int dp[n + 1];
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }

    int fibRecurtion(int n) {
        if (n <= 1) {
            return n;
        }
        return fibRecurtion(n - 1) + fibRecurtion(n - 2);
    }
};

int main()
{
    Solution sol;
    cout << sol.fib(4) << endl;

    return 0;
}
