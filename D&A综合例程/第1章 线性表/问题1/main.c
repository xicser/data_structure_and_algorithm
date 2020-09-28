
/*
2017年11月30日，小王持续奋斗！

问题1：编写C程序，实现顺序表的插入、删除和求给定元素在表中的位序等运算

注：是顺序表，即连续存储结构
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define LIST_SIZE 100//初始表能达到的最大长度
#define LIST_INCREASE  10

typedef char ElemType;//数据类型
typedef struct
{
    ElemType *elem; //表中第一个元素地址
    int length;     //当前表长
    int listsize;   //表能达到的最大长度
}SqList;//定义顺序表类型

SqList L;//定义一个顺序表数据结构

//初始化顺序表L
//返回值：L的地址，失败时返回0
SqList* InitList(void)
{
    L.elem=(ElemType*)malloc(LIST_SIZE*sizeof(ElemType));
    if(L.elem==NULL)//内存申请失败
    {
        printf("溢出，扩展空间失败！");
        return 0;
    }
    L.length=0;
    L.listsize=LIST_SIZE;

    return &L;
}
//撤销顺序表L
void DestroyList(SqList* L)
{
    free(L->elem);//释放内存
}
//在顺序表L中第i个位置插入元素e
//返回值：1成功，0失败
int ListInsert(SqList* L,int i,ElemType e)
{
    int j;
    ElemType* newbase;

    if(i<1||i>L->length+1)//插入位置合法性检查
    {
        printf("位置不合法");
        return 0;
    }
    if(L->length==L->listsize)//当前表长已达到最大长度，则申请额外空间
    {
        newbase=(ElemType*)realloc(L->elem,
                (L->listsize+LIST_INCREASE)
                *sizeof(ElemType));
        //内存申请失败
        if(newbase==NULL){printf("溢出，扩展空间失败！");return 0;}
        L->elem=newbase;
        L->listsize+=LIST_INCREASE;
    }
    i--;//将位序参数转化为数组下标
    for(j=L->length-1;j>i;j--)
        L->elem[j+1]=L->elem[j];//后移元素
    L->elem[i]=e;//插入元素

    L->length++;//表长+1

    return 1;
}
//删除顺序表中第i个元素
//返回值：1成功，0失败
int ListDelete(SqList* L,int i)
{
    int j;

    //判断是否为空表
    if(L->length==0){printf("这个表是空表，无法删除");return 0;}
    //判断删除位置是否合法
    else if(i<1||i>L->length){printf("输入位置不合法");return 0;}

    i--;//将位序转化为数组下标
    for(j=i;j<L->length-1;j++)//前移元素
        L->elem[j]=L->elem[j+1];

    L->length--;//表长-1

    return 1;
}
//输出顺序表（遍历）
void ListTraverse(SqList* L)
{
    int i;
    if(L->length==0)printf("空表！\n");
    else
    {
        for(i=0;i<L->length;i++)//遍历输出
            printf("%c",L->elem[i]);
        printf("\n");
    }
}
//在线性表L中确定第一个与参数e满足=/>/<的元素位序
//f=0等于，f=1小于，f=2大于
void LocateElem(SqList* L,ElemType e,int f)
{
    int i;
    switch(f)
    {
        case 0://等于
            for(i=0;i<L->length;i++)
                if(L->elem[i]==e){++i;break;}
            break;

        case 1://小于
            for(i=0;i<L->length;i++)
                if(L->elem[i]<e){++i;break;}
            break;

        case 2://大于
            for(i=0;i<L->length;i++)
                if(L->elem[i]>e){++i;break;}
            break;

        default:printf("参数错误\n");
    }
    if(i<=L->length)printf("所比较元素的关系位于第%d\n",i);
    else printf("不能比较\n");
}
//根据参数a的值选择子函数执行
void chose(int a)
{
    int m,n,i;
    ElemType e;

    switch(a)
    {
        case 1: InitList();
                ListTraverse(&L);
                break;

        case 2: printf("请输入插入元素个数：");
                scanf("%d",&n);
                for(i=0;i<n;i++)
                {
                    printf("请输入插入的元素：");
                    scanf(" %c",&e);
                    printf("请输入插入的元素的位置：");
                    scanf("%d",&m);
                    ListInsert(&L,m,e);
                }
                ListTraverse(&L);
                break;

        case 3: printf("请输入删除元素个数：");
                scanf("%d",&n);
                for(i=0;i<n;i++)
                {
                    printf("请输入要删除的元素的位序：");
                    scanf("%d",&m);
                    ListDelete(&L,m);
                }
                ListTraverse(&L);
                break;

        case 4: printf("请输入需要比较的元素：");
                scanf(" %c",&e);
                printf("请输入需要比较元素的关系（0为等于输入元素，1为小于输入元素，2为大于输入元素）：");
                scanf("%d",&m);
                LocateElem(&L,e,m);
                ListTraverse(&L);
                break;

        case 5: DestroyList(&L);
                ListTraverse(&L);
                break;

        default:printf("参数错误\n");
    }
}
int main(void)
{
    int a;

    printf("1.建立新表\n");
    printf("2.插入元素\n");
    printf("3.删除元素\n");
    printf("4.找出表中与输入元素e满足大于/小于/等于关系的第一个元素的位序\n");
    printf("5.释放顺序表\n");
    printf("0.结束程序\n\n");

    for(;;)
    {
        printf("请输入需要操作对应的数字：");
        scanf("%d",&a);
        if(a==0)break;
        chose(a);
    }

    return 0;
}




















