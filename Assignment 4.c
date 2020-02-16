#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX 3

enum options{EXIT=0,QUICK_SORT,MERGE_SORT,DISPLAY};

int getChoice()
{
	int ch;
	printf("0. EXIT\n1. QUICK_SORT_USING_FUNCTION\n2. MERGE_SORT\n3. DISPLAY\n\n");
	printf("Enter your choice\n");
	scanf("%d",&ch);

	return ch;
}


typedef struct book
{
	int id;
	char name[100];
	int price;
}book;

void getData(struct book *p)
{
	printf("\nEnter Id\n");
	scanf("%d",&p->id);

	printf("Enter Name\n");
	scanf("%s",p->name);

	printf("Enter Price\n");
	scanf("%d",&p->price);
}

void displayData(struct book *p)
{
	printf("\n%3d", p->id);
	printf("%14s", p->name);
	printf("%10d", p->price);
}

int cmpfunc(const void* a, const void* b)
{
	return strcmp(((struct book*)a)->name,((struct book*)b)->name);
}

// IMPLEMENTATION OF MERGE SORT

void merger(struct book *a,int lb,int mid,int ub)
{
	struct book b[MAX]={};

	int i = lb;
	int j = mid+1;
	int k = lb;

	while(i<=mid && j<=ub)
	{
		if(a[i].price > a[j].price)
		{
			b[k] = a[i];
			i++;
		}
		else
		{
			b[k] = a[j];
			j++;	
		}
		k++;
	}

	if(i>mid)
	{
		while(j<=ub)
		{
			b[k] = a[j];
			j++;
			k++;
		}
	}
	else if(j>ub)
	{
		while(i<=mid)
		{
			b[k] = a[i];
			k++;
			i++;
		}
	}

	for(int l=lb; l<=ub ; l++)
	{
		a[l] = b[l];
	}
}

void mergeSort(struct book *p,int lb,int ub)
{
	if(lb<ub)
	{
		int mid = (lb+ub)/2;

		mergeSort(p,lb,mid);

		mergeSort(p,mid+1,ub);

		merger(p,lb,mid,ub);
	}
}


int main()
{
	book b[MAX]={1,"Let Us C",500,2,"Algorithms",200,3,"Java",300};

	// qsort(b,MAX,sizeof(book),cmpfunc);

	// for(int i = 0;i < MAX; i++)
	// {
	// 	displayData(&b[i]);
	// }

	int ch;

	while(ch = getChoice())
	{
		switch(ch)
		{
			case QUICK_SORT:
					qsort(b,MAX,sizeof(book),cmpfunc);
					printf("\n**********  SORTED DATA USING NAME **********\n");
					break;
			case MERGE_SORT:
					mergeSort(b,0,MAX-1);
					printf("\n**********  SORTED DATA USING PRICE **********\n");
					break;
			case DISPLAY:
						// printf("   ID\tNAME\t\t\tPRICE\n\n");
						for(int i = 0;i < MAX; i++)
						{
							displayData(&b[i]);
						}
						printf("\n\n");
						break;
			default:
				printf("Invalid choice\n");
				break;
		}
	}
}

