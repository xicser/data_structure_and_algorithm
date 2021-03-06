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
} BiTNode, *BiTree;

/*操作集*/

//按先序次序输入二叉树中结点的值（TElemType），空格字符表示空树
//构造二叉链表表示的二叉树T
void CreateBiTreeRecursion(BiTree &T);

/* 递归相关操作 */
void PreOrderTraverseRecursion(BiTree T, int level);       //先序遍历
void InOrderTraverseRecursion(BiTree T);                   //中序遍历
void PostOrderTraverseRecursion(BiTree T);                 //后序遍历
void BiTreeCopyRecursion(BiTree pTree, BiTree &pTreeOut);  //二叉树复制
int  GetDepth(BiTree pTree);                               //获取深度
int  GetNodeCount(BiTree pTree);                           //获取结点个数
int  GetLeafNodeCount(BiTree pTree);                       //获取叶子结点个数


/* 非递归遍历 */
void PreOrderTraverse(BiTree pTree);    //先序遍历
void InOrderTraverse(BiTree pTree);     //中序遍历
void PostOrderTraverse(BiTree pTree);   //后序遍历
void LevelOrderTraverse(BiTree pTree);  //层序遍历

/* 其他相关操作 */
int  getMaxWidthUseMap(BiTree pTree);   //获取树的最大宽度那一层的宽度
void preOrderSerialize(BiTree pTree);   //先序序列化
void preOrderDeserialization(string serial, BiTree &T);    //先序反序列化
void levelOrderSerialize(BiTree pTree); //层序序列化
void levelOrderDeserialize(string serial, BiTree &pTree);  //层序反序列化



#endif
