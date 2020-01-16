// Implementation of strcpy() function

#include "stdio.h"
#include "stdlib.h"

#define MAX 3

void getStrings(char*,char*);
void StringCopy(char*,char*);

int main()
{
	char *src = (char *)calloc(MAX,sizeof(char));
	char *des = (char *)calloc(MAX,sizeof(char));

	getStrings(src,des);


	printf("Before string copy\n");
	printf("Source String: %s\n", src);
	printf("Destination String: %s",des);

	StringCopy(src,des);
	printf("\n******************************************\n");
	printf("After String Copy\n");

	printf("Source String: %s\n", src);
	printf("Destination String: %s\n",des);
}

void getStrings(char *src,char *des)
{
	printf("Enter Source string \n");
	scanf("%s",src);
	// gets(src);

	printf("Enter Destination string\n");
	scanf("%s",des);
	// gets(des);

}


void StringCopy(char *des,char *src)
{
	int i=0;
	while(*(src+i)!='\0')
	{
		*(des+i)=*(src+i);
		i++;
	}
	*(des+i)='\0';
}
