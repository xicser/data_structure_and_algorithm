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
        int result = 0;
        int winCost = 0;        //记录当前窗口的花费

        while (down < t.size()) {
            winCost += abs(s[down] - t[down]);
            down++;

            while (winCost > maxCost) {
                winCost -= abs(s[up] - t[up]);
                up++;
            }

            int winSize = down - up;
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
