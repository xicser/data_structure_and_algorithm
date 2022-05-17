#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> vals(n);
    vector<int> compare(n);
    for (int i = 0; i < n; i++) {
        cin >> vals[i];
        compare[i] = i + 1;
    }
    sort(vals.begin(), vals.end());

    int steps = 0;

    for (int i = 0; i < n; i++) {
        steps += abs(vals[i] - compare[i]);
    }

    cout << steps << endl;

    return 0;
}
