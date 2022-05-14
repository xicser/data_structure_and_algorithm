#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int cnt = 0;
    for (int i = 0; i < 32; i++) {
        if (n & (1 << i)) {
            cnt++;
        }
    }

    std::cout << cnt << endl;
}

