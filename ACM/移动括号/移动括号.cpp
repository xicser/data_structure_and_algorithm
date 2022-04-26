#include <iostream>
#include <stack>

using namespace std;

//  )))(((

int process(const string& str)
{

    int sum = 0;

    stack<char> stk;
    for (char c : str) {

        if (c == '(') {
            stk.push('(');
        }
        else {
            if (stk.empty() == false) {
                stk.pop();
            }
        }
    }

    return stk.size();
}

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {

        int n;
        cin >> n;

        string str;
        cin >> str;

        std::cout << process(str) << endl;
    }

    return 0;
}
