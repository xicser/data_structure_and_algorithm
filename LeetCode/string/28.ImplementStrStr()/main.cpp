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

        int i = 0, j = 0;  //iָ��text, jָ��pattern
        while (i < text.size()) {

            if (j == pattern.size() - 1 && pattern[j] == text[i]) {
                index = i - j;
                break;
            }

            if (text[i] == pattern[j]) {
                i++;
                j++;
            }
            else {
                //�����ҵ���һ��λ��
                if (j == 0) {
                    i++;
                }
                else {
                    j = next[j - 1];
                }
            }
        }

        return index;
    }

private:
    //����next����
    void makeNext(const string &pattern, vector<int> &next) {
        int len = 0;  //len��ʾindex֮ǰ������ǰ��׺�ĳ���
        next[0] = 0;
        for (int index = 1; index < pattern.size(); index++) {

            while (len > 0 && pattern[len] != pattern[index]) {
                len = next[len - 1];
            }
            if (pattern[len] == pattern[index]) {
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
