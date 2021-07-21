#ifndef __LINK_TREE_H__
#define __LINK_TREE_H__

#include <string>

using namespace std;

//数据域元素类型
typedef char TElemType;

//树的结点
typedef struct BiTNode
{
    TElemType        data;				//数据域
    struct BiTNode  *lchild, *rchild;	//左右孩子指针
    struct BiTNode  *parent;            //父节点指针
} BiTNode, *BiTree;


//按先序次序输入二叉树中结点的值（TElemType），空格字符表示空树
//构造二叉链表表示的二叉树T
void CreateBiTreeRecursion(BiTree &T);

/* 递归相关操作 */
void PreOrderTraverseRecursion(BiTree T, int level);       //先序遍历
void InOrderTraverseRecursion(BiTree T);                   //中序遍历
void PostOrderTraverseRecursion(BiTree T);                 //后序遍历

void printTreeGraphic(BiTree T);                           //图形化方法打印一棵树
BiTree getInOrderTraverseSuccessorNode(BiTree treeNode);   //获取中序遍历下的后继节点
void printCrease(int N);                                   //打印折痕
bool isTreeBalance(BiTree T);                              //判断一个树是否是平衡二叉树
int  getFarestDistance(BiTree T);                          //获取一个树上的最大距离, 距离: 距离最大的两个节点
BiTree getMaxBiSearchSubTree(BiTree T);                    //返回这颗二叉树中最大的二叉搜索子树的头节点(即满足搜索二叉树结构的最大子树)



#endif
