
/*

2017��12��14�գ�С������Ŭ����

BF�㷨���ܻƣ��ܱ�����������

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_INIT_SIZE 20
#define BUFFER_INCREASE  10


//BF�㷨���
int BFCheck(char *Str, char *checked)
{
    int i=0,j=0,k;
    int tempi,tempj;
    int chklen=strlen(checked);


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


int main()
{
    int res,len;
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

    len=strlen(BufferBeChecked);
    res=BFCheck(String, BufferBeChecked);
    if(res==-1)printf("ƥ��ʧ�ܣ�\n");
    else
    printf("�ӵ�%d���ַ���ʼ�ĺ���%d���ַ�Ϊƥ������",res+1,len);

    return 0;
}
