#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:

    //获取链表最后一个节点的地址
    ListNode* getLast(ListNode* list) {

        if (list == nullptr) {
            return nullptr;
        }

        while (list->next != nullptr) {
            list = list->next;
        }
        return list;
    }

public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode dummyNode(-1, list1);  //伪头节点
        ListNode* list2Last = getLast(list2); //获取list2的最后一个节点的地址

        int numToDelete = b - a + 1;
        int cnt = -1;
        ListNode* pPrev = &dummyNode;
        ListNode* pCur = list1;
        while (pCur != nullptr) {
            cnt++;

            int nowDelete = 0;  //记录当前已经删除的个数
            //跑到a的位置了, 开始删除
            if (cnt == a) {
                pPrev->next = list2;

                ListNode* next;
                // 一直删除, 直到删除到指定数量
                while (nowDelete != numToDelete) {
                    next = pCur->next;
                    delete pCur;
                    pCur = next;
                    nowDelete++; //删除数量++
                }

                list2Last->next = next;
                break;
            }

            pPrev = pPrev->next;
            pCur = pCur->next;
        }

        return list1;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
