#include <iostream>
#include <queue>

using namespace std;

//typedef struct {
//    int start;
//    int end;
//} Meeting;
//
///*
//��������ȡ����Ŵ���
//*/
//int processRec()
//{
//
//}
//int bestArrange(Meeting *meeting)
//{
//    return processRec();
//}
//
///*
//˭�������Ȱ���˭
// */
//int bestArrangeAwesome(Meeting *meeting)
//{
//    return processRec();
//}

/* �н��� */
int splitGold(int length[], int cnt)
{
    int sum = 0;
    priority_queue< int, vector<int>, greater<int> > lheap;

    for (int i = 0; i < cnt; i++) {
        lheap.push(length[i]);
    }

    while (lheap.size() > 1) {
        int cur = lheap.top();
        lheap.pop();
        cur += lheap.top();
        lheap.pop();

        sum += cur;
        lheap.push(cur);
    }

    return sum;
}

int main()
{
    int length[] = {3, 9, 6, 4, 1};
    cout << splitGold(length, 5) << endl;

    return 0;
}
