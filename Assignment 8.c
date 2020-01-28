#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int len = 0;

enum options{EXIT,FIND_BY_ID,FIND_BY_NAME,DISPLAY};

typedef struct MOVIE
{
	char id[10];
	char name[50];
	char info[100];
}MOVIE;

typedef struct NODE
{
	struct MOVIE movie_data;
	struct NODE *next;
}NODE;

NODE *head = NULL;

void addLastNode(MOVIE *data)
{
	NODE *newNode,*temp;
	newNode = malloc(sizeof(NODE));

	newNode->movie_data = *data;
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

void getData()
{
	MOVIE *data = malloc(sizeof(MOVIE));
	char buffer[100];

	FILE *fp;

	fp = fopen("data.csv","r");

	if(fp != NULL)
	{
		char *ch;
		while(fgets(buffer , sizeof(buffer),fp) != NULL)
		{
			strcpy(data->id,strtok(buffer,","));
			strcpy(data->name,strtok(NULL,","));
			strcpy(data->info,strtok(NULL,","));
			addLastNode(data);
		}
	}
	fclose(fp);
}



void display()
{
	NODE *temp = head;
	for(int i=0;i<len;i++)
	{
		printf("====================================\n");
		printf("%s\n", temp->movie_data.id);
		printf("%s\n", temp->movie_data.name);
		printf("%s\n", temp->movie_data.info);
		printf("====================================\n");
		temp = temp->next;
	}
	printf("\n");
}



int getOption()
{
	int op;

	printf("0. EXIT\n1. FIND BY GENRE\n2. FIND BY NAME\n3. DISPLAY\n");
	printf("Enter Your Choice\n");

	scanf("%d",&op);

	return op;
}

void findByGenre()
{
	NODE *trav = head;

	int flag = 0;
	char info[20];

	printf("Enter Datails to search\n");
	fflush(stdin);
	scanf("%[^\n]s",info);

	strlwr(info);

	while(trav->next != NULL)
	{
		if(strstr(strlwr(trav->movie_data.info),info)!= NULL)
		{
			printf("====================================\n");
			printf("%s\n", trav->movie_data.id);
			printf("%s\n", trav->movie_data.name);
			printf("%s\n", trav->movie_data.info);
			printf("====================================\n");
			
			flag = 1;
		}
		trav = trav->next;
	}

	if (flag == 0)
	{
		printf("DATA NOT FOUND\n");
	}
}

void findByName()
{
	NODE *trav = head;

	int flag = 0;
	char info[20];

	printf("Enter Datails to search\n");
	fflush(stdin);
	scanf("%[^\n]s",info);

	strlwr(info);

	while(trav->next != NULL)
	{
		if(strstr(strlwr(trav->movie_data.name),info)!= NULL)
		{
			printf("====================================\n");
			printf("%s\n", trav->movie_data.id);
			printf("%s\n", trav->movie_data.name);
			printf("%s\n", trav->movie_data.info);
			printf("====================================\n");
			
			flag = 1;
		}
		trav = trav->next;
	}

	if (flag == 0)
	{
		printf("DATA NOT FOUND\n");
	}
}


int main()
{

		int op;

		getData();

		while(op=getOption())
		{
			printf("LENGTH : %d\n", len);
			switch(op){
					case FIND_BY_ID:
								if(head!=NULL)
								{
									findByGenre();
								}
								else
								{
									printf("LIST IS EMPTY\n");
								}
								break;
					case FIND_BY_NAME:
								if(head != NULL)
								{
									findByName();
								}
								else
								{
									printf("LIST IS EMPTY\n");
								}
								break;
					case DISPLAY:
								if(head != NULL)
								{
									display();
								}
								else
								{
									printf("LIST IS EMPTY\n");
								}
								break;
					default:
							printf("Invalid Choice\n");
							break;
							}
		}
}