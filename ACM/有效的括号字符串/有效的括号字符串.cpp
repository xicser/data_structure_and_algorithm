// 有效的括号字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:

    bool process1(string s) {

        for (char& c : s) {
            if (c == '*') {
                c = '(';
            }
        }

        stack<char> stk;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push('(');
            }
            else if (s[i] == ')') {
                if (stk.empty() == false) {
                    char top = stk.top();
                    if (top == '(' || top == '*') {
                        stk.pop();
                    }
                    else {
                        return false;
                    }
                }
            }
            else {
                stk.push('*');
            }
        }

        return stk.empty() == true;
    }

    bool process2(string s) {

        for (char& c : s) {
            if (c == '*') {
                c = ')';
            }
        }

        stack<char> stk;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push('(');
            }
            else if (s[i] == ')') {
                if (stk.empty() == false) {
                    char top = stk.top();
                    if (top == '(' || top == '*') {
                        stk.pop();
                    }
                    else {
                        return false;
                    }
                }
            }
            else {
                stk.push('*');
            }
        }

        return stk.empty() == true;
    }

    /**
     *
     * @param s string字符串
     * @return bool布尔型
     */
    bool checkValidString(string s) {
        
        if (s.size() == 0) {
            return true;
        }
        return process1(s) || process2(s);
    }
};

int main()
{
    Solution sol;
    std::cout << sol.checkValidString("(*)") << endl;

    return 0;
}
