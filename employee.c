#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"dict.h"
struct empl{
	int sal;
	char gen;
};
struct empl *create(void){
	struct empl *new_employee;
	new_employee=(struct empl *)malloc(sizeof(struct empl));
	return new_employee;
}
int main(void){
	int choice,input,sal;
	char name[50];
	char gen;
	Dict *dict,*dict1,*dict2;
	dict1=NULL;
	dict2=NULL;
	while(1){
		printf("\nEnter 1 to create a record of employees:");
		printf("\nEnter 2 to insert a employee details in records:");
		printf("\nEnter 3 to search for employee details:");
		printf("\nEnter 4 to update the salary of employee:");
		printf("\nEnter 5 to delete a employee record:");
		printf("\nEnter 6 to merge two employee records:");
		printf("\nEnter 7 to display employee record");
		printf("\nEnter 8 to destroy dictonary:");
		printf("\nEnter 9 to Exit");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:dict=create_dict();
			break;
			
			case 2:printf("Enter the name of the employee:");
				   scanf("%s",name);
				   fflush(stdin);
				   printf("Enter the Gender of the employee(M for Male and F for Female) :");
				   scanf("%c",&gen);
				   printf("Enter employee salary:");
				   scanf("%d",&sal);
				   struct empl *temp1=create();
				   temp1->gen=gen;
				   temp1->sal=sal;
				   insert_dict_with_key(&dict,name,temp1);
			break;
			case 3:printf("\nEnter the name of employee to search:");
				   scanf("%s",name);
					struct empl *temp=search_dict_with_key(dict,name);
				   	if(temp==NULL){
				   		printf("\nEmployee not found");
				   	}
				   	else{
				   		printf("Employee details:\n");
				   		printf("\nname=%s\n Gender=%c\nsalary=%d\n",name,temp->gen,temp->sal);
				   	}
			break;
			case 4:printf("Enter employee name to update cgpa:");
				   scanf("%s",name);
				   printf("Enter new salary of employee to update:");
				   scanf("%d",&sal);
				   struct empl *temp2=create();
				   temp2->sal=sal;
				   update_dict_given_key(&dict,name,temp2);
			break;
			case 5:printf("Enter employee name to delete:");
				   scanf("%s",name);
			       delete_from_dict_given_key(&dict,name);
			break;
			case 6:
			    if(dict2==NULL){
                       dict2=create_dict();
                   }
                   dict=Merge_two_dict(dict1,dict2);
				   printf("Two employee records are merged into first employee record");
			break;
			
			case 7:
                    if(dict==NULL){
			            printf("Dictionary not created");
                    }
                    else{
                        printf("Number of employees in the dictionary are:%d\n",dict->count);
                    }
            break;
            case 8:destroy_dict(&dict);
				   printf("\nYour employee record is destroyed successfully");
			break;
			case 9:exit(0);
			break;
			default:printf("Enter data correctly");
		}
	}
}
