#include<stdio.h>
int sort_01_func(int,int *);
void swap(int* x,int* y);
int main()
{
int size=0,i;
int* ptr;
printf("enter size of array:");
scanf("%d",&size);//input the size of the array*/
int a[size];
for(i=0;i<size;i++)
	{
	printf("enter 0 or 1");
	scanf("%d",&a[i]);
	}
ptr=&a[0];
sort_01_func(int size,int *ptr);
for(i=0;i<size;i++)
{
printf("%d",*(ptr+i));
}
}


int sort_01_func(int size,int *ptr)
{
int i=0;
while(i<size)
{
	if(*ptr==0)
	{
		ptr++;
	}
	else
	{
	if(*(ptr[i])==1)
	{
	i++;
	}
	}
	swap(int* ptr[i],int* ptr);
}

void swap(int* x,int* y);
{
int temp;
temp=*x;
*x=*y;
*y=temp;
}

	
	
			
