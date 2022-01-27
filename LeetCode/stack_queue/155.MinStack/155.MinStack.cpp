#include <iostream>
#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> stk;
    stack<int> minStk;

public:
    MinStack() {

    }

    void push(int val) {

        stk.push(val);

        if (minStk.size() > 0) {
            int topMin = minStk.top();
            if (topMin < val) {
                minStk.push(topMin);
            }
            else {
                minStk.push(val);
            }
        }
        else {
            minStk.push(val);
        }
    }

    void pop() {
        stk.pop();
        minStk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minStk.top();
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
