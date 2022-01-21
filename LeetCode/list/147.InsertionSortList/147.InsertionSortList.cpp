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
    ListNode* insertionSortList(ListNode* head) {

        //空链表
        if (head == nullptr) {
            return nullptr;
        }

        //只有一个节点, 已经有序了
        if (head->next == nullptr) {
            return head;
        }

        ListNode dummy(-9999, head);  //伪头节点(默认值最小)

        ListNode* pTail = head;
        while (pTail != nullptr && pTail->next != nullptr) {

            ListNode* pNextSave = pTail->next;
            int val = pNextSave->val;
            ListNode* pNextNextSave = pNextSave->next;

            ListNode* pNow = &dummy;
            ListNode* pNext = dummy.next;

            //找插入位置
            while (pNext != pNextSave) {

                //找到了
                if (pNow->val <= val && val <= pNext->val) {
                    
                    //插入
                    pNow->next = pNextSave;
                    pNextSave->next = pNext;

                    //tail更新
                    pTail->next = pNextNextSave;
                    break;
                }
                pNow = pNow->next;
                pNext = pNext->next;
            }

            //当前这个数已经是最大的, 即已经有序, 则直接调整tail
            if (pNext == pNextSave) {
                pTail = pTail->next;
            }
        }

        return dummy.next;
    }

    ListNode* createList(vector<int>& nums) {

        ListNode* head = nullptr;

        for (int i = nums.size() - 1; i >= 0; i--) {
            ListNode* newNode = new ListNode(nums[i]);
            newNode->next = head;
            head = newNode;
        }

        return head;
    }

    void printList(ListNode* head) {
        ListNode* pCur = head;
        while (pCur != nullptr) {
            printf("%d ", pCur->val);
            pCur = pCur->next;
        }
        printf("\n");
    }
};

int main()
{
    vector<int> nums = { 2, 3, 4, 5, 6, 7 };
    Solution sol;
    ListNode* list = sol.createList(nums);
    sol.printList(list);

    ListNode* newList = sol.insertionSortList(list);
    sol.printList(newList);
}
