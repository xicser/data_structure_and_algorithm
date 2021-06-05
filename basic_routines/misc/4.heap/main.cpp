#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;


// �󶥶�ʵ��
class MaxHeap {

public:
    MaxHeap(int limit) {
        this->heapSizeLimit = limit;
        this->heapSize = 0;
        heapArray = new int[this->heapSizeLimit];
    }
    ~MaxHeap() {
        delete []heapArray;
    }

    bool isEmpty() {
        return heapSize == 0;
    }

    bool isFull() {
        return heapSize == heapSizeLimit;
    }

    void push(int value) {
        if (heapSize == heapSizeLimit) {
            return;
        }

        heapArray[heapSize] = value;
        heapInsert(heapSize);
        heapSize++;
    }

    int pop() {
        if (heapSize == 0) {
            return -999999;
        }

        int tmp = heapArray[0];
        heapSize--;
        heapArray[0] = heapArray[heapSize];
        heapify();

        return tmp;
    }

private:
    int *heapArray;
    int heapSizeLimit;
    int heapSize;

    // ���󶥶��������һ���ڵ�
    void heapInsert(int heapIndex) {
        if (heapIndex == 0) {
            return;
        }

        int father = (heapIndex - 1) / 2;
        while (1) {

            if (heapArray[father] < heapArray[heapIndex]) {
                swap(heapArray, father, heapIndex);
                heapIndex = father;
                //�����˸��ڵ�
                if (heapIndex == 0) {
                    break;
                }
            } else {
                break;
            }

            father = (father - 1) / 2;
        }
    }

    // �Ӹ��ڵ�λ��, ���¿�, ���ϵ��³�
    void heapify() {

        if (heapSize == 0) {
            return;
        }

        int index = 0;
        int left = index * 2 + 1;
        while (left < heapSize) { // ���������, ��û���Һ���, �����п���û��
            // �ѽϴ��ӵ��±�, ��largest
            int largest = left + 1 < heapSize && heapArray[left + 1] > heapArray[left] ? left + 1 : left;
            largest = heapArray[largest] > heapArray[index] ? largest : index;
            if (largest == index) {
                break;
            }
            // index�ͽϴ���, Ҫ����
            swap(heapArray, largest, index);
            index = largest;
            left = index * 2 + 1;
        }
    }

    void swap(int *arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
};


class RightMaxHeap {

public:
    RightMaxHeap(int limit) {
        heapArray = new int[limit];
        this->heapSizeLimit = limit;
        heapSize = 0;
    }
    ~RightMaxHeap() {
        delete []heapArray;
    }

    bool isEmpty() {
        return heapSize == 0;
    }

    bool isFull() {
        return heapSize == heapSizeLimit;
    }

    void push(int value) {
        if (heapSize == heapSizeLimit) {
            return;
        }
        heapArray[heapSize++] = value;
    }

    int pop() {
        int maxIndex = 0;
        for (int i = 1; i < heapSize; i++) {
            if (heapArray[i] > heapArray[maxIndex]) {
                maxIndex = i;
            }
        }
        int ans = heapArray[maxIndex];
        heapArray[maxIndex] = heapArray[--heapSize];
        return ans;
    }

private:
    int *heapArray;
    int heapSizeLimit;
    int heapSize;
};

int main()
{
    srand((unsigned)time(NULL));

    int value = 1000;
    int limit = 100;
    int testTimes = 1000000;
    for (int i = 0; i < testTimes; i++) {
        int curLimit = rand() % limit + 1;
        MaxHeap *my = new MaxHeap(curLimit);
        RightMaxHeap *test = new RightMaxHeap(curLimit);
        int curOpTimes = rand() % limit + 1;
        for (int j = 0; j < curOpTimes; j++) {
            if (my->isEmpty() != test->isEmpty()) {
                printf("Oops!\n");
            }
            if (my->isFull() != test->isFull()) {
                printf("Oops!\n");
            }
            if (my->isEmpty()) {
                int curValue = rand() % value + 1;
                my->push(curValue);
                test->push(curValue);
            } else if (my->isFull()) {
                if (my->pop() != test->pop()) {
                    printf("Oops!\n");
                }
            }
        }
    }
    printf("finish!\n");

    return 0;
}
