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
        for (unsigned int i = 0; i < stones.size(); i++) {
            sum += stones[i];
        }
        target = sum / 2;

        //给容量为target的背包中装的最大重量
        vector<int> dp(target + 1, 0);

        //01背包
        for (int i = 0; i < stones.size(); i++) {
            for (int j = target; j >= stones[i]; j--) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }

        return abs((sum - dp[target]) - dp[target]);
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
