#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AD.h"


int main()
	{
     int capacity=0,choose=0,ans=1; /*ans will hold the answer that back from the function*/
     float begin;
     AD* ad_ptr;
     Meeting* m_ptr;
     printf("enter a capacity ");
     scanf("%d",&capacity);
	
	 while(choose!=-1){
        printf("press 1 for createAD \n");
        printf("press 2 for createMeeting \n");
        printf("press 3 for insert \n");
        printf("press 4 for remove \n");
        printf("press 5 for find \n");
        printf("press 6 for printf \n");
        scanf("%d",&choose);
        switch(choose)
        {
            case 1:
                  ad_ptr=create_AD(capacity);
                  break;
            case 2:
                  m_ptr=create_meeting();
                  break;
            case 3:
                  ans=insert_appointment_into_AD(ad_ptr,m_ptr);
                  if(ans==0)
                  {
                    printf("cant insert ");
                  }
                  break;
            case 4:
                  printf("  enter begin hour to remove meeting ");
                  scanf(" %f",&begin);
                  ans=remove_appointment_from_AD(ad_ptr,begin);
                  if(ans==0)
                  {
                    printf("cant remove ");
                  }
                  break;
            case 5:
                  printf(" find your meeting, enter a begin hour ");
                  scanf(" %f",&begin);
                  m_ptr=Find(ad_ptr,begin);
                  if(m_ptr==NULL)
                  {
                    printf("cant find ");
                  }
                  else
                  {
                      printf("your meeting is %f - %f in room %d ",m_ptr->beginT, m_ptr->endT , m_ptr->RoomNuum);
                  }
                  break;
            case 6:
                  print(ad_ptr);
                  break;
            default: 
                    break;
          }
            
     }
     
     
    
	
    
     
     destroy(ad_ptr);
   
        
      return 0;
}


