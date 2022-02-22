#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        inStk.push(x);
    }

    int pop() {

        if (empty() == true) {
            return -1;
        }

        //只要发现out栈空了, 就把in栈里的所有元素导进去
        if (outStk.empty() == true) {
            while (inStk.empty() == false) {
                outStk.push(inStk.top());
                inStk.pop();
            }
        }

        int ret = outStk.top();
        outStk.pop();
        return ret;
    }

    int peek() {

        if (empty() == true) {
            return -1;
        }

        //只要发现out栈空了, 就把in栈里的所有元素导进去
        if (outStk.empty() == true) {
            while (inStk.empty() == false) {
                outStk.push(inStk.top());
                inStk.pop();
            }
        }

        return outStk.top();
    }

    bool empty() {
        return inStk.empty() == true && outStk.empty() == true;
    }

private:
    stack<int> inStk;
    stack<int> outStk;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
