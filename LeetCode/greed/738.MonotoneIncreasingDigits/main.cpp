#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string number = to_string(n);
        int len = number.size();

        /*
        遇到strNum[i - 1] > strNum[i]的情况, 让strNum[i-1]--, 然后strNum[i]给为9, 可以保证这两位
        变成最大单调递增（非减）整数
        */

        int idx = len;
        for (int i = len - 2; i >= 0; i--) {
            if (number[i] > number[i + 1]) {
                number[i]--;
                idx = i + 1;
            }
        }

        for (int i = idx; i < len; i++) {
            number[i] = '9';
        }

        return stoi(number);
    }
};

int main()
{
    Solution sol;

    cout << sol.monotoneIncreasingDigits(120) << endl;
    return 0;
}
