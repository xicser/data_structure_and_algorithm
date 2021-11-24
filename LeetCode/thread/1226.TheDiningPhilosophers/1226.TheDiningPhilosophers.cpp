#include <iostream>
#include <functional>
#include <mutex>
#include <thread>

using namespace std;

class DiningPhilosophers {
private:
    mutex forks[5];
    mutex lock;
public:
    DiningPhilosophers() {

    }

    void wantsToEat(int philosopher,
        function<void()> pickLeftFork,
        function<void()> pickRightFork,
        function<void()> eat,
        function<void()> putLeftFork,
        function<void()> putRightFork) {

        int left, right;
        if (philosopher == 0) {
            left = 0;
            right = 4;
        }
        else {
            left = philosopher;
            right = philosopher - 1;
        }

        //同时锁住两个
        lock.lock();
        forks[left].lock();
        forks[right].lock();
        lock.unlock();

        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();

        forks[left].unlock();
        forks[right].unlock();
    }
};

int main()
{
    DiningPhilosophers diningPhilosophers;

   // thread tph1(&DiningPhilosophers::wantsToEat, ref(diningPhilosophers));


    std::cout << "Hello World!\n";
}

