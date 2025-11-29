#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

	typedef struct {
 	 int id;
  	char name[30];
  	char email[20];
  	int rollno;
  	int contactno;
  	char address[40];
}Record;

void createRecord(){
  Record record;
  FILE *file = fopen("records.txt", "a");
  
  if (file == NULL){
    printf("Error opening file!\n");
    return;
  }
  
  printf("enter record ID: ");
  scanf("%d", &record.id);
  
  printf("Enter record name: ");
  scanf("%s", record.name);
  
  printf("Enter record email: ");
  scanf("%s", record.email);
  
  printf("Enter record rollno: ");
  scanf("%d",&record.rollno);
  
  printf("Enter record contactno: ");
  scanf("%d",&record.contactno);
  
  printf("Enter record address:  ");
  scanf("%s",record.address);
  
  fwrite(&record, sizeof(Record),1, file);
  fclose(file);
  printf("Record created successfully!\n");
}

void readrecords(){
  Record record;
  FILE *file = fopen("records.txt", "r");
  
  if (file == NULL) {
  	printf("error opening file!\n");
  	return;
  }
  
  while (fread(&record, sizeof(Record), 1, file)) {
  	printf("id: %d, name: %s, email: %s, rollno: %d, contactno: %d, address: %s\n", record.id, record.name, record.email, record.rollno, record.contactno, record.address);
	}	
	fclose(file);
}

void updateRecord(){
	Record record;
	FILE *file = fopen("records.txt", "r+");
	int id, found = 0;
	
	if (file == NULL) {
		printf("Error opening file!\n");
		return;
	}
	
	printf("Enter record ID to update: ");
	scanf("%d",&id);
	
	while (fread(&record, sizeof(Record),1, file)) {
		if (record.id == id) {
			printf("Enter new record name: ");
			scanf("%s", record.name);
			
			fflush(stdin);
			
			printf("Enter new record email: ");
			scanf("%s", record.email);
			
			fflush(stdin);
			
			printf("Enter new record rollno: ");
			scanf("%s", &record.rollno);
			printf("Enter new record contactno: ");
			scanf("%d", &record.contactno);
			printf("Enter new record address: ");
			scanf("%s", record.address);
			
			fflush(stdin);
			
			fseek(file, -sizeof(Record), SEEK_CUR);
			
			fwrite(&record, sizeof(Record),1, file);
			
			found = 1;
			break;
		}
	}
	
	if (!found) {
		printf("Record not found!\n");
	} else {
		printf("Record updated successfully!\n");
	}
	
	fclose(file);
}

void deleteRecord() {
	Record record;
	FILE *file = fopen("records.txt", "r");
	FILE *tempFile = fopen("temp.txt", "w");
	int id, found = 0;
	
	if (file == NULL || tempFile == NULL) {
		printf("Error opening file!\n");
		return;
	}
	
	printf("Enter record ID to delete: ");
	scanf("%d", &id);
	
	while (fread(&record, sizeof(Record),1, file)) {
		if (record.id != id) {
			fwrite(&record, sizeof(Record), 1, tempFile);
		} else {
			found = 1;
		}
	}
	
	fclose(file);
	fclose(tempFile);
	
	if (!found) {
		printf("Record not found!\n");
	} else {
		remove("records.txt");
		rename("temp.txt", "records.txt");
		printf("Record deleted successfully!\n");
	}
}

int main() {
	int choice;
	
	while (1) {
		printf("1. Create Record\n");
		printf("2. Read Records\n");
		printf("3. Update Record\n");
		printf("4. Delete Record\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		
		switch (choice) {
			case 1:
				createRecord();
				break;
			case 2:
				readRecord();
				break;
			case 3:
				updateRecord();
				break;
			case 4:
				deleteRecord();
				break;
			case 5:
				exit(0);
			default:
				printf("Invalid choice!\n");
	}
}
	return 0;
}
		
