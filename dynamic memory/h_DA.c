#include <stdio.h>
#include <stdlib.h>
#include "h_DA.h"


DA_t* createDA(int capacity)
{
	DA_t* Da1;
	Da1=(DA_t*)malloc(sizeof(DA_t));
	if(Da1!=NULL)
	{
	(*Da1).capacity=capacity;
	(*Da1).index=0;
	(*Da1).arr=malloc(capacity*sizeof(int));
	}
	return Da1;
}
int insert(DA_t* da_ptr,int num)
{
	int *temp=(da_ptr->arr);
	if((da_ptr->index)>=(da_ptr->capacity))
	{
		temp=realloc((da_ptr->arr),((da_ptr->capacity)*2)*sizeof(int));
		if(temp)/*check if pointer is ok*/
		{
			(da_ptr->arr)=temp;
			(da_ptr->capacity)*=2;/*make capacity dual*/
			
		}
		else
		{
			return 0;
		}
	}

	da_ptr->arr[da_ptr->index]=num;
			((da_ptr->index))++;

	return 1;
}

void printDA(DA_t* da_ptr)
{
	int i=0;
	for(i=0;i<(da_ptr->index);i++)
	{
	printf("%d",da_ptr->arr[i]);
	}
}
void destroyDA(DA_t* da_ptr)
{
	free(da_ptr->arr);
	free(da_ptr);
}
	

