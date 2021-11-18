#include <iostream>
#include <functional>
#include <mutex>
#include <thread>

using namespace std;

class semaphore {
public:
    semaphore(int val) : m_count(val) {}

    void signal() {
        lock_guard<mutex> lg(mux);
        m_count++;
        cond.notify_one();
    }

    void wait() {
        unique_lock<mutex> ul(mux);
        cond.wait(ul, [=] { return m_count > 0; });
        m_count--;
    }

private:
    mutex mux;
    condition_variable cond;
    long m_count;
};

class FooBar {
private:
    int n;

public:
    FooBar(int n) : semF2B(0), semB2F(1) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {

        for (int i = 0; i < n; i++) {

            // printFoo() outputs "foo". Do not change or remove this line.
            semB2F.wait();
            printFoo();
            semF2B.signal();
        }
    }

    void bar(function<void()> printBar) {

        for (int i = 0; i < n; i++) {

            // printBar() outputs "bar". Do not change or remove this line.
            semF2B.wait();
            printBar();
            semB2F.signal();
        }
    }

    semaphore semF2B;
    semaphore semB2F;
};

int main()
{
    function<void()> f1 = []() { cout << "foo"; };
    function<void()> f2 = []() { cout << "bar"; };

    FooBar fb(100);
    thread t1(&FooBar::foo, ref(fb), f1);
    thread t2(&FooBar::bar, ref(fb), f2);

    t1.join();
    t2.join();
}
