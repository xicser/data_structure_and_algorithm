#ifndef __LINK_TREE_H__
#define __LINK_TREE_H__


//数据域元素类型
typedef char TElemType;

//树的结点
typedef struct BiTNode
{
	TElemType		 data;				//数据域
	struct BiTNode	*lchild, *rchild;	//左右孩子指针
} BiTNode, *BiTree;

/*操作集*/

//按先序次序输入二叉树中结点的值（TElemType），空格字符表示空树
//构造二叉链表表示的二叉树T
void CreateBiTreeRecursion(BiTree &T);

/*递归函数*/
void PreOrderTraverseRecursion(BiTree T, int level);//先序遍历
void InOrderTraverseRecursion(BiTree T);//中序遍历
void PostOrderTraverseRecursion(BiTree T);//后序遍历


/*非递归函数*/
void PreOrderTraverse(BiTree pTree);//先序遍历
void InOrderTraverse(BiTree pTree);//中序遍历
void PostOrderTraverse(BiTree pTree);//后序遍历
void LevelOrderTraverse(BiTree pTree);//层序遍历


#endif
