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
    ListNode* removeElements(ListNode* head, int val) {

        if (head == nullptr) {
            return nullptr;
        }

        ListNode dummy(-1, head);
        ListNode* pPrev = &dummy;
        ListNode* pCur = head;
        while (pCur != nullptr) {
            if (pCur->val == val) {
                ListNode* next = pCur->next;
                delete pCur;
                pPrev->next = next;
                pCur = next;
            }
            else {
                pPrev = pPrev->next;
                pCur = pCur->next;
            }
        }

        return dummy.next;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
