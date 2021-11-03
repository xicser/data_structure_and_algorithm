#include <iostream>
#include <queue>
#include <stdio.h>

using namespace std;

class MyStack {
public:
    MyStack() {

    }

    void push(int x) {
        que.push(x);
    }

    int pop() {

        if (empty() == true) {
            return -1;
        }

        int cnt = que.size() - 1;
        while (cnt--) {
            int val = que.front();
            que.pop();
            que.push(val);
        }
        int val = que.front();
        que.pop();
        return val;
    }

    int top() {
        if (empty() == true) {
            return -1;
        }

        return que.back();
    }

    bool empty() {
        return que.empty();
    }

private:
    queue<int> que;
};

int main()
{
    MyStack* obj = new MyStack();
    obj->push(10);
    int param_2 = obj->pop();
    int param_3 = obj->top();
    bool param_4 = obj->empty();

    printf("%d %d %d\n", param_2, param_3, param_4);

    return 0;
}
