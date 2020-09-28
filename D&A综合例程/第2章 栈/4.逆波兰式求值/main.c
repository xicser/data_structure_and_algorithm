
/*

2017��12��9�գ�С������Ŭ����

�����沨��ʽ��

-ʵ�ֶ��沨������ı��ʽ���м���
-֧�ִ�С���������

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define STACK_INIT_SIZE 100//˳��ջ����Ԫ�ش洢�ռ�ĳ�ʼ������
#define STACK_INCREASE  10 //˳��ջ����Ԫ�ش洢�ռ�ķ�������
#define MAX_BUFFER      10

//ջԪ�����Ͷ���
typedef double ElemType;

//˳��ջ���Ͷ���
typedef struct
{
	ElemType *top;		//ջ��ָ��
	ElemType *base;		//����Ԫ�ش洢�ռ����ַ
	int size;			//��ǰ�洢�ռ���������sizeof(ElemType)Ϊ��λ��ջ���ܴﵽ����󳤶ȣ�
}Stack;//StackΪ�ṹ������


//ջ�Ĳ�����
int  InitStack(Stack *S);//����һ����ջS
void DestroyStack(Stack *S);//����ջS���ͷ�ռ�õ��ڴ棩
void ClearStack(Stack *S);//��S��Ϊ��ջ
int  StackEmpty(Stack S);//���S�Ƿ�Ϊ��ջ
int  StackLength(Stack S);//����ջS�е�����Ԫ�ظ�������ջ�ĳ���
int  GetTop(Stack S, ElemType *e);//��e����S��ջ��Ԫ��
int  Push(Stack *S, ElemType e);//ѹջ
int  Pop(Stack *S, ElemType *e);//��ջ
void StackTraverse(Stack S, void(*visit)(ElemType *));//����ջ�е�Ԫ��


int main(void)
{
    Stack s;//����һ��ջ
    int i=0;
    char c;
    double d,e;
    char str[MAX_BUFFER];

    InitStack(&s);//��ʼ��ջ

    printf("�������沨��ʽ�����س�������\n");

    scanf("%c", &c);//�����һ���ַ�
    while(c!='\n')
    {
        //�����ѭ����������
        while( isdigit(c) || c=='.' )
        {
            str[i++] = c;
            str[i] = '\0';
            if(i>=10)
            {
                printf("��������ĵ������ݹ�����\n");
                return -1;
            }
            scanf("%c", &c);
            if(c==' ')
            {
                d = atof(str);
                Push(&s, d);//������ѹջ
                i=0;
                break;
            }
        }
        //���������
        switch(c)
        {
            case '+':
                Pop(&s, &e);
                Pop(&s, &d);
                Push(&s, e+d);
                break;
            case '-':
                Pop(&s, &e);
                Pop(&s, &d);
                Push(&s, d-e);
                break;
            case '*':
                Pop(&s, &e);
                Pop(&s, &d);
                Push(&s, d*e);
                break;
            case '/':
                Pop(&s, &e);
                Pop(&s, &d);
                if(e!=0)Push(&s, d/e);
                else
                {
                    printf("��������Ϊ0��\n");
                    return -1;//ʧ��
                }
                break;
            default:break;
        }

        scanf("%c", &c);
    }

    Pop(&s, &d);
    printf("���=%f\n", d);

    return 0;
}

//����һ����ջS
//����ֵ��0�ɹ�����0ʧ��
int InitStack(Stack *S)
{
	S->base = (ElemType*)malloc(sizeof(ElemType)*STACK_INIT_SIZE);
	if (S->base == NULL)return 1;//ʧ��

	S->top = S->base;//��ʼʱջ��λ��
	S->size = STACK_INIT_SIZE;

	return 0;//�ɹ�
}
//����ջS���ͷ�ռ�õ��ڴ棩
void DestroyStack(Stack *S)
{
	free(S->base);//�ͷ��ڴ�
	S->base = S->top = NULL;
	S->size = 0;
}
//��S��Ϊ��ջ
void ClearStack(Stack *S)
{
	if (S != NULL)S->top = S->base;
}
//���S�Ƿ�Ϊ��ջ
//����ֵ����SΪ��ջ������TRUE����SΪ�ǿ�ջ������FALSE
int StackEmpty(Stack S)
{
	return S.top == S.base;
}
//����ջS�е�����Ԫ�ظ�������ջ�ĳ���
int StackLength(Stack S)
{
	return S.top - S.base;
}
//��e����S��ջ��Ԫ��
//����ֵ��0�ɹ�����0ʧ��
int GetTop(Stack S,ElemType *e)
{
	if (S.top > S.base && e != NULL)//ջ�ǿ�
	{
		*e = *(S.top - 1);//����S��ջ��Ԫ��
		return 0;//�ɹ�
	}
	return 1;//ջΪ�գ�ʧ��
}
//ѹջ,����e��ջ������Ԫ��eΪ�µ�ջ��Ԫ��
//����ֵ��0�ɹ�����0ʧ��
int Push(Stack *S, ElemType e)
{
	if (S->top - S->base >= S->size)//��ջ�ռ�����׷�Ӵ洢�ռ�
	{
		S->base = (ElemType*)realloc(S->base, (S->size + STACK_INCREASE)*sizeof(ElemType));
		if (S->base == NULL)return 1;//�ڴ����·���ʧ��
		S->top = S->base + S->size;//�µ�ջ����ַ
		S->size += STACK_INCREASE;//����ջ���������
	}
	*(S->top)++ = e;//e��ջ

	return 0;
}
//��ջ����ջ��Ϊ�գ�����*e����S��ջ��Ԫ��
//����ֵ��0�ɹ�����0ʧ��
int Pop(Stack *S, ElemType *e)
{
	if (S->top == S->base)return 1;//ջΪ��
	*e = *--(S->top);//��ջ��*e
	return 0;
}
//����ջ�е�Ԫ��
//��ջ�׵�ջ�����ζ�ջ��ÿ��Ԫ�ص��ú���visit������
void StackTraverse(Stack S, void(*visit)(ElemType *))
{
	while (S.top > S.base)visit(S.base++);
}
