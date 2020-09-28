
/*

2017年12月9日，小王持续努力！

计算逆波兰式：

-实现对逆波兰输入的表达式进行计算
-支持带小数点的数据

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define STACK_INIT_SIZE 100//顺序栈数据元素存储空间的初始分配量
#define STACK_INCREASE  10 //顺序栈数据元素存储空间的分配增量
#define MAX_BUFFER      10

//栈元素类型定义
typedef double ElemType;

//顺序栈类型定义
typedef struct
{
	ElemType *top;		//栈顶指针
	ElemType *base;		//数据元素存储空间基地址
	int size;			//当前存储空间容量（以sizeof(ElemType)为单位，栈所能达到的最大长度）
}Stack;//Stack为结构体类型


//栈的操作集
int  InitStack(Stack *S);//构造一个空栈S
void DestroyStack(Stack *S);//销毁栈S（释放占用的内存）
void ClearStack(Stack *S);//将S置为空栈
int  StackEmpty(Stack S);//检测S是否为空栈
int  StackLength(Stack S);//返回栈S中的数据元素个数，即栈的长度
int  GetTop(Stack S, ElemType *e);//用e返回S的栈顶元素
int  Push(Stack *S, ElemType e);//压栈
int  Pop(Stack *S, ElemType *e);//弹栈
void StackTraverse(Stack S, void(*visit)(ElemType *));//遍历栈中的元素


int main(void)
{
    Stack s;//定义一个栈
    int i=0;
    char c;
    double d,e;
    char str[MAX_BUFFER];

    InitStack(&s);//初始化栈

    printf("请输入逆波兰式，按回车结束：\n");

    scanf("%c", &c);//输入第一个字符
    while(c!='\n')
    {
        //用这个循环接收数据
        while( isdigit(c) || c=='.' )
        {
            str[i++] = c;
            str[i] = '\0';
            if(i>=10)
            {
                printf("出错：输入的单个数据过长！\n");
                return -1;
            }
            scanf("%c", &c);
            if(c==' ')
            {
                d = atof(str);
                Push(&s, d);//把数据压栈
                i=0;
                break;
            }
        }
        //处理运算符
        switch(c)
        {
            case '+':
                Pop(&s, &e);
                Pop(&s, &d);
                Push(&s, e+d);
                break;
            case '-':
                Pop(&s, &e);
                Pop(&s, &d);
                Push(&s, d-e);
                break;
            case '*':
                Pop(&s, &e);
                Pop(&s, &d);
                Push(&s, d*e);
                break;
            case '/':
                Pop(&s, &e);
                Pop(&s, &d);
                if(e!=0)Push(&s, d/e);
                else
                {
                    printf("出错：除数为0！\n");
                    return -1;//失败
                }
                break;
            default:break;
        }

        scanf("%c", &c);
    }

    Pop(&s, &d);
    printf("结果=%f\n", d);

    return 0;
}

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
