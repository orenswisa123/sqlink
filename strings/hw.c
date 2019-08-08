#include <stdio.h>
#include <string.h>

char* func_Int2Bin(int ,char*);
int func_Bin2Int(char* );
char* squeeze(char *,char *);
char* location(char *,char *);

int main()
{
	int cont=1;
	unsigned int option=0;
		
	while(cont)
	{
		printf("Choose option: \n");
		printf("1: Int2Bin  \n");
		printf("2:Bin2Int    \n");
		printf("3: Squeeze  \n");
		printf("4: Location  \n");
		printf("Any another number - stop \n");
		
		scanf("%d", &option);

		switch (option)
		{

			/*case 1:
				int num1=0;
				char binary[33];
				printf("enter decimal number:");
				scanf("%d",&num1);
				func_Int2Bin(num1,binary);
			break;*/
		
			case 2:
				char binary2[]={"10001"};
				func_Bin2Int(binary2);
			break;
		
			case 3:
				char s1[]="ABCDEF";
				char s2[]="BKE";
				char s3[]="CD";
				printf("%s\n",squeeze(s1,s2));
			break;
		
			/*case 4:
				location(char *,char *);
			break;
		*/
			default:
				cont=0;
			break;
		}
	}

}

char* func_Int2Bin(int num,char* binary)
{
	int j=0,i=0;
	for(j=0;binary[j]!='\0';j++)
		binary[j]=0;
	while(num>0)    
	{    
		binary[i]=num%2+48;    
		num=num/2; 
		i++;   
	}   
	for(i=(strlen(binary)-1);i>=0;i--)
		printf("%c",binary[i]);
	printf("\n");
	return binary;

}

int func_Bin2Int(char* s1)
{
	int i=0,dec_num=0,base=1,last_dig=0, bin_num=atoi(s1);
	
	for(i=0;i<strlen(s1)-1;i++)
		{
		last_dig=bin_num%10;
		bin_num=bin_num/10;
		dec_num=dec_num+(last_dig*base);
		base=base*2;
		}
		printf("%d\n",dec_num);
		return dec_num;
}
	

char* squeeze(char *s1,char *s2)
{
	int i,j,k;
	for(i=0;s2[i]!='\0';i++)
	{
		for(j=0;s1[j]!='\0';j++)
		{
			if(s2[i]==s1[j])
			{
				for(k=j;s1[k]!='\0';k++)
				{
				s1[k]=s1[k+1];
				}
			}
		}
	}
	return s1;
}





char* location(char *s1,char *s2)
{

}
	
