#include <iostream>
#include <vector>

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
    ListNode* createList(vector<int>& nums) {

        ListNode* head = nullptr;

        for (int i = nums.size() - 1; i >= 0; i--) {
            ListNode* node = new ListNode(nums[i]);
            node->next = head;
            head = node;
        }

        return head;
    }

    int getLen(ListNode* head) {
        int len = 0;
        while (head != nullptr) {
            len++;
            head = head->next;
        }

        return len;
    }

    void printList(ListNode* head) {
        while (head != nullptr) {
            printf("%d ", head->val);
            head = head->next;
        }
        printf("\n");
    }

public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        vector<ListNode*> result;
        int len = getLen(head);

        if (len < k) {
            int cnt = 0;
            while (head != nullptr) {
                result.push_back(head);
                cnt++;
                ListNode* next = head->next;
                head->next = nullptr;
                head = next;
            }
            for (int i = 0; i < k - cnt; i++) {
                result.push_back(nullptr);
            }
            return result;
        }

        int devide = len / k;
        int mod = len % k;
        vector<int> bucket(k, devide);   //计算每一段的长度
        for (int i = 0; i < mod; i++) {
            bucket[i]++;
        }
        int index = 0;

        int cur = 0;
        ListNode* pCur = head;
        result.push_back(pCur);
        while (pCur != nullptr) {
            cur++;
            if (cur == bucket[index]) {
                index++; //下一次就是下一段的长度了
                ListNode* nextNode = pCur->next;
                if (nextNode == nullptr) {
                    break;
                }
                result.push_back(nextNode);

                pCur->next = nullptr;
                pCur = nextNode;
                cur = 0;

                continue;
            }

            pCur = pCur->next;
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
    ListNode *list = sol.createList(nums);
//    sol.printList(list);

    vector<ListNode*> result = sol.splitListToParts(list, 2);
    for (auto item : result) {
        sol.printList(item);
    }

    return 0;
}
