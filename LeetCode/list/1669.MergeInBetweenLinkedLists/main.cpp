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
private:

    //��ȡ�������һ���ڵ�ĵ�ַ
    ListNode* getLast(ListNode* list) {

        if (list == nullptr) {
            return nullptr;
        }

        while (list->next != nullptr) {
            list = list->next;
        }
        return list;
    }

public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode dummyNode(-1, list1);  //αͷ�ڵ�
        ListNode* list2Last = getLast(list2); //��ȡlist2�����һ���ڵ�ĵ�ַ

        int numToDelete = b - a + 1;
        int cnt = -1;
        ListNode* pPrev = &dummyNode;
        ListNode* pCur = list1;
        while (pCur != nullptr) {
            cnt++;

            int nowDelete = 0;  //��¼��ǰ�Ѿ�ɾ���ĸ���
            //�ܵ�a��λ����, ��ʼɾ��
            if (cnt == a) {
                pPrev->next = list2;

                ListNode* next;
                // һֱɾ��, ֱ��ɾ����ָ������
                while (nowDelete != numToDelete) {
                    next = pCur->next;
                    delete pCur;
                    pCur = next;
                    nowDelete++; //ɾ������++
                }

                list2Last->next = next;
                break;
            }

            pPrev = pPrev->next;
            pCur = pCur->next;
        }

        return list1;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
