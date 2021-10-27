#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        int lenA = getListLen(headA);
        int lenB = getListLen(headB);

        ListNode *pA = headA;
        ListNode *pB = headB;

        if (lenA > lenB) {
            int delta = lenA - lenB;
            while (delta--) {
                pA = pA->next;
            }
        }
        else if (lenA < lenB) {
            int delta = lenB - lenA;
            while (delta--) {
                pB = pB->next;
            }
        }

        while (pA != pB) {
            pA = pA->next;
            pB = pB->next;
        }

        return pA;
    }

private:
    int getListLen(ListNode *head) {
        int len = 0;

        ListNode *pCur = head;
        while (pCur != nullptr) {
            len++;
            pCur = pCur->next;
        }

        return len;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
