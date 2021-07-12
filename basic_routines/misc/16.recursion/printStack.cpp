#include "printStack.h"

//移除栈底元素, 并返回这个元素
static char removeBottom(stack<char> &st)
{
    char result = st.top();
    st.pop();

    if (st.empty() == true) {
        return result;
    }
    else {
        char last = removeBottom(st);
        st.push(result);
        return last;
    }
}

//逆序栈
void reverseStack(stack<char> &st)
{
    if (st.empty() == true) {
        return;
    }
    char i = removeBottom(st);
    reverseStack(st);
    st.push(i);
}
