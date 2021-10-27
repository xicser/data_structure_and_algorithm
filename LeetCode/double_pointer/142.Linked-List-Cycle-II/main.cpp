#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return nullptr;
        }

        ListNode* slow = head->next;
        ListNode* fast = head->next->next;
        while (fast != slow) {

            if (slow->next == nullptr || fast->next == nullptr  || fast->next->next == nullptr) {
                return nullptr;
            }

            slow = slow->next;
            fast = fast->next->next;
        }

        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }

        return fast;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
