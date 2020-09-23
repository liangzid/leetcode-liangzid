#include<stdio.h>

int strStr(char*,char*);
int length_str(char*);
int block_equal(char *,char *);

//找到haystack中needle第一次出现的索引
// 定义一种特殊的遍历，称之为block equal，然后用这种block equal去遍历，找到所有相等的地方
int strStr(char *haystack, char *needle)
{
    int pos=-1;

    int len_needle=length_str(needle);
    if(len_needle==0)
    {
        return 0;
    }

    int begin=0;
    int end=length_str(haystack)-length_str(needle);
    // printf("%d\n",end);

    for(int i=begin;i<=end;i++)
    {
        // printf("%s\n",haystack+i);
        if(block_equal((haystack+i),needle))
        {
            pos=i;
            break;
        }
    }
    return pos;

}

int length_str(char *x)
{
    int i=0;
    while(x[i]!='\0')
    {
        i++;
    }
    return i;
}

int block_equal(char *x,char *y)
{
    // if(length_str(x)!=length_str(y))
    // {
    //     printf("error.");
    //     //报错；
    // }
    for(int i=0;i<length_str(y);i++)
    {
        if(x[i]!=y[i])
        {
            return 0;
        }
    }
    return 1;
}


int main()
{
    // printf("%d\n",length_str("qwer"));

    int pos=strStr("hello","ll");
    printf("%d\n",pos);
    return 0;
}