#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//class Solution {
//public:
//    ListNode* mergeKLists(vector<ListNode*>& lists) {
//
//        if (lists.size() == 0) {
//            return nullptr;
//        }
//        if (lists.size() == 1) {
//            return lists[0];
//        }
//
//        ListNode* list = lists[0];
//        for (unsigned int i = 1; i < lists.size(); i++) {
//            list = mergeTwoLists(list, lists[i]);
//        }
//
//        return list;
//    }
//
//    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//
//        if (list1 == nullptr) {
//            return list2;
//        }
//        if (list2 == nullptr) {
//            return list1;
//        }
//
//        if (list1->val < list2->val) {
//            list1->next = mergeTwoLists(list1->next, list2);
//            return list1;
//        }
//        else {
//            list2->next = mergeTwoLists(list1, list2->next);
//            return list2;
//        }
//    }
//};


class Solution {
private:
    struct cmp {
        //小根堆
        bool operator()(ListNode* l1, ListNode* l2) {
            return l1->val > l2->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        //小根堆
        priority_queue<ListNode*, vector<ListNode*>, cmp> que;

        for (auto list : lists) {
            if (list != nullptr) {
                que.push(list);
            }
        }

        ListNode dummy(-1, nullptr);  //伪头节点
        ListNode* pCur = &dummy;

        while (que.empty() == false) {
            ListNode* l = que.top();
            que.pop();

            pCur->next = l;
            pCur = l;

            if (l->next != nullptr) {
                que.push(l->next);
            }
        }

        return dummy.next;
    }
};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
