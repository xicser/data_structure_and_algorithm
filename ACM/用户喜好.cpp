#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    int n;
    cin >> n;

    unordered_map<int, vector<int> > valueIdxs;

    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        valueIdxs[val].push_back(i);
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int l, r, k;
        cin >> l >> r >> k;

        int cnt = 0;
        vector<int>& indexes = valueIdxs[k];
        for (int idx : indexes) {
            if (l <= idx && idx <= r) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}
