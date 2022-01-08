#include <iostream>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;


//���ݽṹ��
typedef struct tagStudent_t{
    int id;         //ѧ��ѧ��
    int age;        //ѧ������

    tagStudent_t(int id, int age) {
        this->id = id;
        this->age = age;
    }
} Student_t;


// ����id��С, �����ʵ��
class MaxHeap {

public:
    MaxHeap(int limit) {
        this->heapSizeLimit = limit;
        this->heapSize = 0;
        heapArray = new Student_t *[this->heapSizeLimit];
    }
    ~MaxHeap() {
//        for (int i = 0; i < this->heapSizeLimit; i++) {
//            delete heapArray[i];
//        }
        delete []heapArray;
    }

    bool isEmpty() {
        return heapSize == 0;
    }

    bool isFull() {
        return heapSize == heapSizeLimit;
    }

    bool push(Student_t *student) {
        if (heapSize == heapSizeLimit) {
            return false;
        }

        heapArray[heapSize] = student;

        //����map
        mp[student] = heapSize;

        heapInsert(heapArray, heapSize);
        heapSize++;

        return true;
    }

    bool pop(Student_t **studentOut) {
        if (heapSize == 0) {
            *studentOut = nullptr;
            return false;
        }

        *studentOut = heapArray[0];
        heapSize--;
        heapArray[0] = heapArray[heapSize];

        //����map
        mp[ heapArray[heapSize] ] = 0;

        heapify(heapArray, 0, heapSize);

        return true;
    }

    void adjust(Student_t *stu) {
        int index = mp[stu];

        heapInsert(heapArray, index);
        heapify(heapArray, index, this->heapSize);
    }

private:
    Student_t **heapArray;
    int heapSizeLimit;
    int heapSize;
    map <Student_t *, int> mp;  //��¼ÿ��student���ĸ�λ����

    // ���󶥶��������һ���ڵ�
    void heapInsert(Student_t **heapArray, int heapIndex) {
        if (heapIndex == 0) {
            return;
        }

        int father = (heapIndex - 1) / 2;
        while (1) {

            if (heapArray[father]->id < heapArray[heapIndex]->id) { //�����ִ�

                //����map
                mp[ heapArray[father] ] = heapIndex;
                mp[ heapArray[heapIndex] ] = father;

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
    void heapify(Student_t **heapArray, int index, int heapSize) {

        if (heapSize == 0) {
            return;
        }

        int left = index * 2 + 1;
        while (left < heapSize) { // ���������, ��û���Һ���, �����п���û��
            // �ѽϴ��ӵ��±�, ��largest
            int largest = left + 1 < heapSize && heapArray[left + 1]->id > heapArray[left]->id ? left + 1 : left;
            largest = heapArray[largest]->id > heapArray[index]->id ? largest : index;
            if (largest == index) {
                break;
            }

            //����map
            mp[ heapArray[largest] ] = index;
            mp[ heapArray[index] ] = largest;

            // index�ͽϴ���, Ҫ����
            swap(heapArray, largest, index);
            index = largest;
            left = index * 2 + 1;
        }
    }

    void swap(Student_t **arr, int i, int j) {
        Student_t *tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
};

int main()
{
    MaxHeap *maxHeap = new MaxHeap(10000);

    Student_t *stu1 = new Student_t(1, 12);
    Student_t *stu2 = new Student_t(6, 76);
    Student_t *stu3 = new Student_t(7, 78);
    Student_t *stu4 = new Student_t(2, 21);
    Student_t *stu5 = new Student_t(3, 34);
    Student_t *stu6 = new Student_t(8, 32);
    Student_t *stu7 = new Student_t(4, 54);
    Student_t *stu8 = new Student_t(9, 11);
    Student_t *stu9 = new Student_t(5, 56);

    cout << maxHeap->push(stu1) << endl;
    cout << maxHeap->push(stu2) << endl;
    cout << maxHeap->push(stu3) << endl;
    cout << maxHeap->push(stu4) << endl;
    cout << maxHeap->push(stu5) << endl;
    cout << maxHeap->push(stu6) << endl;
    cout << maxHeap->push(stu7) << endl;
    cout << maxHeap->push(stu8) << endl;
    cout << maxHeap->push(stu9) << endl;

    cout << endl;
    while (maxHeap->isEmpty() == false) {
        Student_t *student = nullptr;
        maxHeap->pop(&student);
        cout << "id = " << student->id << " age = " << student->age << endl;
    }

    cout << endl;
    cout << maxHeap->push(stu1) << endl;
    cout << maxHeap->push(stu2) << endl;
    cout << maxHeap->push(stu3) << endl;
    cout << maxHeap->push(stu4) << endl;
    cout << maxHeap->push(stu5) << endl;
    cout << maxHeap->push(stu6) << endl;
    cout << maxHeap->push(stu7) << endl;
    cout << maxHeap->push(stu8) << endl;
    cout << maxHeap->push(stu9) << endl;

    stu1->id = 100;
    maxHeap->adjust(stu1);
    cout << endl;
    while (maxHeap->isEmpty() == false) {
        Student_t *student = nullptr;
        maxHeap->pop(&student);
        cout << "id = " << student->id << " age = " << student->age << endl;
    }

    delete maxHeap;
    delete stu1; delete stu2; delete stu3; delete stu4; delete stu5; delete stu6; delete stu7;
    delete stu8; delete stu9;

    return 0;
}
