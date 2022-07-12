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
//    ListNode* reverseList(ListNode* head) {
//
//        ListNode* pre = nullptr;
//        ListNode* cur = head;
//        while (cur != nullptr) {
//
//            ListNode* next = cur->next;
//            cur->next = pre;
//
//            pre = cur;
//            cur = next;
//        }
//
//        return pre;
//    }

    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
