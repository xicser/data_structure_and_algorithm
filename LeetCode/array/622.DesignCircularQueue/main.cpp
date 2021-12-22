#include <iostream>

using namespace std;

class MyCircularQueue {
private:
    int size;
    int total;
    int head, tail;
    int *buffer;

public:
    MyCircularQueue(int k) {
        this->total = 0;
        this->size = k;
        buffer = new int [this->size];
        head = tail = 0;
    }
    ~MyCircularQueue() {
        delete [] buffer;
    }

    bool enQueue(int value) {
        //已经满了
        if (this->total == this->size) {
            return false;
        }

        buffer[tail] = value;
        this->total++;
        tail = (tail + 1) % this->size;

        return true;
    }

    bool deQueue() {
        //为空
        if (this->total == 0) {
            return false;
        }

        // val =  buffer[head];
        this->total--;
        this->head = (head + 1) % this->size;

        return true;
    }

    int Front() {
        if (this->total == 0) {
            return -1;
        }
        return buffer[head];
    }

    int Rear() {
        if (this->total == 0) {
            return -1;
        }
        if (tail == 0) {
            return buffer[this->size - 1];
        }
        return buffer[tail - 1];
    }

    bool isEmpty() {
        return this->total == 0;
    }

    bool isFull() {
        return this->size == this->total;
    }
};


int main()
{
    MyCircularQueue circularQueue(3);
    cout << circularQueue.enQueue(1) << endl;
    cout << circularQueue.enQueue(2) << endl;
    cout << circularQueue.enQueue(3) << endl;
    cout << circularQueue.enQueue(4) << endl;
    cout << circularQueue.Rear() << endl;
    cout << circularQueue.isFull() << endl;
    cout << circularQueue.deQueue() << endl;
    cout << circularQueue.enQueue(4) << endl;
    cout << circularQueue.Rear() << endl;

    return 0;
}
