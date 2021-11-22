#include <iostream>
#include <functional>
#include <mutex>

using namespace std;

//信号量
class Semaphore {
public:
    Semaphore(int val) : m_count(val) {}

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

class FizzBuzz {
private:
    int n;
    int seq;
    bool done;
    Semaphore semDone;
    Semaphore semFizz;
    Semaphore semBuzz;
    Semaphore semFizzBuzz;

public:
    FizzBuzz(int n) : semDone(1), semFizz(0), semBuzz(0), semFizzBuzz(0)
    {
        this->done = false;
        this->n = n;
        this->seq = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (true) {
            semFizz.wait();
            if (this->done == true) {
                break;
            }
            printFizz();
            semDone.signal();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (true) {
            semBuzz.wait();
            if (this->done == true) {
                break;
            }
            printBuzz();
            semDone.signal();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        while (true) {
            semFizzBuzz.wait();
            if (this->done == true) {
                break;
            }
            printFizzBuzz();
            semDone.signal();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        for (; seq <= this->n; seq++) {

            semDone.wait();

            if (seq % 3 == 0 && seq % 5 == 0) {
                semFizzBuzz.signal();
            }
            else if (seq % 3 == 0) {
                semFizz.signal();
            }
            else if (seq % 5 == 0) {
                semBuzz.signal();
            }
            else {
                printNumber(seq);
                semDone.signal();
            }
        }

        semDone.wait();  //等最后那个打印线程打印完
        this->done = true;
        //唤醒所有可能阻塞在信号量上的线程
        semFizzBuzz.signal();
        semFizz.signal();
        semBuzz.signal();
    }
};

int main()
{
    function<void()> printFizz = []() {
        std::cout << "fizz" << endl;
    };
    function<void()> printBuzz = []() {
        std::cout << "buzz" << endl;
    };
    function<void()> printFizzBuzz = []() {
        std::cout << "fizzbuzz" << endl;
    };
    function<void(int)> printNumber = [](int x) {
        std::cout << x << endl;
    };

    FizzBuzz fizzBuzz(14);
    thread tFizz(&FizzBuzz::fizz, ref(fizzBuzz), printFizz);
    thread tBuzz(&FizzBuzz::buzz, ref(fizzBuzz), printBuzz);
    thread tFizzbuzz(&FizzBuzz::fizzbuzz, ref(fizzBuzz), printFizzBuzz);
    thread tNumber(&FizzBuzz::number, ref(fizzBuzz), printNumber);

    tFizz.join();
    tBuzz.join();
    tFizzbuzz.join();
    tNumber.join();
}

