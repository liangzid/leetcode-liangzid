#include<stdio.h>
#include<string.h>

int str_equal(char*,char*);
int length_str(char *);
char *str_slide(char*,int,int);
int one_equal2others(char *, char **);


char * longestCommonPrefix(char ** strs, int strsSize)
{
    char *str1=strs[0];
    char ** str1_list;
    for(int i=0;i<length_str(str1);i++)
    {
        //?????这一行有问题
        *(str1_list+i)=str_slide(str1,0,i+1);
    }
    for(int i=length_str(str1);i!=0;i--)
    {
        if(one_equal2others(str1_list[i-1],strs))
        {
            free(str1_list);
            return str_slide(strs[0],0,i); 
        }
        else
        {
            continue;
        }
    }
    return "";
}


int one_equal2others(char *a, char **bs)
{
    for(int i=0;*(bs+i)!=NULL;i++)
    {
        if(!str_equal(a,bs[i]))
        {
            return 0;
        }
    }
    return 1;
}




char *str_slide(char *a,int begin,int end)
{
    char *something;
    something=(char*) malloc(sizeof(char)*(end-begin));
    for(int i=begin;i<end;i++)
    {
        something=strcat(something,a[i]);
    }
    return something;
}



int str_equal(char* str_short, char*y)
{
    int str_len=length_str(str_short);
    for(int i=0;i<str_len;i++)
    {
        if(str_short[i]!=y[i])
        {
            return 0;
        }
    }
    return 1;

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



int main()
{
    //这里同样也有问题！
    char ** alist={"flower", "flow", "flight"};
    char * result=longestCommonPrefix(alist,3);
    printf("%s",result);
    return 0;

}