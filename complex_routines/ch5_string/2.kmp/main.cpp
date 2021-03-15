#include <iostream>
#include <string>
#include <vector>
#include "kmp.h"

using namespace std;

int main()
{
    string text;
    string pattern;
    vector <int> outIndexes;

    cin >> text;
    cin >> pattern;

    bool hasFound;
    outIndexes = KMP_Check(text.c_str(), pattern.c_str(), &hasFound);
    if (hasFound == true) {
        for (unsigned int i = 0; i < outIndexes.size(); i++) {
            cout << outIndexes[i] << " ";
        }
        cout << endl;
    } else {
        cout << pattern << " not found" << endl;
    }

    return 0;
}
