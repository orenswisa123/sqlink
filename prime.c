#include<stdio.h>
int prime_func(int x);
int main()
{
printf("%d\n",prime_func(19));
}

int prime_func(x)
{
	int i;
	for(i=2;i<=(x/2);i++)
	{
		if(x%i==0)
		{
		return 0;
		}
	}
	return 1;
}
	
