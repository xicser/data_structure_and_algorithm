
/*

2017��11��30�գ�С�������ܶ���

����2����дC����ʵ���ڴ�ͷ���ĵ������е�12����������

*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef char ElemType;

//�������
typedef struct LNode
{
    ElemType data;          //������
    struct LNode* next;     //ָ����
}LinkList;



/*1.��ʼ��һ���յĵ�����*/
LinkList* InitList(void)
{
    LinkList* L;
    L=(LinkList*)malloc(sizeof(LinkList));//����ͷ���
    L->next=NULL;
    return L;
}
/*2.�ͷŵ�����L*/
void DestroyList(LinkList* L)
{
    LinkList *p=L,*q=p->next;
    while(q!=NULL)
    {
        free(p);
        p=q;
        q=p->next;
    }
    free(p);//�Ƿ����һ�����
}
/*3.��L��Ϊ�ձ�*/
void SetNull(LinkList *L)
{
    L->next=NULL;//���᣿�����������ڴ�й©�𣡣�
}
/*4.��LΪ�ձ��򷵻�TRUE,���򷵻�FALSE*/
int ListEmpty(LinkList *L)
{
    return (L->next==NULL);
}
/*5.������L��Ԫ�صĸ���������֮*/
int ListLength(LinkList *L)
{
    LinkList *p=L;
    int i=0;
    while(p->next!=NULL)
    {
        i++;
        p=p->next;
    }
    return i;
}
/*6.����L�еĵ�i��Ԫ�ص�ֵ������ʧ���򷵻�'F'*/
ElemType GetElem(LinkList *L,int i)
{
    int j=0;
    LinkList *p=L;
    ElemType e;
    while(j<i&&p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)return 'F';
    else{e=p->data;return e;}
}
/*7.�ڵ�����L�в���ָ��Ԫ��e������������λ�򣨵�һ�γ��ֵ�λ��
��L��û��Ԫ��e���򷵻�0���������᣿������Ԫ�ؾ���0��զ�죡��
*/
int LocateElem(LinkList *L,ElemType e)
{
    LinkList *p=L->next;//pָ��ʼ���
    int n=1;

    while(p!=NULL&&p->data!=e)
    {
        p=p->next;
        n++;
    }
    if(p==NULL)return 0;
    else return n;
}
/*
8.��cur_e��L�е�����Ԫ���Ҳ��ǵ�һ�����򷵻�����ǰ��Ԫ��
�������ʧ�ܷ���'F'
����ǰ�᣺cur_e��L�е�Ԫ�أ�
*/
ElemType PriorElem(LinkList *L,ElemType cur_e)
{
    LinkList *p=L->next;//pָ��ʼ���
    ElemType pre_e;

    if(p->data==cur_e)return 'F';//��һ��Ԫ��û��ǰ��Ԫ��
    else
    {
        /*��p->next->data�Ƚϣ�ǰ��Ԫ����p->data*/
        while(p->next->data!=cur_e)p=p->next;
        pre_e=p->data;
        return pre_e;
    }
}
/*
9.��cur_e��L�е�����Ԫ���Ҳ������һ�����򷵻����ĺ��Ԫ�أ�
�������ʧ�ܷ���'F'
����ǰ�᣺cur_e��L�е�Ԫ�أ�
*/
ElemType NextElem(LinkList *L,ElemType cur_e)
{
    LinkList *p=L->next,*q;
    ElemType next_e;

    if(p==NULL)return 'F';//���
    else
    {
        while(p->data!=cur_e)p=p->next;
        q=p->next;
        if(q!=NULL)//���Ԫ�ش���
        {
            next_e=q->data;//��ȡ���Ԫ��
            return next_e;
        }
        else return 'F';
    }
}
/*
10.��L�е�i��λ��֮ǰ�����µ�Ԫ��e
����ɹ�����1�����򷵻�0
*/
int ListInsert(LinkList *L,int i,ElemType e)
{
    int j=0;
    LinkList *p=L,*s;

    while(j<i-1&&p!=NULL)//���ҵ�i-1�����
    {
        j++;
        p=p->next;
    }//��ѭ��ִ����ɺ������������pָ���i������ǰһ�����
    if(p==NULL||j>i-1)return 0;//δ�ҵ�i-1��㣬��i<1����ڱ�
    else//�ҵ�i-1���
    {
        s=(LinkList*)malloc(sizeof(LinkList));//����һ���½��
        s->data=e;
        s->next=p->next;
        p->next=s;//��s���뵽��i-1�����֮��

        return 1;
    }
}
/*
11.ɾ��L�е�i��Ԫ�أ���������ֵ
*/
ElemType ListDelete(LinkList *L,int i)
{
    int j=0;
    LinkList *p=L,*q;
    ElemType e;

    while(j<i-1&&p!=NULL)//���ҵ�i-1�����
    {
        j++;
        p=p->next;
    }//��ѭ��ִ����ɺ������������pָ���i������ǰһ�����
    if(p==NULL||j>i-1)return 'F';//ɾ��λ��i������
    else//�ҵ��˵�i-1�����
    {
        q=p->next;//qָ��Ҫɾ���Ľ��
        if(q==NULL)return 'F';//��ɾ�ڵ㲻����
        e=q->data;
        p->next=q->next;//ɾ��q���
        free(q);
        return e;//���ر�ɾ����ֵ
    }
}
/*12.���������������Ԫ�ص�ֵ��������*/
void ListTraverse(LinkList *L)
{
    LinkList *p=L->next;
    while(p!=NULL)
    {
        printf("%c",p->data);
        p=p->next;
    }
    printf("\n");
}

int main(void)
{
    ElemType e;
    LinkList *L=NULL;
    printf("(1)��ʼ��������L\n");
    L=InitList();
    printf("(2)���β���Ԫ��a,b,c,d,e\n");
    ListInsert(L,1,'a');
    ListInsert(L,2,'b');
    ListInsert(L,3,'c');
    ListInsert(L,4,'d');
    ListInsert(L,5,'e');
    printf("(3)���������");
    ListTraverse(L);
    printf("(4)������L�ĳ��ȣ�%d\n",ListLength(L));
    printf("(5)������LΪ��%s\n",ListEmpty(L)?"��":"�ǿ�");
    e=GetElem(L,3);
    printf("(6)������L��3��Ԫ�أ�%c\n",e);
    printf("(7)Ԫ��a��λ�ã�%d\n",LocateElem(L,'a'));
    e=PriorElem(L,'b');
    printf("(8)Ԫ��b��ǰ��Ϊ��%c\n",e);
    e=NextElem(L,'b');
    printf("(9)Ԫ��b�ĺ��Ϊ��%c\n",e);
    printf("(10)�ڵ��ĸ�λ�ò���fԪ�أ������֮��");
    ListInsert(L,4,'F');
    ListTraverse(L);
    printf("(11)ɾ����3��Ԫ�أ������֮��");
    e=ListDelete(L,3);
    ListTraverse(L);
    printf("(12)��L����Ϊ�ձ�\n");
    SetNull(L);
    printf("(13)������LΪ��%s\n",ListEmpty(L)?"��":"�ǿ�");
    printf("(14)�ͷŵ�����L\n");
    DestroyList(L);

    return 0;
}






