#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "stack.h"



//构造一个空栈S
//返回值：0成功，非0失败
int InitStack(Stack *S)
{
	S->base = (ElemType*)malloc(sizeof(ElemType)*STACK_INIT_SIZE);
	if (S->base == NULL)return 1;//失败

	S->top = S->base;//初始时栈顶位置
	S->size = STACK_INIT_SIZE;

	return 0;//成功
}
//销毁栈S（释放占用的内存）
void DestroyStack(Stack *S)
{
	free(S->base);//释放内存
	S->base = S->top = NULL;
	S->size = 0;
}
//将S置为空栈
void ClearStack(Stack *S)
{
	if (S != NULL)S->top = S->base;
}
//检测S是否为空栈
//返回值：若S为空栈，返回TRUE，若S为非空栈，返回FALSE
int StackEmpty(Stack S)
{
	return S.top == S.base;
}
//返回栈S中的数据元素个数，即栈的长度
int StackLength(Stack S)
{
	return S.top - S.base;
}
//用e返回S的栈顶元素
//返回值：0成功，非0失败
int GetTop(Stack S,ElemType *e)
{
	if (S.top > S.base && e != NULL)//栈非空
	{
		*e = *(S.top - 1);//返回S的栈顶元素
		return 0;//成功
	}
	return 1;//栈为空，失败
}
//压栈,即将e进栈，插入元素e为新的栈顶元素
//返回值：0成功，非0失败
int Push(Stack *S, ElemType e)
{
	if (S->top - S->base >= S->size)//若栈空间满则追加存储空间
	{
		S->base = (ElemType*)realloc(S->base, (S->size + STACK_INCREASE)*sizeof(ElemType));
		if (S->base == NULL)return 1;//内存重新分配失败
		S->top = S->base + S->size;//新的栈顶地址
		S->size += STACK_INCREASE;//设置栈的最大容量
	}
	*(S->top)++ = e;//e入栈

	return 0;
}
//弹栈，若栈不为空，则用*e返回S的栈顶元素
//返回值：0成功，非0失败
int Pop(Stack *S, ElemType *e)
{
	if (S->top == S->base)return 1;//栈为空
	*e = *--(S->top);//出栈到*e
	return 0;
}
//遍历栈中的元素
//从栈底到栈顶依次对栈中每个元素调用函数visit访问它
void StackTraverse(Stack S, void(*visit)(ElemType *))
{
	while (S.top > S.base)visit(S.base++);
}
