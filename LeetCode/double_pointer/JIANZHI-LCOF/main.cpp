#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int spaceCnt = 0;
        int oldLen = s.size();
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                spaceCnt++;
            }
        }

        // 一个空格扩充两个
        s.resize(s.size() + spaceCnt * 2);
        int newLen = s.size();

        //从后向前遍历
        for (int i = oldLen - 1, j = newLen - 1; i >= 0; ) {

            if (s[i] != ' ') {
                s[j] = s[i];
                i--;
                j--;
            }
            else {
                s[j] = '0'; j--;
                s[j] = '2'; j--;
                s[j] = '%'; j--;
                i--;
            }
        }

        return s;
    }
};

int main()
{
    Solution sol;

    cout << sol.replaceSpace("we are h") << endl;
    return 0;
}
