#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

using namespace std;


List::List(int limit)
{
    this->head = nullptr;

    for (int i = 0; i < limit; i++) {
        this->insertHead(i);
    }
}

List::~List()
{
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
    cout << pNode->elemt << " ";
    while (pNode->next != nullptr) {
        pNode = pNode->next;
        cout << pNode->elemt << " ";
    }

    cout << endl;
}

/* �������ȷ����е�, ż�����ȷ������е� */
Node *List::getMiddleOrMiddleUp()
{
    Node *slow, fast;



}
