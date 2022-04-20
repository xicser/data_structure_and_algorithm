#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n;

    cin >> n;
    map<int, int> times;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;

        times[val]++;
    }

    for (map<int, int>::iterator it = times.begin(); it != times.end(); it++) {
        int val = it->first;
        int cnt = it->second;

        if (cnt == 1) {
            cout << val << endl;
            return 0;
        }
        //cout << val << " " << cnt << endl;
    }

    cout << -1 << endl;

    return 0;
}
