#include <stdio.h>
#include "h_DA.h"

int main()
{

	int capacity=0,num=0;
	printf("enter number: ");
	scanf("%d",&capacity);
	DA_t* Da1;	
	Da1=createDA(capacity);
	
	
	printf("enter number: \n");
	scanf("%d",&num);
	while(num!=-5)
	{
		insert(Da1,num);
		printf("enter number: \n");
		scanf("%d",&num);
	}
	
	printDA(Da1);
	destroyDA(Da1);
	
	
	return 0;
}

