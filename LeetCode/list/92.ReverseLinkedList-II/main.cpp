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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        ListNode dummyHead(-999, head);   //αͷ�ڵ�

        //���ҵ�left�ڵ�, ������ǰһ���ڵ�
        ListNode* nodeLeftPrev = &dummyHead;
        ListNode* nodeLeft;
        int cnt = 0;
        while (nodeLeftPrev != nullptr) {
            if (cnt == left - 1) {
                break;
            }
            cnt++;
            nodeLeftPrev = nodeLeftPrev->next;
        }
        nodeLeft = nodeLeftPrev->next;

        //���ҵ�right�ڵ�, ��������һ���ڵ�
        ListNode* nodeRightNext;
        ListNode* nodeRight = nodeLeftPrev;
        while (nodeRight != nullptr) {
            if (cnt == right) {
                break;
            }
            cnt++;
            nodeRight = nodeRight->next;
        }
        nodeRightNext = nodeRight->next;

        //��ת����
        ListNode* pre = nodeRightNext;
        ListNode* cur = nodeLeft;
        while (cur != nodeRightNext) {
            ListNode* nextOld = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nextOld;
        }
        nodeLeftPrev->next = pre;

        return dummyHead.next;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
