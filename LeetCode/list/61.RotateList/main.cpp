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
    //��ȡ������
    int getListLen(ListNode* head) {
        int len = 0;

        while (head != nullptr) {
            len++;
            head = head->next;
        }

        return len;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {

        ListNode* oldHead = head;
        ListNode* newHead;
        int len = getListLen(head);
        if (len == 0) {
            return nullptr;
        }
        if (k == 0 || k == len || len == 1) {
            return head;
        }

        k = k % len;
        //�պ�������, ����ת
        if (k == 0) {
            return head;
        }

        int preCnt = len - k;
        int curCnt = 0;
        while (head != nullptr) {
            curCnt++;
            if (curCnt == preCnt) {
                newHead = head->next;
                head->next = nullptr;
                break;
            }
            head = head->next;
        }

        ListNode* pCur = newHead;
        while (pCur != nullptr) {
            //���һ���ڵ�
            if (pCur->next == nullptr) {
                //���һ���ڵ�ָ��ͷ�ڵ�
                pCur->next = oldHead;
                break;
            }
            pCur = pCur->next;
        }

        return newHead;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
