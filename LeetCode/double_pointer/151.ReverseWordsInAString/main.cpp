#include <iostream>
#include <string>

using namespace std;
//elpmaxe doog a
class Solution {
public:
    string reverseWords(string s) {

        moveExtraSpace(s);
      //  cout << s << endl;
        reverseStr(s, 0, s.size() - 1);
      //  cout << s << endl;

        for (int i = 0; i < s.size(); ) {
            int j = i;
            while (j < s.size() && s[j] != ' ') {
                j++;
            }
            reverseStr(s, i, j - 1);
            i = j + 1;
        }

        return s;
    }

    //ecilA  sevoL boB
private:
    void moveExtraSpace(string& s) {

        int start = 0;
        while (s[start] == ' ') {
            start++;
        }
        s.erase(0, start);

        int end = s.size() - 1;
        while (s[end] == ' ') {
            end--;
        }
        s.erase(end + 1, s.size() - end);

        //双指针去除多余空格
        int spaceCnt = 0;
        int slow = 1;
        for (int fast = 1; fast < s.size(); fast++) {
            if (s[fast] == s[fast - 1] && s[fast] == ' ') {
                spaceCnt++;
                continue;
            }
            else {
                s[slow++] = s[fast];
            }
        }

        s.resize(s.size() - spaceCnt);
    }

    void reverseStr(string& s, int left, int right) {

        while (left < right) {
            char c = s[left];
            s[left] = s[right];
            s[right] = c;

            left++;
            right--;
        }
    }
};

int main()
{
    Solution sol;
    string str = " a   good   example  ";
    cout << sol.reverseWords(str) << endl;

    return 0;
}
