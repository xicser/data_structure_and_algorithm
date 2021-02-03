/*
表达式求值:
先将中缀表达式转换为后缀表达式,
然后求后缀表达式的值
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <stack>
#include <ctype.h>

using namespace std;

double calSuffix(string suffix);
string convertInfix2Suffix(string infix);
static bool checkPriority(char c1, char c2);
static void clearStack(stack<char> &st);
static void stringAppend(string &s, char c);

int main()
{
    string inputExp;
    cin >> inputExp;
    //cout << calSuffix(convertInfix2Suffix(inputExp)) << endl;
convertInfix2Suffix(inputExp);
//    cout << convertInfix2Suffix(inputExp) << endl;



    return 0;
}


//计算后缀表达式的值
double calSuffix(string suffix)
{

}

//把中缀表达式转换成后缀表达式
string convertInfix2Suffix(string infix)
{
    string suffix;
    suffix.clear();
    stack<char> st;
    clearStack(st);

    for (unsigned int i = 0; i < infix.size(); i++) {

        char cTmp = infix[i];
        if (isdigit(cTmp) == true) { //如果是数字
            stringAppend(suffix, cTmp);
            printf("%c", cTmp);
        }
        else { //如果是符号

            if (st.empty()) {   //栈为空直接入栈
                st.push(cTmp);
                continue;
            }
            switch (cTmp) {
                case '(': {     //左括号直接入栈
                    st.push(cTmp);
                    break;
                }
                case ')': {
                    while (st.top() != '(') {
                        stringAppend(suffix, st.top());
                        printf("%c", st.top());
                        st.pop();
                    }
                    st.pop();
                    break;
                }
                //其他符号: + - * /
                default: {
                    //比栈顶运算符优先级高, 或者栈为空, 直接入栈
                    if (checkPriority(cTmp, st.top()) == true || st.empty()) {
                        st.push(cTmp);
                    } else {
                        while (checkPriority(cTmp, st.top() == false) && (!st.empty())) {
                            stringAppend(suffix, st.top());
                            printf("%c", st.top());
                            st.pop();
                        }
                        st.push(cTmp);
                    }
                    break;
                }
            }
        }
    }

    while (!st.empty()) {
        stringAppend(suffix, st.top());
        printf("%c", st.top());
        st.pop();
    }

    return suffix;
}

//判断两个运算符的优先级, c1大于c2时, 返回true; 否则返回false
static bool checkPriority(char c1, char c2)
{
    if ((c1 == '*' || c1 == '/') && (c2 == '+' || c2 == '-')) {
        return true;
    }

    return false;
}

//清空栈
static void clearStack(stack<char> &st)
{
    while (!st.empty()) {
        st.pop();
    }
}

//给string追加
static void stringAppend(string &s, char c)
{
    s.insert(s.end() - 1, c);
}
