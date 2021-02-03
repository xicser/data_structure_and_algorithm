
/*

2017年12月8日，小王持续奋斗！

约瑟夫问题：

已知n个人（以编号1，2，3...n分别表示）围坐在一张圆桌周围。
从编号为k的人开始报数，数到m的那个人出列；
他的下一个人又从1开始报数，数到m的那个人又出列；
依此规律重复下去，直到圆桌周围的人全部出列

求出列顺序


*/


#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


typedef int ElemType;

typedef struct tagnode
{
    ElemType        data;//数据域
    struct tagnode *next;//指针域
}node,*LinkList;


//创建n个结点的单向循环链表
//n为要生成结点的数目，k为起始报数位置
//返回值：报数位置k处结点的地址
node* Create(int n,int k)
{
    int i=1;
    node *p = NULL,*head = NULL,*s = NULL,*offset=NULL;

    head = (node*)malloc(sizeof(node));
    p=head;

    if(n!=0)
    {
        while(i <= n)
        {
            s = (node*)malloc(sizeof(node));//生成新结点
            s->data = i++;
            p->next = s;
            p = s;
        }
        s->next = head->next;
        free(head);//释放头结点

        offset=s->next;//offset指向开始结点
        for(i=1;i<k;i++)//偏移到第k个结点的位置
            offset=offset->next;

        return offset;//返回报数位置k处结点的地址
    }
    else
    {
        free(head);
        return NULL;
    }
}

int main(void)
{
    int i,m,n,k;
    node *h,*temp;

    printf("请输入数据长度n，数据间隔m，起始报数位置k：\n");
    scanf("%d %d %d",&n,&m,&k);

    h=Create(n,k);//创建不带头结点的单向循环链表，h指向开始结点
    while(h!=h->next)
    {
        for(i=1;i<m-1;i++)
        {
            h=h->next;
        }
        temp=h->next;//temp指向删除的结点
        printf("%d->",h->next->data);//打印要删除结点的数据
        h->next=temp->next;//删除结点
        h=temp->next;

        free(temp);//释放结点
    }
    printf("%d",h->data);//打印最后一个结点的数据

    return 0;
}


