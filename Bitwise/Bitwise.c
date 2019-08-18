#include <stdio.h>
#include<limits.h>

char my_compliment(char c)
{
    char b=255;
    c=c^b;
    return c;
}
char RotateByNum(char c,int n)
{
    int i;
    char temp=c;
    temp=tem<<(sizeof(char)-n);
    c=c>>n;
    c=c|temp;
    return c;
    
}


/*char RotateByNum(char c,int n)
{
    c=(x << n) | (x >> (8 - n);
    return c;
}*/
int SetBitsOne(w,i,j,value)
{
    int index=1;
    int k;
    for(k=0;k<sizeof(int)*8-1;k++)
    {
        index=index<<1;
        index+=1;
    }
    index=index<<j;
    index=index>>i;
    value=w|index;
    return value;
}

int SetBitZero(w,i,j,value)
{
    int index=1;
    int k;
    for(k=0;k<sizeof(int)*8-1;k++)
    {
        index=index<<1;
        index+=1;
    }
    index=index<<j;
    index=index>>i;
    index=~index;
    value=w&index;
    return value;