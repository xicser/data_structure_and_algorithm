#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> result;
    int left = -90, right = 90;
    while (left < right) {
        int mid = (left + right) / 2;

        if (left <= n && n < mid) {
            result.push_back(0);
            right = mid;

            if (result.size() == 6) {
                break;
            }
        }
        else {
            result.push_back(1);
            left = mid;

            if (result.size() == 6) {
                break;
            }
        }
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
    }
    cout << endl;

    return 0;
}
