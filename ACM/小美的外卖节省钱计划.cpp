#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int sumBuyAll = 0;
    int sumPayAll = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        if (x > y) {
            sumBuyAll += x;
            sumPayAll += x - y;
        }
        else {
            sumBuyAll += y;
        }
    }

    cout << sumBuyAll << " " << sumPayAll << endl;

    return 0;
}
