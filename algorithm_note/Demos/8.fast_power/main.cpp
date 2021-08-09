/*

快速幂

a^b % m

*/

#include <iostream>

using namespace std;

typedef long long ll;

/* 直接乘的办法 */
ll LLpow(ll a, ll b, ll m)
{
    ll ans = 1;
    for (int i = 0; i < b; i++) {
        ans = ans * a % m;
    }

    return ans;
}

/*
计算a ^ b % m
快速幂, 利用递归
*/
ll fastPowRecursion(ll a, ll b, ll m)
{
    ll res = 0;

    if (a >= m) {  //直接取模
        a %= m;
    }
    if (m == 1) {  //任何正整数对1取模一定等于0
        return 0;
    }

    if (b == 1) {
        return a;
    } else if (b % 2 == 0) {
        ll temp = fastPowRecursion(a, b / 2, m);
        res = temp * temp % m;
    } else if (b % 2 == 1) {
        res = a * fastPowRecursion(a, b - 1, m) % m;
    }

    return res;
}

/*
计算a ^ b % m
快速幂, 利用迭代
*/
ll fastPowIteration(ll a, ll b, ll m)
{
    ll ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans = ans * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }

    return ans;
}

int main()
{
    cout << fastPowRecursion(20, 5, 3) << endl;
    cout << fastPowRecursion(3, 2, 2) << endl;
    cout << fastPowIteration(20, 5, 3) << endl;
    cout << fastPowIteration(3, 2, 2) << endl;

    return 0;
}
