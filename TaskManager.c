#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

struct DATA{
	char name[64];
	char category[100];
	int day, month, year;
	char status[20];
}task[100];

int task_SIZE = 0;

void pressAnyKey(){
	printf("\nPress Any Key to Continue...\n");
	getch();
}

void addTask(){
	system("cls");
	char names[64], categories[100], stats[20];
	int days, months, years;
	
	
	printf("Input Task Name: ");
	scanf("%[^\n]", names);
	getchar();
	
	printf("Input Task Category: ");
	scanf("%[^\n]", categories);
	getchar();
	
	printf("Input Task Date: ");
	scanf("%d %d %d", &days, &months, &years);
	getchar();
	
	printf("Input Task Status: ");
	scanf("%[^\n]", stats);
	getchar();
	
	strcpy(task[task_SIZE].name,names);
	strcpy(task[task_SIZE].category,categories);
	strcpy(task[task_SIZE].status,stats);
	task[task_SIZE].day = days;
	task[task_SIZE].month = months;
	task[task_SIZE].year = years;
	
	task_SIZE++;
	puts("Task Added Successfully!\n");
	pressAnyKey();
}

void swap(struct DATA* a, struct DATA* b){
	struct DATA temp = *a;
	*a = *b;
	*b = temp;
}

void ascending(){
	system("cls");
	int i,j;
	for(i=0; i<task_SIZE; i++){
		for(j=0; j<task_SIZE-i-1; j++){	
			if(task[j].year > task[j+1].year){
				swap(&task[j], &task[j+1]);
			} else if(task[j].year == task[j+1].year){
				if(task[j].month > task[j+1].month){
					swap(&task[j], &task[j+1]);					
				} else if(task[j].month == task[j+1].month){
					if(task[j].day > task[j+1].day){
						swap(&task[j], &task[j+1]);
					}
				}
			}
			
		}	
	}
	
		puts("==========================================================================================");
		printf("| No. | Name                        | Category        | Date           | Status          |\n");
		puts("==========================================================================================");
		for(i=0; i<task_SIZE; i++){
			printf("| %-3d | %-27s | %-15s | %02d-%02d-%d     | %-15s |\n", i+1, task[i].name, task[i].category, task[i].day
							, task[i].month, task[i].year, task[i].status);
			}
		puts("==========================================================================================");
}

void descending(){
	int i,j;
	for(i=0; i<task_SIZE; i++){
		for(j=0; j<task_SIZE-i-1; j++){	
			if(task[j].year < task[j+1].year){
				swap(&task[j], &task[j+1]);
			} else if(task[j].year == task[j+1].year){
				if(task[j].month < task[j+1].month){
					swap(&task[j], &task[j+1]);					
				} else if(task[j].month == task[j+1].month){
					if(task[j].day < task[j+1].day){
						swap(&task[j], &task[j+1]);
					}
				}
			}
			
		}	
	}
}

void viewTask(){
	system("cls");
	if(!task_SIZE){
		printf("No Task..\n");
		pressAnyKey();	
		return;
	}
	
	int menu2 = 999;
	while(1){
		system("cls");
		puts("View All Task");
		printf("1. Show Ascending\n");
		printf("2. Show Descending\n");
		printf("3. Back\n");
		scanf("%d", &menu2);
		getchar();
		
		switch(menu2){
			case 1:
				ascending();
				pressAnyKey();
				break;
			case 2:
				system("cls");
				descending();
				puts("==========================================================================================");
				printf("| No. | Name                        | Category        | Date           | Status          |\n");
				puts("==========================================================================================");
				int i;
				for(i=0; i<task_SIZE; i++){
					printf("| %-3d | %-27s | %-1.05s | %02d-%02d-%d     | %-15s |\n", i+1, task[i].name, task[i].category, task[i].day
									, task[i].month, task[i].year, task[i].status);
				}
				puts("==========================================================================================");
				pressAnyKey();
				break;	
		}
		
		if(menu2 == 3){
			return;
		}
	}

}

void updateTask(){
	system("cls");
	if(!task_SIZE){
		printf("No Task..\n");
		pressAnyKey();
		return;
	}
	ascending();
	
	int num;
	do{
		printf("Input number data to update: ");
		scanf("%d", &num);
		getchar();
	} while(!(num>=1 && num<=task_SIZE));
	
	printf("Input New Task Name: ");
	scanf("%[^\n]", task[num-1].name);
	getchar();
	
	printf("Input New Task Category: ");
	scanf("%[^\n]", task[num-1].category);
	getchar();
	
	printf("Input New Task Date: ");
	scanf("%d %d %d", &task[num-1].day, &task[num-1].month, &task[num-1].year);
	getchar();
	
	printf("Input New Task Status: ");
	scanf("%[^\n]", task[num-1].status);
	getchar();
	
	printf("Data Updated!\n");
	pressAnyKey();
}

void deleteTask(){
	system("cls");
	if(!task_SIZE){
		printf("No Task..\n");
		pressAnyKey();
		return;
	}
	ascending();
	int num;
	do{
		printf("Input number data to delete: ");
		scanf("%d", &num);
		getchar();
	} while(!(num>=1 && num<=task_SIZE));
	
	task[num-1].year = 0;
	descending();
	task_SIZE--;
	
	printf("Data Deleted!\n");
	pressAnyKey();
}

void writeFile(){
	FILE* file = fopen("taskData.txt","w");
	int i;
	for(i=0; i<task_SIZE; i++){
		fprintf(file,"%s,%s,%d-%d-%d,%s\n", task[i].name, task[i].category, task[i].day, task[i].month,
				task[i].year, task[i].status);
	}
	fclose(file);
}

void readData(){
	FILE* file = fopen("taskData.txt","r");
	if(file==NULL){
		return;
	}
	while(!feof(file)){
		fscanf(file,"%[^,],%[^,],%d-%d-%d,%[^\n]\n", task[task_SIZE].name, task[task_SIZE].category, &task[task_SIZE].day, 
				&task[task_SIZE].month, &task[task_SIZE].year, task[task_SIZE].status );
		task_SIZE++;
	}
	fclose(file);
}

int main(){
	readData();
	
	int menu = 999;
	while(1){
		system("cls");
		puts("Personal Task Management");
		puts("1. Add New Task");
		puts("2. View All Task");
		puts("3. Update Task");
		puts("4. Delete Task");
		puts("5. Exit Program");
		printf("Select Option : ");
		scanf("%d", &menu);
		getchar();
		
		switch(menu){
			case 1:
				addTask();
				break;
			case 2:
				viewTask();
				break;
			case 3:
				updateTask();
				break;
			case 4:
				deleteTask();
				break;
		}
		
		if(menu==5){
			writeFile();
			printf("the program finished");
			break;
		}
	}
	

	return 0;
}
