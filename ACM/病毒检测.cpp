#include <string>
#include <iostream>

using namespace std;

//2
//01010
int main()
{
    int k;
    string s;

    cin >> k >> s;

    int result = 0;

    int len = s.size();
    for (int i = 0; i < len; i++) {
        int winKCnt = 0;
        int left = i, right = i;

        while (right < len) {
            if (s[right] == '1') {
                winKCnt++;
            }
            right++;

            //找到第一个满足的
            if (winKCnt == k) {
                result++;

                //直到它不满足
                while (right < len && s[right] == '0') {
                    result++;
                    right++;
                }
                break;
            }
        }
    }

    std::cout << result << endl;

    return 0;
}
