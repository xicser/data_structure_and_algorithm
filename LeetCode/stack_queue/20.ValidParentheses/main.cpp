#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {

        for (unsigned int i = 0; i < s.size(); i++) {

            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stk.push(s[i]);
            }
            else {
                if (stk.empty() == true) {
                    return false;
                }

                switch (s[i]) {
                case ')':
                    if (stk.top() == '(') {
                        stk.pop();
                    }
                    else return false;
                    break;
                case ']':
                    if (stk.top() == '[') {
                        stk.pop();
                    }
                    else return false;
                    break;
                case '}':
                    if (stk.top() == '{') {
                        stk.pop();
                    }
                    else return false;
                    break;

                default: break;
                }
            }
        }

        return stk.empty();
    }

private:
    stack<char> stk;
};

int main()
{
    Solution sol;

    cout << sol.isValid("()") << endl;
    cout << sol.isValid("()[]{}") << endl;

    return 0;
}
