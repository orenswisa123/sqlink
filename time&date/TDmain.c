#include<stdio.h>
#include<stdlib.h>
#include"TD.h"

int main()
{
    int option = 0, DateOption = 0, TimeOption = 0;
    while (option != -1)
    {
        printf("press 1 for Date \n");
        printf("press 2 for Time \n");
        printf("press -1 to exit \n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
        {   
            date_t *d1; 
            date_t *d2;
            DateOption = 0;
            d1 = Create_Date();
            
            if(d1==NULL)
                {break;}
            while (DateOption != -1)
            {
                printf("\npress 3 to create another date \n");
                printf("press 4 to add second date to first \n");
                printf("press 5 to update the first date \n");
                printf("press 6 to get the year \n");
                printf("press 7 to get the month \n");
                printf("press 8 to get the day \n");
                printf("press -1 to exit \n");
                scanf("%d", &DateOption);
                switch (DateOption)
                {
                case 3:
                {   
                    
                    d2 = Create_Date();


                }
                break;
                case 4:
                {   
                    AddDate(d1,d2);
                }
                break;
                case 5:
                {
                    UpdateDate(d1);
                }
                break;
                case 6:
                {
                    printf("%d\n", getYear(d1));
                }
                break;
                case 7:
                {
                    printf("%d\n", getMonth(d1));
                }
                break;
                case 8:
                {
                    printf("%d\n", getDay(d1));
                }
                break;
                default:
                    break;
                }
            }
            
        }
        case 2:
        {

        }
        }
    }
    return 0;
}

                   