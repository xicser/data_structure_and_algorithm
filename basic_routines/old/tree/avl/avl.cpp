/*
avl树本身是一颗二叉查找树
*/

#include "avl.h"
#include <stdio.h>
#include <algorithm>

using namespace std;

/* 创建新节点 */
AVLTree newNode(int data)
{
    AVLTree node = new AVLNode();
    node->data = data;
    node->height = 1;
    node->lchild = nullptr;
    node->rchild = nullptr;

    return node;
}

/* 获取以root为根结点的树的高度 */
int getHeight(AVLTree root)
{
    if (root == nullptr) {
        return 0;
    }
    return root->height;
}

/* 获取平衡因子 */
int getBalanceFactor(AVLTree root)
{
    return getHeight(root->lchild) - getHeight(root->rchild);
}

/* 更新根结点的height */
void updateHeight(AVLTree root)
{
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

/* 查找数据域值为value结点 */
void searchNode(AVLTree tree, int value)
{
    if (tree == nullptr) {
        printf("search failed...\n");
        return;
    }

    if (tree->data == value) {
        printf("%d\n", tree->data);
    }
    else if (value < tree->data) {
        searchNode(tree->lchild, value);
    }
    else {
        searchNode(tree->rchild, value);
    }
}

