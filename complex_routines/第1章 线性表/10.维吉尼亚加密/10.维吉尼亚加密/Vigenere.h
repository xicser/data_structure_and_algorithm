#ifndef __VIGENERE_H__
#define __VIGENERE_H__

#include "Cycle_DList.h"

Status VigInit(void);//���ܳ�ʼ��
char   Encrypt(char Letter, int key);//�����ַ�����
char   Decrypt(char Letter, int key);//�����ַ�����
void   EncryptString(char *pString, int *keyArray);//�ַ�������
void   DecryptString(char *pString, int *keyArray);//�ַ�������

#endif
