
/*

小王持续奋斗！

链式栈的相关实现

*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "chainStack.h"


//初始化栈
void InitStack(Stack* stack)
{
	stack->top /*= stack->base*/ = (Node*)malloc(sizeof(Node));
	stack->top->next = NULL;
}
//清空栈
//释放除了top指向的那个结点
void Clear(Stack* stack)
{
	Node* pNode, *tmp;

	pNode = stack->top->next;//指向第一个结点

	//遍历栈，释放每一块节点内存（除了top指向的那个结点）
	while (pNode != NULL)
	{
		tmp = pNode;//记录下要释放的内存地址
		pNode = pNode->next;//下一个节点的地址
		free((void*)tmp->valueAddr);//释放结点点上的数据
		free(tmp);//释放结点
	}
	stack->top->next = NULL;
}
//销毁栈
//释放所有结点
void Destroy(Stack* stack)
{
	Clear(stack);//先清空栈，释放内存
	free(stack->top);//释放top指向的那个结点
}
//判断栈是否为空
//栈为空时返回1，非空时返回0
int isEmpty(Stack *stack)
{
    if(stack->top->next==NULL) return 1;
    else return 0;
}
//压栈
//float a = 10.3;
//Push(&linkStack, (u32)&a, DATA_FLOAT);
void Push(Stack *stack, u32 valAddr, int valType)
{
    float *tempFloat;
    int *tempInt;

    Node *nodeNew = (Node*)malloc(sizeof(Node));//生成新结点
    //给结点加数据
    switch(valType) {
        case DATA_FLOAT://浮点数压栈
            nodeNew->DataType = DATA_FLOAT;//数据类型标识
            tempFloat = (float *)malloc(sizeof(float));
            *tempFloat = *((float *)valAddr);
            nodeNew->valueAddr = (u32)tempFloat;
            break;
        case DATA_INT://整型压栈
            nodeNew->DataType = DATA_INT;//数据类型标识
            tempInt = (int *)malloc(sizeof(int));
            *tempInt = *((int *)valAddr);
            nodeNew->valueAddr = (u32)tempInt;
            break;
        default: break;
    }
	nodeNew->next = stack->top->next;//入栈节点 next指向原栈第一个节点
	stack->top->next = nodeNew;//栈顶top指向该入栈节点
}
//弹栈
//返回结点数据的地址，返回结点数据类型标识
void Pop(Stack* stack, u32 *valAddr, int *valType)
{
	Node* del = NULL;

	del = stack->top->next;//栈顶结点地址
	if (del != NULL)//栈非空
	{
		stack->top->next = del->next;//指向第二个节点（可能为NULL）
	}
	*valAddr = del->valueAddr;//返回结点数据的地址
	*valType = del->DataType;//返回结点数据类型标识
    //释放结点
    free(del);
}
//获取栈长度
int Length(Stack* stack)
{
	int i = 0;//i为计数器
	Node* pNode;

	pNode = stack->top->next;//指向栈的第一个结点
	while (pNode != NULL)
	{
		i++;
		pNode = pNode->next;
	}
	return i;
}
//显示栈节点数据
void NodeDisplay(Node* node)
{
    switch(node->DataType) {
        case DATA_FLOAT://如果是浮点数
            printf("%.1f   ", *((float *)(node->valueAddr)));
            break;
        case DATA_INT://如果是整型
            printf("%d   ", *((int *)(node->valueAddr)));
            break;
        default: break;
    }
}
//遍历栈
void StackTraverse(Stack* stack)
{
	Node* pNode;
	pNode = stack->top->next;//pNode指向第一个结点

	while (pNode != NULL)
	{
		NodeDisplay(pNode);
		pNode = pNode->next;
	}
}
