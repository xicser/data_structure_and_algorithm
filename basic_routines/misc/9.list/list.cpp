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

/* 头插法 */
void List::insertHead(ElemType elemt)
{
    Node *node = new Node(elemt);
    node->next = head;
    head = node;
}

/* 遍历 */
void List::traverse()
{
    Node *pNode = head;

    while (pNode != nullptr) {
        cout << pNode->elemt << " ";
        pNode = pNode->next;
    }
    cout << endl;
}

/* 奇数长度返回中点, 偶数长度返回上中点 */
Node *List::getMiddleOrMiddleUp()
{
//    Node *slow, *fast;

    return nullptr;
}

/* 检测当前链表是否是回文 */
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

/* 复制带有random指针的链表 */
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

/* 检测链表中是否有环, 并找出相遇节点 */
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

/* 检测链表中是否有环, 并找出相遇节点 */
Node *List::getLoopNodeSF(Node *head)
{
    //0个, 1个, 2个节点, 都不可能有环
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
        return nullptr;
    }

    Node *slow, *fast;

    slow = head->next;
    fast = head->next->next;

    //先让slow和fast相遇一次
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

/* 检测两个无环链表是否相交, 相交时返回相交节点, 否则返回nullptr
相交时, 只可能是"Y型"相交的样子
 */
Node *List::check2NoLoopList(Node *head1, Node *head2)
{
    if (head1 == nullptr || head2 == nullptr) {
        return nullptr;
    }

    Node *pNode1 = head1;
    Node *pNode2 = head2;
    int n = 0;

    //pNode1来到end1
    while (pNode1->next != nullptr) {
        n++;
        pNode1 = pNode1->next;
    }
    //pNode2来到end2
    while (pNode1->next != nullptr) {
        n--;
        pNode1 = pNode1->next;
    }
    //如果相交, 最后一个节点一定是一样的
    if (pNode1 != pNode2) {
        return nullptr;
    }

    pNode1 = n > 0 ? head1 : head2;           // 谁长, 谁的头变成pNode1
    pNode2 = pNode1 == head1 ? head2 : head1; // 谁短, 谁的头变成pNode2

    //先把长的那部分走完
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

//检测两个有环链表是否相交, 相交时返回相交节点, 否则返回nullptr
Node *List::check2LoopList(Node *head1, Node *loop1, Node *head2, Node *loop2)
{
    Node *pNode1 = nullptr;
    Node *pNode2 = nullptr;

    if (loop1 == loop2) {
        pNode1 = head1;
        pNode2 = head2;
        int n = 0;
        //pNode1来到loop1
        while (pNode1 != loop1) {
            n++;
            pNode1 = pNode1->next;
        }
        //pNode2来到loop2
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

/* 检测两个链表是否相交 */
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
