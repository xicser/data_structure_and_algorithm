
/*

2017年12月14日，小王持续努力！

BF算法，很黄，很暴力。。。。

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_INIT_SIZE 20
#define BUFFER_INCREASE  10


//BF算法检测
int BFCheck(char *Str, char *checked)
{
    int i=0,j=0,k;
    int tempi,tempj;
    int chklen=strlen(checked);


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


int main()
{
    int res,len;
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

    len=strlen(BufferBeChecked);
    res=BFCheck(String, BufferBeChecked);
    if(res==-1)printf("匹配失败！\n");
    else
    printf("从第%d个字符开始的后续%d个字符为匹配结果！",res+1,len);

    return 0;
}
