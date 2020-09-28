
/*

2017年12月9日，小王持续努力！

二进制转换为八进制

*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

//数据元素类型定义
typedef char ElemType;

//栈结点结构定义
typedef struct Node
{
	ElemType		 value;	//数据域
	struct Node		*next;	//指针域
}Node;

//栈结构定义
typedef struct
{
	Node *top;     //栈顶指针
//	Node *base;    //栈底指针（链式栈中 base作用不大）
}Stack;

//栈的操作集
void  InitStack(Stack* stack);//初始化栈
void  Clear(Stack* stack);//清空栈
void  Destroy(Stack* stack);//销毁栈
int   Push(Stack* stack, ElemType e);//压栈
int   Pop(Stack* stack, ElemType *e);//弹栈
int   Length(Stack* stack);//获取栈长度
void  StackDisplay(Stack* stack);//显示栈（遍历）

//根据输入的十进制数获取16进制数的符号
char GetHexCode(int dec);

int main(void)
{
    int i,j,len,sum;
    Stack SBin,SOtc;
    ElemType c;

    InitStack(&SBin);//初始化栈
    InitStack(&SOtc);

    printf("请输入二进制数，按下回车表示结束！\n");

    while(1)//一直循环
    {
        while(1)
        {//输入直到回车
            scanf("%c",&c);
            if(c!='\n')
            {
                //元素压栈
                Push(&SBin,c);
            }
            else break;
        }

        len = Length(&SBin);
        for(i=0; i<len/3; i++)//先将前n-1个三位二进制算完
        {
            sum=0;
            for(j=0;j<3;j++)
            {
                Pop(&SBin,&c);//弹栈
                sum+=(c-48)*pow(2,j);
            }
            c = GetHexCode(sum);
            //压入8进制栈
            Push(&SOtc,c);
        }

        len = Length(&SBin);
        if(len!=0)
        {//再计算最后一组不足3位二进制的
            sum=0;
            for(i=0; i<len; i++)
            {
                Pop(&SBin,&c);//弹栈
                sum+=(c-48)*pow(2,i);
            }
            c = GetHexCode(sum);
            //压入8进制栈
            Push(&SOtc,c);
        }

        //弹出8进制栈
        printf("0");

        //显示8进制栈
        StackDisplay(&SOtc);

        //清空栈，以便下一次输入
        Clear(&SBin);
        Clear(&SOtc);
        printf("\n");
    }

    return 0;
}

//根据输入的十进制数获取16进制数的符号
char GetHexCode(int dec)
{
    return dec + 0x30;
}
//初始化栈
void InitStack(Stack* stack)
{
	stack->top /*= stack->base*/ = (Node*)malloc(sizeof(Node));
	stack->top->next = NULL;
}
//清空栈
//释放除了top指向的那个结点
//还原栈位调用InitStack后的状态
void Clear(Stack* stack)
{
	Node* pNode, *tmp;

	pNode = stack->top->next;

	//遍历栈，释放每一块节点内存（除了top指向的那个结点）
	while (pNode != NULL)
	{
		tmp = pNode;//记录下要释放的内存地址
		pNode = pNode->next;//下一个节点的地址
		free(tmp);
	}
	stack->top->next=NULL;
}
//销毁栈
//释放所有结点
void Destroy(Stack* stack)
{
	Clear(stack);//先清空栈，释放内存
	free(stack->top);//释放top指向的那个结点
}
//压e进栈
int Push(Stack* stack, ElemType e)
{
    Node *s=NULL;

	s=(Node*)malloc(sizeof(Node));//生成一个新结点
	if(s==NULL)return 1;//内存申请失败

    s->value=e;
	s->next = stack->top->next;//入栈节点 next指向原栈第一个节点
	stack->top->next = s;//栈顶top指向该入栈节点

	return 0;
}
//弹栈
//返回被删结点地址，当栈空时，返回NULL
int Pop(Stack* stack, ElemType *e)
{
	Node* del = NULL;

	del = stack->top->next;
	if (del != NULL)//非空
	{
	    *e=del->value;
		stack->top->next = del->next;//指向第二个节点（可能为NULL）

		free(del);
		return 0;//成功
	}
	return 1;//栈空
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
//显示栈（遍历）
void StackDisplay(Stack* stack)
{
	Node* pNode;
	pNode = stack->top->next;//pNode指向第一个结点

	while (pNode != NULL)
	{
		printf("%c", pNode->value);
		pNode = pNode->next;
	}
}
