#include "heap.h"

Heap::Heap(int limit,
    function<bool(const void* a, const void* b)> comparator) {
    this->heapSizeLimit = limit;
    this->heapSize = 0;
    this->heapArray = new void *[this->heapSizeLimit];
    this->comparator = comparator;
}

Heap::~Heap() {
    delete []heapArray;
}

void Heap::swap(int i, int j) {
    //同步更新indexMap
    void* a = heapArray[i];
    void* b = heapArray[j];
    indexMap[a] = j;
    indexMap[b] = i;

    void* tmp = heapArray[i];
    heapArray[i] = heapArray[j];
    heapArray[j] = tmp;
}

void Heap::heapInsert(int index) {

    //比他爸爸"大"
    while (comparator(heapArray[index],             //孩子
                      heapArray[(index - 1) / 2])   //爸爸
            == true) {
        swap(index, (index - 1) / 2);
        index = (index - 1) / 2;
    }
}

void Heap::heapify(int index)
{
    if (heapSize == 0) {
        return;
    }

    //左孩子下标
    int left = index * 2 + 1;

    //有左孩子
    while (left < heapSize) {

        //获取左右孩子中大的那个孩子的下标
        //右孩子存在且右孩子的值大于左孩子, 右孩子胜出, 否则左孩子胜出
        int right = left + 1;
        int largest = right < heapSize && comparator(heapArray[right], heapArray[left]) == true ? right : left;

        //当前节点和较大孩子节点比较大小, 取较大的那个的下标
        largest = comparator(heapArray[largest], heapArray[index]) == true ? largest : index;

        //两个孩子没有一个能干过当前父亲
        if (largest == index) {
            break;
        }

        swap(index, largest);
        index = largest;
        left = index * 2 + 1;
    }
}

void Heap::push(void* value) {
    if (heapSize == heapSizeLimit) {
        return;
    }

    heapArray[heapSize] = value;
    indexMap[value] = heapSize;  //同步更新indexMap

    heapInsert(heapSize);
    heapSize++;
}

void* Heap::top() {
    if (heapSize == 0) {
        return nullptr;
    }

    return heapArray[0];
}

void Heap::pop() {
    if (heapSize == 0) {
        return;
    }

    //同步更新indexMap
    indexMap.erase(heapArray[0]);

    heapSize--;
    heapArray[0] = heapArray[heapSize];

    //同步更新indexMap
    indexMap[ heapArray[0] ] = 0;

    heapify(0);
}

void Heap::adjust(void* value)
{
    int index = indexMap[value];
    heapInsert(index);
    heapify(index);
}

bool Heap::empty()
{
    return heapSize == 0;
}

bool Heap::full()
{
    return heapSize == heapSizeLimit;
}

int Heap::size()
{
    return this->heapSize;
}
