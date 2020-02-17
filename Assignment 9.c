#include "stdio.h"
#include "string.h"
#include "stdlib.h"


FILE *fp;

enum options{EXIT=0,ADD,FIND,DISPLAY_ALL,EDIT,DELETE};

int len = 0;
typedef struct DATA
{
	int id;
	char name[20];
	int price;
	int quantity;
}DATA;

typedef struct NODE
{
	DATA data;
	struct NODE *next;

}NODE;

NODE *head = NULL;



// THIS FUNCTION ADD DATA FROM FILE TO LINKED LIST
void addLastNode(DATA *file_data)
{
	NODE *newNode,*temp;
	newNode = malloc(sizeof(NODE));

	newNode->data = *file_data;
	newNode->next = NULL;

	if(head == NULL)
	{
		head = newNode;
	}
	else
	{
		temp = head;

		while(temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = newNode;
	}
	len++;
}

// Get data from user and add it the end of list
void addData()
{
	// DATA *file_data = malloc(sizeof(DATA));
	DATA *file_data = malloc(sizeof(DATA));

	printf("Enter ID : ");
	scanf("%d",&file_data->id);

	printf("Enter Name : ");
	// fflush(stdin);
	scanf("%s",file_data->name);

	printf("Enter Price : ");
	scanf("%d",&file_data->price);

	printf("Enter Quantity : ");
	scanf("%d",&file_data->quantity);

	// file_data file_data = {11,"VAIBHAV",100,100};

	addLastNode(file_data);
}

int getOption()
{
	int op;

	printf("0. EXIT\n1. ADD\n2. FIND\n3. DISPLAY ALL\n4. EDIT\n5. DELETE\n");
	printf("Enter Your Choice\n");

	scanf("%d",&op);

	return op;
}


void loadData()
{
	DATA data;

	fp = fopen("data.bin","rb");

	if(fp == NULL)
	{
		printf("FILE NOT FOUND\n");
		exit(1);
	}
	else
	{
		int flag = 0;

		while(fread(&data,sizeof(DATA),1,fp))
		{
			addLastNode(&data);
			flag = 1;
		}
		if(flag == 0)
		{
			printf("FILE WAS EMPTY\n");
		}
		else
		{
			printf("------------------------\n");
			printf("DATA LOADED...\n");
			printf("------------------------\n");
		}
	}
	fclose(fp);
}

// Upload the entire list into file
void uploadData()
{
	fp = fopen("data.bin","wb");

	if(fp == NULL)
	{
		printf("INVALID FILE\n");
		exit(1);
	}
	else
	{
		
			NODE *trav = head;

			for(int i=0;i<len;i++)
			{
				fwrite(&trav->data,sizeof(DATA),1,fp);
				trav = trav->next;
			}
			printf("--------------------------\n");
			printf("FILE SAVED....\n");
			printf("--------------------------\n");


	}

	fclose(fp);
}

void display()
{
	NODE *trav = head;

	if(len>0)
	{
		for(int i=0;i<len;i++)
		{
			printf("-------------------------------------------------\n");
			printf("ID : %d\n", trav->data.id);
			printf("NAME : %s\n", trav->data.name);
			printf("PRICE : %d\n", trav->data.price);
			printf("QUANTITES : %d\n", trav->data.quantity);
			printf("-------------------------------------------------\n");

			trav = trav->next;
		}
		printf("\n");
	}
	else
	{
		printf("--------------------------------\n");
		printf("DATA NOT FOUND...\n");
		printf("--------------------------------\n");
	}
}

char* getName()
{
	char *name = malloc(sizeof(char)*10);
	printf("Enter Product Name\n");
	scanf("%s",name);

	return name;
}

void findByName(char *name)
{
		NODE *trav = head;
		int flag = 0;

		// strlwr(name);

		int i=0;
		while(i < len)
		{
			if(strstr((trav->data.name),name) != NULL)
			{
				printf("====================================\n");
				printf("ID : %d\n", trav->data.id);
				printf("NAME : %s\n", trav->data.name);
				printf("PRICE : %d\n", trav->data.price);
				printf("QUANTITES: %d\n",trav->data.quantity);
				printf("====================================\n");
				
				flag = 1;
			}
			trav = trav->next;
			i++;
		}

		if (flag == 0)
		{
			printf("---------------------------------\n");
			printf("DATA NOT FOUND\n");
			printf("---------------------------------\n");
		}

}

// Deleting data from file 

void delLast()
{
	if(head == NULL || len<1)
	{
		printf("LIST IS EMPTY\n");
	}
	else
	{
		NODE *trav = head;
		NODE *temp;
		for(int i=1;i<len-1;i++)
		{	
			trav = trav->next;
		}
		
		temp = trav->next;
		trav->next = NULL;
		free(temp);
		len--;
	}
}

void delFirst()
{
	NODE *temp = malloc(sizeof(NODE));
	
	if(head == NULL)
	{
		printf("LIST IS EMPTY\n");
	}
	else
	{
		// printf("%d\n", head->data);
		temp = head;
		head = head->next;
		free(temp);
		len--;
	}
	
}


void deleteNode()
{
	if(head == NULL)
	{
		printf("-------------------------\n");
		printf("FILE IS EMPTY\n");
		printf("-------------------------\n");
	}
	else
	{
		NODE *trav = head;
		NODE *temp;

		int index;
		printf("Enter Product ID : ");
		scanf("%d",&index);
		int cnt = 1;
		
		if(trav->data.id == index)
		{
			delFirst();
			printf("----------------------------------------\n");
			printf("PRODUCT GET DELETED FROM FILE\n");
			printf("----------------------------------------\n");
		}
		else
		{
			int flag = 0;
			for(int i=0;i<len-1;i++)
			{
				if(trav->next->data.id == index)
				{
					flag = 1;
					break;
				}
				trav = trav->next;

			}

			if(flag == 1)
			{
				if(trav->next!= NULL)
				{
					temp = trav->next;
					trav->next = temp->next;
					free(temp);
					len--;	
					printf("----------------------------------------\n");
					printf("PRODUCT GET DELETED FROM FILE\n");
					printf("----------------------------------------\n");
				}
				else
				{
					delLast();
					printf("----------------------------------------\n");
					printf("PRODUCT GET DELETED FROM FILE\n");
					printf("----------------------------------------\n");
				}
			}
			else
			{
				printf("ID NOT FOUND\n");
			}
		}
	
	}
}


void editData()
{
	int id;
	printf("Enter ID for edit data\n");
	scanf("%d",&id);

	NODE *trav = head;

	if(trav == NULL)
	{
		printf("``````````````````````````\n");
		printf("FILE IS EMPTY\n");
		printf("``````````````````````````\n");
	}
	else
	{
		int flag = 0;
		while(trav != NULL)
		{
			if(trav->data.id == id)
			{
				flag = 1;
				break;
			}
			trav = trav->next;
		}

		if(flag == 1)
		{
			int temp;
			printf("Enter New Quantities : ");
			scanf("%d",&temp);

			trav->data.quantity = temp;

			printf("-------------------------\n");
			printf("QUANTITES UPDATED\n");
			printf("-------------------------\n");
		}
		else
		{
			printf("```````````````````````````\n");
			printf("RECORD NOT FOUND\n");
			printf("```````````````````````````\n");
		}
	}



}




int main()
{
	// This function is used to load data from binary file.
	// Load data in file into list
	loadData();

	int op;

		while(op = getOption())
		{
			switch(op)
			{
				case ADD:
						// printf("ADD\n");
						addData();
						break;
				case FIND:
						findByName(getName());
						break;
				case DISPLAY_ALL:
						// printf("DISPLAY ALL\n");
						display();
						break;
				case EDIT:
						// printf("EDIT\n");
						editData();
						break;
				case DELETE:
						deleteNode();
						break;
				default:
						printf("Invalid Choice\n");
						break;
			}
		}
		uploadData();
}
