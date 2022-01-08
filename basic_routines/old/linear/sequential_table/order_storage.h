#ifndef __ORDER_STORAGE_H__
#define __ORDER_STORAGE_H__


#define LIST_INIT_SIZE  100		//顺序表数据元素存储空间的初始分配量
#define LIST_INCREASE	10		//顺序表数据元素存储空间的分配增量


//线性表元素类型
typedef int ElemType;

//线性顺序表类型
typedef struct
{
	ElemType	*base;		    //数据元素存储空间基地址
	int          length;		//顺序表长度(以sizeof(ElemType)为单位)
	int          size;			//当前存储空间容量(以sizeof(ElemType)为单位)
}List;//List为结构体类型


int  CreateList(List *L, int n, void(*input)(ElemType *));//建立顺序表
int  LocateElem(List L, ElemType e, int(*compare)(ElemType *, ElemType *));//线性表查找
int  ListInsert(List *L, int i, ElemType e);//线性表插入
int  ListDelete(List *L, int i, ElemType *e);//线性表删除
void ListTraverse(List L, void(*visit)(ElemType*));//线性表遍历
int  InitList(List *L);//构造一个空的顺序表L
void DestroyList(List *L);//销毁顺序表L
void ClearList(List *L);//将线性表L置为空表
int  ListEmpty(List L);//检测线性表L是否为空表
int  ListLength(List L);//返回线性表L中元素个数，即线性表长度
int  GetElem(List L, int i, ElemType *e);//用*e返回L中的第i个数据元素
int  PriorElem(List L, ElemType cur_e, ElemType *pre_e);//用*pre_e返回cur_e的前驱
int  NextElem(List L, ElemType cur_e, ElemType *next_e);//用*next_e返回cur_e的后继

void Union(List *LA, List *LB);//求两个集合的并
//连接两个有序表，结果仍为有序表
void MergeList(List La, List Lb, List *Lc);





#endif
