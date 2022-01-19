#include <iostream>
#include <string>
#include <string>

using namespace std;

class Solution {
public:
    //s = "abcd"    up
    //t = "bcdf"    down
    //maxCost = 3
    int equalSubstring(string s, string t, int maxCost) {
        int up = 0, down = 0;
        int winCnt = 0;  //当前窗口中的开销
        int result = 0;
        while (up < s.size()) {
            int costUp = abs(s[up] - t[up]);
            winCnt += costUp;
            up++;

            while (winCnt > maxCost) {
                int costDown = abs(s[down] - t[down]);
                winCnt -= costDown;
                down++;
            }

            //获取最大窗口长度
            int winSize = up - down;
            result = max(result, winSize);
        }

        return result;
    }
};

int main()
{
    Solution sol;
    std::cout << sol.equalSubstring("abcd", "abcd", 3) << endl;
    std::cout << sol.equalSubstring("abcd", "cdef", 3) << endl;
    std::cout << sol.equalSubstring("abcd", "acde", 0) << endl;
}
