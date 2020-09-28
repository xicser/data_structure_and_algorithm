
/*

小王持续努力！

链式栈测试DEMO

*/


#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "chainStack.h"


int main(void)
{
    int a1 = 1, a3 = 3;
    float a2 = 2.0, a4 = 4.0;

	u32 valAddr;//弹栈时，用于存储数据类型和数据地址的变量
	int valType;

	Stack linkStack;//定义一个链式栈

	//初始化栈
	InitStack(&linkStack);

	//a1压栈测试
	Push(&linkStack, (u32)(&a1), DATA_INT);
	printf("%d压栈，栈长度为%d\n", a1, Length(&linkStack));
	printf("遍历一遍栈：\n");
	StackTraverse(&linkStack);//遍历一遍栈
	printf("\n\n");
	//a2压栈测试
	Push(&linkStack, (u32)(&a2), DATA_FLOAT);
	printf("%.1f压栈，栈长度为%d\n", a2, Length(&linkStack));
	printf("遍历一遍栈：\n");
	StackTraverse(&linkStack);//遍历一遍栈
	printf("\n\n");

    //弹栈测试
	Pop(&linkStack, &valAddr, &valType);//弹栈
	switch(valType) {
        case DATA_FLOAT:
            printf("%.1f弹栈，栈长度为%d\n", *((float *)valAddr), Length(&linkStack));
            //弹出的结点数据使用完后要释放内存！
            free((void *)valAddr);
            break;
        case DATA_INT:
            printf("%d弹栈，栈长度为%d\n", *((int *)valAddr), Length(&linkStack));
            //弹出的结点数据使用完后要释放内存！
            free((void *)valAddr);
            break;
	}
	printf("遍历一遍栈：\n");
	StackTraverse(&linkStack);//遍历一遍栈
	printf("\n\n");

	//a3压栈测试
	Push(&linkStack, (u32)(&a3), DATA_INT);
	printf("%d压栈，栈长度为%d\n", a3, Length(&linkStack));
	printf("遍历一遍栈：\n");
	StackTraverse(&linkStack);//遍历一遍栈
	printf("\n\n");
	//a4压栈测试
	Push(&linkStack, (u32)(&a4), DATA_FLOAT);
	printf("%.1f压栈，栈长度为%d\n", a4, Length(&linkStack));
	printf("遍历一遍栈：\n");
	StackTraverse(&linkStack);//遍历一遍栈
	printf("\n\n");

	return 0;
}








