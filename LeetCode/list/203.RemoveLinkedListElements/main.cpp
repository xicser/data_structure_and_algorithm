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
        if (head->next == nullptr) {
            if (head->val == val) {
                delete head;
                return nullptr;
            }
            else {
                return head;
            }
        }

        ListNode* pPrev = head;
        ListNode* pCur = head->next;
        while (pCur != nullptr) {

            if (pCur->val == val) {
                pPrev->next = pCur->next;
                delete pCur;
                pCur = pPrev->next;
            }
            else {
                pPrev = pCur;
                pCur = pCur->next;
            }
        }

        if (head->val == val) {
            ListNode* headNext = head->next;
            delete head;
            return headNext;
        }

        return head;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
