#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    string input;
    cin >> input;

    stack<char> stk;


    for (int i = 0; i < input.size(); i++) {
        char c = input[i];

        switch (c)
        {
        case '(':
            stk.push(c);
            break;

        case ')':
            while (stk.empty() == false) {
                char cTop = stk.top();
                if (cTop == '(') {
                    stk.pop();
                    break;
                }
                else {
                    stk.pop();
                }
            }
            break;

        case '<':
            if (stk.empty() == false) {
                stk.pop();
            }
            break;

        default:
            stk.push(c);
            break;
        }
    }

    string result;
    while (stk.empty() == false) {
        result.push_back(stk.top());
        stk.pop();
    }

    reverse(result.begin(), result.end());

    std::cout << result << endl;

    return 0;
}
