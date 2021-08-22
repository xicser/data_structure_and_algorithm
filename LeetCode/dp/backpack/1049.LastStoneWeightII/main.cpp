#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {

        if (stones.size() == 1) {
            return stones[0];
        }
        int sum = 0;
        int target;
        for (unsigned int i = 0 ; i < stones.size(); i++) {
            sum += stones[i];
        }
        target = sum / 2;

//        cout << sum << endl;
//        cout << target << endl;

        //dp[i][j]表示, 从下标为[0 - i]的物品中任意取, 放进容量为j的背包, 价值总和最大是多少
        int row = stones.size();
        int col = target + 1;
        vector< vector<int> > dp(row, vector<int>(col, 0));

        //dp数组初始化
        for (int j = 1; j < col; j++) {
            if (stones[0] <= j) {
                dp[0][j] = stones[0];
            }
        }

        //01背包
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (j < stones[i]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i]] + stones[i]);
                }
            }
        }

//        cout << dp[row - 1][target] << endl;

        return abs((sum - dp[row - 1][target]) - dp[row - 1][target]);
    }
};

int main()
{
    Solution sol;
    vector<int> num1 = {2,7,4,1,8,1};
    vector<int> num2 = {31,26,33,21,40};
    vector<int> num3 = {1, 2, 3};

    cout << sol.lastStoneWeightII(num1) << endl;
    cout << sol.lastStoneWeightII(num2) << endl;
    cout << sol.lastStoneWeightII(num3) << endl;

    return 0;
}
