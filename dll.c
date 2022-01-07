- 👋 Hi, I’m @Usmanafan
- 👀 I’m interested in ...
- 🌱 I’m currently learning ...
- 💞️ I’m looking to collaborate on ...
- 📫 How to reach me ...

<!---
Usmanafan/Usmanafan is a ✨ special ✨ repository because its `README.md` (this file) appears on your GitHub profile.
You can click the Preview link to take a look at your changes.
--->
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int count=0;
struct node
{
int ssn, phno;
float sal;
char name[50],dept[50],desig[50];
struct node *llink;
struct node *rlink;
};
struct node *first = NULL,*temp = NULL,*temp1=NULL,*temp2=NULL;
void CreateNode()
{
int ssn,phno;
float sal;
char name[50],dept[50],desig[50];
temp =(struct node *)malloc(sizeof(struct node));
temp->llink = NULL;
temp->rlink = NULL;
printf("\nEnter ssn,name,department, designation, salary and phno of employee\n");
scanf("%d %s %s %s %f %d", &ssn, name,dept,desig,&sal, &phno);
temp->ssn = ssn;
strcpy(temp->name,name);
strcpy(temp->dept,dept);
strcpy(temp->desig,desig);
temp->sal = sal;
temp->phno = phno;
count++;
}
void InsertAtFront()
{
if (first == NULL)
{
CreateNode();
first = temp;
temp1 = first;
}
else
{
CreateNode();
temp->rlink = first;
first->llink = temp;
first = temp;
}
}
void InsertAtEnd()
{
if(first==NULL)
{
CreateNode();
first = temp;
temp1 = first;
}
else
{
CreateNode();
temp1->rlink = temp;
temp->llink = temp1;
temp1 = temp;
}
}
void Display()
{
temp2 =first;
if(temp2 == NULL)
{
printf("\nList is empty \n");
}
else
{
printf("\n\nThe elements of DLL are :\n");
while (temp2!= NULL)
{
printf("%d %s %s %s %f %d\n", temp2->ssn, temp2->name,temp2->dept,temp2->desig,temp2->sal, temp2->phno );
temp2 = temp2->rlink;
}
}
printf("Number of employees = %d ", count);
}
void DeleteAtEnd()
{
struct node *temp;
temp=first;
if(first == NULL)
printf("\nList is empty\n");
else if(temp->rlink==NULL)
{
printf("The employee record deleted is\n%d %s %s %s %f %d\n", temp->ssn, temp->name,temp->dept,temp->desig,temp->sal, temp->phno );
free(temp);
first=NULL;
count--;
}
else
{
temp2=temp1->llink;
temp2->rlink=NULL;
printf("The employee record deleted is\n%d %s %s %s %f %d\n", temp1->ssn, temp1->name,temp1->dept,temp1->desig,temp1->sal, temp1->phno );
free(temp1);
temp1 = temp2;
count--;
}
}
void DeleteAtFront()
{
struct node *temp;
temp=first;
if(first == NULL)
printf("\nList is empty\n");
else if(temp->rlink==NULL)
{
printf("The employee record deleted is\n%d %s %s %s %f %d", temp->ssn, temp->name,temp->dept, temp->desig,temp->sal, temp->phno );
free(temp);
first=NULL;
count--;
}
else
{
first=first->rlink;
printf("The employee record deleted is\n%d %s %s %s %f %d", temp->ssn, temp->name,temp->dept, temp->desig,temp->sal, temp->phno );
free(temp); \
count--;
}
}
int main()
{
int choice,choice2,n,i, flag, flag1, flag2;
first=NULL;
temp = temp1 = NULL;
while(1)
{
printf("\n\n**********************MENU*****************");
printf("\n1. Create a DLL of N employees Data by using end insertion\n2. Display the status of DLL and count the number of nodes in it\n3.Perform Insertion and Deletion at End of DLL\n4. Perform Insertion and Deletion at Front of DLL\n5. Demonstaration of DLL as DOUBLE ENDED QUEUE\n6. Exit");
printf("\nEnter your choice : ");
scanf("%d",&choice);
switch(choice)
{
case 1 : printf("Enter the number of employees : ");
scanf("%d",&n);
for(i=0;i<n;i++)
InsertAtEnd();
break;
case 2 : Display();
break;
case 3 : flag1 = 0;
while(flag1 == 0)
{
printf("\n\n1. Insertion\n2. Deletion\n3. Exit");
printf("\n\nEnter your option\n");
scanf("%d",&choice2);
switch(choice2)
{
case 1 : InsertAtEnd();
Display();
break;
case 2 : DeleteAtEnd();
Display();
break;
case 3 : flag1 = 1;
break;
}
}
break;
case 4 : flag2 = 0;
while(flag2 == 0)
{
printf("\n\n1. Insertion\n2. Deletion\n3. Exit\n");
printf("\n\nEnter your option\n");
scanf("%d",&choice2);
switch(choice2)
{
case 1 : InsertAtFront();
Display();
break;
case 2 : DeleteAtFront();
Display();
break;
case 3 : flag2 = 1;
break;
}
}
break;
case 5 : printf("Demonstration of DLL as DOUBLE ENDED QUEUE\n");
flag = 0;
while(flag == 0)
{
printf("\n\n1. Insert at end\n2. Delete at end\n3. Insert at front\n4. Delete at front\n5. Exit\n\n");
printf("\nEnter your option : ");
scanf("%d",&choice2);
switch(choice2)
{
case 1 : InsertAtEnd();
Display();
break;
case 2 : DeleteAtEnd();
Display();
break;
case 3 : InsertAtFront();
Display();
break;
case 4 : DeleteAtFront();
Display();
break;
case 5 : flag = 1;
break;
}
}
break;
case 6 : exit(0);
break;
}
}
}
