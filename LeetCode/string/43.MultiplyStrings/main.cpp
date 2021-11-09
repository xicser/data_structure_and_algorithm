#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
//num1 =  1 2 3 4
//num2 =    5 6 7
//
class Solution {
public:
    string multiply(string num1, string num2) {

        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        string result;
        vector<string> results;
        int zeroCnt = 0;
        for (int i = num2.size() - 1; i >= 0; i--) {
            results.push_back(oneStep(num1, num2[i], zeroCnt));
            zeroCnt++;
        }

        if (results.size() == 1) {
            return results[0];
        }
        if (results.size() == 2) {
            result = bigAdd(results[0], results[1]);
        }
        else {
            result = bigAdd(results[0], results[1]);
            for (unsigned int i = 2; i < results.size(); i++) {
                result = bigAdd(result, results[i]);
            }
        }

        return result;
    }

    //大数乘法中的一步
    string oneStep(string& num, char c, int zeroCnt) {
        string result;

        int carry = 0;
        for (int i = num.size() - 1; i >= 0; i--) {
             int val = (num[i] - 48) * (c - 48) + carry;
             result.push_back(val % 10 + 48);  //本位数字
             carry = val / 10;                 //进位数字
        }
        if (carry != 0) {
            result.push_back(carry + 48);
        }

        reverse(result.begin(), result.end());

        for (int i = 0; i < zeroCnt; i++) {
            result.push_back('0');
        }

        return result;
    }

    //大数加法
    string bigAdd(string num1, string num2) {

        string result;
        int carry = 0;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        for (; i >= 0 && j >= 0; i--, j--) {
            int val = num1[i] - 48 + num2[j] - 48 + carry;
            result.push_back(val % 10 + 48);  //个位数字
            carry = val / 10;                 //进位
        }

        //num1短, num2长
        if (i < 0 && j >= 0) {
            while (j >= 0) {
                int val = num2[j] - 48 + carry;
                result.push_back(val % 10 + 48);
                carry = val / 10;

                j--;
            }
        }
        else if (i >= 0 && j < 0) {
            while (i >= 0) {
                int val = num1[i] - 48 + carry;
                result.push_back(val % 10 + 48);
                carry = val / 10;

                i--;
            }
        }

        if (carry != 0) {
            result.push_back(carry + 48);
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

int main()
{
    Solution sol;
    cout << sol.multiply("9133", "0") << endl;

//    cout << sol.bigAdd("9999", "9999") << endl;
//    cout << sol.bigAdd("999924", "8991") << endl;

    return 0;
}
