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
    ListNode* split(ListNode* list) {

        ListNode* slow = list, *fast = list->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* next = slow->next;
        slow->next = nullptr;

        return next;
    }

    ListNode* reverse(ListNode* list) {

        ListNode* pPre = nullptr;
        ListNode* pCur = list;

        while (pCur != nullptr) {
            ListNode* next = pCur->next;
            pCur->next = pPre;
            pPre = pCur;
            pCur = next;
        }

        return pPre;
    }

public:
    void reorderList(ListNode*& head) {

        ListNode* l1 = head;
        ListNode* l2 = split(l1);
        l2 = reverse(l2);

        ListNode dummy;

        ListNode* pCur = &dummy;

        bool which = true;

        //合并
        while (l1 != nullptr && l2 != nullptr) {

            if (which == true) {
                pCur->next = l1;
                pCur = l1;

                l1 = l1->next;
                which = false;
            }
            else {
                pCur->next = l2;
                pCur = l2;

                l2 = l2->next;
                which = true;
            }
        }

        if (l1 == nullptr) {
            pCur->next = l2;
        }
        else if (l2 == nullptr) {
            pCur->next = l1;
        }

        head = dummy.next;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
