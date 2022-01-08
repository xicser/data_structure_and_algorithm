#ifndef __STATICLINKLIST_H__
#define __STATICLINKLIST_H__

#include "sys.h"

//������󳤶�����
#define MAX_SIZE 1000

//Ԫ�����Ͷ���
typedef int ElemType;

typedef struct
{
	ElemType data;   //����
	int		 cur;	 //�α�
}component, staticlink[MAX_SIZE];//����ṹ������


Status InitLink(staticlink space);//��ʼ����̬����
int    GetLength(staticlink space);//��ȡ����
Status CreateValue(staticlink space, int num);//����ֵ
Status InsertNode(staticlink space, int index, ElemType e);//����ڵ�
Status DeleteNode(staticlink space, int index);//ɾ���ڵ�
Status PrintLink(staticlink space);//�������



#endif
