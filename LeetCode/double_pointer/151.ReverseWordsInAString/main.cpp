#include <iostream>
#include <string>

using namespace std;
//elpmaxe doog a
class Solution {
public:
    string reverseWords(string s) {
        moveExtraSpace(s);
        reverseStr(s, 0, s.size() - 1);

        for (int i = 0; i < s.size(); ) {

            int j = i + 1;
            while (s[j] != ' ' && j < s.size()) {
                j++;
            }
            reverseStr(s, i, j - 1);
            i = j + 1;
        }

        return s;
    }

private:
    //�Ƴ�����ո�
    void moveExtraSpace(string &s) {

        for (int i = s.size() - 1; i > 0; i--) {
            if (s[i] == s[i - 1] && s[i] == ' ') {
                s.erase(s.begin() + i);
            }
        }

        // ɾ���ַ��������Ŀո�
        if (s.size() > 0 && s[s.size() - 1] == ' ') {
            s.erase(s.begin() + s.size() - 1);
        }
        // ɾ���ַ�����ǰ��Ŀո�
        if (s.size() > 0 && s[0] == ' ') {
            s.erase(s.begin());
        }
    }

    //��ת�����ַ���
    void reverseStr(string &s, int left, int right) {
        while (left <= right) {
            int tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;

            left++;
            right--;
        }
    }
};

int main()
{
    Solution sol;
    string str = "  Bob    Loves  Alice   ";
    cout << sol.reverseWords(str) << endl;

    return 0;
}
