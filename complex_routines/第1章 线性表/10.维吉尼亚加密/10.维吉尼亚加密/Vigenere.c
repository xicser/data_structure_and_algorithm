
/*

2017��12��8�գ�С�������ܶ���

ά�����Ǽ������ʵ��

*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Vigenere.h"
#include "Cycle_DList.h"


//������ĸ˫��ѭ������
DualLinkList L;

//���ܳ�ʼ��
//��ʼ���ɹ�����0��ʧ�ܷ���1
Status VigInit(void)
{
	if (InitList(&L) == OK)return OK;
	else return ERROR;
}
//�����ַ�����
//���룺�������ַ�����Ӧ����Կ
//���ؼ��ܺ���ַ�
char Encrypt(char Letter, int key)
{
	int i, cnt = Letter - 'A';
	DualLinkList mov = L;//movָ��ʼ���

	//�Ƚ�movָ������ܵ���ĸ
	for (i = 0; i < cnt; i++)mov = mov->next;

	//key���ڼ���mov��Ų����
	if (key > 0)//����
	{
		do
		{
			mov = mov->next;
			key--;
		} while (key);
	}
	else if (key < 0)//����
	{
		do
		{
			mov = mov->prior;
			key++;
		} while (key);
	}
	else return Letter;//����

	return mov->data;//���ؼ��ܺ���ַ�
}
//�����ַ�����
//���룺�������ַ�����Ӧ����Կ
//���ؽ��ܺ���ַ�
char Decrypt(char Letter, int key)
{
	int i, cnt = Letter - 'A';
	DualLinkList mov = L;//movָ��ʼ���

	//�Ƚ�movָ������ܵ���ĸ
	for (i = 0; i < cnt; i++)mov = mov->next;

	//key���ڼ���mov��Ų����
	if (key > 0)//����
	{
		do
		{
			mov = mov->prior;
			key--;
		} while (key);
	}
	else if (key < 0)//����
	{
		do
		{
			mov = mov->next;
			key++;
		} while (key);
	}
	else return Letter;//����

	return mov->data;//���ؽ��ܺ���ַ�
}
//�ַ�������
//pString�ַ�����ָ��
//keyArray��Կ����ָ��
void EncryptString(char *pString,int *keyArray)
{
	int i;

	for (i = 0; pString[i] != 0; i++)
	{
		pString[i] = Encrypt(pString[i], keyArray[i]);
	}
}
//�ַ�������
//pString�ַ�����ָ��
//keyArray��Կ����ָ��
void DecryptString(char *pString, int *keyArray)
{
	int i;

	for (i = 0; pString[i] != 0; i++)
	{
		pString[i] = Decrypt(pString[i], keyArray[i]);
	}
}

