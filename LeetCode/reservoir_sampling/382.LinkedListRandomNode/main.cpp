#include <iostream>
#include <stdlib.h>
#include <time.h>

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
    ListNode* head;
public:
    Solution(ListNode* head) {
        srand((unsigned)time(NULL));
        this->head = head;
    }

    int getRandom() {
        int value = -1;
        int cnt = 0;

        ListNode* pCur = this->head;
        while (pCur != nullptr) {

            cnt++;
            if (rand() % cnt == 0) {
                value = pCur->val;
            }

            pCur = pCur->next;
        }

        return value;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
