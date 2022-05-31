#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

/* Definition for singly-linked list. */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* pL1 = l1;
        ListNode* pL2 = l2;

        ListNode dummyNode(-1, nullptr);
        ListNode* newList = &dummyNode;

        int carry = 0;
        while (pL1 != nullptr && pL2 != nullptr) {

            int val1 = pL1->val;
            int val2 = pL2->val;
            int sum = val1 + val2 + carry;

            int ge = sum % 10;
            carry = sum / 10;

            // 尾插法
            ListNode* newNode = new ListNode(ge, nullptr);
            newList->next = newNode;
            newList = newNode;

            pL1 = pL1->next;
            pL2 = pL2->next;
        }

        while (pL1 != nullptr) {
            int val1 = pL1->val;
            int sum = val1 + carry;

            int ge = sum % 10;
            carry = sum / 10;

            // 尾插法
            ListNode* newNode = new ListNode(ge, nullptr);
            newList->next = newNode;
            newList = newNode;

            pL1 = pL1->next;
        }

        while (pL2 != nullptr) {
            int val2 = pL2->val;
            int sum = val2 + carry;

            int ge = sum % 10;
            carry = sum / 10;

            // 尾插法
            ListNode* newNode = new ListNode(ge, nullptr);
            newList->next = newNode;
            newList = newNode;

            pL2 = pL2->next;
        }

        if (carry) {
            // 尾插法
            ListNode* newNode = new ListNode(carry, nullptr);
            newList->next = newNode;
            newList = newNode;
        }

        return dummyNode.next;
    }
};

int main()
{

    return 0;
}
