#include <iostream>
#include <queue>
#include <algorithm>
#include <stdio.h>

using namespace std;

/*
已知一个几乎有序的数组,
几乎有序是指, 如果把数组排好顺序的话, 每个元素移动的距离, 一定不超过K，
并且k相对于数组长度来说是比较小的
*/

class SortArrayDistanceLessK {

public:
    static void sortedArrDistanceLessK(int *arr, int len, int k) {
        if (k == 0) {
            return;
        }

		// 默认小根堆
        priority_queue< int, vector<int>, greater<int> > heap;

        int index = 0;
		// 0..K
        for (; index <= min(len - 1, k); index++) {
            heap.push(arr[index]);
        }
        int i = 0;
        for (; index < len; i++, index++) {
            arr[i] = heap.top();
            heap.pop();

            heap.push(arr[index]);
		}
		while (heap.empty() == false) {
			arr[i++] = heap.top();
			heap.pop();
		}
	}
};

int main()
{

}
