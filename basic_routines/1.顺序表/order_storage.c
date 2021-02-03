
//���Ա� ˳��洢�ṹ �����ʵ��

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "order_storage.h"


//����˳���
//����ֵ��0�ɹ�����0ʧ��
int CreateList(List *L, int n, void(*input)(ElemType *))
{
	ElemType s, *p;
	p = L->base = (ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));//����ռ�
	if (p == NULL)return 1;//�ڴ����ʧ��

	L->length = n;//��ʼ��˳�����Ϊn
	L->size = LIST_INIT_SIZE;//��ʼ�洢����

	for (; n > 0; n--)//����n���������
	{
		input(&s);//����input��������Ԫ�ظ�s
		*p++ = s;//���δ���˳�����
	}

	return 0;//�ɹ�
}
//���Ա����
//����˳����е�һ����e�����ϵcompare()������Ԫ�ص�λ����������������Ԫ�أ��򷵻�0
static int compare(ElemType *ep1, ElemType *ep2)
{
	//... ...�Լ�����
	return 0;
}
int LocateElem(List L, ElemType e, int(*compare)(ElemType *, ElemType *))
{
	int i = 1;//ָ���һ��Ԫ��
	ElemType *p = L.base;
	while (i <= L.length && !compare(p, &e))i++, p++;
	if (i > L.length)return 0;//��ϵ��������������0
	return i;//��ϵ����������λ��
}
//���Ա����
//����ֵ��0�ɹ�����0ʧ��
int ListInsert(List *L, int i, ElemType e)
{
	ElemType *base, *p, *q;
	if (i<1 || i>L->length + 1)return 1;//����λ�ò��Ϸ�
	if (L->length >= L->size)//��ǰ�洢�ռ����������ݣ�
	{
		L->size += LIST_INCREASE;//���Ӵ洢����
		base = (ElemType*)realloc(L->base,L->size*sizeof(ElemType));
		L->base = base;//�µĻ���ַ
	}
	q = L->base + i - 1;//qΪ����λ��

	for (p = L->base + L->length - 1; p >= q; --p)
		*(p + 1) = *p;//����λ���Լ�֮���Ԫ������

	*q = e;//����e
	++(L->length);//���Ա��ȼ�1

	return 0;//�ɹ�
}
//���Ա�ɾ��
//����ֵ��0�ɹ�����0ʧ��
int ListDelete(List *L, int i, ElemType *e)
{
	ElemType *p, *q;

	if (i<1||i>L->length)return 1;//ɾ��λ�ò�����
	p = L->base + i - 1;//pΪ��ɾ��Ԫ�ص�λ��

	if (e != NULL)*e = *p;//��*e���ر�ɾ�������ֵ
	q = L->base + L->length - 1;//��βԪ�ص�λ��

	for (++p; p <= q; ++p)
		*(p - 1) = *p;//��ɾԪ��֮���Ԫ������

	(L->length)--;//���Ա��ȼ�1

	return 0;
}

//���Ա����
static void visit(ElemType *ep)
{
	//...�Լ�����
}
void ListTraverse(List L, void(*visit)(ElemType*))
{
	int i;
	ElemType *p = L.base;
	for (i = 1; i <= L.length; i++)
		visit(p++);//����visit����ÿ�����
}
//����һ���յ�˳���L
//����ֵ��0�ɹ�����0ʧ��
int InitList(List *L)
{
	L->base = (ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));//����ռ�
	if (L->base == NULL)return 1;//�ڴ�����ʧ��
	L->length = 0;//�ձ���Ϊ0
	L->size = LIST_INIT_SIZE;//��ʼ�洢����
	return 0;//�ɹ�
}
//����˳���L
void DestroyList(List *L)
{
	free(L->base);//�ͷ�����Ԫ��ռ�õĿռ�
	L->base = NULL;
	L->length = L->size = 0;
}
//�����Ա�L��Ϊ�ձ�
void ClearList(List *L)
{
	L->length = 0;
}
//������Ա�L�Ƿ�Ϊ�ձ�
//��LΪ�գ�����true�����򷵻�false
int ListEmpty(List L)
{
	return L.length == 0;
}
//�������Ա�L��Ԫ�ظ����������Ա���
int ListLength(List L)
{
	return L.length;
}
//��*e����L�еĵ�i������Ԫ��
//����ֵ��0�ɹ�����0ʧ��
int GetElem(List L, int i, ElemType *e)
{
	if (i<1 || i>L.length)return 1;//iֵ���Ϸ�
	if (e != NULL)*e = *(L.base + i - 1);//ȡ��i��Ԫ�ص�*e

	return 0;//�ɹ�
}
//��*pre_e����cur_e��ǰ��
//����ֵ��0�ɹ�����0ʧ��
int PriorElem(List L, ElemType cur_e, ElemType *pre_e)
{
	int i = 2;
	ElemType *p = L.base + 1;

	while (i <= L.length && *p != cur_e)i++, p++;
	if (i > L.length)return 1;//������cur_e

	if (pre_e != NULL)*pre_e = *(--p);
	return 0;//�ɹ�
}
//��*next_e����cur_e�ĺ��
//����ֵ��0�ɹ�����0ʧ��
int NextElem(List L, ElemType cur_e, ElemType *next_e)
{
	int i = 1;
	ElemType *p = L.base;

	while (i < L.length && *p != cur_e)i++, p++;
	if (i == L.length)return 1;//������cur_e

	if (next_e != NULL)*next_e = *(++p);
	return 0;//�ɹ�
}
//���������ϵĲ�
//�����������Ա�Lb�е�����La�е�����Ԫ�ز��뵽La��
void Union(List *LA,List *LB)
{
	int LA_len, LB_len, i;
	ElemType e;

	LA_len = ListLength(*LA);//���������Ա��
	LB_len = ListLength(*LB);

	for (i = 1; i <= LB_len; i++)//�������Ա�*LB
	{
		GetElem(*LB, i, &e);//ȡ*LB�е�i������Ԫ��e
		if (LocateElem(*LA,e,compare))
			ListInsert(LA,++LA_len,e);//��*LA������e�����֮
	}
}
/*
��֪�������Ա�La��Lb�е�����Ԫ�ذ��������У���Ҫ��La��Lb�鲢Ϊһ���µ����Ա�Lc
��Lc�е�����Ԫ��Ҳ�ǰ��������е�
*/
void MergeList(List La, List Lb, List *Lc)
{
	int i = 1, j = 1, k = 0, la_len, lb_len;
	ElemType a, b;

	InitList(Lc);//�������Ա�Lc
	la_len = ListLength(La);//��ȡ���Ա���
	lb_len = ListLength(Lb);

	while (i<=la_len && j<=lb_len)//��La�ͱ�Lb���ǿ�
	{
		GetElem(La, i, &a), GetElem(Lb,j,&b);//ȡLaԪ��a��ȡLbԪ��b
		if (a <= b){ ListInsert(Lc, ++k, a); i++; }//����a��Lc��
		else{ ListInsert(Lc, ++k, b); j++; }//����b��Lc��
	}
	while (i <= la_len)//��La�ǿ��ұ�Lb��
		GetElem(La, i++, &a), ListInsert(Lc, ++k, a);//����La��ʣ��Ԫ��
	while (j <= lb_len)//��Lb�ǿ��ұ�La��
		GetElem(Lb, j++, &b), ListInsert(Lc, ++k, b);//����Lb��ʣ��Ԫ��
}















