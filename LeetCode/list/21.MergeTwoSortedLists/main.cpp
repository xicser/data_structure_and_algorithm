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

    //函数含义: 把两个有序链表1和2合并成一个有序链表
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }

        int val1 = l1->val;
        int val2 = l2->val;
        if (val1 < val2) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
    }
};

int main()
{


    return 0;
}
