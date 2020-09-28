


/*

�������������ʵ��

*/

#include <stdio.h>
#include <stdlib.h>
#include "BiThreadTree.h"


//�ǵݹ�����������������Ķ�����
//Tָ�� ͷ��� ��ͷ��������lchildָ������
void InOrderTraverse_Thr(BiThrTree T)
{
	BiThrTree p;//����ָ�����ָ��

	p = T->lchild;	//pָ������
	while (p != T)	//�������������ʱ��p==T
	{
		while (p->LTag == Link)p = p->lchild;
		printf("%c ", p->data);//������������Ϊ�յĽ��

		while (p->RTag == Thread && p->rchild != T)
		{
			p = p->rchild;
			printf("%c ", p->data);//���ʺ�̽��
		}
		p = p->rchild;
	}
}

//����������������
static void InThreading(BiThrTree p)
{
	BiThrTree pre=0;

	if (p)
	{
		InThreading(p->lchild);	//������������
		if (!p->lchild){ p->LTag = Thread; p->lchild = pre; }//ǰ������
		if (!pre->rchild){ pre->RTag = Thread; pre->rchild = p; }//�������
		pre = p;				//����preָ��p��ǰ��
		InThreading(p->rchild); //������������
	}
}
//�������������T��������������������Thrtָ��ͷ���
void InOrderThreading(BiThrTree *Thrt, BiThrTree T)
{
	BiThrTree pre;

	(*Thrt) = (BiThrTree)malloc(sizeof(BiThrNode));
	if ((*Thrt) == NULL)return;

	(*Thrt)->LTag = Link; (*Thrt)->RTag = Thread;//����ͷ���
	(*Thrt)->rchild = (*Thrt);//��ָ���ָ
	if (!T)(*Thrt)->lchild = (*Thrt);//��������Ϊ�գ�����ָ���ָ
	else
	{
		(*Thrt)->lchild = T; pre = (*Thrt);
		InThreading(T);//���������������������
		pre->rchild = (*Thrt); pre->RTag = Thread;//���һ�����������
		(*Thrt)->rchild = pre;
	}
}






