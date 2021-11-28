#include <iostream>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <thread>

using namespace std;

class H2O {
private:
    int m_count;
    mutex mux;
    condition_variable cond;
public:
    H2O() {
        m_count = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lock(mux);
        cond.wait(lock, [&] {
            return m_count < 2;
        });
        releaseHydrogen();
        m_count++;
        cond.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {

        unique_lock<mutex> lock(mux);
        cond.wait(lock, [&] {
            return m_count == 2;
        });
        m_count = 0;
        releaseOxygen();
        cond.notify_all();
    }
};

int main()
{
    return 0;
}
