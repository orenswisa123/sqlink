#include <stdio.h>

int perfect_func(int x);
int main()
{
	printf("%d\n",perfect_func(6));
}

int perfect_func(x)
{
	int i,sum=0;
	for(i=1;i<x;i++)
	{
	if(x%i==0)
	{
	sum=sum+i;	
	}
	}
	if(sum==x)
	{
	return 1;
	}
	return 0;
}
