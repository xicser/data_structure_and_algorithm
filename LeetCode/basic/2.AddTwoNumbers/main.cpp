#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

/* Definition for singly-linked list. */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> num1 = getDigits(l1);
        vector<int> num2 = getDigits(l2);
        vector<int> sumRes = bigAdd(num1, num2);
        return generateList(sumRes);
    }

    //根据数字列表构造list
    ListNode *generateList(vector<int> &res) {
        ListNode *head = nullptr;

        for (int i = res.size() - 1; i >= 0; i--) {
            ListNode *newNode = new ListNode(res[i], head);
            head = newNode;
        }

        return head;
    }

private:
    //获取链表中包含的数字
    vector<int> getDigits(ListNode *list) {
        vector<int> res;

        ListNode *pCur = list;
        while (pCur != nullptr) {
            res.push_back(pCur->val);
            pCur = pCur->next;
        }

        return res;
    }

    //大数相加
    vector<int> bigAdd(vector<int> &num1, vector<int> &num2) {

        if (num1.size() > num2.size()) {
            int delta = num1.size() - num2.size();
            for (int i = 0; i < delta; i++) {
                num2.push_back(0);
            }
        }
        else if (num1.size() < num2.size()) {
            int delta = num2.size() - num1.size();
            for (int i = 0; i < delta; i++) {
                num1.push_back(0);
            }
        }

        vector<int> res;
        int carry = 0; //进位
        for (unsigned int i = 0; i < num1.size() || i < num2.size(); i++) {
            int resTmp = num1[i] + num2[i] + carry;
            res.push_back(resTmp % 10);
            carry = resTmp / 10;
        }

        if (carry != 0) {
            res.push_back(carry);
        }

        return res;
    }
};

int main()
{
//    int num1Array1[] = {5, 7, 4};
//    int num1Array2[] = {2, 4, 3};
//    int num1Array1[] = {2, 4, 3};
//    int num1Array2[] = {5, 6, 4};
    int num1Array1[] = {0};
    int num1Array2[] = {5, 6, 4};

    vector<int> num1;
    vector<int> num2;

    for (unsigned int i = 0; i < sizeof(num1Array1) / sizeof(int); i++) {
        num1.push_back(num1Array1[i]);
    }
    for (unsigned int i = 0; i < sizeof(num1Array2) / sizeof(int); i++) {
        num2.push_back(num1Array2[i]);
    }

    Solution solution;
    ListNode *l1, *l2, *resList;
    l1 = solution.generateList(num1);
    l2 = solution.generateList(num2);
    resList = solution.addTwoNumbers(l1, l2);

    //打印结果
    while (resList != nullptr) {
        printf("%d ", resList->val);
        resList = resList->next;
    }
    printf("\n");

    return 0;
}
