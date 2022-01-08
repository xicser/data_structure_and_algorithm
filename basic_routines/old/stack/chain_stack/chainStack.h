#ifndef __CHAINSTACK_H__
#define __CHAINSTACK_H__

//结点数据类型定义
#define DATA_FLOAT  0
#define DATA_INT    1

//32-bit无符号整型，用来表示地址
#define u32 unsigned int

//栈节点结构定义
typedef struct Node
{
	u32		     valueAddr;	//数据域地址
	int          DataType;  //数据类型指示
	struct Node	*next;	    //指针域
}Node;

//栈结构定义
typedef struct
{
	Node *top;     //栈顶指针
}Stack;

//操作集
void  InitStack(Stack* stack);//初始化栈
void  Clear(Stack* stack);//清空栈
void  Destroy(Stack* stack);//销毁栈
void  Push(Stack *stack, u32 valAddr, int valType);//压栈
void  Pop(Stack* stack, u32 *valAddr, int *valType);//弹栈
int   Length(Stack* stack);//获取栈长度
void  NodeDisplay(Node* node);//显示栈节点数据
void  StackTraverse(Stack* stack);//遍历

#endif
