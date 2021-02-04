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
void clearStack(stack<char> &st);
void stringAppend(string &s, char c);
bool checkPriority(char c1, char c2);

int main()
{
    string inputExp;
    getline(cin, inputExp);

    cout << calSuffix(convertInfix2Suffix(inputExp)) << endl;
    return 0;
}

//计算后缀表达式的值
double calSuffix(string suffix)
{
    stack<double> st;

    for (unsigned int i = 0; i < suffix.size(); i++) {

        char cTmp = suffix[i];

        if (isdigit(cTmp) == true) { //如果是数字
            st.push(cTmp - 48);
        }
        else {
            double num1, num2, res;
            num1 = st.top();
            st.pop();
            num2 = st.top();
            st.pop();

            switch (cTmp) {
                case '+': res = num1 + num2; break;
                case '-': res = num2 - num1; break;
                case '*': res = num1 * num2; break;
                case '/': res = num2 / num1; break;
                default: break;
            }
            st.push(res);
        }
    }

    return st.top();
}

//把中缀表达式转换成后缀表达式
//1+2*3+(4*5+6)*7
//123*+45*6+7*+
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
            // printf("%c", cTmp);
        }
        //如果是符号
        else {
            if (cTmp == '(') {
                st.push(cTmp);
            }
            else if (cTmp == ')') {
                while (st.top() != '(') {
                    // printf("%c", st.top());
                    stringAppend(suffix, st.top());
                    st.pop();
                }
                st.pop();
            }
            //+ - * /
            else {
                if (st.empty()) {
                    st.push(cTmp);
                }
                //cTemp优先级大于栈顶运算符
                else if (checkPriority(cTmp, st.top()) == true) {
                    st.push(cTmp);
                }
                else {
                    //如果有'(', 则把'('上面的, 优先级大于等于cTemp的运算符弹栈
                    //如果没有'(', 直接
                    while (!st.empty()) {
                        if (st.top() != '(') {
                            if (checkPriority(cTmp, st.top()) == false) {
                                // printf("%c", st.top());
                                stringAppend(suffix, st.top());
                                st.pop();
                            } else {
                                break;
                            }
                        } else {
                            break;
                        }
                    }
                    st.push(cTmp);
                }
            }
        }
    }

    while (!st.empty()) {
        // printf("%c", st.top());
        stringAppend(suffix, st.top());
        st.pop();
    }
    // printf("\n");

    return suffix;
}

//清空栈
void clearStack(stack<char> &st)
{
    while (!st.empty()) {
        st.pop();
    }
}

//给string追加
void stringAppend(string &s, char c)
{
    if (s.length() == 0) {
        s.insert(s.begin(), c);
    } else {
        s.insert(s.end(), c);
    }
}

//判断两个运算符的优先级, c1大于c2时, 返回true; 否则返回false
bool checkPriority(char c1, char c2)
{
    if ((c1 == '*' || c1 == '/') && (c2 == '+' || c2 == '-')) {
        return true;
    }
    if (c2 == '(') {
        return true;
    }

    return false;
}
