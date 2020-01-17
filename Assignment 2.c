#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX 3

void getStrings(char*,char*);
void StringCopy(char*,char*);
void strCat(char*,char*);
void strRev(char*);


int main()
{
	char *src = (char *)calloc(MAX,sizeof(char));
	char *des = (char *)calloc(MAX,sizeof(char));

	getStrings(src,des);

	//++++++++++++++++++++++++++STRING COPY+++++++++++++++++++++++++++++++++++
	// printf("Before string copy\n");
	// printf("Source String: %s\n", src);
	// printf("Destination String: %s",des);

	// StringCopy(src,des);
	// printf("\n******************************************\n");
	// printf("After String Copy\n");

	// printf("Source String: %s\n", src);
	// printf("Destination String: %s\n",des);

	//+++++++++++++++++++++++++++STRING CONCAT++++++++++++++++++++++++++++++++

	// strCat(des,src);

	//++++++++++++++++++++++++++++STRING REVERSE+++++++++++++++++++++++++++++++

	strRev(src);

	//+++++++++++++++++++++++++++++STRING COMPAIR++++++++++++++++++++++++++++++

	// printf("%d\n", strcmp(src,des));
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

void strCat(char *src,char *des)
{
	int i=0;
	int j=0;
	while(1)
	{
		if(*(src+i)=='\0')
		{
			break;
		}
		i++;
	}
	while(1)
	{
		if(*(des+j)=='\0')
		{
			break;
		}
		*(src+i) = *(des+j);

		i++;
		j++;
	}
}

void strRev(char *p)
{
	int len = strlen(p)-1;
	//int mid = len/2;
	int i = 0;
	char temp;

	// printf("%d\n", len);
	// while(i<=mid && len>=mid)
	while(i<=len)
	{
		temp = *(p+i);
		*(p+i) = *(p+len);
		*(p+len) = temp;

		i++;
		len--;
	}
}

// void strCmp(char *p,char *q)
// {
// 	if()
// }