
/*

С������Ŭ����

��ʽջ����DEMO

*/


#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "chainStack.h"


int main(void)
{
    int a1 = 1, a3 = 3;
    float a2 = 2.0, a4 = 4.0;

	u32 valAddr;//��ջʱ�����ڴ洢�������ͺ����ݵ�ַ�ı���
	int valType;

	Stack linkStack;//����һ����ʽջ

	//��ʼ��ջ
	InitStack(&linkStack);

	//a1ѹջ����
	Push(&linkStack, (u32)(&a1), DATA_INT);
	printf("%dѹջ��ջ����Ϊ%d\n", a1, Length(&linkStack));
	printf("����һ��ջ��\n");
	StackTraverse(&linkStack);//����һ��ջ
	printf("\n\n");
	//a2ѹջ����
	Push(&linkStack, (u32)(&a2), DATA_FLOAT);
	printf("%.1fѹջ��ջ����Ϊ%d\n", a2, Length(&linkStack));
	printf("����һ��ջ��\n");
	StackTraverse(&linkStack);//����һ��ջ
	printf("\n\n");

    //��ջ����
	Pop(&linkStack, &valAddr, &valType);//��ջ
	switch(valType) {
        case DATA_FLOAT:
            printf("%.1f��ջ��ջ����Ϊ%d\n", *((float *)valAddr), Length(&linkStack));
            //�����Ľ������ʹ�����Ҫ�ͷ��ڴ棡
            free((void *)valAddr);
            break;
        case DATA_INT:
            printf("%d��ջ��ջ����Ϊ%d\n", *((int *)valAddr), Length(&linkStack));
            //�����Ľ������ʹ�����Ҫ�ͷ��ڴ棡
            free((void *)valAddr);
            break;
	}
	printf("����һ��ջ��\n");
	StackTraverse(&linkStack);//����һ��ջ
	printf("\n\n");

	//a3ѹջ����
	Push(&linkStack, (u32)(&a3), DATA_INT);
	printf("%dѹջ��ջ����Ϊ%d\n", a3, Length(&linkStack));
	printf("����һ��ջ��\n");
	StackTraverse(&linkStack);//����һ��ջ
	printf("\n\n");
	//a4ѹջ����
	Push(&linkStack, (u32)(&a4), DATA_FLOAT);
	printf("%.1fѹջ��ջ����Ϊ%d\n", a4, Length(&linkStack));
	printf("����һ��ջ��\n");
	StackTraverse(&linkStack);//����һ��ջ
	printf("\n\n");

	return 0;
}








