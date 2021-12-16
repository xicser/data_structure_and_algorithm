#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {

        int len = primes.size();
        //dp[i]表示第i个丑数
        vector<int> dp(n + 1);
        dp[1] = 1;
        vector<int> index(len, 1);
        vector<int> tmpArr(len);

        for (int i = 2; i <= n; i++) {

            int minn = INT_MAX;
            for (int j = 0; j < len; j++) {
                tmpArr[j] = dp[ index[j] ] * primes[j];
                minn = min(minn, tmpArr[j]);
            }

            dp[i] = minn;
            for (int j = 0; j < len; j++) {
                if (minn == tmpArr[j]) {
                    index[j]++;
                }
            }
        }

        return dp[n];
    }
};

int main()
{
    Solution sol;
    vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541};

    cout << sol.nthSuperUglyNumber(1000000, primes) << endl;

    return 0;
}
