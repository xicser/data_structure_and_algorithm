#include <iostream>
#include <string>
#include <stack>

using namespace std;

/* ¿®∫≈∆•≈‰ */
class Solution {
public:
    bool isValid(string s) {

        for (unsigned int i = 0; i < s.size(); i++) {

            char c = s[i];
            switch (c) {
                case '(':
                case '[':
                case '{':
                    stk.push(c);
                    break;

                default: {
                    if (stk.empty() == true) {
                        return false;
                    }
                    if (c == ')') {
                        if (stk.top() == '(') {
                            stk.pop();
                        }
                        else return false;
                    }
                    else if (c == ']') {
                        if (stk.top() == '[') {
                            stk.pop();
                        }
                        else return false;
                    }
                    else if (c == '}') {
                        if (stk.top() == '{') {
                            stk.pop();
                        }
                        else return false;
                    }

                    break;
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
