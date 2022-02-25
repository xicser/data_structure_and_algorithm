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

    //分割链表, 返回中间截断的那个新的头
    ListNode* split(ListNode* head) {

        //快慢指针
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (slow != nullptr && fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        //记录新的头
        ListNode* newHead = slow->next;

        //截断
        slow->next = nullptr;

        return newHead;
    }

public:
    //使用归并法
    ListNode* sortList(ListNode* head) {

        //空节点
        if (head == nullptr) {
            return nullptr;
        }

        //只有一个节点, 则自然有序
        if (head->next == nullptr) {
            return head;
        }

        ListNode* head1 = head;
        ListNode* head2 = split(head);

        ListNode* sortedL1 = sortList(head1);
        ListNode* sortedL2 = sortList(head2);

        return mergeTwoLists(sortedL1, sortedL2);
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
