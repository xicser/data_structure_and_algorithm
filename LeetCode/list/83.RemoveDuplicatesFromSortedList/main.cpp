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
    ListNode* deleteDuplicates(ListNode* head) {

        if (head == nullptr) {
            return nullptr;
        }
        if (head->next == nullptr) {
            return head;
        }

        ListNode* first = head;
        ListNode* pCur;
        ListNode* pNext;
        while (1) {

            while (1) {
                pCur = first;
                pNext = first->next;
                if (pCur->val == pNext->val) {
                    pCur->next = pNext->next;
                    delete pNext;
                    pNext = pCur->next;
                    if (pNext == nullptr) {
                        break;
                    }
                }
                else {
                    first = pNext;
                    break;
                }
            }

            if (first->next == nullptr) {
                break;
            }
        }

        return head;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
