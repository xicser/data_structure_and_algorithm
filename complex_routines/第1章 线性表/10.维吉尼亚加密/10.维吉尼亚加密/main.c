
/*

2017��12��8�գ�С�������ܶ���

ά�����Ǽ��ܣ�

����������ʱ���Զ����������Կƥ��������ÿ����ĸ����λ����
���ܹ�������֮�෴

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
	sta=VigInit();//��ʼ������
	if (sta == OK)printf("���ܳ�ʼ���ɹ���\n");

	printf("����ǰ���ַ�����%s\n", Text);
	printf("����...\n");
	EncryptString(Text, Key);
	printf("���ܺ���ַ�����%s\n", Text);

	printf("����...\n");
	DecryptString(Text,Key);
	printf("���ܺ���ַ�����%s\n", Text);


	system("pause");
	return 0;
}