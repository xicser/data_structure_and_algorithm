#ifndef __BI__THREAD_TREE_H__
#define __BI__THREAD_TREE_H__

//���Ԫ������
typedef char TElemType;

//ָʾ��ָ��or����
typedef enum
{
	Link,		//ָ��
	Thread		//����
}PointerTag;

//���
typedef struct BiThrNode
{
	TElemType		  data;				//����
	struct BiThrNode *lchild, *rchild;	//���Һ���ָ��
	PointerTag	LTag, RTag;				//���ұ�־
}BiThrNode, *BiThrTree;






#endif
