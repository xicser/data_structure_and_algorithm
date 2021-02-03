
/*

2017年12月8日，小王持续奋斗！

拉丁方阵：

拉丁方阵（英语：Latin square）是一种 n × n 的方阵，
在这种 n × n 的方阵里，恰有 n 种不同的元素，
每一种不同的元素在同一行或同一列里只出现一次。



补充知识：如何用malloc申请一个二维数组？

    int i, row, column, **arr;

    arr = (int **)malloc(sizeof(int *) * row);//分配所有行的首地址
    for(i = 0; i < row; i ++)//按行分配每一列
        arr[i] = (int *)malloc(sizeof(int) * column);

    //释放开辟的二维数组空间
    for (int i = 0; i < row; ++i)
    free(*(arr + i));
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


typedef int ElemType;

typedef struct node
{
    ElemType     data;//数据域
    struct node *next;//指针域
}sqlist,*linklist;


//生成含有n个结点的，不带头结点的单向循环链表
//返回值：开始结点地址
linklist CreateLinkList(int n)
{
    linklist head = NULL;
    linklist s, r;
    int i;

    r = head;

    for(i=1;i<=n;i++)
    {
        s=(linklist)malloc(sizeof(sqlist));
        s->data = i;

        if(head == NULL)head=s;
        else r->next=s;

        r=s;
    }
    r->next = head;

    return head;
}

int main(void)
{
    int i,j,n,cnt;
    int **pArray;
    linklist L,tmp1,tmp2;

    printf("请输入n值：");
    scanf("%d",&n);

    //申请n*n数组空间
    pArray=(int **)malloc(sizeof(int *) * n);//分配所有行的首地址
    for(i = 0; i < n; i ++)//按行分配每一列
        pArray[i] = (int *)malloc(sizeof(int) * n);

    //创建循环链表
    L=CreateLinkList(n);

    //遍历数组元素
    tmp1=tmp2=L;
    for(i=0;i<n;i++)
    {
        cnt=0;
        while(tmp1->next!=tmp2)
        {
            pArray[i][cnt]=tmp1->data;
            tmp1=tmp1->next;
            cnt++;
        }
        pArray[i][cnt]=tmp1->data;

        tmp2=tmp2->next;
        tmp1=tmp2;
    }

    //输出
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",pArray[i][j]);
        printf("\n");
    }

    return 0;
}
