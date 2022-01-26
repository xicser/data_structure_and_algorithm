#include <iostream>
#include <string>

using namespace std;

class Solution {

private:
    void reverseStr(string& str, int start, int end) {
        while (start < end) {

            char tmpChar = str[start];
            str[start] = str[end];
            str[end] = tmpChar;

            start++;
            end--;
        }
    }

public:
    //"Let's take LeetCode contest"
    string reverseWords(string s) {

        int left = 0, right = 0;
        s.push_back(' ');
        while (right < s.size()) {

            if (s[right] == ' ') {
                reverseStr(s, left, right - 1);
                right++;
                left = right;
            }
            else {
                right++;
            }
        }
        s.erase(s.end() - 1);

        return s;
    }
};

int main()
{
    Solution sol;
    cout << sol.reverseWords("Let's take") << endl;
}
