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
    //��������: ��������������1��2�ϲ���һ����������
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }

        int val1 = l1->val;
        int val2 = l2->val;

        if (val1 < val2) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
    }

    //�ָ�����, �����м�ضϵ��Ǹ��µ�ͷ
    ListNode* split(ListNode* head) {

        //����ָ��
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (slow != nullptr && fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        //��¼�µ�ͷ
        ListNode* newHead = slow->next;

        //�ض�
        slow->next = nullptr;

        return newHead;
    }

public:
    //ʹ�ù鲢��
    ListNode* sortList(ListNode* head) {

        //�սڵ�
        if (head == nullptr) {
            return nullptr;
        }

        //ֻ��һ���ڵ�, ����Ȼ����
        if (head->next == nullptr) {
            return head;
        }

        ListNode* head1 = head;
        ListNode* head2 = split(head);

        ListNode* sortedL1 = sortList(head1);
        ListNode* sortedL2 = sortList(head2);

        return mergeTwoLists(sortedL1, sortedL2);
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
