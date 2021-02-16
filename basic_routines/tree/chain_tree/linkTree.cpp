
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

//非递归先序遍历
//pTree为指向根结点地指针
void PreOrderTraverse(BiTree pTree)
{
    stack<BiTree> st;
    BiTree pCur = pTree;

    while (pCur || !st.empty()) {
        if (pCur) {
            st.push(pCur);
            printf("%c ", pCur->data);
            pCur = pCur->lchild;
        }
        else {
            pCur = st.top();
            st.pop();
            pCur = pCur->rchild;
        }
    }
}

//非递归中序遍历
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
    stack<BiTree> stOut;
    stack<BiTree> st;
    BiTree pCur = pTree;

    while (pCur || !st.empty()) {
        if (pCur) {
            st.push(pCur);

            // printf("%c ", pCur->data);
            stOut.push(pCur);

            pCur = pCur->rchild;
        }
        else {
            pCur = st.top();
            st.pop();
            pCur = pCur->lchild;
        }
    }

    while (!stOut.empty()) {
        pCur = stOut.top();
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
		printf("%c ", pCur->data);

		if (pCur->lchild) {
            que.push(pCur->lchild);
		}
		if (pCur->rchild) {
            que.push(pCur->rchild);
		}

		que.pop();
	}
}
