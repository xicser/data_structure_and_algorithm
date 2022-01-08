#ifndef __CHAINSTACK_H__
#define __CHAINSTACK_H__

//����������Ͷ���
#define DATA_FLOAT  0
#define DATA_INT    1

//32-bit�޷������ͣ�������ʾ��ַ
#define u32 unsigned int

//ջ�ڵ�ṹ����
typedef struct Node
{
	u32		     valueAddr;	//�������ַ
	int          DataType;  //��������ָʾ
	struct Node	*next;	    //ָ����
}Node;

//ջ�ṹ����
typedef struct
{
	Node *top;     //ջ��ָ��
}Stack;

//������
void  InitStack(Stack* stack);//��ʼ��ջ
void  Clear(Stack* stack);//���ջ
void  Destroy(Stack* stack);//����ջ
void  Push(Stack *stack, u32 valAddr, int valType);//ѹջ
void  Pop(Stack* stack, u32 *valAddr, int *valType);//��ջ
int   Length(Stack* stack);//��ȡջ����
void  NodeDisplay(Node* node);//��ʾջ�ڵ�����
void  StackTraverse(Stack* stack);//����

#endif
