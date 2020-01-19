// An example program to demonstrate working 
// of enum in C 
#include<stdio.h> 

enum operations {EXIT=0,MIN,MAX,ADD,DEL};

// Taking options from users 
int getOp();
void minElement(int*);
void maxElement(int*);
void addElement(int*);
void delElement(int*);

int main()
{
	int ch;

	int a[10]={0};

	
	int max = 1;
	while(ch=getOp())
	{
		printf("\n\n");
		switch(ch)
		{
			case MIN:
					minElement(a);
					break;
			case MAX:
					maxElement(a);
					break;
			case ADD:
					addElement(a);
					break;
			case DEL:
					delElement(a);
					break;
			default:
					printf("Invalid Choice\n");
		}
	}
}

int getOp()
{
	enum operations op;

	
	printf("0:EXIT\n1:MIN\n2:MAX\n3:ADD\n4:DELETE\n");

	printf("\nEnter Your Choice\n");
	scanf("%d",&op);

	return op;
}

void minElement(int *a)
{
	int min = 100000;
	int id;
	int i=0;
	while(i<10)
	{
		if(a[i]<min && a[i]!=0)
		{
			min = a[i];
			id = i;
		}
		i++;
	}
	printf("Minimum number in array is %d at %d location\n",min,id);
}

void maxElement(int *a)
{
	int max = 1;
	int id;

	int i=0;
	while(i<10)
	{
		if(max<a[i])
		{
			max = a[i];
			id = i;
		}
		i++;
	}
	printf("Maximum number in array is %d at %d location\n",max,id);
}

void addElement(int *a)
{
	int i=0;
	int n,loc;
	printf("Available locations to add new number\n");

	while(i<10)
	{
		if(a[i]==0)
		{
			printf("%d  ",i);
		}
		i++;
	}
	printf("\n");

	printf("Enter location and number\n");
	scanf("%d%d",&loc,&n);
	if(a[loc]!=0)
	{
		printf("You cannot insert number to that location\n");
	}
	else
	{
		a[loc] = n;
		printf("number added to an array\n");
	}
}

void delElement(int *a)
{
	int i=0;
	int loc;

	printf("These are the only element which we can delete from array\n");

	while(i<10)
	{
		if(a[i]!=0)
		{
			printf("%d:%d  ", i,a[i]);
		}
		i++;
	}

	printf("\nEnter location from which you want delete element\n");
	scanf("%d",&loc);

	if(a[loc]!=0)
	{
		a[loc] = 0;
		printf("Number deleted from array\n");
	}
	else
	{
		printf("You cannot perform delete operation on %d location\n", loc
			);
	}
}