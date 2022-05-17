#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isIn(int x, int y, int val) {
    return x <= val && val <= y;
}
int main()
{
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> scores(n);
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }

    sort(scores.begin(), scores.end());

    for (int i = 0; i < scores.size(); i++) {

        int less = i + 1;                       // <=
        int more = scores.size() - i - 1;       // >

        if (isIn(x, y, less) && isIn(x, y, more)) {
            cout << scores[i] << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}
