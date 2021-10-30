#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {

        for (int i = 0; i < s.size(); ) {
            reverseSubStr(s, i, i + k - 1);
            i += 2 * k;
        }

        return s;
    }

private:
    void reverseSubStr(string &s, int i, int j) {

        if (j >= s.size()) {
            j = s.size() - 1;
        }

        while (i <= j) {
            char tmpC = s[i];
            s[i] = s[j];
            s[j] = tmpC;

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
