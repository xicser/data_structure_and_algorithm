#include <iostream>
#include <vector>
#include <stack>
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
    if (head == nullptr) {
        return;
    }

    vector <Node *> nodeList;

    Node *pNode = head;
    nodeList.push_back(pNode);
    while (pNode->next != nullptr) {
        pNode = pNode->next;
        nodeList.push_back(pNode);
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
    if (head == nullptr) {
        return false;
    }

    stack<ElemType> st;

    Node *pNode = head;
    st.push(pNode->elemt);
    while (pNode->next != nullptr) {
        pNode = pNode->next;
        st.push(pNode->elemt);
    }

    pNode = head;
    while (1) {

        ElemType elemt = st.top();
        st.pop();
        if (pNode->elemt != elemt) {
            return false;
        }

        pNode = pNode->next;
        if (pNode == nullptr) {
            break;
        }
    }

    return true;
}
