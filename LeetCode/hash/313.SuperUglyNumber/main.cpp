#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

//参考 264.UglyNumber-II
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {

        int len = primes.size();
        vector<int> dp(n + 1);
        dp[1] = 1;

        vector<int> indexes(len, 1);
        vector<int> tempResult(len);
        for (int i = 2; i <= n; i++) {

            int minVal = INT_MAX;
            for (int j = 0; j < len; j++) {
                tempResult[j] = primes[j] * dp[ indexes[j] ];  //存起来, 避免后面重复计算
                minVal = min(minVal, tempResult[j]);
            }

            dp[i] = minVal;
            for (int j = 0; j < len; j++) {
                if (minVal == tempResult[j]) {
                    indexes[j]++;
                }
            }
        }

        return dp[n];
    }
};

int main()
{
    Solution sol;
    vector<int> primes = {2,7,13,19};
    cout << sol.nthSuperUglyNumber(12, primes) << endl;

    return 0;
}
