#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

class Solution {
public:
    int strStr(string text, string pattern) {

        if (text.size() == 0 && pattern.size() == 0) {
            return 0;
        }
        if (text.size() < pattern.size()) {
            return -1;
        }
        if (text.size() != 0 && pattern.size() == 0) {
            return 0;
        }

        vector<int> next(pattern.size(), 0);
        makeNext(pattern, next);

        int index = -1;

        int i = 0, j = 0;  //i指向text, j指向pattern
        while (i < text.size()) {

            //找到一个
            if (j == pattern.size() - 1 && text[i] == pattern[j]) {
                index = i - j;
                break;  //只用找到一个就行
            }

            if (text[i] == pattern[j]) {
                i++;
                j++;
            }
            else {
                if (j != 0) {
                    j = next[j - 1];
                }
                else {
                    i++;
                }
            }
        }

        return index;
    }

private:
    //计算next数组
    void makeNext(const string &pattern, vector<int> &next) {
        int len = 0;
        next[0] = 0;
        for (int index = 1; index < pattern.size(); index++) {
            while(len > 0 && pattern[index] != pattern[len]) {
                len = next[len - 1];
            }
            if (pattern[index] == pattern[len]) {
                len++;
            }
            next[index] = len;
        }
    }
};

int main()
{
    Solution sol;

    cout << sol.strStr("aaa", "a") << endl;
    return 0;
}
