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
private:
    //获取链表中点
    ListNode* getMid(ListNode* head) {

        //快慢指针
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (slow != nullptr && fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    //链表反转
    ListNode* reverseList(ListNode* head) {

        ListNode* pre = nullptr;
        ListNode* cur = head;

        while (cur != nullptr) {
            ListNode* nextOld = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nextOld;
        }

        return pre;
    }

public:
    bool isPalindrome(ListNode* head) {

        if (head == nullptr) {
            return true;
        }
        if (head != nullptr && head->next == nullptr) {
            return true;
        }

        ListNode* head1 = head;
        ListNode* head2 = getMid(head);
        head2->next = reverseList(head2->next);  //把后半部分反转
        head2 = head2->next;

        while (head2 != nullptr) {

            if (head1->val != head2->val) {
                return false;
            }

            head1 = head1->next;
            head2 = head2->next;
        }

        return true;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
