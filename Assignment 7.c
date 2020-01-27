#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int len=0;

enum options{EXIT,ADDFIRST,ADDLAST,DISPLAY_FORWARD,DISPLAY_BACKWARD,FIND_BY_ID,FIND_BY_NAME,DELETE_RECORD};

typedef struct BANK
{
	int id;
	char name[30];
	char type[30];
	char address[50];
	char mobile[15];
}BANK;

typedef struct NODE
{
	BANK *bank_data;
	struct NODE *next;
	struct NODE *prev;
}NODE;

NODE *head = NULL;

// Getting data from user
struct BANK* getData()
{
	BANK *data = malloc(sizeof(BANK));

	printf("ENTER ID: ");
	scanf("%d",&data->id);

	printf("ENTER NAME: ");
	fflush(stdin);
	scanf("%[^\n]s",data->name);

	printf("ENTER TYPE: ");
	fflush(stdin);
	scanf("%[^\n]s",data->type);

	printf("ENTER ADDRESS: ");
	fflush(stdin);
	scanf("%[^\n]s",data->address);

	printf("ENTER MOBILE: ");
	fflush(stdin);
	scanf("%[^\n]s",data->mobile);

	return data;
}

// Getting ID from user
int getID()
{
	int n;
	printf("ENTER ID\n");
	scanf("%d",&n);

	return n;
}

// Getting name from user
char* getName()
{
	char *name = (char*)malloc(10*sizeof(char));
	printf("Enter name\n");
	getchar();
	scanf("%[^\n]s",name);

	return name;
}

int getOption()
{
	int op;
	printf("\n0. EXIT\n1. ADD FIRST\n2. ADD LAST\n3. DISPLAY FORWARD\n4. DISPLAY BACKWARD\n5. FIND BY ID\n6. FIND BY NAME\n7. DELETE ALL RECORD\n");
	printf("Enter Option\n");
	scanf("%d",&op);

	return op;
}

// Adding node to the end of list
void addLastNode(BANK *data)
{
	NODE *newNode = malloc(sizeof(NODE));

	newNode->bank_data = data;
	newNode->next = NULL;

	if(head == NULL)
	{
		newNode->prev = NULL;

		head = newNode;
	}
	else
	{
		NODE *temp;
		temp = head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}

		newNode->prev = temp;

		temp->next = newNode;
	}
	len++;
}

//Adding node to first place of list
void addFirstNode(BANK *data)
{
	NODE *newNode = malloc(sizeof(NODE));

	newNode->bank_data = data;
	newNode->prev = NULL;

	if(head == NULL)
	{
		newNode->next = NULL;
		head = newNode;
	}
	else
	{
		head->prev = newNode;
		newNode->next = head;

		head = newNode;
	}
	len++;
}

void findByID(NODE *head,int n)
{
	NODE *trav = head;
		int flag = 0;

		while(trav->next != NULL)
		{
			if(trav->bank_data->id == n)
			{
				printf("++++++++++++++++++++++++\n");
				printf("ID : %d\n", trav->bank_data->id);
				printf("NAME : %s\n", trav->bank_data->name);
				printf("TYPE : %s\n", trav->bank_data->type);
				printf("ADDRESS : %s\n", trav->bank_data->address);
				printf("MOBILE : %s\n", trav->bank_data->mobile);
				printf("++++++++++++++++++++++++\n");
				
				flag++;
			}

			trav = trav->next;
		}

		if(flag == 0)
		{
			printf("DATA NOT FOUND\n");
		}
		else
		{
			if(trav->bank_data->id == n)
			{
				printf("++++++++++++++++++++++++\n");
				printf("ID : %d\n", trav->bank_data->id);
				printf("NAME : %s\n", trav->bank_data->name);
				printf("TYPE : %s\n", trav->bank_data->type);
				printf("ADDRESS : %s\n", trav->bank_data->address);
				printf("MOBILE : %s\n", trav->bank_data->mobile);
				printf("++++++++++++++++++++++++\n");
			}
		}



}

