// Problem Statement
//-------------------------------------------------------------------------------
// Input a string from user on command line.
// String may have multiple commas e.g. "Welcome,to,Sunbeam,CDAC,Diploma,Course".
// Print each word individually. Hint: use strtok() function
//-------------------------------------------------------------------------------

#include "stdio.h"
#include "string.h"
// int main(int argc,char** argv)
// {
// 	char *p = argv[1];

// 	int i=0;

// 	while(*(p+i)!='\0')
// 	{
// 		if(*(p+i)==',')
// 		{
// 			printf("\n");
// 			i++;
// 		}
// 		printf("%c",*(p+i));
// 		i++;
// 	}
// }

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


void foo(char*,char);

int main(int argc,char* argv[])
{
	foo(argv[1],',');
}

void foo(char* p,char ch)
{
	int i=0;

	while(*(p+i)!='\0')
	{
		if(*(p+i)==ch)
		{
			printf("\n");
			i++;
		}
		printf("%c", *(p+i));
		i++;
	}
}
