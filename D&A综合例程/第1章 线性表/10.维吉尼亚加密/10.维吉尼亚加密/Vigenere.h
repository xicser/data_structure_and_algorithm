#ifndef __VIGENERE_H__
#define __VIGENERE_H__

#include "Cycle_DList.h"

Status VigInit(void);//加密初始化
char   Encrypt(char Letter, int key);//单个字符加密
char   Decrypt(char Letter, int key);//单个字符解密
void   EncryptString(char *pString, int *keyArray);//字符串加密
void   DecryptString(char *pString, int *keyArray);//字符串解密

#endif
