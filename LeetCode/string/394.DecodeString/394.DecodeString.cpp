// 394.DecodeString.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

using namespace std;

// "abc3[cd]xyz"
class Solution {
private:
    bool isNum(char c) {
        if ('0' <= c && c <= '9') {
            return true;
        }

        return false;
    }

public:
    string decodeString(string s) {
        
        for (int i = s.size() - 1; i >= 0; ) {

            int j = i;
            while (j >= 0 && s[j] != '[') {
                j--;
            }
            if (j < 0) {
                break;
            }

            //往前找数字
            int k = j - 1;
            while (k >= 0 && isNum(s[k]) == true) {
                k--;
            }

            string numStr = s.substr(k + 1, j - (k + 1));
            int times = atoi(numStr.c_str());

            //找[]中的字符串
            int q = j + 1;
            while (q < s.size() && s[q] != ']') {
                q++;
            }

            string repeat = s.substr(j + 1, q - (j + 1));

            string replace;
            for (int n = 0; n < times; n++) {
                replace += repeat;
            }

            s.replace(k + 1, q + 1 - (k + 1), replace);

            i = k;
        }

        return s;
    }
};

int main()
{
    Solution sol;
    
    std::cout << sol.decodeString("abc3[cd]xyz") << endl;

    return 0;
}

