#include<stdio.h>
#include<stdlib.h>
#include "Bit.h"


int main()
{
    BitMap *B1;
    int nf=0,option=0,ans=1,bit=0;
    B1 = malloc(sizeof(BitMap));
    printf("enter num of fitchers");
    scanf("%d", &nf);
    B1 = Create_BM(nf);

    while (option != -1)
    {
        printf("\n press 1 to turn on bit \n");
        printf("press 2 to turn off bit \n");
        printf("press 3 to check bit status \n");
        printf("press 4 to destroy\n");
        printf("press -1 to exit \n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
        {
            printf("enter bit number");
            scanf("%d", &bit);
            BitOn(B1, bit);
        }
        break;
        case 2:
        {
            printf("enter bit number");
            scanf("%d", &bit);
            BitOff(B1, bit);
        }
        break;
        case 3:
        {
            printf("enter bit number");
            scanf("%d", &bit);
            BitStat(B1, bit);
        }
        break;
        case 4:
        {
        }
        }
     }
     destroy(B1);
}

