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
    //递归含义: 删除以 head 作为开头的有序链表中, 值出现重复的节点
    ListNode* deleteDuplicates(ListNode* head) {

        if (head == nullptr) {
            return nullptr;
        }

        //只有一个节点的链表, 不用移除
        if (head->next == nullptr) {
            return head;
        }

        if (head->val != head->next->val) {
            head->next = deleteDuplicates(head->next);
            return head;
        }
        else {
            ListNode* move = head->next;
            while (move != nullptr && head->val == move->val) {
                move = move->next;
            }

            return deleteDuplicates(move);
        }
    }
};

int main()
{
    Solution sol;
    vector<int> nums = { 1,2,3,3,4,4,5 };
    ListNode* head = sol.createList(nums);
    head = sol.deleteDuplicates(head);


    return 0;
}
