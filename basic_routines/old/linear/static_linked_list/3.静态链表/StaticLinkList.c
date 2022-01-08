
/*

2017��12��6�գ�С�������ܶ���

��̬�������ʵ��

���ݽṹ��ÿ�������㶼��ֵ���αꣻ
�α��ʾ��һ����㣬����Ϊ���ý��ͱ��ý�㣻
��һ����������㱣����
��һ������α��ʾ���ý����ʼλ�ã�
���һ������α��ʾ���ý�����ʼλ�ã�
���ý������һ��Ԫ�ص��α�ָ��0����ʾĩβ��

*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sys.h"
#include "StaticLinkList.h"


/**********************************
��ʼ����̬����
����ֵ�������ָ��
���ֵ��״̬��
���ܣ�  �����Խڵ���α�ָ���һ�����
***********************************/
Status InitLink(staticlink space)
{
	int i;
	for (i = 0; i<(MAX_SIZE - 1); i++)//���������һ�����������н��
	{ 
		space[i].cur = i + 1;//�������α�ָ���¸����
	}
	//���һ�������α�ָ���һ�����
	space[MAX_SIZE - 1].cur = 0;

	return OK;
}
/*********************************
���䱸�ÿռ�
����ֵ�������ָ��
���ֵ�����ýڵ���±�
���ܣ�  ��õ�һ�����н����±�
*********************************/
static int mallocSpace(staticlink space)
{
	int i;

	i = space[0].cur;//ȡ����һ�����ýڵ�

	if (space[0].cur)//���ȡ���ɹ�
		space[0].cur = space[i].cur;//��һ���ڵ��ָ�������ƶ�

	return i;
}
/********************************
��ȡ����
����ֵ�������ָ��
���ֵ������ֵ
���ܣ�  �������������õĽڵ����
********************************/
int GetLength(staticlink space)
{
	int mov = MAX_SIZE - 1;
	int j = 0;//��������ʼֵΪ0

	while (space[mov].cur)//�����������ýڵ�
	{
		mov = space[mov].cur;
		j++;
	}
	return j;
}
/*********************************
����ֵ
����ֵ�������ָ�룬��ʼֵ����
���ֵ��״̬��
���ܣ�  Ϊ�����ʼ��ָ�����������ֵ
*********************************/
Status CreateValue(staticlink space, int num)
{
	int i, mov = MAX_SIZE - 1;

	srand((unsigned int)time(0));//��ʼ�������������

	space[mov].cur = 1;//���һ�������α�ָ���±�Ϊ1�Ľ��
	for (i = 0; i<num; i++)
	{
		mov = space[mov].cur;//�ƶ��α�
		space[mov].data = rand() % 100 + 1;//��ʼ�����ֵ
	}
	space[0].cur = space[mov].cur;//��һ���ڵ��α�ָ���ýڵ�
	space[mov].cur = 0;//Ϊ0��־�������Ľ���

	return OK;
}
/*********************************
����ڵ�
����ֵ�������ָ�룬����λ��(��1��ʼ)
���ֵ��״̬��
���ܣ�  ��ָ����λ�ò���ָ����ֵe
*********************************/
Status InsertNode(staticlink space, int index, ElemType e)
{
	int new, mov, i;

	//����λ�ü��
	if (index<1 || index>GetLength(space)+1)return ERR1;

	mov = MAX_SIZE - 1;
	new = mallocSpace(space);//��õ�һ�����н����±�
	if (new)//��ȡ�ɹ�
	{
		space[new].data = e;//���½���������
		for (i = 1; i<index; i++)//��λ����ڵ��ǰһ�ڵ�
			mov = space[mov].cur;

		space[new].cur = space[mov].cur;//����
		space[mov].cur = new;//��ǰ

		return OK;
	}

	return ERR2;
}
/***********************************
�ͷŽڵ�
����ֵ�������ָ�룬�ͷŽڵ��λ�ã�Ҫɾ������λ�ã�
���ֵ��״̬��
����:   �����ýڵ��ͷųɱ��ýڵ�
***********************************/
static Status freeNode(staticlink space, int target)
{
	space[target].cur = space[0].cur;//�ͷŽڵ����ӱ�������
	space[0].cur = target;//��һ�ڵ������ͷŽڵ�
	return OK;
}
/************************************
ɾ���ڵ�
����ֵ�������ָ�룬ɾ��λ��(��1��ʼ)
���ֵ��״̬��
���ܣ�  ɾ��ָ���Ľڵ�
************************************/
Status DeleteNode(staticlink space, int index)
{
	int mov, next, i;

	//ɾ��λ�ü��
	if (index<1 || index>GetLength(space))return ERR1;

	mov = MAX_SIZE - 1;
	for (i = 1; i<index; i++)//��λɾ���ڵ��ǰһ�ڵ�
		mov = space[mov].cur;

	next = space[mov].cur;//��ȡ��ɾ�ڵ��±�
	space[mov].cur = space[next].cur; //ǰһ�ڵ����ӱ�ɾ�ڵ���α�
	freeNode(space, next);//�ͷű�ɾ�ڵ�

	return OK;
}
/**********************************
�������
����ֵ�������ָ��
���ֵ��״̬��
���ܣ�  �������ֵһһ���
**********************************/
Status PrintLink(staticlink space)
{
	int mov = MAX_SIZE - 1;
	while (space[mov].cur)
	{
		mov = space[mov].cur;
		printf("[%d] ", space[mov].data);
	}
	printf("\n");
	return OK;
}
