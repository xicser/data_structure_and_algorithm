#include <iostream>
#include <queue>
#include <algorithm>
#include <stdio.h>

using namespace std;

/*
��֪һ���������������,
����������ָ, ����������ź�˳��Ļ�, ÿ��Ԫ���ƶ��ľ���, һ��������K��
����k��������鳤����˵�ǱȽ�С��
*/

class SortArrayDistanceLessK {

public:
    static void sortedArrDistanceLessK(int *arr, int len, int k) {
        if (k == 0) {
            return;
        }

		// Ĭ��С����
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
