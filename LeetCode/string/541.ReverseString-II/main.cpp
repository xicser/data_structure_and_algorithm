#include <iostream>
#include <string>

using namespace std;

//s = "abcd efg", k = 2
class Solution {
public:
    string reverseStr(string s, int k) {

        for (int i = 0; i < s.size(); ) {
            reverseString(s, i, i + k - 1);
            i += 2 * k;
        }

        return s;
    }

private:
    void reverseString(string& str, int i, int j) {

        if (j >= str.size()) {
            j = str.size() - 1;
        }

        while (i < j) {
            char tmp = str[i];
            str[i] = str[j];
            str[j] = tmp;

            i++;
            j--;
        }

    }
};

int main()
{
    Solution sol;
    string str = sol.reverseStr("abcde", 2);
    cout << str << endl;
    return 0;
}
