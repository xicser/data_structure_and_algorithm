#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {

        for (char c : s) {
            if (stk.empty() == true) {
                stk.push(c);
            }
            else {
                if (stk.top() == c) {
                    stk.pop();
                }
                else {
                    stk.push(c);
                }
            }
        }

        string result;
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

    cout << sol.removeDuplicates("abbaca") << endl;
    return 0;
}
