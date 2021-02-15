
//线性表 顺序存储结构 的相关实现

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "order_storage.h"


//建立顺序表
//返回值：0成功；非0失败
int CreateList(List *L, int n, void(*input)(ElemType *))
{
	ElemType s, *p;
	p = L->base = (ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));//分配空间
	if (p == NULL)return 1;//内存分配失败

	L->length = n;//初始化顺序表长度为n
	L->size = LIST_INIT_SIZE;//初始存储容量

	for (; n > 0; n--)//创建n个结点链表
	{
		input(&s);//调用input输入数据元素给s
		*p++ = s;//依次存入顺序表中
	}

	return 0;//成功
}
//线性表查找
//返回顺序表中第一个与e满足关系compare()的数据元素的位序，若不存在这样的元素，则返回0
static int compare(ElemType *ep1, ElemType *ep2)
{
	//... ...自己定制
	return 0;
}
int LocateElem(List L, ElemType e, int(*compare)(ElemType *, ElemType *))
{
	int i = 1;//指向第一个元素
	ElemType *p = L.base;
	while (i <= L.length && !compare(p, &e))i++, p++;
	if (i > L.length)return 0;//关系都不成立，返回0
	return i;//关系成立，返回位序
}
//线性表插入
//返回值：0成功；非0失败
int ListInsert(List *L, int i, ElemType e)
{
	ElemType *base, *p, *q;
	if (i<1 || i>L->length + 1)return 1;//插入位置不合法
	if (L->length >= L->size)//当前存储空间已满，扩容！
	{
		L->size += LIST_INCREASE;//增加存储容量
		base = (ElemType*)realloc(L->base,L->size*sizeof(ElemType));
		L->base = base;//新的基地址
	}
	q = L->base + i - 1;//q为插入位置

	for (p = L->base + L->length - 1; p >= q; --p)
		*(p + 1) = *p;//插入位置以及之后的元素右移

	*q = e;//插入e
	++(L->length);//线性表长度加1

	return 0;//成功
}
//线性表删除
//返回值：0成功；非0失败
int ListDelete(List *L, int i, ElemType *e)
{
	ElemType *p, *q;

	if (i<1||i>L->length)return 1;//删除位置不合理
	p = L->base + i - 1;//p为被删除元素的位置

	if (e != NULL)*e = *p;//用*e返回被删结点数据值
	q = L->base + L->length - 1;//表尾元素的位置

	for (++p; p <= q; ++p)
		*(p - 1) = *p;//被删元素之后的元素左移

	(L->length)--;//线性表长度减1

	return 0;
}

//线性表遍历
static void visit(ElemType *ep)
{
	//...自己定制
}
void ListTraverse(List L, void(*visit)(ElemType*))
{
	int i;
	ElemType *p = L.base;
	for (i = 1; i <= L.length; i++)
		visit(p++);//调用visit访问每个结点
}
//构造一个空的顺序表L
//返回值：0成功；非0失败
int InitList(List *L)
{
	L->base = (ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));//分配空间
	if (L->base == NULL)return 1;//内存申请失败
	L->length = 0;//空表长度为0
	L->size = LIST_INIT_SIZE;//初始存储容量
	return 0;//成功
}
//销毁顺序表L
void DestroyList(List *L)
{
	free(L->base);//释放数据元素占用的空间
	L->base = NULL;
	L->length = L->size = 0;
}
//将线性表L置为空表
void ClearList(List *L)
{
	L->length = 0;
}
//检测线性表L是否为空表
//若L为空，返回true，否则返回false
int ListEmpty(List L)
{
	return L.length == 0;
}
//返回线性表L中元素个数，即线性表长度
int ListLength(List L)
{
	return L.length;
}
//用*e返回L中的第i个数据元素
//返回值：0成功；非0失败
int GetElem(List L, int i, ElemType *e)
{
	if (i<1 || i>L.length)return 1;//i值不合法
	if (e != NULL)*e = *(L.base + i - 1);//取第i个元素到*e

	return 0;//成功
}
//用*pre_e返回cur_e的前驱
//返回值：0成功；非0失败
int PriorElem(List L, ElemType cur_e, ElemType *pre_e)
{
	int i = 2;
	ElemType *p = L.base + 1;

	while (i <= L.length && *p != cur_e)i++, p++;
	if (i > L.length)return 1;//不存在cur_e

	if (pre_e != NULL)*pre_e = *(--p);
	return 0;//成功
}
//用*next_e返回cur_e的后继
//返回值：0成功；非0失败
int NextElem(List L, ElemType cur_e, ElemType *next_e)
{
	int i = 1;
	ElemType *p = L.base;

	while (i < L.length && *p != cur_e)i++, p++;
	if (i == L.length)return 1;//不存在cur_e

	if (next_e != NULL)*next_e = *(++p);
	return 0;//成功
}
//求两个集合的并
//将所有在线性表Lb中但不在La中的数据元素插入到La中
void Union(List *LA,List *LB)
{
	int LA_len, LB_len, i;
	ElemType e;

	LA_len = ListLength(*LA);//求两个线性表表长
	LB_len = ListLength(*LB);

	for (i = 1; i <= LB_len; i++)//遍历线性表*LB
	{
		GetElem(*LB, i, &e);//取*LB中第i个数据元素e
		if (LocateElem(*LA,e,compare))
			ListInsert(LA,++LA_len,e);//若*LA不存在e则插入之
	}
}
/*
已知两个线性表La和Lb中的数据元素按升序排列，现要求将La和Lb归并为一个新的线性表Lc
且Lc中的数据元素也是按升序排列的
*/
void MergeList(List La, List Lb, List *Lc)
{
	int i = 1, j = 1, k = 0, la_len, lb_len;
	ElemType a, b;

	InitList(Lc);//构造线性表Lc
	la_len = ListLength(La);//获取线性表长度
	lb_len = ListLength(Lb);

	while (i<=la_len && j<=lb_len)//表La和表Lb均非空
	{
		GetElem(La, i, &a), GetElem(Lb,j,&b);//取La元素a，取Lb元素b
		if (a <= b){ ListInsert(Lc, ++k, a); i++; }//插入a到Lc中
		else{ ListInsert(Lc, ++k, b); j++; }//插入b到Lc中
	}
	while (i <= la_len)//表La非空且表Lb空
		GetElem(La, i++, &a), ListInsert(Lc, ++k, a);//插入La的剩余元素
	while (j <= lb_len)//表Lb非空且表La空
		GetElem(Lb, j++, &b), ListInsert(Lc, ++k, b);//插入Lb的剩余元素
}















