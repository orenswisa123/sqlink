#include <stdio.h>
#include <stdlib.h>
#include "AD.h"

AD* create_AD(int capacity)
{
	AD* ADarr;
	ADarr=malloc(sizeof(AD));
	if(ADarr==NULL)
		return NULL;
	else
	{
		ADarr->capacity=capacity;
		ADarr->index=0;
		ADarr->meetings=malloc(capacity*sizeof(Meeting*));
		if(ADarr->meetings==NULL)
			free(ADarr);
	}
		return ADarr;
}
Meeting* create_meeting()
{
	Meeting M;
	M=malloc(sizeof(Meeting));
	if(M==NULL)
		return NULL;
	float bT,eT;
	int RNum=0;
	do
	{
	printf("enter begin time of the meeting :\n");
	scanf("%f",&bT);
	printf("enter end time of the meeting :\n");
	scanf("%f",&eT);
	}while((bT<0||eT>24||bT>24||eT<0)&&(eT>bT))   /*end of loop only if the time is ok*/
	printf("enter room number :\n");
	scanf("%d",&RNum);
	M->beginT=bT;
	M->endT=eT;
	M->RoomNum=RNum;
	return M;
	else
	return NULL;
}
int insert_appointment_into_AD(AD* ad_ptr,Meeting* m_ptr)
{	
	int i,place;
	Meeting **temp=(ad_ptr->meetings)    /*temporary pointer to not erase the original*/
	if((ad_ptr==NULL)||(m_ptr==NULL))
	{
		return 0;
	}
		if(ad_ptr->index==0)
		{
			ad_ptr->meetings[0]=m_ptr;
			((ad_ptr->index))++; 
			return 1;  
		}   
		else 
		{
			if (ad_ptr->meetings[0]->beginT) >= (m_ptr->endT)
			{
		for(i=ad_ptr->index;i>0;i--)
			ad_ptr->meetings[i]=ad_ptr_meetings[i+1];
			if((da_ptr->index)>=(da_ptr->capacity))
			{
				temp=realloc((ad_ptr->meetings),((ad->capacity)*2)*sizeof(Meeting*)); /*realloc*/
				if(temp)  /*check if pointer is ok*/
				{
					(ad_ptr->meetings)=temp;
					(ad_ptr->capacity)*=2;/*make capacity dual*/
				}
				ad_ptr->meetings[0]=m_ptr;
				((ad_ptr->index))++;
				return 1;
			}
		if(ad_ptr->meetings[ad_ptr->index]->endT <= (m_ptr->beginT)
		   {
			 ad_ptr->meetings[(ad_ptr->index)+1]=m_ptr;
			 ((ad_ptr->index))++;
			 return 1;
		   }
		for(i=1;i<(da_ptr->index);i++)
		{
			if((m_ptr->beginT)>=(ad_ptr->meetings[i-1]->endT)&&(m_ptr->endT)<=(ad_ptr->meetings[i]->beginT)
			{
				place=i;
				for(i=ad_ptr->index;i>place;i--)
				ad_ptr->meetings[i]=ad_ptr_meetings[i-1];
				if((da_ptr->index)>=(da_ptr->capacity))
				{
					temp=realloc((ad_ptr->meetings),((ad->capacity)*2)*sizeof(Meeting*));  /*realloc*/
					if(temp)  /*check if pointer is ok*/
					{
						(ad_ptr->meetings)=temp;
						(ad_ptr->capacity)*=2;/*make capacity dual*/
					}
				ad_ptr->meetings[place]=m_ptr;
				((ad_ptr->index))++;
				return 1;
				}
			}
		}
		return 0;
   }

}	

int remove_appointment_from_AD(AD* ad_ptr,float begin){
   int i=0,j=0;
      
      if(ad_ptr!=NULL){
	  for(i=0;i<ad_ptr->index;i++){
	     if(ad_ptr->meetings[i]->beginT==begin){
		 free(ad_ptr->meetings[i]);
                 for(j=i;j<ad_ptr->index;j++){
                     ad_ptr->meetings[j]=ad_ptr->meetings[j+1];
                 }
              	ad_ptr->index--;
             	 return 1;
	     }
            
	  }
	 
      }
  
    return 0;
}

Meeting* Find(AD* ad_ptr,float begin){
  int i=0;
      
      if(ad_ptr!=NULL){
	  for(i=0;i<ad_ptr->index;i++){
	     if(ad_ptr->meetings[i]->beginT==begin){
		 return ad_ptr->meetings[i];
	     }
	  }
	 
      }
  
    return NULL;
}

		
	
void print(AD* ad_ptr){
   int i=0;
  if(ad_ptr!=NULL){
    for(i=0;i<ad_ptr->index;i++){
       printf("begin hour= %f ",ad_ptr->meetings[i]->beginT);
       printf("end hour= %f ",ad_ptr->meetings[i]->endT);
       printf("room number= %d ",ad_ptr->meetings[i]->RoomNum);
    }
  }

}

void destroy(AD*  ad_ptr){
  int i=0;
  if(ad_ptr!=NULL){
         for(i=0;i<ad_ptr->index;i++){
              if(ad_ptr->meetings!=NULL){
                  free(ca->day[i]);
              }
    }

         free(ad_ptr->meetings);
         free(ad_ptr);
   }
  

}

	
	
		
		
