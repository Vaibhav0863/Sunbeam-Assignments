// Problem Statement
//-------------------------------------------------------------------------------
// Input a string from user on command line.
// String may have multiple commas e.g. "Welcome,to,Sunbeam,CDAC,Diploma,Course".
// Print each word individually. Hint: use strtok() function
//-------------------------------------------------------------------------------

#include "stdio.h"
#include "string.h"

//************************************************************************************

// 				Using strtok() function

//***********************************************************************************
// int main(int argc, char* argv[])
// {
// 	char *p=strtok(argv[1]," ");

// 	while(*p!='\0')
// 	{
// 		printf("%s\n", p);
// 		p = strtok(NULL," ");

// 	}
// 	return 0;
// }
//*************************************************************************************

//					Without using strtok() function

//***********************************************************************************
void foo(char*);

int main(int argc,char* argv[])
{
	// This function take first argument as command line argument
	// and second argument as seperator
	foo(argv[1]);
}

void foo(char* p)
{
	int i=0;

	while(*(p+i)!='\0')
	{
		if(*(p+i)>=65 && *(p+i)<=90 || *(p+i)>=97 && *(p+i)<=122 || *(p+i)>=48 && *(p+i)<=57)
		{
			printf("%c",*(p+i));
		}
		else
		{
			printf("\n");
		
		}
		i++;
	}
}
