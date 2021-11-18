#include <iostream>
#include <functional>
#include <mutex>
#include <condition_variable>

using namespace std;

/* 借助互斥量和条件变量实现信号量  */
class Semaphore {
public:
    Semaphore(long count = 0) : m_count(count) {
    
    }
    void Signal() {
        std::unique_lock<std::mutex> lock(_mutex);
        ++m_count;
        _cv.notify_one();
    }
    void Wait() {
        std::unique_lock<std::mutex> lock(_mutex);
        _cv.wait(lock, [=] {return m_count > 0; });
        --m_count;
    }

private:
    std::mutex _mutex;
    std::condition_variable _cv;
    long m_count;
};

class Foo {
public:
    Foo() : semA2B(0), semB2C(0) {

    }

    void first(function<void()> printFirst) {

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        semA2B.Signal();
    }

    void second(function<void()> printSecond) {

        semA2B.Wait();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        semB2C.Signal();
    }

    void third(function<void()> printThird) {

        semB2C.Wait();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }

private:
    Semaphore semA2B;
    Semaphore semB2C;
};


int main()
{
    std::cout << "Hello World!\n";
}
