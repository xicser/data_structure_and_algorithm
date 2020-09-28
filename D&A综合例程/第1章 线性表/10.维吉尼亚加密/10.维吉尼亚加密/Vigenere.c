
/*

2017年12月8日，小王持续奋斗！

维吉尼亚加密相关实现

*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Vigenere.h"
#include "Cycle_DList.h"


//定义字母双向循环链表
DualLinkList L;

//加密初始化
//初始化成功返回0，失败返回1
Status VigInit(void)
{
	if (InitList(&L) == OK)return OK;
	else return ERROR;
}
//单个字符加密
//输入：待加密字符，对应的密钥
//返回加密后的字符
char Encrypt(char Letter, int key)
{
	int i, cnt = Letter - 'A';
	DualLinkList mov = L;//mov指向开始结点

	//先将mov指向待加密的字母
	for (i = 0; i < cnt; i++)mov = mov->next;

	//key等于几，mov就挪几次
	if (key > 0)//右移
	{
		do
		{
			mov = mov->next;
			key--;
		} while (key);
	}
	else if (key < 0)//左移
	{
		do
		{
			mov = mov->prior;
			key++;
		} while (key);
	}
	else return Letter;//不移

	return mov->data;//返回加密后的字符
}
//单个字符解密
//输入：待解密字符，对应的密钥
//返回解密后的字符
char Decrypt(char Letter, int key)
{
	int i, cnt = Letter - 'A';
	DualLinkList mov = L;//mov指向开始结点

	//先将mov指向待解密的字母
	for (i = 0; i < cnt; i++)mov = mov->next;

	//key等于几，mov就挪几次
	if (key > 0)//左移
	{
		do
		{
			mov = mov->prior;
			key--;
		} while (key);
	}
	else if (key < 0)//右移
	{
		do
		{
			mov = mov->next;
			key++;
		} while (key);
	}
	else return Letter;//不移

	return mov->data;//返回解密后的字符
}
//字符串加密
//pString字符数组指针
//keyArray密钥数组指针
void EncryptString(char *pString,int *keyArray)
{
	int i;

	for (i = 0; pString[i] != 0; i++)
	{
		pString[i] = Encrypt(pString[i], keyArray[i]);
	}
}
//字符串解密
//pString字符数组指针
//keyArray密钥数组指针
void DecryptString(char *pString, int *keyArray)
{
	int i;

	for (i = 0; pString[i] != 0; i++)
	{
		pString[i] = Decrypt(pString[i], keyArray[i]);
	}
}

