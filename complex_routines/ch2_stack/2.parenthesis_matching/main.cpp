#include <iostream>
#include <string>
#include <stack>

using namespace std;

//清空栈
static void clearStack(stack<char> &st);
bool isMatch(string str);

//[ ( { } [ ] ) ]
//[({}[])]
int main()
{
    string str;
    getline(cin, str);

    if (isMatch(str)) {
        cout << "yes !" << endl;
    } else {
        cout << "No !" << endl;
    }

    return 0;
}

bool isMatch(string str)
{
    stack<char> st;
    clearStack(st);
    for (unsigned int i = 0; i < str.length(); i++) {

        if (str[i] == ' ') {
            continue;
        }
        switch (str[i]) {
            case '(':
            case '[':
            case '{':
                st.push(str[i]);
                break;

            case ')':
                if (st.top() == '(') {
                    st.pop();
                } else {
                    return false;
                }
                break;

            case ']':
                if (st.top() == '[') {
                    st.pop();
                } else {
                    return false;
                }
                break;

            case '}':
                if (st.top() == '{') {
                    st.pop();
                } else {
                    return false;
                }
                break;

            default: break;
        }
    }

    if (st.empty()) return true;
    else return false;
}

//清空栈
static void clearStack(stack<char> &st)
{
    while (!st.empty()) {
        st.pop();
    }
}
