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

        if (head->val != head->next->val) {
            head->next = deleteDuplicates(head->next);
        }
        else {
            ListNode* move = head->next;
            while (move != nullptr && move->val == head->val) {
                move = move->next;
            }
            head->next = deleteDuplicates(move);
        }

        return head;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
