
/*
2017��11��30�գ�С�������ܶ���

����1����дC����ʵ��˳���Ĳ��롢ɾ���������Ԫ���ڱ��е�λ�������

ע����˳����������洢�ṹ
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define LIST_SIZE 100//��ʼ���ܴﵽ����󳤶�
#define LIST_INCREASE  10

typedef char ElemType;//��������
typedef struct
{
    ElemType *elem; //���е�һ��Ԫ�ص�ַ
    int length;     //��ǰ��
    int listsize;   //���ܴﵽ����󳤶�
}SqList;//����˳�������

SqList L;//����һ��˳������ݽṹ

//��ʼ��˳���L
//����ֵ��L�ĵ�ַ��ʧ��ʱ����0
SqList* InitList(void)
{
    L.elem=(ElemType*)malloc(LIST_SIZE*sizeof(ElemType));
    if(L.elem==NULL)//�ڴ�����ʧ��
    {
        printf("�������չ�ռ�ʧ�ܣ�");
        return 0;
    }
    L.length=0;
    L.listsize=LIST_SIZE;

    return &L;
}
//����˳���L
void DestroyList(SqList* L)
{
    free(L->elem);//�ͷ��ڴ�
}
//��˳���L�е�i��λ�ò���Ԫ��e
//����ֵ��1�ɹ���0ʧ��
int ListInsert(SqList* L,int i,ElemType e)
{
    int j;
    ElemType* newbase;

    if(i<1||i>L->length+1)//����λ�úϷ��Լ��
    {
        printf("λ�ò��Ϸ�");
        return 0;
    }
    if(L->length==L->listsize)//��ǰ���Ѵﵽ��󳤶ȣ����������ռ�
    {
        newbase=(ElemType*)realloc(L->elem,
                (L->listsize+LIST_INCREASE)
                *sizeof(ElemType));
        //�ڴ�����ʧ��
        if(newbase==NULL){printf("�������չ�ռ�ʧ�ܣ�");return 0;}
        L->elem=newbase;
        L->listsize+=LIST_INCREASE;
    }
    i--;//��λ�����ת��Ϊ�����±�
    for(j=L->length-1;j>i;j--)
        L->elem[j+1]=L->elem[j];//����Ԫ��
    L->elem[i]=e;//����Ԫ��

    L->length++;//��+1

    return 1;
}
//ɾ��˳����е�i��Ԫ��
//����ֵ��1�ɹ���0ʧ��
int ListDelete(SqList* L,int i)
{
    int j;

    //�ж��Ƿ�Ϊ�ձ�
    if(L->length==0){printf("������ǿձ��޷�ɾ��");return 0;}
    //�ж�ɾ��λ���Ƿ�Ϸ�
    else if(i<1||i>L->length){printf("����λ�ò��Ϸ�");return 0;}

    i--;//��λ��ת��Ϊ�����±�
    for(j=i;j<L->length-1;j++)//ǰ��Ԫ��
        L->elem[j]=L->elem[j+1];

    L->length--;//��-1

    return 1;
}
//���˳���������
void ListTraverse(SqList* L)
{
    int i;
    if(L->length==0)printf("�ձ�\n");
    else
    {
        for(i=0;i<L->length;i++)//�������
            printf("%c",L->elem[i]);
        printf("\n");
    }
}
//�����Ա�L��ȷ����һ�������e����=/>/<��Ԫ��λ��
//f=0���ڣ�f=1С�ڣ�f=2����
void LocateElem(SqList* L,ElemType e,int f)
{
    int i;
    switch(f)
    {
        case 0://����
            for(i=0;i<L->length;i++)
                if(L->elem[i]==e){++i;break;}
            break;

        case 1://С��
            for(i=0;i<L->length;i++)
                if(L->elem[i]<e){++i;break;}
            break;

        case 2://����
            for(i=0;i<L->length;i++)
                if(L->elem[i]>e){++i;break;}
            break;

        default:printf("��������\n");
    }
    if(i<=L->length)printf("���Ƚ�Ԫ�صĹ�ϵλ�ڵ�%d\n",i);
    else printf("���ܱȽ�\n");
}
//���ݲ���a��ֵѡ���Ӻ���ִ��
void chose(int a)
{
    int m,n,i;
    ElemType e;

    switch(a)
    {
        case 1: InitList();
                ListTraverse(&L);
                break;

        case 2: printf("���������Ԫ�ظ�����");
                scanf("%d",&n);
                for(i=0;i<n;i++)
                {
                    printf("����������Ԫ�أ�");
                    scanf(" %c",&e);
                    printf("����������Ԫ�ص�λ�ã�");
                    scanf("%d",&m);
                    ListInsert(&L,m,e);
                }
                ListTraverse(&L);
                break;

        case 3: printf("������ɾ��Ԫ�ظ�����");
                scanf("%d",&n);
                for(i=0;i<n;i++)
                {
                    printf("������Ҫɾ����Ԫ�ص�λ��");
                    scanf("%d",&m);
                    ListDelete(&L,m);
                }
                ListTraverse(&L);
                break;

        case 4: printf("��������Ҫ�Ƚϵ�Ԫ�أ�");
                scanf(" %c",&e);
                printf("��������Ҫ�Ƚ�Ԫ�صĹ�ϵ��0Ϊ��������Ԫ�أ�1ΪС������Ԫ�أ�2Ϊ��������Ԫ�أ���");
                scanf("%d",&m);
                LocateElem(&L,e,m);
                ListTraverse(&L);
                break;

        case 5: DestroyList(&L);
                ListTraverse(&L);
                break;

        default:printf("��������\n");
    }
}
int main(void)
{
    int a;

    printf("1.�����±�\n");
    printf("2.����Ԫ��\n");
    printf("3.ɾ��Ԫ��\n");
    printf("4.�ҳ�����������Ԫ��e�������/С��/���ڹ�ϵ�ĵ�һ��Ԫ�ص�λ��\n");
    printf("5.�ͷ�˳���\n");
    printf("0.��������\n\n");

    for(;;)
    {
        printf("��������Ҫ������Ӧ�����֣�");
        scanf("%d",&a);
        if(a==0)break;
        chose(a);
    }

    return 0;
}




















