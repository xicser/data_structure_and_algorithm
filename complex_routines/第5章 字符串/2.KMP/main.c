
/*

2017��12��15�գ�С������Ŭ����

KMP�㷨��

1.




*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_INIT_SIZE 20
#define BUFFER_INCREASE  10

//BF�㷨���
int BFCheck(char *Str, char *checked, int chklen)
{
    int i=0,j=0,k;
    int tempi,tempj;

    for(; Str[i] != 0; )
    {
        if(Str[i]==checked[j])//ƥ������һ��
        {
            tempi=i;tempj=j;
            for(k=1;k<=chklen;k++)
            {
                if(Str[tempi]!=checked[tempj])break;//��;ƥ��ʧ�ܣ�
                tempi++;tempj++;
            }
            if(k==chklen+1)return i;//ƥ��ɹ�
            else//��;ƥ��ʧ��
            {
                i++;
                j=0;
            }
        }
        else//ûƥ����
        {
            i++;
            j=0;
        }
    }

    return -1;//ƥ��ʧ��
}
//KMP�㷨ʵ��
//str�����촮
//check��������
int KMP_Check(char *str, char *check)
{
    int i;
    int len_str,len_check;
    int *match_value=NULL;

    //�����ַ�������
    len_str=strlen(str);
    len_check=strlen(check);

    //������������ڴ��촮�����Ȼ�޷�ƥ�䣡
    if(len_check>len_str)return -1;

    //Ϊ����ƥ��ֵ��������ڴ�
    match_value=(int*)malloc(sizeof(int)*len_check);
    if(match_value==NULL)return -2;

    //�����������Ĳ���ƥ��ֵ
    match_value[0]=0;
    for(i=2;i<=len_check;i++)
    {
        for(j=0;j<i-1;j++)
        {

        }
    }


    i=0;
    for( ; len_str[i]!=0; )
    {

    }



    return -3;
}


int main()
{
    char temp;
    int i,buffersizeString=BUFFER_INIT_SIZE,buffersizeChecked=BUFFER_INIT_SIZE;
    char *String,*BufferBeChecked;

    //�������뻺����
    String=(char*)malloc(sizeof(char)*BUFFER_INIT_SIZE);
    printf("�������ַ��������س�������\n");
    i=0;
    while(1)
    {
        temp=getchar();
        if(temp=='\n')
        {
            String[i]=0;//�ַ�����β��־
            break;
        }
        if(i>=buffersizeString)//���뻺��������
        {
            buffersizeString+=BUFFER_INCREASE;
            String=(char*)realloc(String,
            sizeof(char)*buffersizeString);
        }
        String[i++]=temp;
    }
//printf("%s\n",String);//��ӡ������ַ�����������
    //�������뻺����
    BufferBeChecked=(char*)malloc(sizeof(char)*BUFFER_INIT_SIZE);
    printf("������Ҫ���ҵ��ֶΣ����س�������\n");
    i=0;
    while(1)
    {
        temp=getchar();
        if(temp=='\n')
        {
            BufferBeChecked[i]=0;//�ַ�����β��־
            break;
        }
        if(i>=buffersizeChecked)//���뻺��������
        {
            buffersizeChecked+=BUFFER_INCREASE;
            BufferBeChecked=(char*)realloc(BufferBeChecked,
            sizeof(char)*buffersizeChecked);
        }
        BufferBeChecked[i++]=temp;
    }
//printf("%s\n",BufferBeChecked);//��ӡ������ַ�����������

//    KMP_Check(String,BufferBeChecked);




    return 0;
}

















