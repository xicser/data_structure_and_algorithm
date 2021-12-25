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
    int getDecimalValue(ListNode* head) {

        vector<int> nums;

        while (head != nullptr) {
            nums.push_back(head->val);
            head = head->next;
        }

        int result = 0;
        int move = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i]) {
                result |= 1 << move;
            }
            move++;
        }

        return result;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
