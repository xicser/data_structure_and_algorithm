#include <iostream>
#include <vector>

using namespace std;

/*
第1步: 先上到第0个或者第1个台阶上, 吃掉相应台阶上的屎(cost[0]或者cost[1])
第2步: 向上走1个或者2个台阶, 到达这个台阶后, 吃掉该台阶上的屎
第3步: 上到最后一个台阶的时候, 不用吃屎
*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp[n];   //到达第i个台阶需要的最小吃屎数量为dp[i], i从0开始

        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; i++) {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }

        //上到最后一个台阶的时候, 不用吃屎
        return min(dp[n - 1], dp[n - 2]);
    }
};

int main()
{
    Solution sol;
    vector<int> cost;

//    int arr[] = {10,15,20};
    int arr[] = {
        1,100,1,1,1,100,1,1,100,1
    };
    for (unsigned int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        cost.push_back(arr[i]);
    }

    cout << sol.minCostClimbingStairs(cost) << endl;

    return 0;
}
