#ifndef __BI__THREAD_TREE_H__
#define __BI__THREAD_TREE_H__

//结点元素类型
typedef char TElemType;

//指示：指针or线索
typedef enum
{
	Link,		//指针
	Thread		//线索
}PointerTag;

//结点
typedef struct BiThrNode
{
	TElemType		  data;				//数据
	struct BiThrNode *lchild, *rchild;	//左右孩子指针
	PointerTag	LTag, RTag;				//左右标志
}BiThrNode, *BiThrTree;






#endif
