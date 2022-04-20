#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

//求最小值
int calMin(int a, int b, int c) {
    return min(a, min(b, c));
}
int calMin(int a, int b) {
    return min(a, b);
}
int calMin(int a, int b, int c, int d) {
    return min(calMin(a, b, c), d);
}

int main()
{
    int n;
    cin >> n;

    vector<int> company(n);
    vector<int> gym(n);

    for (int i = 0; i < n; i++) {
        cin >> company[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> gym[i];
    }

    vector< vector<int> > dp(n, vector<int>(3, INT_MAX));
    //dp[i][0]: 第 i 休息, 最少的休息天数
    //dp[i][1]: 第 i 工作, 最少的休息天数
    //dp[i][2]: 第 i 锻炼, 最少的休息天数
    dp[0][0] = 1;
    if (company[0]) {
        dp[0][1] = 0;
    }
    if (gym[0]) {
        dp[0][2] = 0;
    }

    for (int i = 1; i < n; i++) {

        //休息
        dp[i][0] = calMin(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]) + 1;
        
        //工作
        if (company[i]) {
            dp[i][1] = calMin(dp[i - 1][0], dp[i - 1][2]);
        }

        //锻炼
        if (gym[i]) {
            dp[i][2] = calMin(dp[i - 1][0], dp[i - 1][1]);
        }
    }

    cout << calMin(dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]) << endl;

    return 0;
}
