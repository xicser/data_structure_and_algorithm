#include <iostream>
#include <string>
#include <map>
#include <limits.h>

using namespace std;

void toLower(string& str)
{
    for (int i = 0; i < str.size(); i++) {
        if ('A' <= str[i] && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    map<string, int> mapStr;

    while (n) {
        n--;
        string strInput;
        cin >> strInput;
        toLower(strInput);

        mapStr[strInput]++;
    }

    int cntMax = INT_MIN;
    string strRes;
    for (auto& it : mapStr) {
        string str = it.first;
        int times = it.second;

        if (times > cntMax) {
            cntMax = times;
            strRes = str;
        }
    }

    cout << strRes << " " << cntMax << endl;

    return 0;
}
