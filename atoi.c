#include<stdio.h>
#define INT_MAXEDGE 2147483648
typedef unsigned int uint;

long myxpowery(int,int);
int mystr2int(char*,int,int);


int myAtoi(char * str){
    int i=0;
    while (*(str+i)==' ')
    {
        i++;
    }

    int flag_negative=0;
    int x;
    int j=0;

    //判断是否是负号；
    if (*(str+i) == '-')
    {
        flag_negative=1;
        i++;
    }
    else if(*(str+i) == '+')
    {
        i++;
    }

    int flag_have0=0;
    while(*(str+i)=='0')
    {
        flag_have0=1;
        i++;
    }

    //如果不是数字，直接结束
    if (*(str+i)<'0'||*(str+i)>'9')
    {
        // printf("1111111111111111111");
        return 0;
    }
    //如果是数字，或许连续数字的长度
    while(*(str+i+j)>='0' && (*(str+i+j)<='9'))
        {
            j++;
        }

    x=mystr2int(str+i,j-1,flag_negative);
    
    return x;

}

int mystr2int(char * p, int length, int flag_negative)
{
    // printf("%s\n",p);
    long result=0;
    for(int m=length;m>=0;m--)
    {
        
        // printf("char pointers: %c\n", *(p+m));
        // printf("pointers: %d\n", *(p+m)-48);
        // printf("m: %d\n",m);
        // printf("length:%d\n",length);
        // printf("part result: %ld\n",myxpowery(10,length-m));
        long temp=myxpowery(10,length-m);
        result= result + temp*(*(p+m)-48);
        // printf("result: %d\n",result);
        // printf("result: %lld\n",result);
        // printf("int result %d\n",(int)result);
        if ((int)result!=result)
        {
            if (flag_negative>0)
            {
                // printf("11111");
                result=INT_MAXEDGE;
                result=0-result;
            }
            else
            {
                result=INT_MAXEDGE;
                result--;
            }
            break;
        }
    }
    result=(flag_negative>0)?(0-result):(result);

    return (int)result;
}

long myxpowery(int x, int y)
{
    long m=1;
    // long temp=x;
    while (y>0)
    {
        m=m*x;
        // printf("x:%ld\n",x);
        // printf("m: %lld\n",m);
        y--;
    }
    return m;
}


int main()
{
    // int a=10;
    // long b=a;
    // printf("b: %ld",b);

    // long long temp=myxpowery(10,10);
    // printf("%lld",temp);
    // int cc=myAtoi("-91283472332");
    int cc=myAtoi("-200000000000000000000");
    printf("%d",cc);
    return 0;
}
