#include <iostream>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <thread>

using namespace std;

class H2O {
    atomic<int> h;
public:
    H2O() {
        h.store(0);
    }

    void hydrogen(function<void()> releaseHydrogen) {
        while (h == 2) {
            this_thread::yield();
        }
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        ++h;
    }

    void oxygen(function<void()> releaseOxygen) {
        while (h != 2) {
            this_thread::yield();
        }
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        h = 0;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
