
/*

2017��12��9�գ�С������Ŭ����

������ת��Ϊʮ����

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
void  NodeDisplay(Node* node);//��ʾջ�ڵ�����
void  StackDisplay(Stack* stack);//��ʾջ��������


int main(void)
{
    int i,len,sum;
    Stack s;
    ElemType c;

    InitStack(&s);//��ʼ��ջ

    printf("������������������»س���ʾ������\n");

    while(1)//һֱѭ��
    {
        while(1)
        {//����ֱ���س�
            scanf("%c",&c);
            if(c!='\n')
            {
                //Ԫ��ѹջ
                Push(&s,c);
            }
            else break;
        }

        sum=0;
        len = Length(&s);
        for(i=0; i<len; i++)
        {//����
            //��ջ
            Pop(&s,&c);
            sum+=(c-48)*pow(2,i);
        }
        printf("%d\n",sum);

        //���ջ
        Clear(&s);
    }

    return 0;
}

//��ʼ��ջ
void InitStack(Stack* stack)
{
	stack->top /*= stack->base*/ = (Node*)malloc(sizeof(Node));
	stack->top->next = NULL;
}
//���ջ
//�ͷų���topָ����Ǹ����
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
//��ʾջ�ڵ�����
void NodeDisplay(Node* node)
{
	printf("%c ", node->value);
}
//��ʾջ��������
void StackDisplay(Stack* stack)
{
	Node* pNode;
	pNode = stack->top->next;//pNodeָ���һ�����

	while (pNode != NULL)
	{
		NodeDisplay(pNode);
		pNode = pNode->next;
	}
}


