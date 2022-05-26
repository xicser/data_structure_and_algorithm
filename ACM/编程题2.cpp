#include <iostream>

using namespace std;

/*
aabaabaa
*/
int main()
{
    int n, m;
    cin >> n >> m;

    string str;
    cin >> str;

    int aCnt = 0, bCnt = 0;

    for (char c : str) {
        if (c == 'a') {
            aCnt++;
        }
        else {
            bCnt++;
        }
    }

    if (aCnt == 0 || bCnt == 0) {
        cout << str.size();
        return 0;
    }

    char c = aCnt < bCnt ? 'a' : 'b';

    int left = 0, right = 0;
    int result = 0;
    int winCharCnt = 0;

    while (right < str.size()) {
        if (str[right] == c) {
            winCharCnt++;
        }
        right++;

        while (winCharCnt > m) {
            if (str[left] == c) {
                winCharCnt--;
            }
            left++;
        }

        //记录最大的那个
        int winSize = right - left;
        result = max(result, winSize);
    }

    cout << result << endl;

    return 0;
}

