#include <iostream>
#include <string>

using namespace std;



/*
3*[a232*[c]]

3*[acc]

*/

class Solution {
public:
    /**
     *
     * @param str string字符串
     * @return string字符串
     */
    string computeString(string str) {

        int len = str.size();

        for (int i = len - 1; i >= 0; i--) {

            if (str[i] == '[') {
                //提取中括号里的串
                int j = i + 1;
                while (str[j] != ']') {
                    j++;
                }
                string sub = str.substr(i + 1, j - i - 1);

                //提取次数
                int k = i - 2;
                while (k >= 0 && isNum(str[k]) == true) {
                    k--;
                }
                string timesStr = str.substr(k + 1, i - 1 - (k + 1));
                int times = atoi(timesStr.c_str());

                //合成
                string strAdd;
                for (int i = 0; i < times; i++) {
                    strAdd += sub;
                }

                str.replace(k + 1, (j + 1) - (k + 1), strAdd);

                i = k;
            }
        }

        return str;
    }

private:
    bool isNum(char c) {
        return '0' <= c && c <= '9';
    }
};

int main()
{
    Solution sol;
    cout << sol.computeString("3*[a2*[c]]") << endl;
}
