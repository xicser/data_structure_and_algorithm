
/*

2017年12月15日，小王持续努力！

KMP算法：

1.




*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_INIT_SIZE 20
#define BUFFER_INCREASE  10

//BF算法检测
int BFCheck(char *Str, char *checked, int chklen)
{
    int i=0,j=0,k;
    int tempi,tempj;

    for(; Str[i] != 0; )
    {
        if(Str[i]==checked[j])//匹配上了一个
        {
            tempi=i;tempj=j;
            for(k=1;k<=chklen;k++)
            {
                if(Str[tempi]!=checked[tempj])break;//中途匹配失败！
                tempi++;tempj++;
            }
            if(k==chklen+1)return i;//匹配成功
            else//中途匹配失败
            {
                i++;
                j=0;
            }
        }
        else//没匹配上
        {
            i++;
            j=0;
        }
    }

    return -1;//匹配失败
}
//KMP算法实现
//str：待检串
//check：搜索串
int KMP_Check(char *str, char *check)
{
    int i;
    int len_str,len_check;
    int *match_value=NULL;

    //计算字符串长度
    len_str=strlen(str);
    len_check=strlen(check);

    //如果搜索串长于待检串，则必然无法匹配！
    if(len_check>len_str)return -1;

    //为部分匹配值数组分配内存
    match_value=(int*)malloc(sizeof(int)*len_check);
    if(match_value==NULL)return -2;

    //计算搜索串的部分匹配值
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

    //开辟输入缓冲区
    String=(char*)malloc(sizeof(char)*BUFFER_INIT_SIZE);
    printf("请输入字符串，按回车结束：\n");
    i=0;
    while(1)
    {
        temp=getchar();
        if(temp=='\n')
        {
            String[i]=0;//字符串结尾标志
            break;
        }
        if(i>=buffersizeString)//输入缓冲区扩容
        {
            buffersizeString+=BUFFER_INCREASE;
            String=(char*)realloc(String,
            sizeof(char)*buffersizeString);
        }
        String[i++]=temp;
    }
//printf("%s\n",String);//打印输入的字符串，调试用
    //开辟输入缓冲区
    BufferBeChecked=(char*)malloc(sizeof(char)*BUFFER_INIT_SIZE);
    printf("请输入要查找的字段，按回车结束：\n");
    i=0;
    while(1)
    {
        temp=getchar();
        if(temp=='\n')
        {
            BufferBeChecked[i]=0;//字符串结尾标志
            break;
        }
        if(i>=buffersizeChecked)//输入缓冲区扩容
        {
            buffersizeChecked+=BUFFER_INCREASE;
            BufferBeChecked=(char*)realloc(BufferBeChecked,
            sizeof(char)*buffersizeChecked);
        }
        BufferBeChecked[i++]=temp;
    }
//printf("%s\n",BufferBeChecked);//打印输入的字符串，调试用

//    KMP_Check(String,BufferBeChecked);




    return 0;
}

















