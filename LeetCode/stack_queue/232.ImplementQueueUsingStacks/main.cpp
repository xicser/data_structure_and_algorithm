#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        inputStack.push(x);
    }

    int pop() {
        if (outputStack.empty() == true) {
            while (inputStack.empty() == false) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }

        int result = outputStack.top();
        outputStack.pop();

        return result;
    }

    int peek() {

        if (empty() == true) {
            return -1;
        }

        if (outputStack.empty() == true) {
            while (inputStack.empty() == false) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
        return outputStack.top();
    }

    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }

private:
    stack<int> inputStack;
    stack<int> outputStack;
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
