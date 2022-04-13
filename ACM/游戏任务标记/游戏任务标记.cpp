#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<int, bool> mapMission;

    for (int i = 1; i <= 1024; i++) {
        mapMission[i] = false;
    }

    int id1, id2;
    cin >> id1 >> id2;

    if (1 > id2 || id2 > 1024) {
        cout << -1 << endl;
        return 0;
    }
    if (1 > id1 || id1 > 1024) {
        cout << -1 << endl;
        return 0;
    }

    mapMission[id1] = true;
    if (mapMission[id2] == true) {
        cout << 1 << endl;
    }
    else {
        cout << 0 << endl;
    }

    return 0;
}
