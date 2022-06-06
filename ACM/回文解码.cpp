#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    string str;
    cin >> str;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int p, l;
        cin >> p >> l;

        string sub = str.substr(p, l);
        string sub2 = sub + sub;
        reverse(sub2.begin() + sub.size(), sub2.end());

        str.replace(p, l, sub2);
    }

    std::cout << str << endl;

    return 0;
}
