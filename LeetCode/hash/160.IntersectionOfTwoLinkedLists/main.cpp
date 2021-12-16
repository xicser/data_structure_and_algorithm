#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        unordered_set<ListNode *> setNodes;
        ListNode *pCurA = headA, *pCurB = headB;

        //�Ȱѵ�һ�������еĽڵ�Ž�ȥ
        while (pCurA != nullptr) {
            setNodes.insert(pCurA);
            pCurA = pCurA->next;
        }

        //Ȼ��ӵڶ���������
        while (pCurB != nullptr) {

            if (!setNodes.count(pCurB)) {
                setNodes.insert(pCurB);
            }
            else {
                return pCurB;
            }

            pCurB = pCurB->next;
        }

        return nullptr;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
