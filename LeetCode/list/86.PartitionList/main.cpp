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
public:
    ListNode* partition(ListNode* head, int x) {

        if (head == nullptr) {
            return nullptr;
        }

        //伪头节点
        ListNode lessStart(-1);
        ListNode* pLess = &lessStart; //记录小于x的链

        //伪头节点
        ListNode moreStart(-1);
        ListNode* pMore = &moreStart; //记录大于等于x的链

        ListNode* pCur = head;
        while (pCur != nullptr) {
            int val = pCur->val;
            if (val < x) {
                pLess->next = pCur;
                pLess = pCur;
            }
            else {
                pMore->next = pCur;
                pMore = pCur;
            }

            pCur = pCur->next;
        }

        //把两个链表串起来
        pLess->next = moreStart.next;
        pMore->next = nullptr;

        return lessStart.next;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
