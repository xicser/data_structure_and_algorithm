
/*

2017年12月8日，小王持续奋斗！

维吉尼亚加密：

当输入明文时，自动生成随机密钥匹配明文中每个字母并移位加密
解密过程则与之相反

*/


#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Cycle_DList.h"
#include "Vigenere.h"


int  Key[] = {12,-2345,34,-8,23,2,543,-23,-234,-27};
char Text[] = "ILOVEFISHC";

int main(void)
{
	int sta;
	sta=VigInit();//初始化加密
	if (sta == OK)printf("加密初始化成功！\n");

	printf("加密前的字符串：%s\n", Text);
	printf("加密...\n");
	EncryptString(Text, Key);
	printf("加密后的字符串：%s\n", Text);

	printf("解密...\n");
	DecryptString(Text,Key);
	printf("解密后的字符串：%s\n", Text);


	system("pause");
	return 0;
}