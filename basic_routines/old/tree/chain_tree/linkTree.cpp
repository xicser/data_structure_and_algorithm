
/*

二叉树的链式存储实现
1
2
4
^
^
5
^
^
3
6
^
^
7
^
^
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stack>
#include <map>
#include <queue>
#include "linkTree.h"

using namespace std;

// 先序次序 递归地输入二叉树中结点的值, '^'字符表示空树
// 构造二叉链表表示的二叉树T
void CreateBiTreeRecursion(BiTree &T)
{
    TElemType ch = getchar();
    fflush(stdin);
    if (ch == '^') {
        T = nullptr;//空树，保证是叶子结点，递归结束条件
        return;
    }

    //生成结点
    T = (BiTNode *)malloc(sizeof(BiTNode));
    if (T == nullptr) {
        return;
    }
    T->data = ch;

    //构造左子树
    printf("输入左子树:\n");
    CreateBiTreeRecursion(T->lchild);

    //构造右子树
    printf("输入右子树:\n");
    CreateBiTreeRecursion(T->rchild);
}

//递归先序遍历
//T为指向二叉树根结点的指针
//level用于指示元素在哪一层
void PreOrderTraverseRecursion(BiTree T, int level)
{
    if (T == nullptr)return;//递归结束条件：达到了叶子结点

    printf("%c在第%d层\n", T->data, level);//访问根结点
    level++;
    PreOrderTraverseRecursion(T->lchild, level);//遍历左子树
    PreOrderTraverseRecursion(T->rchild, level);//遍历右子树
}

//递归中序遍历
//T为指向二叉树根结点的指针
void InOrderTraverseRecursion(BiTree T)
{
    if (T == nullptr)return;

    InOrderTraverseRecursion(T->lchild);
    printf("%c ", T->data);
    InOrderTraverseRecursion(T->rchild);
}

//递归后序遍历
//T为指向二叉树根结点的指针
void PostOrderTraverseRecursion(BiTree T)
{
    if (T == nullptr)return;

    PostOrderTraverseRecursion(T->lchild);
    PostOrderTraverseRecursion(T->rchild);
    printf("%c ", T->data);
}

/* 二叉树复制 */
void BiTreeCopyRecursion(BiTree pTree, BiTree &pTreeOut)
{
    if (pTree == nullptr) {
        pTreeOut = nullptr;
        return;
    }

    pTreeOut = (BiTree)malloc(sizeof(BiTNode));
    pTreeOut->data = pTree->data;

    BiTreeCopyRecursion(pTree->lchild, pTreeOut->lchild);
    BiTreeCopyRecursion(pTree->rchild, pTreeOut->rchild);
}

/* 获取深度 */
int GetDepth(BiTree pTree)
{
    if (pTree == nullptr) {
        return 0;
    }

    int depthLeft = GetDepth(pTree->lchild);
    int depthRight = GetDepth(pTree->rchild);

    return max(depthLeft, depthRight) + 1;
}

/* 获取结点个数 */
int GetNodeCount(BiTree pTree)
{
    if (pTree == nullptr) {
        return 0;
    }

    int nodeCntLeft = GetNodeCount(pTree->lchild);
    int nodeCntRight = GetNodeCount(pTree->rchild);

    return nodeCntLeft + nodeCntRight + 1;
}

/* 获取叶子结点个数 */
int GetLeafNodeCount(BiTree pTree)
{
    if (pTree == nullptr) {
        return 0;
    }
    if (pTree->lchild == nullptr && pTree->rchild == nullptr) {
        return 1;
    }

    int nodeCntLeftLeaf = GetLeafNodeCount(pTree->lchild);
    int nodeCntRightLeaf = GetLeafNodeCount(pTree->rchild);

    return nodeCntLeftLeaf + nodeCntRightLeaf;
}

/*
非递归先序遍历
1, 根节点进栈;
2, 弹出就打印;
3, 如果有右孩子, 压入右孩子;
3, 如果有左孩子, 压入左孩子;
*/
//pTree为指向根结点地指针
void PreOrderTraverse(BiTree pTree)
{
    if (pTree == nullptr) {
        return;
    }

    stack<BiTree> st;

    st.push(pTree);
    while (!st.empty()) {

        BiTree pCur = st.top();
        st.pop();
        printf("%c ", pCur->data);

        if (pCur->rchild != nullptr) {
            st.push(pCur->rchild);
        }
        if (pCur->lchild != nullptr) {
            st.push(pCur->lchild);
        }
    }
}

/*

非递归中序遍历:
1, 整条左边界依次入栈
2, 1走到尽头的时候, 弹栈打印
3, 来到右树, 重复1

*/
//pTree为指向根结点地指针
void InOrderTraverse(BiTree pTree)
{
    stack<BiTree> st;
    BiTree pCur = pTree;

    while (pCur || !st.empty()) {
        if (pCur) {
            st.push(pCur);
            pCur = pCur->lchild;
        }
        else {
            pCur = st.top();
            st.pop();
            printf("%c ", pCur->data);
            pCur = pCur->rchild;
        }
    }
}

