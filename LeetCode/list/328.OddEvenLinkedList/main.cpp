#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* 分析方法: 针对链表长度是 奇数 和 偶数 分别举例子, 然后编码 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if (head == nullptr) {
            return nullptr;
        }

        int cnt = 1;
        ListNode* pCur = head;

        ListNode listOdd, *pOdd;           //奇数
        ListNode listEven, *pEven;         //偶数
        pOdd = &listOdd;
        pEven = &listEven;
        while (pCur != nullptr) {

            //奇数
            if (cnt % 2 != 0) {
                pOdd->next = pCur;
                pOdd = pCur;
            }
            //偶数
            else {
                pEven->next = pCur;
                pEven = pCur;
            }

            cnt++;
            pCur = pCur->next;
        }

        //连接起来
        pOdd->next = listEven.next;
        pEven->next = nullptr;

        return head;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
