
/*

2017��12��8�գ�С�������ܶ���

��������

��������Ӣ�Latin square����һ�� n �� n �ķ���
������ n �� n �ķ����ǡ�� n �ֲ�ͬ��Ԫ�أ�
ÿһ�ֲ�ͬ��Ԫ����ͬһ�л�ͬһ����ֻ����һ�Ρ�



����֪ʶ�������malloc����һ����ά���飿

    int i, row, column, **arr;

    arr = (int **)malloc(sizeof(int *) * row);//���������е��׵�ַ
    for(i = 0; i < row; i ++)//���з���ÿһ��
        arr[i] = (int *)malloc(sizeof(int) * column);

    //�ͷſ��ٵĶ�ά����ռ�
    for (int i = 0; i < row; ++i)
    free(*(arr + i));
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


typedef int ElemType;

typedef struct node
{
    ElemType     data;//������
    struct node *next;//ָ����
}sqlist,*linklist;


//���ɺ���n�����ģ�����ͷ���ĵ���ѭ������
//����ֵ����ʼ����ַ
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

    printf("������nֵ��");
    scanf("%d",&n);

    //����n*n����ռ�
    pArray=(int **)malloc(sizeof(int *) * n);//���������е��׵�ַ
    for(i = 0; i < n; i ++)//���з���ÿһ��
        pArray[i] = (int *)malloc(sizeof(int) * n);

    //����ѭ������
    L=CreateLinkList(n);

    //��������Ԫ��
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

    //���
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",pArray[i][j]);
        printf("\n");
    }

    return 0;
}
