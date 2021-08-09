#include <iostream>

using namespace std;

typedef long long ll;

//通过定义计算
ll C_def(ll n, ll m)
{
    ll ans = 1;
    for (ll i = 1; i <= n; i++) {
        ans *= i;
    }

    for (ll i = 1; i <= m; i++) {
        ans /= i;
    }

    for (ll i = 1; i <= n - m; i++) {
        ans /=i;
    }

    return ans;
}

//通过递推关系计算
ll res[100][100] = {0};
ll C_Rec(ll n, ll m)
{
    if (m == 0 || m == n) return 1;
    if (res[n][m] != 0) return res[n][m];
    res[n][m] = C_Rec(n - 1, m) + C_Rec(n - 1, m - 1);
    return res[n][m];
}

//计算C(n, m) % p
ll resMod[1010][1010];
ll C_Rec_Mod_p(ll n, ll m, int p)
{
    if (m == 0 || m == n) return 1;
    if (resMod[n][m] != 0) return resMod[n][m];
    resMod[n][m] = (C_Rec_Mod_p(n - 1, m, p) + C_Rec_Mod_p(n - 1, m - 1, p)) % p;
    return resMod[n][m];
}

int main()
{
    cout << C_def(4, 2) << endl;
    cout << C_Rec(5, 2) << endl;
    cout << C_Rec_Mod_p(4, 2, 5) << endl;

    return 0;
}
