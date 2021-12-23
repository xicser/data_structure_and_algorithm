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
    ListNode* partition(ListNode* head, int x) {

        if (head == nullptr) {
            return nullptr;
        }

        //αͷ�ڵ�
        ListNode lessStart(-1);
        ListNode* pLess = &lessStart; //��¼С��x����

        //αͷ�ڵ�
        ListNode moreStart(-1);
        ListNode* pMore = &moreStart; //��¼���ڵ���x����

        ListNode* pCur = head;
        while (pCur != nullptr) {
            int val = pCur->val;
            if (val < x) {
                pLess->next = pCur;
                pLess = pCur;
            }
            else {
                pMore->next = pCur;
                pMore = pCur;
            }

            pCur = pCur->next;
        }

        //��������������
        pLess->next = moreStart.next;
        pMore->next = nullptr;

        return lessStart.next;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
