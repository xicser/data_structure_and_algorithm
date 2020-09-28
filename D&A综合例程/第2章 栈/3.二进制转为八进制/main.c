
/*

2017��12��9�գ�С������Ŭ����

������ת��Ϊ�˽���

*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

//����Ԫ�����Ͷ���
typedef char ElemType;

//ջ���ṹ����
typedef struct Node
{
	ElemType		 value;	//������
	struct Node		*next;	//ָ����
}Node;

//ջ�ṹ����
typedef struct
{
	Node *top;     //ջ��ָ��
//	Node *base;    //ջ��ָ�루��ʽջ�� base���ò���
}Stack;

//ջ�Ĳ�����
void  InitStack(Stack* stack);//��ʼ��ջ
void  Clear(Stack* stack);//���ջ
void  Destroy(Stack* stack);//����ջ
int   Push(Stack* stack, ElemType e);//ѹջ
int   Pop(Stack* stack, ElemType *e);//��ջ
int   Length(Stack* stack);//��ȡջ����
void  StackDisplay(Stack* stack);//��ʾջ��������

//���������ʮ��������ȡ16�������ķ���
char GetHexCode(int dec);

int main(void)
{
    int i,j,len,sum;
    Stack SBin,SOtc;
    ElemType c;

    InitStack(&SBin);//��ʼ��ջ
    InitStack(&SOtc);

    printf("������������������»س���ʾ������\n");

    while(1)//һֱѭ��
    {
        while(1)
        {//����ֱ���س�
            scanf("%c",&c);
            if(c!='\n')
            {
                //Ԫ��ѹջ
                Push(&SBin,c);
            }
            else break;
        }

        len = Length(&SBin);
        for(i=0; i<len/3; i++)//�Ƚ�ǰn-1����λ����������
        {
            sum=0;
            for(j=0;j<3;j++)
            {
                Pop(&SBin,&c);//��ջ
                sum+=(c-48)*pow(2,j);
            }
            c = GetHexCode(sum);
            //ѹ��8����ջ
            Push(&SOtc,c);
        }

        len = Length(&SBin);
        if(len!=0)
        {//�ټ������һ�鲻��3λ�����Ƶ�
            sum=0;
            for(i=0; i<len; i++)
            {
                Pop(&SBin,&c);//��ջ
                sum+=(c-48)*pow(2,i);
            }
            c = GetHexCode(sum);
            //ѹ��8����ջ
            Push(&SOtc,c);
        }

        //����8����ջ
        printf("0");

        //��ʾ8����ջ
        StackDisplay(&SOtc);

        //���ջ���Ա���һ������
        Clear(&SBin);
        Clear(&SOtc);
        printf("\n");
    }

    return 0;
}

//���������ʮ��������ȡ16�������ķ���
char GetHexCode(int dec)
{
    return dec + 0x30;
}
//��ʼ��ջ
void InitStack(Stack* stack)
{
	stack->top /*= stack->base*/ = (Node*)malloc(sizeof(Node));
	stack->top->next = NULL;
}
//���ջ
//�ͷų���topָ����Ǹ����
//��ԭջλ����InitStack���״̬
void Clear(Stack* stack)
{
	Node* pNode, *tmp;

	pNode = stack->top->next;

	//����ջ���ͷ�ÿһ��ڵ��ڴ棨����topָ����Ǹ���㣩
	while (pNode != NULL)
	{
		tmp = pNode;//��¼��Ҫ�ͷŵ��ڴ��ַ
		pNode = pNode->next;//��һ���ڵ�ĵ�ַ
		free(tmp);
	}
	stack->top->next=NULL;
}
//����ջ
//�ͷ����н��
void Destroy(Stack* stack)
{
	Clear(stack);//�����ջ���ͷ��ڴ�
	free(stack->top);//�ͷ�topָ����Ǹ����
}
//ѹe��ջ
int Push(Stack* stack, ElemType e)
{
    Node *s=NULL;

	s=(Node*)malloc(sizeof(Node));//����һ���½��
	if(s==NULL)return 1;//�ڴ�����ʧ��

    s->value=e;
	s->next = stack->top->next;//��ջ�ڵ� nextָ��ԭջ��һ���ڵ�
	stack->top->next = s;//ջ��topָ�����ջ�ڵ�

	return 0;
}
//��ջ
//���ر�ɾ����ַ����ջ��ʱ������NULL
int Pop(Stack* stack, ElemType *e)
{
	Node* del = NULL;

	del = stack->top->next;
	if (del != NULL)//�ǿ�
	{
	    *e=del->value;
		stack->top->next = del->next;//ָ��ڶ����ڵ㣨����ΪNULL��

		free(del);
		return 0;//�ɹ�
	}
	return 1;//ջ��
}
//��ȡջ����
int Length(Stack* stack)
{
	int i = 0;//iΪ������
	Node* pNode;

	pNode = stack->top->next;//ָ��ջ�ĵ�һ�����
	while (pNode != NULL)
	{
		i++;
		pNode = pNode->next;
	}
	return i;
}
//��ʾջ��������
void StackDisplay(Stack* stack)
{
	Node* pNode;
	pNode = stack->top->next;//pNodeָ���һ�����

	while (pNode != NULL)
	{
		printf("%c", pNode->value);
		pNode = pNode->next;
	}
}
