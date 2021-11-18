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

class ZeroEvenOdd {
private:
    int n;

public:
    ZeroEvenOdd(int n) : which(1), semOdd(0), semEven(0), semZero(1) {
        this->n = n;
    }

    void zero(function<void(int)> printNumber) {
        
        for (int i = 0; i < n; i++) {
            
            semZero.wait();

            printNumber(0);

            if (which == 1) {
                which = 2;
                semOdd.signal();
            }
            else {
                which = 1;
                semEven.signal();
            }
        }
    }

    void odd(function<void(int)> printNumber) {

        for (int i = 1; i <= n; i += 2) {
            semOdd.wait();
            printNumber(i);

            semZero.signal();
        }
    }

    void even(function<void(int)> printNumber) {

        for (int i = 2; i <= n; i += 2) {
            semEven.wait();
            printNumber(i);

            semZero.signal();
        }
    }

private:
    int which;        //表示当前正在打印哪个: 奇数or偶数

    semaphore semEven;
    semaphore semOdd;
    semaphore semZero;
};

int main()
{
    ZeroEvenOdd zeroEvenOdd(99);
    function<void(int)> printNumber = [=](int n) {cout << n; };

    thread thread1(&ZeroEvenOdd::zero, ref(zeroEvenOdd), printNumber);
    thread thread2(&ZeroEvenOdd::odd, ref(zeroEvenOdd), printNumber);
    thread thread3(&ZeroEvenOdd::even, ref(zeroEvenOdd), printNumber);

    thread1.join();
    thread2.join();
    thread3.join();
}
