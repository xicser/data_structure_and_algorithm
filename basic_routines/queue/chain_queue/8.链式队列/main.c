#include <stdio.h>
#include <stdlib.h>
#include "chainQueue.h"
#include <malloc.h>


int main(void)
{
	int top,bottom,len,k;
	LinkQueue q;//定义一个队列结构体

	//创建一个队列
	CreateQueue(&q);
	Print(&q);//先打印遍历一次

	TopQueue(&q, &top);//获取对头元素
	printf("队头的元素为：%d\n", top);
	BottomQueue(&q, &bottom);//获取队尾元素
	printf("队尾的元素为：%d\n", bottom);

	//获取队列长度
	len = GetQueueLength(&q);
	printf("队列长度为：%d\n", len);
	
	DeQueue(&q, &k);
	printf("%d出队\n", k);
	
	//打印遍历一次
	Print(&q);

	Clear(&q);//释放队列所有结点

	system("pause");
	return 0;
}