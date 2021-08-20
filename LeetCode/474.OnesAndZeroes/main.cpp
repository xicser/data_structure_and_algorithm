#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        int thingCnt = strs.size();
        //统计每隔字符串有几个0, 几个1
        int cnt[thingCnt][2];
        memset(&cnt, 0, sizeof(cnt));

        for (int i = 0; i < thingCnt; i++) {
            for (unsigned int j = 0; j < strs[i].size(); j++) {
                if (strs[i][j] == '0') {
                    cnt[i][0]++;
                } else {
                    cnt[i][1]++;
                }
            }
        }

        //定义dp数组
        int dp[thingCnt][m + 1][n + 1];  //dp[i][j][k]表示, 编号0到i的物品, 装入背包,
                                         //要求最终0的个数 <= j
                                         //要求最终1的个数 <= k
                                         //能够装到的最大重量为dp[i][j][k]
        memset(&dp, 0, sizeof(dp));

        //dp数组初始化
        for (int j = 0; j < m + 1; j++) {
            for (int k = 0; k < n + 1; k++) {
                if (cnt[0][0] <= j && cnt[0][1] <= k) {
                    dp[0][j][k] = 1;
                } else {
                    dp[0][j][k] = 0;
                }
            }
        }

        //01背包问题
        for (int i = 1; i < thingCnt; i++) {
            for (int j = 0; j < m + 1; j++) {
                for (int k = 0; k < n + 1; k++) {
                    if (j >= cnt[i][0] && k >= cnt[i][1]) {
                        dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][ j - cnt[i][0] ][ k - cnt[i][1] ] + 1);
                    }
                    else {
                        dp[i][j][k] = dp[i - 1][j][k];
                    }
                }
            }
        }

        return dp[thingCnt - 1][m][n];
    }
};

int main()
{
    Solution sol;
    vector<string> strs1 = {"10", "0001", "111001", "1", "0"};
    cout << sol.findMaxForm(strs1, 5, 3) << endl;

    vector<string> strs2 = {"10", "0", "1"};
    cout << sol.findMaxForm(strs2, 1, 1) << endl;

    return 0;
}
