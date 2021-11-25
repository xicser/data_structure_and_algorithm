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
    bool hasCycle(ListNode *head) {

        unordered_set<ListNode *> nodeSet;

        ListNode *pCur = head;
        while (pCur != nullptr) {

            if (nodeSet.find(pCur) != nodeSet.end()) {
                return true;
            }
            else {
                nodeSet.insert(pCur);
            }

            pCur = pCur->next;
        }

        return false;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
