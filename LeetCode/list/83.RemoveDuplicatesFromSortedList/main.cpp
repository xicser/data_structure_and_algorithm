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
            ListNode* move = head;
            while (move->next != nullptr && move->val == move->next->val) {
                move = move->next;
            }
            return deleteDuplicates(move);
        }

        return head;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
