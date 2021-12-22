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

        ListNode* odd = head;   //指向第一个
        ListNode* even = head->next, *evenOrigin = head->next;  //指向第二个

        while (odd != nullptr && even != nullptr) {
            odd->next = even->next;
            if (odd->next == nullptr) {
                odd->next = evenOrigin;
                even->next = nullptr;
                break;
            }

            even->next = even->next->next;
            if (even->next == nullptr) {
                odd = odd->next;
                odd->next = evenOrigin;
                break;
            }

            odd = odd->next;
            even = even->next;
        }

        return head;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
