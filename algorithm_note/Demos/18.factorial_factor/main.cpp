#include <iostream>

using namespace std;

//计算n!中, 质因子p的个数
int cal(int n, int p)
{
    int ans = 0;
    while (n) {
        ans += n / p;
        n /= p;
    }
    return ans;
}


int main()
{
    cout << cal(6, 2) << endl;
    return 0;
}
