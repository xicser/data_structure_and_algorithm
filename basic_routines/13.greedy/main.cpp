#include <iostream>
#include <queue>

using namespace std;

//typedef struct {
//    int start;
//    int end;
//} Meeting;
//
///*
//暴力法获取最大安排次数
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
//谁结束早先安排谁
// */
//int bestArrangeAwesome(Meeting *meeting)
//{
//    return processRec();
//}

/* 切金条 */
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
