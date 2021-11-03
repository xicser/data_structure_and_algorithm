#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {

        string result;
        for (unsigned int i = 0; i < s.size(); i++) {

            if (stk.empty() == false) {
                if (s[i] == stk.top()) {
                    stk.pop();
                }
                else {
                    stk.push(s[i]);
                }
            }
            else {
                stk.push(s[i]);
            }
        }

        while (stk.empty() == false) {
            result.push_back(stk.top());
            stk.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }

private:
    stack<char> stk;
};

int main()
{
    Solution sol;

    cout << sol.removeDuplicates("azxxzy") << endl;
    return 0;
}
