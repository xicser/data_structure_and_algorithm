
/*

2017��12��11�գ�С������Ŭ����

��׺���ʽת��Ϊ��׺���ʽ��

ת��������Ҫ�õ�ջ������������£�
1��������������������Ǿ�ֱ�ӽ��������
2����������������������ǽ�����뵽ջ�У�����������ʱ����Ҳ�������ջ�С�
3���������һ�������ţ���ջԪ�ص������������Ĳ��������ֱ������������Ϊֹ��ע�⣬������ֻ�������������
4����������κ������Ĳ��������磨��+���� ��*�������������ȣ���ջ�е���Ԫ��ֱ���������ָ������ȼ���Ԫ��(����ջΪ��)Ϊֹ����������ЩԪ�غ󣬲Ž������Ĳ�����ѹ�뵽ջ�С���һ����Ҫע�⣬ֻ��������" ) "����������ǲŵ���" ( "������������Ƕ����ᵯ��" ( "��
5��������Ƕ����������ĩβ����ջ������Ԫ�����ε�����

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define STACK_INIT_SIZE 100//˳��ջ����Ԫ�ش洢�ռ�ĳ�ʼ������
#define STACK_INCREASE  10 //˳��ջ����Ԫ�ش洢�ռ�ķ�������

#define BUFFER_INIT_SIZE  20//���뻺������ʼ��С
#define BUFFER_INCREASE   10//���뻺��������


//ջԪ�����Ͷ���
typedef char ElemType;

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
void StackTraverse(Stack S);//����ջ�е�Ԫ��


int main(void)
{
    int i,buffersize=BUFFER_INIT_SIZE;
    char temp,e;
    char *Buffer;
    Stack s;//����һ��ջ

    //�������뻺����
    Buffer=(char*)malloc(sizeof(char)*BUFFER_INIT_SIZE);

    printf("��������׺���ʽ�����س�������\n");
    i=0;
    while(1)//������׺���ʽ
    {
        temp=getchar();
        if(temp=='\n')
        {
            Buffer[i]=0;//�ַ�����β��־
            break;
        }
        if(i>=buffersize)//���뻺��������
        {
            buffersize+=BUFFER_INCREASE;
            Buffer=(char*)realloc(Buffer,
            sizeof(char)*buffersize);
        }
        Buffer[i++]=temp;
    }
    //printf("%s\n",Buffer);//��ӡ������ַ�����������

    InitStack(&s);//��ʼ��ջ

    i=0;
    temp=Buffer[i];
    while(1)//�����ַ���
    {
        //�������֣�������λ���֣�ֱ�����
        while('0'<=temp && temp<='9')
        {
            printf("%c", temp);
            temp=Buffer[++i];
            if(temp<'0' || temp>'9')printf(" ");
        }
        //�����˳��������ţ�ֱ��ѹջ
        if(temp=='*' || temp=='/' || temp=='(')
        {
            Push(&s,temp);
            temp=Buffer[++i];
        }
        //���������ţ���ջֱ������������
        else if(temp== ')' )
        {
            Pop(&s, &e);
            while('(' != e )//�����������֮�������
            {
                printf("%c ", e);
                Pop(&s, &e);
            }
            temp=Buffer[++i];
        }
        //�����Ӽ�
        else if('+'==temp || '-'==temp )
        {
            if(StackEmpty(s))Push(&s, temp);//ջ�����Ȼֱ��ѹջ
            else//ջ�ǿգ���Ҫ����������ȼ�
            {
                do
                {//��ѹ��'+','-'ǰ���Ƚ�'('�Ϸ������������������
                 //���ջ��û��'('����ջ���������������
                    Pop(&s, &e);
                    if('(' == e)Push(&s, e);
                    else printf("%c ", e);
                }
                while(StackLength(s) && '('!=e );
                Push(&s, temp);
            }
            temp=Buffer[++i];
        }
        else if( temp==0 )break;//�ַ����Ѿ���ĩβ
        else
        {
            printf("\n�����ʽ����\n");
            return -1;
        }
    }

    //����ջ��ʣ��Ԫ��
    while(StackLength(s))
    {
        Pop(&s, &e);
        printf("%c ", e);
    }

    //�ͷ����뻺����
    free(Buffer);

    return 0;
}//1+(2-3)*4+10/5


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
void StackTraverse(Stack S)
{
	while (S.top > S.base)printf("%c ", *S.base++);
}

