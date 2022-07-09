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
//    ListNode* swapPairs(ListNode* head) {
//
//        ListNode fakeNode(-1, head);
//        ListNode* pCur = &fakeNode;
//
//        while (pCur != nullptr && pCur->next != nullptr && pCur->next->next != nullptr) {
//
//            ListNode* first = pCur->next;
//            ListNode* second = pCur->next->next;
//            ListNode* third = pCur->next->next->next;
//
//            pCur->next = second;
//            second->next = first;
//            first->next = third;
//
//            pCur = first;
//        }
//
//        return fakeNode.next;
//    }

    ListNode* swapPairs(ListNode* head) {

        if (head == nullptr) {
            return nullptr;
        }
        if (head->next == nullptr) {
            return head;
        }

        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* next = head->next->next;

        second->next = first;
        first->next = swapPairs(next);

        return second;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
