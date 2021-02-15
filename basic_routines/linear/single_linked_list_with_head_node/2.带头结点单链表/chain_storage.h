#ifndef __CHAIN_STORAGE_H__
#define __CHAIN_STORAGE_H__

#include "sys.h"

//线性表元素类型
typedef int C_ElemType;

//设计结点Node（线性表的单链表存储结构）
typedef struct tagNode
{
	C_ElemType      data;	//数据域
	struct tagNode *next;	//指针域
}Node, *LinkList;


void C_ListCreateEmpty(LinkList *L);//创建一个空表
//创建线性表
void C_ListCreateHead(LinkList *L, int n, void(*input)(C_ElemType *));//头插法
void C_ListCreateTail(LinkList *L, int n, void(*input)(C_ElemType *));//尾插法

int  C_ListIsEmpty(LinkList L);//判断线性表是否为空表
void C_ListTraverse(LinkList L, void(*visit)(C_ElemType*));//遍历线性表
int  C_ListLength(LinkList L);//计算线性表长度
void C_ListLink(LinkList L1, LinkList *L2);//将两个线性表L1，L2相连
STATUS C_ListGetElem(LinkList L, int i, C_ElemType *e);//当第i个元素存在时，其值赋给*e并返回0，否则返回非0值
//返回线性表中第一个满足compare()关系的元素的位序
int  C_ListLocateElem(LinkList L, C_ElemType e, int(*compare)(C_ElemType*, C_ElemType*));
STATUS C_ListInsert(LinkList *L, int i, C_ElemType e);//在带头结点的单链线性表L中第i个位置之前插入元素e
//在带头结点的单链线性表L中删除第i个元素，并用*e返回其值
STATUS C_ListDelete(LinkList *L, int i, C_ElemType *e);
void C_ListDestroy(LinkList *L);//销毁线性表L
void C_ListClear(LinkList *L);//将L重置为空表
int  C_ListGetLastElem(LinkList L,C_ElemType *e);//获取链表尾结点元素
int  C_ListPriorElem(LinkList L,C_ElemType cur_e,C_ElemType *pre_e);//返回链表中指定元素的前驱元素
int  C_ListNextElem(LinkList L,C_ElemType cur_e,C_ElemType *next_e);//返回链表中指定元素的后继元素
STATUS GetMidNode(LinkList L, C_ElemType *e);//获取链表中间结点元素值


//选择排序法
LinkList C_ListSelectSort1(LinkList head);//从大到小
void C_ListSelectSort2(LinkList head);//从小到大

#endif
