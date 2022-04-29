#include <iostream>



struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int _val) {
        val = _val;
    }
};


class Solution {
public:
    ListNode* reverseLinkedList(ListNode* head, int k) {

        if (k == 1) {
            return head;
        }

        if (head == nullptr) {
            return nullptr;
        }
        if (head->next == nullptr) {
            return head;
        }

        ListNode dummy(-1);
        dummy.val = -1;
        dummy.next = head;

        ListNode* newList = &dummy;
        ListNode* pCur = head;
        while (pCur != nullptr) {

            ListNode* pCount = pCur;
            int cnt = k - 1;
            while (cnt > 0) {
                cnt--;
                pCount = pCount->next;

                //最后一段不足k个
                if (pCount == nullptr) {
                    return dummy.next;
                }
            }

            ListNode* pNext = pCount->next;

            //反转
            ListNode* rList = reverseList(pCur, pNext);

            newList->next = pCount;
            newList = pCur;

            pCur = pNext;
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
