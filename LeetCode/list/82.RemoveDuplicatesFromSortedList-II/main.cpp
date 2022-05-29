#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
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

        if (head->val == head->next->val) {
            ListNode* move = head;
            while (move->val == head->val) {
                move = move->next;
                if (move == nullptr) {
                    break;
                }
            }

            return deleteDuplicates(move);
        }
        else {
            head->next = deleteDuplicates(head->next);
        }

        return head;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = { 1,2,3,3,4,4,5 };


    return 0;
}
