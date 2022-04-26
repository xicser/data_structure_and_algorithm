#include <iostream>

using namespace std;



void process(int n)
{
    if (n == 1 || n == 2) {
        cout << 1 << endl;
        return;
    }

    if (n % 2 == 0) {
        cout << n / 2 << endl;
    }
    else {
        cout << n / 2 + 1 << endl;
    }
}

int main()
{
    int T;
    cin >> T;

    while (T) {

        int n;
        cin >> n;

        process(n);

        T--;
    }

    return 0;
}
