#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {

        if (s.size() == 0) {
            return false;
        }

        vector<int> next(s.size(), 0);
        getNext(s, next);
        int len = s.size();
        if (next[len - 1] != 0 && len % (len - next[len - 1]) == 0) {
            return true;
        }
        return false;
    }

private:

    // KMP里面的求next数组
    void getNext(const string &pattern, vector<int> &next) {

        int len = 0;
        int i = 1;
        for (; i < pattern.size(); i++) {

            while (len > 0 && pattern[len] != pattern[i]) {
                len = next[len - 1];
            }

            if (pattern[len] == pattern[i]) {
                len++;
            }

            next[i] = len;
        }
    }
};

int main()
{
    Solution sol;

    cout << sol.repeatedSubstringPattern("abcabcabcabc") << endl;
    cout << sol.repeatedSubstringPattern("abac") << endl;

    return 0;
}
