#include "bst.h"
#include <stdio.h>

/* 查找数据域值为value结点 */
void searchNode(BSTree tree, int value)
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

/* 插入数据域值为value结点 */
void insertNode(BSTree &tree, int value)
{
    if (tree == nullptr) {
        tree = new BSTNode();
        tree->data = value;
        return;
    }

    if (tree->data == value) {
        return;
    }
    else if (value < tree->data) {
        insertNode(tree->lchild, value);
    }
    else {
        insertNode(tree->rchild, value);
    }
}

/* 创建BST */
BSTree createBST(int *data, int n)
{
    BSTree tree = nullptr;

    for (int i = 0; i < n; i++) {
        insertNode(tree, data[i]);
    }

    return tree;
}

/*
把以二叉查找树中比结点权值小的最大结点称为该结点的前驱，
而把比结点权值大的最小结点称为该结点的后继。
显然，结点的前驱是该结点左子树中的最右结点(也就是从左子树根结点开始不断沿着rchild往下直到rchild为NULL时的结点)，
而结点的后继则是该结点右子树中的最左结点
*/
//获取以root为根的BST的最大节点
static BSTree findMax(BSTree root)
{
    while (root->rchild != nullptr) {
        root = root->rchild;
    }
    return root;
}

//获取以root为根的BST的最小节点
static BSTree findMin(BSTree root)
{
    while (root->lchild != nullptr) {
        root = root->lchild;
    }
    return root;
}

/* 删除某个节点 */
void deleteNode(BSTree &root, int x)
{
    if (root == nullptr) {
        return;
    }

    //找到了要删除的节点
    if (x == root->data) {
        //如果是叶子节点, 直接删除
        if (root->lchild == nullptr && root->rchild == nullptr) {
            delete root;
            root = nullptr;
        }
        //左子树不为空
        else if (root->lchild != nullptr) {
            BSTree prev = findMax(root->lchild);  //左子树的最大节点是其前驱
            root->data = prev->data;
            //然后在左子树中删除prev节点
            deleteNode(root->lchild, prev->data);
        }
        //右子树不为空
        else {
            BSTree next = findMin(root->lchild);  //右子树的最小节点是其后继
            root->data = next->data;
            //然后在右子树中删除next节点
            deleteNode(root->rchild, next->data);
        }
    }
    else if (x < root->data) {
        deleteNode(root->lchild, x);
    }
    else {
        deleteNode(root->rchild, x);
    }
}
