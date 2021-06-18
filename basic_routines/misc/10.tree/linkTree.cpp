
/*

二叉树的链式存储实现:
          1
      2       3
    4   5   6   7

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
#include <algorithm>
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

/* 图形化方法打印一棵树 */
static void printTree(BiTree T, int depth, int wordLen)
{
    if (T == nullptr) {
        return;
    }

    printTree(T->rchild, depth + 1, wordLen);       //右

    for (int i = 0; i < depth; i++) {               //中
        printf("    ");
    }
    printf("%c\n", T->data);

    printTree(T->lchild, depth + 1, wordLen);       //左
}
void printTreeGraphic(BiTree T)
{
    if (T == nullptr) {
        return;
    }

    printTree(T, 1, 20);
}

/* 获取中序遍历下的后继节点 */
static BiTree getLeftMostNode(BiTree node)
{
    if (node == nullptr) {
        return node;
    }
    while (node->lchild != nullptr) {
        node = node->lchild;
    }
    return node;
}
BiTree getInOrderTraverseSuccessorNode(BiTree treeNode)
{
    if (treeNode == nullptr) {
        return nullptr;
    }

    BiTree curNode = treeNode;

    //如果当前节点有右子树, 后继节点就是右子树里面, 最左边那个节点
    if (curNode->rchild != nullptr) {
        return getLeftMostNode(curNode->rchild);
    }
    //否则
    else {
        BiTree parent = curNode->parent;
        while (parent != nullptr && parent->rchild == curNode) { // 当前节点是其父亲节点右孩子, 就一直往上找, 直到是其父亲节点的左孩子
            curNode = parent;
            parent = curNode->parent;
        }
        return parent;
    }
}

/* 打印折痕
   左子树根节点都是凹, 右子树根节点都是凸
 */
static void printCreaseRecursion(int i, int N, bool down)
{
    if (i > N) {
        return;
    }

    printCreaseRecursion(i + 1, N, true);
    down == true ? printf("凹") : printf("凸");
    printCreaseRecursion(i + 1, N, false);
}
void printCrease(int N)
{
    printCreaseRecursion(1, N, true);
}

/* 判断一个树是否是平衡二叉树 */
typedef struct {
    bool isBalance;
    int  height;
} Info_t;
static Info_t checkIsBalance(BiTree T)
{
    if (T == nullptr) {
        Info_t node;
        node.height = 0;
        node.isBalance = true;
        return node;
    }

    Info_t infoLeft = checkIsBalance(T->lchild);
    Info_t infoRight = checkIsBalance(T->rchild);

    Info_t node;
    node.height = max(infoLeft.height, infoRight.height) + 1;

    if (infoLeft.isBalance == true && infoRight.isBalance == true && abs(infoLeft.height - infoRight.height) <= 1 ) {
        node.isBalance = true;
    }
    else {
        node.isBalance = false;
    }

    return node;
}
bool isTreeBalance(BiTree T)
{
    return checkIsBalance(T).isBalance;
}


/* 获取一个树上的最大距离, 距离: 距离最大的两个节点 */
int FarestDistance(BiTree T)
{
    if (T == nullptr) {
        return 0;
    }

    int leftHeight = FarestDistance(T->lchild);
    int rightHeight = FarestDistance(T->rchild);



}


int getFarestDistance(BiTree T)
{
    return FarestDistance(T);
}
























