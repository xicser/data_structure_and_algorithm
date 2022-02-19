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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if (head->next == nullptr) {
            return nullptr;
        }

        ListNode dummy(-1, head);

        //先让fast走n步
        ListNode* fast = head;
        int steps = n;
        while (steps--) {
            fast = fast->next;
        }

        //然后让slow和fast一块走, 直到fast到达链表末尾
        ListNode* pre = &dummy;
        ListNode* slow = head;
        while (fast != nullptr) {
            pre = pre->next;
            slow = slow->next;
            fast = fast->next;
        }
        pre->next = slow->next;
        delete slow;

        return dummy.next;
    }
};

int main()
{
    Solution sol;


    cout << "Hello world!" << endl;
    return 0;
}
