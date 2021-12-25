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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode dummyNode(-1, head);  //伪头节点

        ListNode* slowPrev = &dummyNode;
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (slow != nullptr && fast != nullptr && fast->next != nullptr) {
            slowPrev = slowPrev->next;
            slow = slow->next;
            fast = fast->next->next;
        }

        //奇数个节点
        if (fast == nullptr) {
            ListNode* next = slow->next;
            slowPrev->next = next;
            delete slow;
        }
        //偶数个节点
        else if (fast->next == nullptr) {
            ListNode* toDeleteNode = slow->next;
            slow->next = toDeleteNode->next;
            delete toDeleteNode;
        }

        return dummyNode.next;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
