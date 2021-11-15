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
    //�ݹ麬��: ɾ���� head ��Ϊ��ͷ������������, ֵ�����ظ��Ľڵ�
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        if (head->val != head->next->val) {
            head->next = deleteDuplicates(head->next);
        }
        else {
            ListNode* move = head->next;
            while (move && head->val == move->val) {
                move = move->next;
            }
            return deleteDuplicates(move);
        }
        return head;
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