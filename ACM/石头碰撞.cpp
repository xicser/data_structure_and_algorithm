#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> stones(n);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> stones[i];
        sum += stones[i];
    }

    int target = sum / 2;

    //dp[i]: 背包容量为dp[i]时, 最多能装多少
    vector<int> dp(target + 1, 0);

    for (int i = 0; i < stones.size(); i++) {

        for (int j = target; j >= stones[i]; j--) {
            dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
        }

    }

    std::cout << abs((sum - dp[target]) - dp[target]) << endl;

    return 0;
}
