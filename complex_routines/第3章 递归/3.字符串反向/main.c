
/*

2017��12��13�գ�С������Ŭ����

�ַ�������
��дһ���ݹ麯����ʵ�ֽ���������ⳤ���ַ������������
��������abc�����cba��������ַ�����#��ʾ����

*/

#include <stdio.h>
#include <stdlib.h>


void print()
{
    char a;

    scanf("%c", &a);
    if(a!='#')print();
    if(a!='#')printf("%c",a);
}

int main()
{

    print();
    return 0;
}








