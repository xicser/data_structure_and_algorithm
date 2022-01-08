#ifndef __STATICLINKLIST_H__
#define __STATICLINKLIST_H__

#include "sys.h"

//数组最大长度设置
#define MAX_SIZE 1000

//元素类型定义
typedef int ElemType;

typedef struct
{
	ElemType data;   //数据
	int		 cur;	 //游标
}component, staticlink[MAX_SIZE];//定义结构体数组


Status InitLink(staticlink space);//初始化静态链表
int    GetLength(staticlink space);//获取长度
Status CreateValue(staticlink space, int num);//创建值
Status InsertNode(staticlink space, int index, ElemType e);//插入节点
Status DeleteNode(staticlink space, int index);//删除节点
Status PrintLink(staticlink space);//输出链表



#endif
