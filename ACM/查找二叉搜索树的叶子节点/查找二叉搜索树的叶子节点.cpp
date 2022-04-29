#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

//树的结点
typedef struct BSTNode
{
    int              data;              //数据域
    struct BSTNode* lchild, * rchild;   //左右孩子指针
} BSTNode, * BSTree;

/* 插入数据域值为value结点 */
void insertNode(BSTree& tree, int value)
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
BSTree createBST(int* data, int n)
{
    BSTree tree = nullptr;

    for (int i = 0; i < n; i++) {
        insertNode(tree, data[i]);
    }

    return tree;
}

void trans(BSTree tree) {
    if (tree == nullptr) {
        return;
    }

    if (tree->lchild == nullptr && tree->rchild == nullptr) {
        printf("%d ", tree->data);
    }
    
    trans(tree->lchild);
    trans(tree->rchild);
}


int dataInput[99999];
int main()
{
    int n = 0;
    int a;
    while (scanf("%d", &a) != -1) {
        dataInput[n++] = a;
    }

    BSTree tree = createBST(dataInput, n);
    trans(tree);


    return 0;
}
