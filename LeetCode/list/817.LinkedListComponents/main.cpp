#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
[3,4,0,2,1]
[4]
*/
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());

        bool lastIn;
        int cnt = 0;
        if (numSet.count(head->val) != 0) {
            lastIn = true;
        }
        else {
            lastIn = false;
        }

        ListNode* pCur = head->next;  //从第二个开始算
        while (pCur != nullptr) {
            int val = pCur->val;

            //不在
            if (numSet.count(val) == 0) {

                //不能写成: if (numSet.count(val) == 0 && lastIn == true)
                if (lastIn == true) {
                    cnt++;
                    lastIn = false;
                }
            }
            else {
                lastIn = true;
            }

            pCur = pCur->next;
        }
        if (lastIn == true) {
            cnt++;
        }

        return cnt;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 4, 4, 9};
    sol.numComponents(nullptr, nums);


    return 0;
}
