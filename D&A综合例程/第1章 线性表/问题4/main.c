
/*

2017��12��1�գ�С�������ܶ���

����4����дC����ʵ���� ��ͷ��� �� ˫��ѭ������ �еĲ����ɾ������

*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef char ElemType;

//����˫��������
typedef struct DNode
{
    ElemType data;//������
    struct DNode *prior;//ǰ��ָ����
    struct DNode *next;//���ָ����
}DLinkList;

DLinkList *L;//����ṹָ������



//��ʼ������ͷ����˫��ѭ������
//����ͷָ��
DLinkList *InitList(void)
{
    L=(DLinkList*)malloc(sizeof(DLinkList));//����ͷ���
    L->prior=L;//ѭ��˫������
    L->next=L;
    L->data=-1;

    return L;//����ͷָ��
}
//�ڴ���ͷ����˫��ѭ������L��Ѱ�ҵ�i����㣬
//�ҵ�������ָ�룬�Ҳ�������NULL
DLinkList* getelem(DLinkList *L,int i)
{
    DLinkList *p;
    int n;
    p=L->next;
    n=1;
    if(i<1)return NULL;//i̫С
    while(p!=L&&n<i)//���������ҵ����i
    {
        n++;
        p=p->next;
    }
    if(n==i)return p;//�ҵ����i������ָ�룬��������ͷָ��
    else return NULL;//i̫��
}
//�ڴ�ͷ����˫��ѭ������L�еĵ�i��Ԫ��֮ǰ����Ԫ��e
//i�ķ�Χ��1<=i<=��+1
void listinsert(DLinkList *L,int i,ElemType e)
{
    DLinkList *p,*s;

    p=getelem(L,i);//Ѱ�ҵ�i����㣬������ָ��
    if(p!=NULL)//�ҵ��˵�i�����
    {
        s=(DLinkList*)malloc(sizeof(DLinkList));//����һ���½��
        s->data=e;//����½�������
        p->prior->next=s;s->next=p;//�������µĽ��
        s->prior=p->prior;p->prior=s;
    }
    else//û����i�����
    {
        printf("����λ�ô���\n");
        return;
    }
}
//�ڴ�ͷ����˫��ѭ������L�У�ɾ����i�����
//i�ķ�Χ��1<=i<=��
//����ֵ����ɾ��������ֵ
ElemType listdelete(DLinkList *L,int i)
{
    DLinkList *p;
    ElemType e;

    p=getelem(L,i);//Ѱ�ҵ�i����㣬������ָ��
    if(p!=L&&p!=NULL)//i�Ϸ����ҵ���
    {
        e=p->data;//ɾ����i�����
        p->prior->next=p->next;
        p->next->prior=p->prior;
        free(p);
        return e;//���ر�ɾԪ�ص�ֵ
    }
    else{printf("ɾ�����λ�ô���\n");return '*';}
}
//�������ͷ����˫��ѭ������ĸ�Ԫ��ֵ
void print(DLinkList *L)
{
    DLinkList *p;
    p=L->next;//pָ��ʼ���
    while(p!=L)
    {
        printf("%3c",p->data);
        p=p->next;
    }
    printf("\n");
}
//������ͷ����˫��ѭ������L�Ŀռ�
void destroylist(DLinkList *L)
{
    DLinkList *p=L,*q=p->next;//pָ��ͷ��㣬qָ��ʼ���
    while(q!=NULL)//while(q!=L)��������
    {
        free(p);
        p=q;
        q=q->next;
    }
    free(q);
}

int main(void)
{
    ElemType e='a',De;
    int j,a;

    printf("(1)��ʼ��˫����L\n");
    L=InitList();

    printf("(2)���β���Ԫ��a,b,c,d,e\n");
    for(j=0;j<5;e++)listinsert(L,++j,e);

    printf("(3)���˫����L��");
    print(L);

    printf("(4)������ɾ��������ţ�");
    scanf("%d",&a);
    De=listdelete(L,a);

    printf("(5)ɾ�����%c�������",De);
    print(L);

    printf("(6)�ͷ�˫����\n");
   // destroylist(L);//���ꣿ��һ�ͷžͳ�����

    return 0;
}















