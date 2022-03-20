#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* 递归法 */
//class Solution {
//public:
//
//    //函数含义: 把两个有序链表1和2合并成一个有序链表
//    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//
//        if (l1 == nullptr) {
//            return l2;
//        }
//        if (l2 == nullptr) {
//            return l1;
//        }
//
//        int val1 = l1->val;
//        int val2 = l2->val;
//        if (val1 < val2) {
//            l1->next = mergeTwoLists(l1->next, l2);
//            return l1;
//        }
//        else {
//            l2->next = mergeTwoLists(l2->next, l1);
//            return l2;
//        }
//    }
//};

/* 迭代法 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(-1, nullptr);

        ListNode* pPrev = &dummy;

        while (list1 != nullptr && list2 != nullptr) {
            int val1 = list1->val;
            int val2 = list2->val;

            if (val1 < val2) {
                pPrev->next = list1;
                pPrev = list1;
                list1 = list1->next;
            }
            else {
                pPrev->next = list2;
                pPrev = list2;
                list2 = list2->next;
            }
        }

        if (list1 == nullptr) {
            pPrev->next = list2;
        }
        else if (list2 == nullptr) {
            pPrev->next = list1;
        }

        return dummy.next;
    }
};

int main()
{


    return 0;
}
