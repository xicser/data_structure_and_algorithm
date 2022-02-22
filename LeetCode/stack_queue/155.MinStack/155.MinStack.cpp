#include <iostream>
#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> stk;
    stack<int> stkMin;
public:
    MinStack() {

    }

    void push(int val) {

        stk.push(val);

        if (stkMin.size() > 0) {
            //看看minStk顶部元素的值是否小于val, 把较小的那个push进去
            int topValue = stkMin.top();
            topValue < val ? stkMin.push(topValue) : stkMin.push(val);
        }
        else {
            stkMin.push(val);
        }

    }

    void pop() {
        stk.pop();
        stkMin.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return stkMin.top();
    }
};

int main()
{
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    minStack.getMin();  // -- > 返回 - 3.
    minStack.pop();
    minStack.top();     // -- > 返回 0.
    minStack.getMin();  // -- > 返回 - 2.
}
