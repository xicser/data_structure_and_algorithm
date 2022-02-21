#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int n) {

        string number = std::to_string(n);

        /*
        遇到strNum[i - 1] > strNum[i]的情况, 让strNum[i-1]--, 然后strNum[i]给为9, 可以保证这两位
        变成最大单调递增（非减）整数
        */

        int index = -1;
        for (int i = number.size() - 2; i >= 0; i--) {
            if (number[i] > number[i + 1]) {
                number[i]--;
                index = i + 1;
            }
        }

        if (index != -1) {
            for (int i = index; i < number.size(); i++) {
                number[i] = '9';
            }
        }

        return atoi(number.c_str());
    }
};

int main()
{
    Solution sol;

    cout << sol.monotoneIncreasingDigits(1234) << endl;
    return 0;
}
