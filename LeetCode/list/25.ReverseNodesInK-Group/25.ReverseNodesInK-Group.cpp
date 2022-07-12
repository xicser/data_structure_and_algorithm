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
    //迭代法
    //ListNode* reverseKGroup(ListNode* head, int k) {

    //    ListNode dummy(-1, head);   //伪头节点
    //    ListNode* pPre = &dummy;
    //    ListNode* pCur = head;

    //    while (pCur != nullptr) {

    //        ListNode* from = pCur;

    //        int cnt = k;
    //        while (--cnt) {
    //            pCur = pCur->next;
    //            if (pCur == nullptr) {
    //                return dummy.next;
    //            }
    //        }
    //        ListNode* to = pCur->next;
    //        ListNode* newList = reverseList(from, to);

    //        pPre->next = newList;
    //        from->next = to;

    //        pPre = from;
    //        pCur = to;
    //    }

    //    return dummy.next;
    //}

    //递归法: 反转k
    ListNode* reverseKGroup(ListNode* head, int k) {

        //先数k个节点
        int cnt = k;
        ListNode* pCur = head;
        while (cnt--) {
            pCur = pCur->next;
            
            //剩下的不足k个
            if (pCur == nullptr && cnt > 0) {
                return head;
            }

            //剩下的刚好==k个
            if (pCur == nullptr && cnt == 0) {
                return reverse(head, nullptr);
            }
        }

        //把这k个反转了
        ListNode* newList = reverse(head, pCur);
        head->next = reverseKGroup(head->next, k);

        return newList;
    }

private:
    //反转start到end(不含end)
    ListNode* reverse(ListNode* start, ListNode* end) {
        ListNode* pre = end;
        ListNode* cur = start;
        
        while (cur != end) {
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
