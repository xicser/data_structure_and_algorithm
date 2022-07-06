#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {

        //������, ����ֻ��һ���ڵ������
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        ListNode* slow = head->next;
        ListNode* fast = head->next->next;
        while (slow != fast) {

            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }

            slow = slow->next;
            fast = fast->next->next;
        }

        return true;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
