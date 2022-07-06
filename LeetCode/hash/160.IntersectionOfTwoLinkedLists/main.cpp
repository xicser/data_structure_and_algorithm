#include <iostream>
#include <unordered_set>


using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//class Solution {
//public:
//    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//
//        unordered_set<ListNode *> setNodes;
//        ListNode *pCurA = headA, *pCurB = headB;
//
//        //先把第一个链表当中的节点放进去
//        while (pCurA != nullptr) {
//            setNodes.insert(pCurA);
//            pCurA = pCurA->next;
//        }
//
//        //然后从第二个里面找
//        while (pCurB != nullptr) {
//
//            if (setNodes.count(pCurB) != 0) {
//                return pCurB;
//            }
//
//            pCurB = pCurB->next;
//        }
//
//        return nullptr;
//    }
//};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode *pCurA = headA, *pCurB = headB;

        while (pCurA != pCurB) {
            pCurA = pCurA != nullptr ? pCurA->next : headB;
            pCurB = pCurB != nullptr ? pCurB->next : headA;
        }

        return pCurA;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
