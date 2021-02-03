
/*

2017年12月8日，小王持续奋斗！

魔术师发牌问题：

一位魔术师掏出一叠扑克牌，魔术师取出其中13张黑桃，洗好后，把牌面朝下。
说：“我不看牌，只数一数就能知道每张牌是什么？”魔术师口中念一，
将第一张牌翻过来看正好是A；
魔术师将黑桃A放到桌上，继续数手里的余牌，
第二次数1，2，将第一张牌放到这叠牌的下面，
将第二张牌翻开，正好是黑桃2，也把它放在桌子上。
第三次数1，2，3，前面二张牌放到这叠牌的下面，
取出第三张牌，正好是黑桃3，这样依次将13张牌翻出，
全部都准确无误。
求解：魔术师手中牌的原始顺序是什么样子的？

*/

#include <stdio.h>
#include <stdlib.h>


//有13张牌
#define CARD_NUM 13


typedef int ElemType;

typedef struct node
{
    ElemType     data;//数据域
    struct node *next;//指针域
}sqlist,*linklist;


//生成不带头结点的单向循环链表
//返回值：开始结点地址
linklist CreateLinkList(void)
{
    linklist head = NULL;
    linklist s, r;
    int i;

    r = head;

    for(i=1;i<=CARD_NUM;i++)
    {
        s=(linklist)malloc(sizeof(sqlist));
        s->data = 0;

        if(head == NULL)head=s;
        else r->next=s;

        r=s;
    }
    r->next = head;

    return head;
}

void Magician(linklist head)
{
    int j;
    int cntnum = 2;
    linklist p;

    p = head;
    p->data = 1;//第一张牌放1

    while(1)
    {
        for(j=0;j<cntnum;j++)
        {
            p=p->next;
            if(p->data!=0)j--;//跳过有数据的结点，使循环多进行一次，相当于牌已经被拿走
        }
        if(p->data == 0)
        {
            p->data = cntnum;
            cntnum++;
            if(cntnum == 14)break;
        }
    }
}

int main(void)
{
    linklist L,temp;

    L=CreateLinkList();//创建链表

    Magician(L);//处理

    //输出
    temp=L;
    while(temp->next!=L)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);

    return 0;
}
