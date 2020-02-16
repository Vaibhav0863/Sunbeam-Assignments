#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX 3

void getStrings(char*,char*);
void StringCopy(char*,char*);
void strCat(char*,char*);
void strRev(char*);
int strCmp(char*,char*);


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

	// strRev(src);

	//+++++++++++++++++++++++++++++STRING COMPAIR++++++++++++++++++++++++++++++

	printf("%d\n", strCmp(src,des));
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

int strCmp(char *src,char *des)
{
	int srcLen = strlen(src);
	int desLen = strlen(des);
	// int flag = 0;
	// if(strlen(p)==strlen(q))
	// {
	// 	int i = 0;

	// 	while(*(p+i)!='\0')
	// 	{
	// 		if((*(p+i)-*(q+i))<0)
	// 		{
	// 			flag = -1;
	// 			// break;
	// 			return flag;
	// 		}
	// 		else if((*(p+i)-*(q+i))>0)
	// 		{
	// 			flag = 1;
	// 			// break;
	// 			return flag;
	// 		}
	// 		i++;
	// 	}

	// 	// if(flag == 1)
	// 	// {
	// 	// 	return flag;
	// 	// }
	// 	// else if(flag == -1)
	// 	// {
	// 	// 	return flag;
	// 	// }
	// 	if(flag == 0 )
	// 	{
	// 		return flag;
	// 	}
	// 	else
	// 	{
	// 		return flag;
	// 	}
	// }
	// else
	// {
	// 	flag = 1;
	// 	return flag;
	// }
	int temp;
	if(srcLen <= desLen)
	{
		for(int i=0;i<desLen;i++)
		{
			if(*(src+i)== '\0')
			{
				temp = -*(des+i);
				break;
			}
			else if(*(src + i) != *(des + i))
			{
				temp = (*(src+i) - *(des+i));
				break;
			}
			else
			{
				temp = 0;
			}

		}

		return temp;
	}
	else
	{
		for(int i=0;i<srcLen;i++)
		{
			if(*(des+i)== '\n')
			{
				temp = *(src+i);
				break;
			}
			else if(*(src + i) != *(des + i))
			{
				temp = (*(src+i) - *(des+i));
				break;
			}
			else
			{
				temp = 0;
			}

		}
		return temp;
	}
}