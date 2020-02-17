#include "stdio.h"
#include "string.h"
#include "stdlib.h"
//************************************************************************************

// 				Using strtok() function

//***********************************************************************************
// int main(int argc, char* argv[])
// {
// 	char *p=strtok(argv[1],",");

// 	while(*p!='\0')
// 	{
// 		printf("%s\n", p);
// 		p = strtok(NULL,",");

// 	}
// 	return 0;
// }
//*************************************************************************************

//					Without using strtok() function

//***********************************************************************************
void foo(char*,char*);

int main(int argc,char* argv[])
{
	// This function take first argument as command line argument
	// and second argument as seperator
	foo(argv[1],argv[2]);
}

void foo(char* p,char *sep)
{
	int i=0;

	int len = strlen(sep);
	// printf("%d\n", len);
	// // exit(0);

	while(*(p+i)!='\0')
	{
		// if(*(p+i)>=65 && *(p+i)<=90 || *(p+i)>=97 && *(p+i)<=122 || *(p+i)>=48 && *(p+i)<=57)
		// {
		// 	printf("%c",*(p+i));
		// }
		// else
		// {
		// 	printf("\n");
		
		// }

		for(int j=0;j<len;j++)
		{
			if(*(p+i) == *(sep+j))
			{
				printf("\n");
				i++;
			}
		}
		{
			printf("%c", *(p+i));
		}
		i++;
	}
	printf("\n");
}
