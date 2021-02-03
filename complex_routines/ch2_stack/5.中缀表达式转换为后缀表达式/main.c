
/*

2017年12月11日，小王持续努力！

中缀表达式转换为后缀表达式：

转换过程需要用到栈，具体过程如下：
1）如果遇到操作数，我们就直接将其输出。
2）如果遇到操作符，则我们将其放入到栈中，遇到左括号时我们也将其放入栈中。
3）如果遇到一个右括号，则将栈元素弹出，将弹出的操作符输出直到遇到左括号为止。注意，左括号只弹出并不输出。
4）如果遇到任何其他的操作符，如（“+”， “*”，“（”）等，从栈中弹出元素直到遇到发现更低优先级的元素(或者栈为空)为止。弹出完这些元素后，才将遇到的操作符压入到栈中。有一点需要注意，只有在遇到" ) "的情况下我们才弹出" ( "，其他情况我们都不会弹出" ( "。
5）如果我们读到了输入的末尾，则将栈中所有元素依次弹出。

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define STACK_INIT_SIZE 100//顺序栈数据元素存储空间的初始分配量
#define STACK_INCREASE  10 //顺序栈数据元素存储空间的分配增量

#define BUFFER_INIT_SIZE  20//输入缓冲区初始大小
#define BUFFER_INCREASE   10//输入缓冲区增量


//栈元素类型定义
typedef char ElemType;

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
void StackTraverse(Stack S);//遍历栈中的元素


int main(void)
{
    int i,buffersize=BUFFER_INIT_SIZE;
    char temp,e;
    char *Buffer;
    Stack s;//定义一个栈

    //开辟输入缓冲区
    Buffer=(char*)malloc(sizeof(char)*BUFFER_INIT_SIZE);

    printf("请输入中缀表达式，按回车结束：\n");
    i=0;
    while(1)//输入中缀表达式
    {
        temp=getchar();
        if(temp=='\n')
        {
            Buffer[i]=0;//字符串结尾标志
            break;
        }
        if(i>=buffersize)//输入缓冲区扩容
        {
            buffersize+=BUFFER_INCREASE;
            Buffer=(char*)realloc(Buffer,
            sizeof(char)*buffersize);
        }
        Buffer[i++]=temp;
    }
    //printf("%s\n",Buffer);//打印输入的字符串，调试用

    InitStack(&s);//初始化栈

    i=0;
    temp=Buffer[i];
    while(1)//遍历字符串
    {
        //过滤数字，包括多位数字，直接输出
        while('0'<=temp && temp<='9')
        {
            printf("%c", temp);
            temp=Buffer[++i];
            if(temp<'0' || temp>'9')printf(" ");
        }
        //遇到乘除，左括号，直接压栈
        if(temp=='*' || temp=='/' || temp=='(')
        {
            Push(&s,temp);
            temp=Buffer[++i];
        }
        //遇到右括号，弹栈直到遇到左括号
        else if(temp== ')' )
        {
            Pop(&s, &e);
            while('(' != e )//输出左右括号之间的内容
            {
                printf("%c ", e);
                Pop(&s, &e);
            }
            temp=Buffer[++i];
        }
        //遇到加减
        else if('+'==temp || '-'==temp )
        {
            if(StackEmpty(s))Push(&s, temp);//栈空则必然直接压栈
            else//栈非空，则要考虑算符优先级
            {
                do
                {//在压入'+','-'前，先将'('上方的所有运算符弹出，
                 //如果栈中没有'('，则将栈中所有运算符弹出
                    Pop(&s, &e);
                    if('(' == e)Push(&s, e);
                    else printf("%c ", e);
                }
                while(StackLength(s) && '('!=e );
                Push(&s, temp);
            }
            temp=Buffer[++i];
        }
        else if( temp==0 )break;//字符串已经到末尾
        else
        {
            printf("\n输入格式错误！\n");
            return -1;
        }
    }

    //弹出栈中剩余元素
    while(StackLength(s))
    {
        Pop(&s, &e);
        printf("%c ", e);
    }

    //释放输入缓冲区
    free(Buffer);

    return 0;
}//1+(2-3)*4+10/5


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
void StackTraverse(Stack S)
{
	while (S.top > S.base)printf("%c ", *S.base++);
}

