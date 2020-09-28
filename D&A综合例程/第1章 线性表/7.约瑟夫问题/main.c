
/*

2017��12��8�գ�С�������ܶ���

Լɪ�����⣺

��֪n���ˣ��Ա��1��2��3...n�ֱ��ʾ��Χ����һ��Բ����Χ��
�ӱ��Ϊk���˿�ʼ����������m���Ǹ��˳��У�
������һ�����ִ�1��ʼ����������m���Ǹ����ֳ��У�
���˹����ظ���ȥ��ֱ��Բ����Χ����ȫ������

�����˳��


*/


#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


typedef int ElemType;

typedef struct tagnode
{
    ElemType        data;//������
    struct tagnode *next;//ָ����
}node,*LinkList;


//����n�����ĵ���ѭ������
//nΪҪ���ɽ�����Ŀ��kΪ��ʼ����λ��
//����ֵ������λ��k�����ĵ�ַ
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
            s = (node*)malloc(sizeof(node));//�����½��
            s->data = i++;
            p->next = s;
            p = s;
        }
        s->next = head->next;
        free(head);//�ͷ�ͷ���

        offset=s->next;//offsetָ��ʼ���
        for(i=1;i<k;i++)//ƫ�Ƶ���k������λ��
            offset=offset->next;

        return offset;//���ر���λ��k�����ĵ�ַ
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

    printf("���������ݳ���n�����ݼ��m����ʼ����λ��k��\n");
    scanf("%d %d %d",&n,&m,&k);

    h=Create(n,k);//��������ͷ���ĵ���ѭ������hָ��ʼ���
    while(h!=h->next)
    {
        for(i=1;i<m-1;i++)
        {
            h=h->next;
        }
        temp=h->next;//tempָ��ɾ���Ľ��
        printf("%d->",h->next->data);//��ӡҪɾ����������
        h->next=temp->next;//ɾ�����
        h=temp->next;

        free(temp);//�ͷŽ��
    }
    printf("%d",h->data);//��ӡ���һ����������

    return 0;
}


