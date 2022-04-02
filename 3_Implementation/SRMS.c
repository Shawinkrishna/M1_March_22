#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>

struct candidate
{
    int usn;
    char name[100];
    char email[100];
    float cgpa;
    struct candidate * next;
    
} * HEAD;

void insertStudent(int usn,char* name,char* email,float cgpa)
{
    struct candidate * candidate =(struct candidate *) malloc(sizeof(struct candidate));
    
    candidate ->usn=usn;
    strcpy(candidate ->name,name);
    strcpy(candidate ->email,email);
    candidate ->cgpa=cgpa;
    
    candidate ->next=NULL;
    
    if(HEAD == NULL)
    {
        HEAD = candidate;
    }
    else
    {
        candidate ->next =HEAD;
        HEAD =candidate;
    }
}

void searchStudent(int usn)

{
    struct candidate * temp = HEAD;
    while(temp != NULL)
    {
        if (temp ->usn==usn)
        {
            printf("usn of the student to be serch:%d \n",temp->usn);
            printf("name of the student to be serch:%s\n",temp->name);
            printf("email of the student:%s\n",temp->email);
            printf("cgpa of the student:%0.4f\n",temp->cgpa);
            return;
        }
        temp =temp ->next;
    }
    printf("student with usn %d is not found!!",usn);
}

void deleteStudent(int usn)
{
    struct candidate * temp1 =HEAD;
    struct candidate * temp2 =HEAD;
    
    while(temp1 != NULL)
    {
        if(temp1 ->usn==usn)
        {
            printf("record with usn %d found!!",usn);
            
            if(temp1 =temp2)
            {
                HEAD =HEAD ->next;
                free(temp1);
            }
            else
            {
                temp2 ->next= temp1 ->next;
                free(temp1);
            }
            printf("record is succesfully deleted");
            return;
        }
        temp2 =temp1;
        temp1 =temp1 -> next;
    }
    printf("student with usn %d is not found",usn);
}

void updateStudent(int usn)

{
    struct candidate * temp =HEAD;
    
    while(temp != NULL)
    {
        if(temp -> usn==usn)
        {
            printf("Record with usn %d is found\n",usn);
            printf("enter new name : ");
            scanf("%s", temp ->name);
            printf("enter new email id :");
            scanf("%s", temp ->email);
            printf("enter new cgpa: ");
            scanf("%f",&temp ->cgpa);
            printf("updated succesfully!!");
            return;
        }
        temp =temp ->next;
    
    }
    printf("student with usn %d is not found",usn);
}

void display()
{
    struct candidate * temp = HEAD;
    
    while( temp != NULL)
    {
        printf("USN:%d \n",temp ->usn);
        printf("Name:%s \n",temp ->name);
        printf("email:%s \n",temp ->email);
        printf("cgpa:%0.4f \n \n",temp ->cgpa);
        
        temp = temp ->next;
    }
}
int main()
{
    HEAD = NULL;
    int choice;
    char name[100];
    char email[100];
    int usn;
    float cgpa;
    do
    {

         printf("1 to insert student details\n2 to search for student details\n3 to delete student details\n4 to update student details\n5 to display all student details");
    
    
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter USN: ");
                scanf("%d", &usn);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email id: ");
                scanf("%s", email);
                printf("Enter cgpa: ");
                scanf("%f", &cgpa);
                insertStudent(usn, name, email, cgpa);
                break;
            case 2:
                printf("Enter usn to search: ");
                scanf("%d", &usn);
                searchStudent(usn);
                break;
            case 3:
                printf("Enter usn to delete: ");
                scanf("%d", &usn);
                deleteStudent(usn);
                break;
            case 4:
                printf("Enter usn to update: ");
                scanf("%d", &usn);
                updateStudent(usn);
                break;
            case 5:
                display();
                break;
            case 6:
               printf("exit\n");
               break;
            
        }
        
    } while (choice != 6);

}




























