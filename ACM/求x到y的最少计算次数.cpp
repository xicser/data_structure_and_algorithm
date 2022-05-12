#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <limits.h>

using namespace std;

int a, b;
int cntMax;

int result = INT_MAX;
void dfs(int cnt, int val)
{
    if (cnt == cntMax && val != b) {
        return;
    }

    if (val == b) {
        //有可能多条路径到达, 这里只记录最小那个
        result = min(cnt, result);
        return;
    }

    cnt++;

    dfs(cnt, val + 1);      //+1
    dfs(cnt, val - 1);      //-1
    dfs(cnt, val << 1);     //*2
}

int main()
{
    scanf("%d,%d", &a, &b);
    cntMax = abs(a - b);

    dfs(0, a);

    cout << result << endl;

    return 0;
}
