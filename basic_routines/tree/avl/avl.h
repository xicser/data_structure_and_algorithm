#ifndef AVL_H
#define AVL_H

//树的结点
typedef struct AVLNode
{
    int              data;              //数据域
    int              height;            //当前子树高度
    struct AVLNode  *lchild, *rchild;   //左右孩子指针
} AVLNode, *AVLTree;

#endif // AVL_H
