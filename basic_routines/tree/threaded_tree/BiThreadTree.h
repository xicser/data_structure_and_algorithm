#ifndef __BI__THREAD_TREE_H__
#define __BI__THREAD_TREE_H__

//����״̬�������
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

//Status�Ǻ��������ͣ���ֵ�Ǻ������״̬����
typedef int Status;

//���Ԫ������
typedef char TElemType;

//ָʾ: ָ��or����
typedef enum
{
	Link,		//ָ��
	Thread		//����
} PointerTag;

//���
typedef struct BiThrNode
{
	TElemType		  data;				//����
	struct BiThrNode *lchild, *rchild;	//���Һ���ָ��
	PointerTag	LTag, RTag;				//���ұ�־
} BiThrNode, *BiThrTree;


void CreateBiThrNode(BiThrTree &tree);
void InOrderThreading(BiThrTree tree, BiThrTree &head);
void InOrderTraverse(BiThrTree head);

#endif
