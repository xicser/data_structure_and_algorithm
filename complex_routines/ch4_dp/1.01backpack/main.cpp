#include <iostream>
#include <vector>

using namespace std;

void test_2_wei_bag_problem()
{
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;

    // 二维数组
    vector<vector<int>> dp(weight.size(), vector<int>(bagWeight + 1, 0));
    // 初始化
    for (int j = bagWeight; j >= weight[0]; j--)
    {
        dp[0][j] = dp[0][j - weight[0]] + value[0];
    }
    // weight数组的大小就是物品个数
    for(unsigned int i = 1; i < weight.size(); i++)    // 遍历物品
    {
        for(int j = 0; j <= bagWeight; j++)   // 遍历背包容量
        {
            if (j < weight[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] +
                                    value[i]);
        }
    }
    cout << dp[weight.size() - 1][bagWeight] << endl;
}

void test_1_wei_bag_problem()
{
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;

    // 初始化
    vector<int> dp(bagWeight + 1, 0);
    for(unsigned int i = 0; i < weight.size(); i++) { // 遍历物品
        for(int j = bagWeight; j >= weight[i]; j--) { // 遍历背包容量
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout << dp[bagWeight] << endl;
}

int main()
{
    test_1_wei_bag_problem();
    test_2_wei_bag_problem();

    return 0;
}
