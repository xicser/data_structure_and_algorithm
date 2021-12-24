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
    ListNode* reverseList(ListNode* head) {

        ListNode* pre = nullptr;
        ListNode* cur = head;

        while (cur != nullptr) {
            ListNode* nextOld = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nextOld;
        }

        return pre;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* pNew = nullptr;
        ListNode* pCur1 = reverseList(l1);
        ListNode* pCur2 = reverseList(l2);

        int carry = 0;
        while (pCur1 != nullptr && pCur2 != nullptr) {

            int valResult = pCur1->val + pCur2->val + carry;

            //ͷ�巨
            ListNode* newNode = new ListNode(valResult % 10);
            newNode->next = pNew;
            pNew = newNode;

            carry = valResult / 10;

            pCur1 = pCur1->next;
            pCur2 = pCur2->next;
        }

        ListNode* pCur;
        if (pCur1 == nullptr) {
            pCur = pCur2;
        }
        else if (pCur2 == nullptr) {
            pCur = pCur1;
        }

        while (pCur != nullptr) {
            int valResult = pCur->val + carry;

            //ͷ�巨
            ListNode* newNode = new ListNode(valResult % 10);
            newNode->next = pNew;
            pNew = newNode;

            carry = valResult / 10;

            pCur = pCur->next;
        }

        //�������Ľ�λ
        if (carry != 0) {
            //ͷ�巨
            ListNode* newNode = new ListNode(carry);
            newNode->next = pNew;
            pNew = newNode;
        }

        return pNew;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
