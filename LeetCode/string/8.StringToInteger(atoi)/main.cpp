#include <iostream>

using namespace std;


class Solution {
public:
    int myAtoi(string s) {

        double result = 0;
        bool negative;

        int sIndex = 0;
        //移除空格
        for (; sIndex < s.size(); sIndex++) {
            if (s[sIndex] != ' ') {
                break;
            }
        }

        if (s[sIndex] == '-') {
            negative = true;
            sIndex++;
        }
        else if (s[sIndex] == '+') {
            negative = false;
            sIndex++;
        }
        else {
            negative = false;
        }

        int e;
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
    string s = "42";

//    sol.removePreSpace(s);
//    cout << s << endl;
//
//    sol.removePreZero(s);
//    cout << s << endl;

    cout << sol.myAtoi(s) << endl;
    return 0;
}