void findByName(NODE *head,char *name)
{
	NODE *trav = head;
		int flag = 0;

		while(trav->next != NULL)
		{
			if(strcmp(trav->bank_data->name,name) == 0)
			{
				printf("++++++++++++++++++++++++\n");
				printf("ID : %d\n", trav->bank_data->id);
				printf("NAME : %s\n", trav->bank_data->name);
				printf("TYPE : %s\n", trav->bank_data->type);
				printf("ADDRESS : %s\n", trav->bank_data->address);
				printf("MOBILE : %s\n", trav->bank_data->mobile);
				printf("++++++++++++++++++++++++\n");
				
				flag++;
			}

			trav = trav->next;
		}

		if(flag == 0)
		{
			printf("DATA NOT FOUND\n");
		}
		else
		{
			if(strcmp(trav->bank_data->name,name) == 0)
			{
				printf("++++++++++++++++++++++++\n");
				printf("ID : %d\n", trav->bank_data->id);
				printf("NAME : %s\n", trav->bank_data->name);
				printf("TYPE : %s\n", trav->bank_data->type);
				printf("ADDRESS : %s\n", trav->bank_data->address);
				printf("MOBILE : %s\n", trav->bank_data->mobile);
				printf("++++++++++++++++++++++++\n");
			}
		}

}

// Deleting  first node from list
void deleteFirstNode()
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

// Deleting all record of list
void deleteRecord(NODE *head)
{
	if(head == NULL)
	{
		printf("===============LIST IS EMPTY=============\n");
		return;
	}
	else
	{
		NODE *trav = head;
		while(trav->next != NULL)
		{
			trav = trav->next;
			deleteFirstNode();
		}
			deleteFirstNode();
		printf("+++++++++++++++RECORD DELETED SUCCESSFULLY++++++++++++++++\n");
	}
}


// Display data from start to end
void displayForward()
{
	NODE *trav = head;

	if(len!=0)
	{
		for(int i=0;i<len;i++)
		{
			printf("++++++++++++++++++++++++\n");
			printf("ID : %d\n", trav->bank_data->id);
			printf("NAME : %s\n", trav->bank_data->name);
			printf("TYPE : %s\n", trav->bank_data->type);
			printf("ADDRESS : %s\n", trav->bank_data->address);
			printf("MOBILE : %s\n", trav->bank_data->mobile);
			printf("++++++++++++++++++++++++\n");
			trav = trav->next;
		}
		printf("\n");
	}
	else
	{
		printf("================LIST IS EMPTY=================\n");
	}
}

// Display data from end to start
void displayBackward(NODE *head)
{
	if(len!=0)
	{
			if(head == NULL)
			{
				return;
			}
			displayBackward(head->next);

			printf("++++++++++++++++++++++++\n");
			printf("ID : %d\n", head->bank_data->id);
			printf("NAME : %s\n", head->bank_data->name);
			printf("TYPE : %s\n", head->bank_data->type);
			printf("ADDRESS : %s\n", head->bank_data->address);
			printf("MOBILE : %s\n", head->bank_data->mobile);
			printf("++++++++++++++++++++++++\n");
	}
	else
	{
			printf("================LIST IS EMPTY=================\n");
	
	}
}

int main()
{
	int ch;

	while(ch = getOption())
	{
		switch(ch)
		{
			case ADDFIRST:
							addFirstNode(getData());
							break;
			case ADDLAST:
							addLastNode(getData());
							break;
			case DISPLAY_FORWARD:
							displayForward();
							break;
			case DISPLAY_BACKWARD:
							displayBackward(head);
							break;
			case FIND_BY_ID:
							if(head == NULL)
							{
								printf("LIST EMPTY\n");
							}
							else
							{
								findByID(head,getID());
							}
							break;
			case FIND_BY_NAME:
							if(head == NULL)
							{
								printf("LIST EMPTY\n");
							}
							else
							{
								findByName(head,getName());
							}
							
							break;
			case DELETE_RECORD:
							deleteRecord(head);
							break;

			default:
					printf("INVALID CHOICE\n");
					break;
		}
	}

}