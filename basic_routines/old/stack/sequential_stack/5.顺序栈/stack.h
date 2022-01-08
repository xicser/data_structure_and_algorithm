#ifndef __STACK_H__
#define __STACK_H__

#define STACK_INIT_SIZE 100//顺序栈数据元素存储空间的初始分配量
#define STACK_INCREASE  10 //顺序栈数据元素存储空间的分配增量

//栈元素类型定义
typedef int ElemType;

//顺序栈类型定义
typedef struct
{
	ElemType *top;		//栈顶指针
	ElemType *base;		//数据元素存储空间基地址
	int size;			//当前存储空间容量（以sizeof(ElemType)为单位，栈所能达到的最大长度）
}Stack;//Stack为结构体类型

int  InitStack(Stack *S);//构造一个空栈S
void DestroyStack(Stack *S);//销毁栈S（释放占用的内存）
void ClearStack(Stack *S);//将S置为空栈
int  StackEmpty(Stack S);//检测S是否为空栈
int  StackLength(Stack S);//返回栈S中的数据元素个数，即栈的长度
int  GetTop(Stack S, ElemType *e);//用e返回S的栈顶元素
int  Push(Stack *S, ElemType e);//压栈
int  Pop(Stack *S, ElemType *e);//弹栈
void StackTraverse(Stack S, void(*visit)(ElemType *));//遍历栈中的元素

#endif
