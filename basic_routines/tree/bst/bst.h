#ifndef BST_H
#define BST_H

//树的结点
typedef struct BSTNode
{
    int              data;              //数据域
    struct BSTNode  *lchild, *rchild;   //左右孩子指针
} BSTNode, *BSTree;

void searchValue(BSTree tree);

#endif // BST_H
