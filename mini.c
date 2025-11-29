#include<stdio.h>

int  main(){
	
	struct student{
		
		char name[15];
		char class[10];
		int rollno;
		int contactno;
		char address[15];
	}typedef student;
		
		int option ;
		student s[100];
	int count = 0;
	int i;
		
		while(1){
			
			printf("=====================MENU======================\n");
			
			printf("1. Add record student\n2. update record\n3. show all detail\n4. delete record\n5. exit");
			printf("\nyour option : ");
			scanf("%d",&option);
			
			if(option == 1){
				
				printf("enter the name\n");
				scanf("%s",s[count].name);
				
				printf("enter the class\n");
				scanf("%s",s[count].class);
				
				printf("enter the rollno\n");
				scanf("%d",&s[count].rollno);
				
				printf("enter the contactno\n");
				scanf("%ld",&s[count].contactno);
				
				printf("enter the address\n");
				scanf("%s",s[count].address);
				
				count++;
				
				printf("student added sucessfully!\n");
				
			}else if(option == 2){
				int trollno;
				printf("enter rollno for update ");
				scanf("%d",&trollno);
				
				for(i=0;i<count;i++){
					if(trollno == s[i].rollno){
						printf("Enter new data for update ");
						printf("new name ");
						scanf("%s",s[i].name);
					}
				}

			}else if(option == 3){
				
				printf("==========All student record================\n");
				for(i = 0;i<count;i++){
				
				
				printf("name : %s\n",s[i].name);
				printf("class : %s\n",s[i].class);
				printf("rollno: %d\n",s[i].rollno);
				printf("contactno : %d\n",s[i].contactno);
				printf("address : %s\n",s[i].address);
				printf("----------------\n");
			}
			}else if(option == 4){
				int trollno;
				printf("enter rollno for update ");
				scanf("%d",&trollno);
				
				for(i = 0;i<count;i++){
					if(trollno != s[i].rollno ){
						printf("enter new data for update \n");
						printf("new rollno ");
						scanf("%d",&s[i].rollno);
					}
				}
				
			
			}else if(option == 5){
				break;
			}
		}
	
	
	
	}

