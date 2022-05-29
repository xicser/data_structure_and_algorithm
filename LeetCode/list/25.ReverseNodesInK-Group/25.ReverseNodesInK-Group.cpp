#include <iostream>

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode dummy(-1, head);   //伪头节点
        ListNode* pPre = &dummy;
        ListNode* pCur = head;

        while (pCur != nullptr) {

            ListNode* from = pCur;

            int cnt = k;
            while (--cnt) {
                pCur = pCur->next;
                if (pCur == nullptr) {
                    return dummy.next;
                }
            }
            ListNode* to = pCur->next;
            ListNode* newList = reverseList(from, to);

            pPre->next = newList;
            from->next = to;

            pPre = from;
            pCur = to;
        }

        return dummy.next;
    }

private:
    //反转head（含）到tail（不含）这一段链表
    ListNode* reverseList(ListNode* head, ListNode* tail) {
        ListNode* pre = tail;
        ListNode* cur = head;
        while (cur != tail) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
