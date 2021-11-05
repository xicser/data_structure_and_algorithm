#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {

        double result = 0;
        bool negative;

        removePreSpace(s);

        int sIndex;
        if (s[0] == '-') {
            negative = true;
            sIndex = 1;
        }
        else if (s[0] == '+') {
            negative = false;
            sIndex = 1;
        }
        else {
            negative = false;
            sIndex = 0;
        }

        unsigned int e;
        for (e = sIndex; e < s.size(); e++) {
            //如果不是数字
            if (isNum(s[e]) == false) {
                break;
            }
        }
        e--;

        double k = 1;
        for (int i = e; i >= sIndex; i--, k *= 10) {
            result += (s[i] - 48) * k;
        }

        if (negative == true) {

            if (-result < INT_MIN) {
                return INT_MIN;
            }
            return -result;
        }
        else {
            if (result > INT_MAX) {
                return INT_MAX;
            }
            return result;
        }
    }

    //移除前导空格
    void removePreSpace(string &s) {
        unsigned int i = 0;
        for (; i < s.size(); i++) {
            if (s[i] != ' ') {
                break;
            }
        }

        for (int j = i - 1; j >= 0; j--) {
            s.erase(s.begin() + j);
        }
    }

    bool isNum(char c) {
        if ('0' <= c && c <= '9') {
            return true;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    string s = "  0000000000012345678";

//    sol.removePreSpace(s);
//    cout << s << endl;
//
//    sol.removePreZero(s);
//    cout << s << endl;

    cout << sol.myAtoi(s) << endl;
    return 0;
}
