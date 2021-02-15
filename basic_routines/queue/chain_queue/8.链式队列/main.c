#include <stdio.h>
#include <stdlib.h>
#include "chainQueue.h"
#include <malloc.h>


int main(void)
{
	int top,bottom,len,k;
	LinkQueue q;//����һ�����нṹ��

	//����һ������
	CreateQueue(&q);
	Print(&q);//�ȴ�ӡ����һ��

	TopQueue(&q, &top);//��ȡ��ͷԪ��
	printf("��ͷ��Ԫ��Ϊ��%d\n", top);
	BottomQueue(&q, &bottom);//��ȡ��βԪ��
	printf("��β��Ԫ��Ϊ��%d\n", bottom);

	//��ȡ���г���
	len = GetQueueLength(&q);
	printf("���г���Ϊ��%d\n", len);
	
	DeQueue(&q, &k);
	printf("%d����\n", k);
	
	//��ӡ����һ��
	Print(&q);

	Clear(&q);//�ͷŶ������н��

	system("pause");
	return 0;
}