#include <iostream>
#include <stack>

using namespace std;

bool check()
{
    string str;
    cin >> str;

    stack<char> stk;

    for (int i = 0; i < str.size(); i++) {
        switch (str[i])
        {
        case '(':
            stk.push('(');
            break;

        case ')':
            if (stk.empty() == true) {
                return false;
            }
            if (stk.top() != '(') {
                return false;
            }
            stk.pop();
            break;

        default:
            if (str[i] != '(' && str[i] != ')') {
                return false;
            }
            break;
        }
    }

    return stk.empty() == true;
}

int main()
{
    if (check() == true) {
        std::cout << "YES" << endl;
    }
    else {
        std::cout << "NO" << endl;
    }

    return 0;
}
