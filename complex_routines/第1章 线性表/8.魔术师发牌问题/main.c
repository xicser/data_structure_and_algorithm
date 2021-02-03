
/*

2017��12��8�գ�С�������ܶ���

ħ��ʦ�������⣺

һλħ��ʦ�ͳ�һ���˿��ƣ�ħ��ʦȡ������13�ź��ң�ϴ�ú󣬰����泯�¡�
˵�����Ҳ����ƣ�ֻ��һ������֪��ÿ������ʲô����ħ��ʦ������һ��
����һ���Ʒ�������������A��
ħ��ʦ������A�ŵ����ϣ���������������ƣ�
�ڶ�����1��2������һ���Ʒŵ�����Ƶ����棬
���ڶ����Ʒ����������Ǻ���2��Ҳ�������������ϡ�
��������1��2��3��ǰ������Ʒŵ�����Ƶ����棬
ȡ���������ƣ������Ǻ���3���������ν�13���Ʒ�����
ȫ����׼ȷ����
��⣺ħ��ʦ�����Ƶ�ԭʼ˳����ʲô���ӵģ�

*/

#include <stdio.h>
#include <stdlib.h>


//��13����
#define CARD_NUM 13


typedef int ElemType;

typedef struct node
{
    ElemType     data;//������
    struct node *next;//ָ����
}sqlist,*linklist;


//���ɲ���ͷ���ĵ���ѭ������
//����ֵ����ʼ����ַ
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
    p->data = 1;//��һ���Ʒ�1

    while(1)
    {
        for(j=0;j<cntnum;j++)
        {
            p=p->next;
            if(p->data!=0)j--;//���������ݵĽ�㣬ʹѭ�������һ�Σ��൱�����Ѿ�������
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

    L=CreateLinkList();//��������

    Magician(L);//����

    //���
    temp=L;
    while(temp->next!=L)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);

    return 0;
}
