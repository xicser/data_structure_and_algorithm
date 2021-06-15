#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

using namespace std;


List::List()
{
    this->head = nullptr;
}

List::~List()
{
    vector <Node *> nodeList;

    Node *pNode = head;
    while (pNode != nullptr) {
        nodeList.push_back(pNode);
        pNode = pNode->next;
    }

    printf("size = %lld\n", nodeList.size());
    for (unsigned int i = 0; i < nodeList.size(); i++) {
        delete nodeList[i];
    }
}

/* ͷ�巨 */
void List::insertHead(ElemType elemt)
{
    Node *node = new Node(elemt);
    node->next = head;
    head = node;
}

/* ���� */
void List::traverse()
{
    Node *pNode = head;

    while (pNode != nullptr) {
        cout << pNode->elemt << " ";
        pNode = pNode->next;
    }
    cout << endl;
}

/* �������ȷ����е�, ż�����ȷ������е� */
Node *List::getMiddleOrMiddleUp()
{
//    Node *slow, *fast;

    return nullptr;
}

/* ��⵱ǰ�����Ƿ��ǻ��� */
bool List::detectionPalindrome()
{
    stack<ElemType> st;

    Node *pNode = head;
    while (pNode != nullptr) {
        st.push(pNode->elemt);
        pNode = pNode->next;
    }

    pNode = head;
    while (pNode != nullptr) {
        ElemType elemt = st.top();
        st.pop();

        if (pNode->elemt != elemt) {
            return false;
        }
        pNode = pNode->next;
    }

    return true;
}

/* ���ƴ���randomָ������� */
Node *List::copyListWithRand()
{
    map<Node *, Node *> mp;

    Node *pNode = head;
    while (pNode != nullptr) {
        mp[pNode] = new Node(pNode->elemt);
        pNode = pNode->next;
    }

    pNode = head;
    while (pNode != nullptr) {
        Node *pNodeCopy = mp[pNode];
        pNodeCopy->next = mp[pNode->next];
        pNodeCopy->random = mp[pNode->random];
    }

    return mp[head];
}

/* ����������Ƿ��л�, ���ҳ������ڵ� */
Node *List::getLoopNodeSet(Node *head)
{
    set<Node *> nodeSet;

    Node *pNode = head;
    set<Node *>::iterator it;

    while (pNode != nullptr) {
        it = nodeSet.find(pNode);
        if (it == nodeSet.end()) {
            nodeSet.insert(pNode);
        } else {
            return pNode;
        }

        pNode = pNode->next;
    }

    return nullptr;
}

/* ����������Ƿ��л�, ���ҳ������ڵ� */
Node *List::getLoopNodeSF(Node *head)
{
    //0��, 1��, 2���ڵ�, ���������л�
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
        return nullptr;
    }

    Node *slow, *fast;

    slow = head->next;
    fast = head->next->next;

    //����slow��fast����һ��
    while (slow != fast) {
        if (fast->next == nullptr || fast->next->next == nullptr) {
            return nullptr;
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    fast = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

/* ��������޻������Ƿ��ཻ, �ཻʱ�����ཻ�ڵ�, ���򷵻�nullptr
�ཻʱ, ֻ������"Y��"�ཻ������
 */
Node *List::check2NoLoopList(Node *head1, Node *head2)
{
    if (head1 == nullptr || head2 == nullptr) {
        return nullptr;
    }

    Node *pNode1 = head1;
    Node *pNode2 = head2;
    int n = 0;

    //pNode1����end1
    while (pNode1->next != nullptr) {
        n++;
        pNode1 = pNode1->next;
    }
    //pNode2����end2
    while (pNode1->next != nullptr) {
        n--;
        pNode1 = pNode1->next;
    }
    //����ཻ, ���һ���ڵ�һ����һ����
    if (pNode1 != pNode2) {
        return nullptr;
    }

    pNode1 = n > 0 ? head1 : head2;           // ˭��, ˭��ͷ���pNode1
    pNode2 = pNode1 == head1 ? head2 : head1; // ˭��, ˭��ͷ���pNode2

    //�Ȱѳ����ǲ�������
    n = abs(n);
    while (n != 0) {
        n--;
        pNode1 = pNode1->next;
    }

    while (pNode1 != pNode2) {
        pNode1 = pNode1->next;
        pNode2 = pNode2->next;
    }
    return pNode1;
}

//��������л������Ƿ��ཻ, �ཻʱ�����ཻ�ڵ�, ���򷵻�nullptr
Node *List::check2LoopList(Node *head1, Node *loop1, Node *head2, Node *loop2)
{
    Node *pNode1 = nullptr;
    Node *pNode2 = nullptr;

    if (loop1 == loop2) {
        pNode1 = head1;
        pNode2 = head2;
        int n = 0;
        //pNode1����loop1
        while (pNode1 != loop1) {
            n++;
            pNode1 = pNode1->next;
        }
        //pNode2����loop2
        while (pNode2 != loop2) {
            n--;
            pNode2 = pNode2->next;
        }
        pNode1 = n > 0 ? head1 : head2;
        pNode2 = pNode1 == head1 ? head2 : head1;
        n = abs(n);
        while (n != 0) {
            n--;
            pNode1 = pNode1->next;
        }
        while (pNode1 != pNode2) {
            pNode1 = pNode1->next;
            pNode2 = pNode2->next;
        }
        return pNode1;
    }
    else {
        pNode1 = loop1->next;
        while (pNode1 != loop1) {
            if (pNode1 == loop2) {
                return loop1;
            }
            pNode1 = pNode1->next;
        }
        return nullptr;
    }
}

/* ������������Ƿ��ཻ */
Node *List::getIntersectNode(Node *head1, Node *head2) {
    if (head1 == nullptr || head2 == nullptr) {
        return nullptr;
    }
    Node *loop1 = getLoopNodeSF(head1);
    Node *loop2 = getLoopNodeSF(head2);
    if (loop1 == nullptr && loop2 == nullptr) {
        return check2NoLoopList(head1, head2);
    }
    if (loop1 != nullptr && loop2 != nullptr) {
        return check2LoopList(head1, loop1, head2, loop2);
    }
    return nullptr;
}
