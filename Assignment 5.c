#include "stdio.h"
#include "time.h"

#define MAX 10

struct employee
{
	int 	id;
	char name[MAX];
	char address[MAX];
	int salary;
	struct dob
	{
		int dd;
		int mm;
		int yy;
	}dob;

	struct date_of_joining
	{
		int dd;
		int mm;
		int yy;
	}doj;
};

int getAge(struct employee emp)
{
	if(emp.doj.yy > emp.dob.yy)
	{
		return (emp.doj.yy - emp.dob.yy);
	}
	else
	{
		return -1;
	}
}

int getExperience(struct employee emp,struct tm *local)
{
	return ((((local->tm_year + 1900)*12) + (local->tm_mon + 1)) - ((emp.doj.yy * 12) + emp.doj.mm));
}

void showInfo(struct employee emp,struct tm *local)
{
	printf("Age of employee when he join company was %d years old.\n",getAge(emp));

	printf("Experience of employee till date is %d months.\n",getExperience(emp,local));

	printf("Probation of employee ending in %d, %d.\n",((emp.doj.mm + 3)%12)==0? 12 : (emp.doj.mm + 3)%12,((emp.doj.mm + 3)%12)==0?emp.doj.yy:emp.doj.yy+1);
}

int main()
{
	time_t now;
	time(&now);

	struct tm *local = localtime(&now);

	struct employee emp={1,"Vaibhav","pune",1000,21,11,1997,21,10,2019};

	showInfo(emp,local);


}