#include <stdio.h>
#include <stdlib.h>
#include "BiThreadTree.h"

/*
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

//线索二叉树初始化, 以先序输入
void CreateBiThrNode(BiThrTree &tree)
{
	TElemType ch = getchar();
	fflush(stdin);
    if (ch=='^') {
        tree = nullptr;
    }
    else {
        tree = (BiThrTree)malloc(sizeof(BiThrNode));
        tree->data = ch;
        tree->LTag = Link; //默认都是链
        tree->RTag = Link;

        printf("输入左子树:\n");
        CreateBiThrNode(tree->lchild);

        printf("输入右子树:\n");
        CreateBiThrNode(tree->rchild);
    }
}

//中序线索化二叉树
static void InThreading(BiThrTree tree, BiThrTree &pre)
{
    if(tree == nullptr) {
        return;
    }

    InThreading(tree->lchild, pre);

    //如果左孩子为空, lchild指向中序前驱
    if (tree->lchild == nullptr) {
        tree->LTag = Thread;
        tree->lchild = pre;
    }

    //如果中序序列的前一个结点的右孩子为空, rchild指向中序后继
    if (pre->rchild == nullptr) {
        pre->RTag = Thread;
        pre->rchild = tree;
    }
    pre = tree; //用pre记录上一个中序结点

    InThreading(tree->rchild, pre);
}

//为中序线索二叉树添加头结点, 使之可以双向操作
void InOrderThreading(BiThrTree tree, BiThrTree &head)
{
    //创建头结点
    head = (BiThrTree)malloc(sizeof(BiThrNode));
    head->LTag = Link;
    head->RTag = Thread;
    head->lchild = tree;  //头结点的左孩子指向根结点
    head->rchild = head;  //头结点的右孩子指向头结点自己

    //线索化
    BiThrTree pre;
    pre = head;           //pre指向头结点
    InThreading(tree, pre);

    //InThreading结束后, pre指向中序序列最后一个结点
    pre->rchild = head;
    pre->RTag = Thread;
    head->rchild = pre;  //头结点的右孩子指向中序序列最后一个结点
}

//非递归中序遍历线索二叉树
void InOrderTraverse(BiThrTree head)
{
    BiThrNode *p = head->lchild;
    while (p != head) {
        while (p->LTag == Link) {
            p = p->lchild;    //走向左子树的尽头
        }
        printf("%c", p->data);

        while (p->RTag == Thread && p->rchild != head) {  //访问该结点的后继结点
            p = p->rchild;
            printf("%c", p->data);
        }
        p = p->rchild;
    }
}
