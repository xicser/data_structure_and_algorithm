#include <iostream>
#include <unordered_set>
#include "heap.h"

using namespace std;

//学生
struct Student_t {
    int grade;
    string name;
    Student_t(int grade, string name) {
        this->grade = grade;
        this->name = name;
    }
};

// 对数器测试用
class RightMaxHeap {
private:
    void** heapArray;
    int heapSizeLimit;
    int heapSize;
    //比较器, 用于确定堆中元素的"逻辑大小关系"
    function<bool(const void* a, const void* b)> comparator;

public:
    RightMaxHeap(int limit, function<bool(const void* a, const void* b)> comparator) {
        this->heapSizeLimit = limit;
        heapArray = new void* [limit];
        this->heapSize = 0;
        this->comparator = comparator;
    }
    ~RightMaxHeap() {
        delete[] heapArray;
    }

    bool empty() {
        return heapSize == 0;
    }

    bool full() {
        return heapSize == heapSizeLimit;
    }

    void push(void* value) {
        if (heapSize == heapSizeLimit) {
            return;
        }
        heapArray[heapSize++] = value;
    }

    void pop() {
        if (heapSize == 0) {
            return;
        }

        int maxIndex = 0;
        for (int i = 1; i < heapSize; i++) {
            if (this->comparator(heapArray[i], heapArray[maxIndex]) == true) {
                maxIndex = i;
            }
        }
        heapArray[maxIndex] = heapArray[--heapSize];
    }

    void* top() {
        if (heapSize == 0) {
            return nullptr;
        }

        int maxIndex = 0;
        for (int i = 1; i < heapSize; i++) {
            if (this->comparator(heapArray[i], heapArray[maxIndex]) == true) {
                maxIndex = i;
            }
        }

        return heapArray[maxIndex];
    }
};

int globalGrade = INT_MIN;
void test()
{
    srand((unsigned)time(NULL));

    int value = 1000;
    int limit = 100;
    int testTimes = 1000000;

    //比较器
    function<bool(const void* a, const void* b)> comparator = [](const void* a, const void* b) {
        return ((Student_t*)(a))->grade > ((Student_t*)(b))->grade;
    };

    for (int i = 0; i < testTimes; i++) {

        int curLimit = rand() % limit + 1;

        Heap* my = new Heap(curLimit, comparator);
        RightMaxHeap* test = new RightMaxHeap(curLimit, comparator);
        unordered_set<Student_t*> stuSet;

        int curOpTimes = rand() % limit + 1;
        for (int j = 0; j < curOpTimes; j++) {

            if (my->empty() != test->empty()) {
                printf("Oops!\n");
            }
            if (my->full() != test->full()) {
                printf("Oops!\n");
            }

            if (my->empty() == true) {
                Student_t* stu = new Student_t(globalGrade++, "zhangsan");
                stuSet.insert(stu);
                my->push(stu);
                test->push(stu);
            }
            else if (my->full() == true) {
                Student_t* topMy = (Student_t*)my->top();
                Student_t* topTest = (Student_t*)test->top();
                my->pop();
                test->pop();
                if (topMy != topTest) {
                    printf("Oops!\n");
                }
            }
            else {
                if (rand() < RAND_MAX / 2) {
                    Student_t* stu = new Student_t(globalGrade++, "lisi");
                    stuSet.insert(stu);
                    my->push(stu);
                    test->push(stu);
                }
                else {
                    Student_t* topMy = (Student_t*)my->top();
                    Student_t* topTest = (Student_t*)test->top();
                    my->pop();
                    test->pop();
                    if (topMy != topTest) {
                        printf("Oops!\n");
                    }
                }
            }
        }

        for (Student_t* stu : stuSet) {
            delete stu;
        }

        delete my;
        delete test;
    }
    printf("finish!\n");
}

int main()
{
//    test();

    Student_t* stu1 = new Student_t(1, "zhangsan");
    Student_t* stu2 = new Student_t(2, "lisi");
    Student_t* stu3 = new Student_t(3, "wangwu");

    //比较器
    function<bool(const void* a, const void* b)> comparator = [](const void* a, const void* b) {
        return ((Student_t*)(a))->grade > ((Student_t*)(b))->grade;
    };
    Heap* my = new Heap(3, comparator);

    my->push(stu1);
    my->push(stu2);
    my->push(stu3);

    stu1->grade = 10;
    my->adjust(stu3);

    while (my->empty() == false) {
        Student_t* stu = (Student_t*)my->top();
        my->pop();
        printf("%d %s\n", stu->grade, stu->name.c_str());
    }


}