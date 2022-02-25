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
    //获取链表长度, 并返回最后一个节点的地址
    ListNode* getListLen(ListNode* head, int* len) {
        *len = 0;
        ListNode* pCur = head;
        ListNode* last;
        while (pCur != nullptr) {
            (*len)++;
            pCur = pCur->next;
            if (pCur != nullptr && pCur->next == nullptr) {
                last = pCur;
            }
        }

        return last;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {

        int len;
        ListNode* lastNode = getListLen(head, &len);

        if (len == 0) {
            return nullptr;
        }
        if (k == 0 || k == len || len == 1) {
            return head;
        }

        k = k % len;
        //刚好能整除, 不用转
        if (k == 0) {
            return head;
        }

        //链表首尾相连
        lastNode->next = head;

        int preCnt = len - k - 1;
        ListNode* pCur = head;
        while (preCnt != 0) {
            pCur = pCur->next;
            preCnt--;
        }
        ListNode* newHead = pCur->next;
        pCur->next = nullptr;

        return newHead;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