//非递归后序遍历
//pTree为指向根结点地指针
void PostOrderTraverse(BiTree pTree)
{
    if (pTree == nullptr) {
        return;
    }

    stack<BiTree> stOut;
    stack<BiTree> st;

    st.push(pTree);
    while (!st.empty()) {

        BiTree pCur = st.top();
        st.pop();
        stOut.push(pCur);

        if (pCur->lchild != nullptr) {
            st.push(pCur->lchild);
        }
        if (pCur->rchild != nullptr) {
            st.push(pCur->rchild);
        }
    }

    while (!stOut.empty()) {
        BiTree pCur = stOut.top();
        stOut.pop();
        printf("%c ", pCur->data);
    }
}

//层序遍历
//pTree为指向根结点地指针
void LevelOrderTraverse(BiTree pTree)
{
    queue<BiTree> que;
    BiTree pCur = pTree;

    que.push(pCur);
    while (!que.empty())//若队列非空
    {
        pCur = que.front();
        que.pop();
        printf("%c ", pCur->data);

        if (pCur->lchild) {
            que.push(pCur->lchild);
        }
        if (pCur->rchild) {
            que.push(pCur->rchild);
        }
    }
}

/* 获取树的最大宽度那一层 */
int getMaxWidthUseMap(BiTree pTree)
{
    if (pTree == nullptr) {
        return 0;
    }

    map<BiTree, int> levelMap; //记录节点在哪一层
    queue<BiTree> que;

    BiTree pCur = pTree;
    que.push(pCur);
    levelMap[pCur] = 1;       //根节点在第一层

    int curLevel = 1;         //当前统计的层
    int curLevelNodes = 0;    //当前统计的层上的节点数
    int maxNodes = 0;
    while (!que.empty())      //若队列非空
    {
        pCur = que.front();
        que.pop();

        int curNodeLevel = levelMap[pCur];
//        printf("%c ", pCur->data);

        if (pCur->lchild) {
            que.push(pCur->lchild);
            levelMap[pCur->lchild] = curNodeLevel + 1;  //记录左孩子节点在哪一层
        }
        if (pCur->rchild) {
            que.push(pCur->rchild);
            levelMap[pCur->rchild] = curNodeLevel + 1;  //记录右孩子节点在哪一层
        }

        if (curNodeLevel == curLevel) {
            curLevelNodes++;
        }
        else {
            maxNodes = max(maxNodes, curLevelNodes);
            curLevel++;
            curLevelNodes = 1;
        }
    }
    maxNodes = max(maxNodes, curLevelNodes);

    return maxNodes;
}

/* 先序序列化 */
void preOrderSerialize(BiTree pTree)
{
    if (pTree == nullptr) {
        printf("^ ");
        return;
    }

    printf("%c ", pTree->data);
    preOrderSerialize(pTree->lchild);
    preOrderSerialize(pTree->rchild);
}

/* 先序反序列化 */
static int index;
static void deserialization(string &serial, BiTree &T)
{
    TElemType ch = serial[index++];
    if (ch == '^') {
        T = nullptr;//空树，保证是叶子结点，递归结束条件
        return;
    }

    //生成结点
    T = (BiTNode *)malloc(sizeof(BiTNode));
    if (T == nullptr) {
        return;
    }
    T->data = ch;

    //构造左子树
    deserialization(serial, T->lchild);

    //构造右子树
    deserialization(serial, T->rchild);
}
void preOrderDeserialization(string serial, BiTree &T)
{
    index = 0;
    deserialization(serial, T);
}

/* 层序序列化 */
void levelOrderSerialize(BiTree pTree)
{
    if (pTree == nullptr) {
        printf("^ ");
        return;
    }

    queue<BiTree> que;
    BiTree pCur = pTree;

    que.push(pCur);
    printf("%c ", pCur->data);

    while (!que.empty())//若队列非空
    {
        pCur = que.front();
        que.pop();

        if (pCur->lchild) {
            que.push(pCur->lchild);
            printf("%c ", pCur->lchild->data);
        } else {
            printf("^ ");
        }

        if (pCur->rchild) {
            que.push(pCur->rchild);
            printf("%c ", pCur->rchild->data);
        } else {
            printf("^ ");
        }
    }
}

/* 层序反序列化 */
static BiTree generateNode(char ch)
{
    if (ch == '^') {
        return nullptr;
    }
    else {
        BiTree retNode = (BiTree)malloc(sizeof(BiTNode));
        retNode->data = ch;
        return retNode;
    }
}
void levelOrderDeserialize(string serial, BiTree &pTree)
{
    if (serial.size() == 0) {
        pTree = nullptr;
    }

    int index = 0;
    queue<BiTree> que;

    BiTree head = generateNode(serial[index++]);
    if (head != nullptr) {
        que.push(head);
    }

    while (!que.empty()) {
        BiTree node = que.front();
        que.pop();

        node->lchild = generateNode(serial[index++]);
        node->rchild = generateNode(serial[index++]);

        if (node->lchild != nullptr) {
            que.push(node->lchild);
        }
        if (node->rchild != nullptr) {
            que.push(node->rchild);
        }
    }

    pTree = head;
}
