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

        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        ListNode* slow = head->next;
        ListNode* fast = head->next->next;
        while (slow != fast) {

            if (fast == nullptr || fast->next == nullptr) {
                return nullptr;
            }

            slow = slow->next;
            fast = fast->next->next;
        }

        //让fast回到开始位置
        fast = head;
        while (fast != slow) {
            slow = slow->next;
            fast = fast->next;
        }

        return fast;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
