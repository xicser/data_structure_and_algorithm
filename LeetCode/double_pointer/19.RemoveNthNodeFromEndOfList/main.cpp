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

        //先让fast走n步
        ListNode* fast = head;
        int step = n;
        while (step--) {
            fast = fast->next;
        }

        //如果删除的是第一个节点(倒数最后一个)
        if (fast == nullptr) {
            ListNode* ret = head->next;
            delete head;
            return ret;
        }

        //然后slow和fast一块走, 直到fast指向空
        ListNode* slow = head;
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        //此时slow指向下一个的就是要删除的节点
        ListNode* toBeDelete = slow->next;
        ListNode* toBeDeleteNext = toBeDelete->next;
        slow->next = toBeDeleteNext;

        delete toBeDelete;

        return head;
    }
};

int main()
{
    Solution sol;


    cout << "Hello world!" << endl;
    return 0;
}
