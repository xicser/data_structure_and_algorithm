#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/*
2 4
ABCD
ABCE
1 2 3 4

*/

int getMost(unordered_map<char, int>& charCnt) {

    int maxCnt = -1;
    for (auto& it : charCnt) {
        int cnt = it.second;

        maxCnt = max(maxCnt, cnt);
    }

    return maxCnt;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> answer(n);
    vector<int> value(m);

    for (int i = 0; i < n; i++) {
        cin >> answer[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> value[i];
    }

    int result = 0;

    //处理每列, 找出每列中出现次数最多的那个字符
    for (int i = 0; i < m; i++) {
        unordered_map<char, int> charCnt;
        charCnt.clear();

        for (int j = 0; j < n; j++) {
            charCnt[ answer[j][i] ]++;
        }
        int count = getMost(charCnt);
        result += value[i] * count;
    }

    std::cout << result << endl;
}
