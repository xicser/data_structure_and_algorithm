#ifndef __BI__THREAD_TREE_H__
#define __BI__THREAD_TREE_H__

//函数状态结果代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

//Status是函数的类型，其值是函数结果状态代码
typedef int Status;

//结点元素类型
typedef char TElemType;

//指示: 指针or线索
typedef enum
{
	Link,		//指针
	Thread		//线索
} PointerTag;

//结点
typedef struct BiThrNode
{
	TElemType		  data;				//数据
	struct BiThrNode *lchild, *rchild;	//左右孩子指针
	PointerTag	LTag, RTag;				//左右标志
} BiThrNode, *BiThrTree;


void CreateBiThrNode(BiThrTree &tree);
void InOrderThreading(BiThrTree tree, BiThrTree &head);
void InOrderTraverse(BiThrTree head);

#endif
