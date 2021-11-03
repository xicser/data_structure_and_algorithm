#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        string result;
        for (unsigned int i = 0; i < tokens.size(); i++) {
            string token = tokens[i];
            if (token == "+") {
                int value1 = atoi(stk.top().c_str());
                stk.pop();
                int value2 = atoi(stk.top().c_str());
                stk.pop();

                result = to_string(value1 + value2);
                stk.push(result);
            }
            else if (token == "-") {
                int value1 = atoi(stk.top().c_str());
                stk.pop();
                int value2 = atoi(stk.top().c_str());
                stk.pop();

                result = to_string(value2 - value1);
                stk.push(result);
            }
            else if (token == "*") {
                int value1 = atoi(stk.top().c_str());
                stk.pop();
                int value2 = atoi(stk.top().c_str());
                stk.pop();

                result = to_string(value1 * value2);
                stk.push(result);
            }
            else if (token == "/") {
                int value1 = atoi(stk.top().c_str());
                stk.pop();
                int value2 = atoi(stk.top().c_str());
                stk.pop();

                result = to_string(value2 / value1);
                stk.push(result);
            }
            else {
                stk.push(token);
            }
        }

        return atoi(stk.top().c_str());
    }

private:
    stack<string> stk;
};

int main()
{
    Solution sol;
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};

    cout << sol.evalRPN(tokens) << endl;
    return 0;
}
